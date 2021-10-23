import numpy as np
import random


def affine_forward(x, w, b):
    x_2D = x.reshape(x.shape[0], -1)
    h = np.dot(x_2D, w) + b
    cache = (x, w, b)
    return h, cache


def affine_backward(dout, cache):
    x, w, b = cache
    dx = np.dot(dout, w.T)
    dx = np.reshape(dx, x.shape)
    x_2D = x.reshape(x.shape[0], -1)
    dw = np.dot(x_2D.T, dout)
    db = np.sum(dout, axis=0, keepdims=True)
    return dx, dw, db


def rand():
    return random.random()*10000*(-1 if random.random() < 0.5 else 1)


def create_date(n):
    x = np.zeros((n, 2), dtype=np.float64)
    y = np.zeros(n, dtype=np.int64)
    for i in range(n):
        x[i] = [rand(), rand()]
        tmp = x[i][0]*x[i][1]
        y[i] = 0 if tmp == 0 else (
            (1 if x[i][0] > 0 else 3) if tmp > 0 else (2 if x[i][0] < 0 else 4))
    return x, y


def preprosess(x):
    # x -= np.mean(x, axis=1, keepdims=True)
    x /= np.std(x, axis=1, keepdims=True) + 1
    return x


if __name__ == '__main__':
    n = 1000
    x, y = create_date(n)
    d = x.shape[1]
    num_classes = 5
    m = 50
    reg = 0.001
    epsilon = 0.001
    threshold = 0.01
    Time = 10000

    # init
    x_ = preprosess(x)
    w1 = np.random.randn(d, m)
    w2 = np.random.randn(m, num_classes)
    b1 = np.zeros((1, m))
    b2 = np.zeros((1, num_classes))
    loss = 1.0
    j = 0
    # train
    while j < Time and loss > threshold:
        # forward
        h_, f_cache_1 = affine_forward(x_, w1, b1)
        h_ = np.maximum(0, h_)
        relu_cache = h_
        y_, f_cache_2 = affine_forward(h_, w2, b2)
        # softmax
        prob = np.exp(y_ - np.max(y_, axis=1, keepdims=True))
        prob /= np.sum(prob, axis=1, keepdims=True)
        # loss
        loss = -np.sum(np.log(prob[np.arange(n), y])) / n
        print('Ite', j, ':', loss)
        j += 1
        # backward
        dx = prob.copy()
        dx[np.arange(n), y] -= 1
        dx /= n
        dh1, dw2, db2 = affine_backward(dx, f_cache_2)
        dh1[relu_cache <= 0] = 0
        dx, dw1, db1 = affine_backward(dh1, f_cache_1)
        # update parameters
        dw2 += reg*w2
        dw1 += reg*w1
        w2 += -epsilon * dw2
        b2 += -epsilon * db2
        w1 += -epsilon * dw1
        b1 += -epsilon * db1

    # init
    tn = 100
    tx, ty = create_date(tn)
    tx_ = preprosess(tx)
    # test
    # forward
    h_, f_cache_1 = affine_forward(tx_, w1, b1)
    h_ = np.maximum(0, h_)
    relu_cache = h_
    y_, f_cache_2 = affine_forward(h_, w2, b2)
    # softmax
    prob = np.exp(y_ - np.max(y_, axis=1, keepdims=True))
    prob /= np.sum(prob, axis=1, keepdims=True)
    correct = 0
    for i in range(tn):
        correct += 1 if ty[i] == np.argmax(prob[i, :]) else 0
        # print(tx[i, :], 'in', np.argmax(prob[i, :]), 'act', ty[i])
    print(correct/tn)
