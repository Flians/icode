import numpy as np


def get_interest_points(image, feature_width):
    """ Returns a set of interest points for the input image
    Args:
        image - can be grayscale or color, your choice.
        feature_width - in pixels, is the local feature width. It might be
            useful in this function in order to (a) suppress boundary interest
            points (where a feature wouldn't fit entirely in the image)
            or (b) scale the image filters being used. Or you can ignore it.
    Returns:
        x and y: nx1 vectors of x and y coordinates of interest points.
        confidence: an nx1 vector indicating the strength of the interest
            point. You might use this later or not.
        scale and orientation: are nx1 vectors indicating the scale and
            orientation of each interest point. These are OPTIONAL. By default you
            do not need to make scale and orientation invariant local features.
    """
    assert image.ndim == 2, "Image must be grayscale"

    import cv2

    ksize = 5
    Ix = cv2.Sobel(image, cv2.CV_64F, 1, 0, ksize=ksize)
    Iy = cv2.Sobel(image, cv2.CV_64F, 0, 1, ksize=ksize)

    ksize = 7
    Ixx = cv2.GaussianBlur(Ix ** 2, (ksize, ksize), 0)
    Iyy = cv2.GaussianBlur(Iy ** 2, (ksize, ksize), 0)
    Ixy = cv2.GaussianBlur(Ix * Iy, (ksize, ksize), 0)

    alpha = 0.06
    threshold = 0.05
    XYR = []
    row = image.shape[0]
    column = image.shape[1]
    offset = feature_width // 2
    for i in range(offset, row - offset, 2):
        for j in range(offset, column - offset, 2):
            Sxx = Ixx[i - offset:i + offset + 1, j - offset:j + offset + 1].sum()
            Syy = Iyy[i - offset:i + offset + 1, j - offset:j + offset + 1].sum()
            Sxy = Ixy[i - offset:i + offset + 1, j - offset:j + offset + 1].sum()
            det = (Sxx * Syy) - (Sxy ** 2)
            trace = Sxx + Syy
            # R = det - alpha * trace ** 2
            R = det / (trace + 0.000001)
            if R > threshold:
                XYR.append([j, i, R])
    XYR = np.asarray(sorted(XYR, key=lambda x: x[2], reverse=True))
    num = min(3000, len(XYR))
    x = XYR[:num, 0:1]
    y = XYR[:num, 1:2]
    return x, y


def get_features(image, x, y, feature_width):
    """ Returns a set of feature descriptors for a given set of interest points.
    Args:
        image - can be grayscale or color, your choice.
        x and y: nx1 vectors of x and y coordinates of interest points.
            The local features should be centered at x and y.
        feature_width - in pixels, is the local feature width. You can assume
            that feature_width will be a multiple of 4 (i.e. every cell of your
            local SIFT-like feature will have an integer width and height).
        If you want to detect and describe features at multiple scales or
            particular orientations you can add other input arguments.
    Returns:
        features: the array of computed features. It should have the
            following size: [length(x) x feature dimensionality] (e.g. 128 for
            standard SIFT)
    """
    assert image.ndim == 2, "Image must be grayscale"

    int_x = np.round(x).astype(int)
    int_y = np.round(y).astype(int)
    y = np.squeeze(int_x)
    x = np.squeeze(int_y)
    offset = feature_width // 2
    image = np.pad(image, (offset, offset), 'edge')
    x += offset
    y += offset

    # step 1 GaussianBlur
    import cv2
    blur_image = cv2.GaussianBlur(image, (9, 9), 0)

    # step 2 gradients
    Gy, Gx = np.gradient(blur_image)

    # step 3 magnitude and orientation
    mag = np.sqrt(Gx**2 + Gy**2)
    orient = np.arctan2(Gy, Gx)
    orient[orient < 0] += np.pi * 2

    # step 4 further weighted by Gaussian
    cell_length = feature_width // 4
    Gau_kernel = cv2.getGaussianKernel(feature_width, offset)
    features = np.zeros((x.shape[0], 128))
    for i in range(x.shape[0]):
        window = mag[(x[i] - offset):(x[i] + offset), (y[i] - offset):(y[i] + offset)]
        window = cv2.sepFilter2D(window, -1, Gau_kernel, np.transpose(Gau_kernel))
        window_orient = orient[(x[i] - offset):(x[i] + offset), int(y[i] - offset):int(y[i] + offset)]
        # Step 5 windows
        for i_x in range(4):
            for i_y in range(4):
                cell = window[i_x * cell_length:(i_x + 1) * cell_length, i_y * cell_length:(i_y + 1) * cell_length]
                cell_orient = window_orient[i_x * cell_length:(i_x + 1) * cell_length, i_y * cell_length:(i_y + 1) * cell_length]
                bin = np.zeros(8)
                for angle in range(8):
                    bin[angle] += np.sum(cell[np.all([cell_orient >= (angle * np.pi / 4), cell_orient < ((angle + 1) * np.pi / 4)], 0)])
                features[i, (i_x * 4 + i_y) * 8:(i_x * 4 + i_y) * 8 + 8] = bin
    # step 6 normalization
    norm = np.linalg.norm(features, axis=1, keepdims=True)
    norm[norm == 0] = 0.000001  # to avoid division by 0
    '''
    features = features / norm
    features[features >= 0.5] = 0.5
    norm = np.linalg.norm(features, axis=1, keepdims=True)
    norm[norm == 0] = 0.000001  # to avoid division by 0
    '''
    return features / norm


def match_features(features1, features2, threshold=0.0):
    """ 
    Args:
        features1 and features2: the n x feature dimensionality features
            from the two images.
        threshold: a threshold value to decide what is a good match. This value 
            needs to be tuned.
        If you want to include geometric verification in this stage, you can add
            the x and y locations of the features as additional inputs.
    Returns:
        matches: a k x 2 matrix, where k is the number of matches. The first
            column is an index in features1, the second column is an index
            in features2. 
        Confidences: a k x 1 matrix with a real valued confidence for every
            match.
        matches' and 'confidences' can be empty, e.g. 0x2 and 0x1.
    """
    distances = np.sqrt(np.sum((features1[:, np.newaxis, :] - features2) ** 2, axis=2))
    indexs = np.argsort(distances, axis=1)

    num_features = len(distances)
    matched = np.zeros((num_features, 2))
    confidence = np.zeros((num_features, 1))
    for i in range(num_features):
        matched[i, 0] = i
        matched[i, 1] = indexs[i][0]
        confidence[i] = distances[i][indexs[i][1]] / (distances[i][indexs[i][0]] if distances[i][indexs[i][0]] != 0 else 0.000001)
    order = np.argsort(confidence, axis=0)[::-1, 0]
    confidence = confidence[order, :]
    matched = matched[order, :]
    index_x, index_y = (confidence > threshold).nonzero()
    confidence = confidence[index_x, index_y]
    matched = matched[index_x, :]
    return matched, confidence
