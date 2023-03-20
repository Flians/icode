import numpy as np
import math
import cv2


def image_t(im, scale=1.0, rot=45, trans=(50, -50)):
    # TODO Write "image affine transformation" function based on the illustration in specification.
    # Return transformed result image
    rot_mat = cv2.getRotationMatrix2D((im.shape[0] // 2, im.shape[1] // 2), rot, scale)
    rot_dst = cv2.warpAffine(im, rot_mat, (im.shape[0], im.shape[1]))

    theta = 0
    scale = 1
    srcTri = np.array([[0, 0], [im.shape[1] - 1, 0], [0, im.shape[0] - 1]]).astype(np.float32)
    dstTri = np.array([
        [trans[0], trans[1]],
        [scale * math.cos(theta) * (im.shape[1] - 1) + trans[0], -scale * math.sin(theta) * (im.shape[1] - 1) + trans[1]],
        [scale * math.sin(theta) * (im.shape[0] - 1) + trans[0], scale * math.cos(theta) * (im.shape[0] - 1) + trans[1]]
    ]).astype(np.float32)
    warp_mat = cv2.getAffineTransform(srcTri, dstTri)
    result = cv2.warpAffine(rot_dst, warp_mat, (im.shape[0], im.shape[1]))
    return result


if __name__ == '__main__':
    im = cv2.imread('./misc/pearl.jpeg')

    scale = 0.5
    rot = 45
    trans = (50, -50)
    result = image_t(im, scale, rot, trans)
    cv2.imwrite('./results/affine_result.png', result)
