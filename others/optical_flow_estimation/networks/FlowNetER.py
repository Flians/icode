import torch
import torch.nn as nn
from torch.nn import init

import math
import numpy as np


class FlowNetEncoderRefine(nn.Module):
    def __init__(self, args, input_channels=6, batchNorm=False, div_flow=20):
        super(FlowNetEncoderRefine, self).__init__()

        self.rgb_max = args.rgb_max
        self.div_flow = div_flow    # A coefficient to obtain small output value for easy training, ignore it

        '''Implement Codes here'''
        ''''''
        def conv(batchNorm, in_planes, out_planes, kernel_size=3, stride=1):
            if batchNorm:
                return nn.Sequential(
                    nn.Conv2d(in_planes, out_planes, kernel_size=kernel_size, stride=stride, padding=(kernel_size - 1) // 2, bias=False),
                    nn.BatchNorm2d(out_planes),
                    nn.LeakyReLU(negative_slope=0.1, inplace=True)
                )
            else:
                return nn.Sequential(
                    nn.Conv2d(in_planes, out_planes, kernel_size=kernel_size, stride=stride, padding=(kernel_size - 1) // 2, bias=True),
                    nn.LeakyReLU(negative_slope=0.1, inplace=True)
                )

        def deconv(in_planes, out_planes):
            return nn.Sequential(
                nn.ConvTranspose2d(in_planes, out_planes, kernel_size=4, stride=2, padding=1, bias=True),
                nn.LeakyReLU(0.1, inplace=True)
            )

        self.batchNorm = batchNorm
        self.conv1 = conv(self.batchNorm, input_channels, 16, kernel_size=7, stride=2)
        self.conv2 = conv(self.batchNorm, 16, 32, kernel_size=4, stride=2)
        self.conv3 = conv(self.batchNorm, 32, 64, kernel_size=3, stride=2)
        self.conv4 = conv(self.batchNorm, 64, 128, kernel_size=3, stride=2)
        self.conv4_1 = conv(self.batchNorm, 128, 128, kernel_size=3, stride=1)

        self.deconv4 = deconv(128, 64)
        self.deconv3 = deconv(128, 32)

        self.predict_flow2 = nn.Conv2d(64, 2, kernel_size=3, stride=1, padding=1, bias=True)

    def forward(self, inputs):
        # input normalization
        rgb_mean = inputs.contiguous().view(inputs.size()[:2] + (-1,)).mean(dim=-1).view(inputs.size()[:2] + (1, 1, 1,))
        x = (inputs - rgb_mean) / self.rgb_max
        x = torch.cat((x[:, :, 0, :, :], x[:, :, 1, :, :]), dim=1)
        ##
        '''Implement Codes here'''
        ''''''
        out_conv1 = self.conv1(x)
        out_conv2 = self.conv2(out_conv1)
        out_conv3 = self.conv3(out_conv2)
        out_conv4 = self.conv4_1(self.conv4(out_conv3))

        out_deconv3 = self.deconv4(out_conv4)
        concat3 = torch.cat((out_conv3, out_deconv3), 1)

        out_deconv2 = self.deconv3(concat3)
        concat2 = torch.cat((out_conv2, out_deconv2), 1)

        flow2_pred = self.predict_flow2(concat2)
        flow2 = torch.nn.functional.interpolate(input=flow2_pred, scale_factor=4)

        if self.training:
            return flow2
        else:
            return flow2 * self.div_flow
