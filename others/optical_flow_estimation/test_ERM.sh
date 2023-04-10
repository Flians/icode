
#    --resume checkpoints/FlowNet2-S_checkpoint.pth.tar
#    --resume work/FlowNet2S_model_best.pth.tar

python3 main.py \
    --inference \
    --model FlowNetERM \
    --loss=MultiscaleLoss \
    --save_flow \
    --inference_visualize \
    --inference_dataset MpiSintelClean \
    --inference_dataset_root data/validation \
    --resume work/FlowNetERM_model_best.pth.tar
