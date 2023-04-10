import torch
import torch.nn as nn
import torch.nn.functional as F
import math


class OursLoss(nn.Module):
    def __init__(self, args, div_flow=0.05):
        super(OursLoss, self).__init__()
        self.div_flow = div_flow
        self.loss_labels = ['Ours'],

    def forward(self, output, target):
        epevalue = 0
        target = self.div_flow * target
        assert output.shape == target.shape, (output.shape, target.shape)
        ''' Implement the your loss here'''
        ''''''
        epevalue = torch.norm(output - target, p=2, dim=1).mean()
        return [epevalue]
