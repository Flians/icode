import numpy as np
import cv2


def bilateral(im, d, sigmaColor, sigmaSpace):
    # TODO Write "bilateral filter" function based on the illustration in specification.
    # Return filtered result image
    result = cv2.bilateralFilter(im, d, sigmaColor, sigmaSpace)
    return result


def joint_bilateral(im, guidance, d, sigmaColor, sigmaSpace):
    # TODO Write "joint bilateral filter" function based on the illustration in specification.
    # Return filtered result image
    result = cv2.ximgproc.jointBilateralFilter(guidance, im, d, sigmaColor, sigmaSpace)
    return result


if __name__ == '__main__':
    im = cv2.imread('./misc/Original_Bilateral.jpg').astype(np.float32)
    guidance = cv2.imread('./misc/GuidanceImage.jpg').astype(np.float32)

    d, sigmaColor, sigmaSpace = 9, 75, 75
    result_bilateral = bilateral(im, d, sigmaColor, sigmaSpace)
    result_joint_bilateral = joint_bilateral(im, guidance, d, sigmaColor, sigmaSpace)

    cv2.imwrite('./results/Billateral.jpg', result_bilateral)
    cv2.imwrite('./results/JointBillateral.jpg', result_joint_bilateral)

    cv2.imwrite('./results/DiffBillateral.jpg', cv2.compare(cv2.cvtColor(result_bilateral, cv2.COLOR_BGR2GRAY), cv2.cvtColor(result_joint_bilateral, cv2.COLOR_BGR2GRAY), cv2.CMP_GT))
