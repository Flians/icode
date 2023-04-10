
#    --resume checkpoints/FlowNet2-S_checkpoint.pth.tar
#    --resume work/FlowNet2S_model_best.pth.tar

python3 main.py \
    --inference \
    --model FlowNetOurs \
    --loss=OursLoss \
    --save_flow \
    --inference_visualize \
    --inference_dataset MpiSintelClean \
    --inference_dataset_root data/validation \
    --resume work/FlowNetOurs_model_best.pth.tar
