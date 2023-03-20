import torch
import torch.nn as nn
import numpy as np
import torch.nn.functional as F


class CrossEntropyLoss(nn.Module):
    # TODO: task 2
    def __init__(self, **kwargs):
        super(CrossEntropyLoss, self).__init__()
        # TODO: implemente cross entropy loss for task2;
        # You cannot directly use any loss functions from torch.nn or torch.nn.functional, other modules are free to use.

    def forward(self, x, y, **kwargs):
        softmax_pred = torch.softmax(x, dim=1)
        target = y.view(-1, 1)
        prob_target = torch.gather(softmax_pred, 1, target)
        log_prob_target = torch.log(prob_target)
        return -1 * log_prob_target.mean()

        '''
        log_softmax = nn.LogSoftmax(dim=1)
        loss_function = nn.NLLLoss()
        output = log_softmax(x)
        loss = loss_function(output, y)
        '''
        return loss
