# ENGG5104 – Image Processing and Computer Vision – Spring 2023
## Assignment 2 — Image Recognition
- ID: 1155186658
- Name: Rongliang Fu

## vggnet structure
To make sure the computational cost should be under 200M FLOPs, the network structure is as follows:
- conv3-64
- maxpool-2*2
- conv3-128
- maxpool-2*2
- conv3-256
- conv3-256
- maxpool-2*2
- conv3-512
- conv3-512
- maxpool-2*2
- conv3-512
- conv3-512
- maxpool-2*2
- avgpool-6*6
- FC-2048
- FC-2048
- FC-10

```shell
$ CUDA_VISIBLE_DEVICES=0 python3 train.py --calculate-flops=True
Files already downloaded and verified
Files already downloaded and verified
conv: 152.92M
linear: 41.97M
bn: 0.00M
relu: 0.16M
pool: 0.12M
  + Number of FLOPs: 195.16M
conv 9.22M
linear: 41.97M
total_params 51.19M
```

## Cross-entroy loss: log2.txt
After completing this part, the accuracy is 51.81%

## Conventional Augmentations: log3.txt
After completing this part, the accuracy is 64.28%

## Cutout Augmentations: log4.txt
After completing Cutout(size=12), the accuracy is 65.96%
