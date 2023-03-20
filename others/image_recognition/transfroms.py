import torch
import numpy as np
import PIL
import cv2
import random

# TODO: implementation transformations for task3;
# You cannot directly use them from pytorch, but you are free to use functions from cv2 and PIL


class Padding(object):
    def __init__(self, padding):
        self.padding = padding

    def __call__(self, img, **kwargs):
        width, height = img.size
        fill_color = (0, 0, 0)  # (np.random.randint(0, 256), np.random.randint(0, 256), np.random.randint(0, 256))
        padded_image = PIL.Image.new(img.mode, (width + self.padding * 2, height + self.padding * 2), fill_color)
        padded_image.paste(img, (self.padding, self.padding))
        return img
        # return PIL.ImageOps.expand(img, border=(self.padding, self.padding, self.padding, self.padding), fill=fill_color)


class RandomCrop(object):
    def __init__(self, size):
        self.size = size

    def __call__(self, img, **kwargs):
        width, height = img.size
        if self.size >= width or self.size >= height:
            wpad, hpad = max(4, self.size - width), max(4, self.size - height)
            img = PIL.ImageOps.expand(img, border=(wpad // 2, hpad // 2, (wpad + 1) // 2, (hpad + 1) // 2), fill=0)
            width, height = img.size
        x = np.random.randint(0, width - self.size + 1)
        y = np.random.randint(0, height - self.size + 1)
        return img.crop((x, y, x + self.size, y + self.size))


class RandomFlip(object):
    def __init__(self,):
        pass

    def __call__(self, img, **kwargs):
        if np.random.random() > 0.5:
            return img.transpose(PIL.Image.FLIP_LEFT_RIGHT)  # if np.random.random() > 0.2 else img.transpose(PIL.Image.FLIP_TOP_BOTTOM)
        else:
            return img


class Cutout(object):
    def __init__(self, size):
        self.size = size

    def __call__(self, img, **kwargs):
        w, h = img.size
        x = np.random.randint(w)
        y = np.random.randint(h)
        x1 = max(0, x - self.size // 2)
        y1 = max(0, y - self.size // 2)
        x2 = min(w, x1 + self.size)
        y2 = min(h, y1 + self.size)
        image = np.array(img)
        image[y1:y2, x1:x2] = (0, 0, 0)
        return PIL.Image.fromarray(image)


class RandomBrightnessContrast(object):
    def __init__(self, brightness_range=[0.5, 1.5], contrast_range=[0.5, 1.5]):
        self.brightness_range = brightness_range
        self.contrast_range = contrast_range

    def __call__(self, img):
        if np.random.random() > 0.2:
            return img
        import torchvision.transforms as transforms
        rnd_brightness = random.uniform(self.brightness_range[0], self.brightness_range[1])  # randomly adjust brightness
        rnd_contrast = random.uniform(self.contrast_range[0], self.contrast_range[1])  # randomly adjust contrast
        brightness_contrast_transform = transforms.Compose([
            transforms.ColorJitter(brightness=rnd_brightness, contrast=rnd_contrast)
        ])
        return brightness_contrast_transform(img)
