import numpy as np
import cv2


def hpf_fourier(im, hpf_w=60):
    # TODO Write "High-pass Filter with Fourier Transform" function based on the illustration in specification.
    # Return transformed result image
    transform = np.fft.fft2(im)
    shift = np.fft.fftshift(transform)
    crow, ccol = im.shape[0] // 2, im.shape[1] // 2
    shift[(crow - hpf_w // 2):(crow + hpf_w // 2), (ccol - hpf_w // 2):(ccol + hpf_w // 2)] = 0
    f_ishift = np.fft.ifftshift(shift)
    result = np.abs(np.fft.ifft2(f_ishift))
    return result


if __name__ == '__main__':
    im = cv2.imread('./misc/lena_gray.bmp', 0)
    hpf_w = 60
    result = hpf_fourier(im, hpf_w)
    cv2.imwrite('./results/hpf_fourier.png', result)
