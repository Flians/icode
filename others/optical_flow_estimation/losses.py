import torch
import torch.nn as nn
import torch.nn.functional as F
import math


class EPELoss(nn.Module):
    def __init__(self, args, div_flow=0.05):
        super(EPELoss, self).__init__()
        self.div_flow = div_flow
        self.loss_labels = ['EPE'],

    def forward(self, output, target):
        epevalue = 0
        target = self.div_flow * target
        assert output.shape == target.shape, (output.shape, target.shape)
        ''' Implement the EPE loss here'''
        ''''''
        epevalue = torch.norm(output - target, p=2, dim=1).mean()
        return [epevalue]


class MultiscaleLoss(nn.Module):
    def __init__(self, args):
        super(MultiscaleLoss, self).__init__()

        self.args = args
        self.div_flow = 0.05
        self.loss_labels = ['Multiscale'],
        ''' Implement the MultiScale loss here'''
        ''''''
        self.loss_weights = torch.FloatTensor([(0.32 / 2 ** scale) for scale in range(3)])  # torch.FloatTensor([0.32, 0.08, 0.02, 0.01, 0.005])

    def forward(self, output, target):
        lossvalue = 0
        epevalue = 0
        target = self.div_flow * target
        for i, output_ in enumerate(output):
            target_ = F.interpolate(target, output_.shape[2:], mode='bilinear', align_corners=False)
            assert output_.shape == target_.shape, (output_.shape, target_.shape)
            ''' Implement the MultiScale loss here'''
            ''''''
            epevalue += self.loss_weights[i] * torch.norm(output_ - target_, p=2, dim=1).mean()
        return [epevalue]
