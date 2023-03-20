import numpy as np
import cv2


def histogram_equalization(im):
    # TODO Write "histogram equalization" function based on the illustration in specification.
    # Return filtered result image
    gray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
    result = cv2.equalizeHist(gray)
    return result


def local_histogram_equalization(im):
    # TODO Write "local histogram equalization" function based on the illustration in specification.
    # Return filtered result image
    gray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
    result = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8)).apply(gray)
    return result


if __name__ == '__main__':
    im = cv2.imread('./misc/Original_HistEqualization.jpeg')

    result_hist_equalization = histogram_equalization(im)

    result_local_hist_equalization = local_histogram_equalization(im)

    cv2.imwrite('./results/HistoEqualization.jpg', result_hist_equalization)
    cv2.imwrite('./results/LocalHistoEqualization.jpg', result_local_hist_equalization)
