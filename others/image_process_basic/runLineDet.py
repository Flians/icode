import numpy as np
import cv2


def line_det(im):
    # TODO Write "line detection" function based on the illustration in specification.
    # Return detected result image
    gray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
    dst = cv2.GaussianBlur(gray, (5, 5), cv2.BORDER_DEFAULT)
    edges = cv2.Canny(dst, 50, 150)
    lines = cv2.HoughLinesP(edges, 1, np.pi / 180, threshold=85, minLineLength=5, maxLineGap=10)

    result = im
    # Iterate over points
    for points in lines:
        # Extracted points nested in the list
        x1, y1, x2, y2 = points[0]
        # Draw the lines joing the points on the original image
        cv2.line(result, (x1, y1), (x2, y2), (0, 255, 0), 2)
    return result


if __name__ == '__main__':
    im = cv2.imread('./misc/road.jpeg')

    result = line_det(im)
    cv2.imwrite('./results/line_det.png', result)
