
#    --training_dataset_root /mnt/proj45/lhj/Dataset/Sintel/data_ds2/even_odd_split/training \
#    --total_epochs 50 \
#    --replicates 100 \

#    --replicates 50 \

python3 main.py \
    --total_epochs 51 \
    --replicates 1 \
    --batch_size 32 \
    --validation_frequency 5 \
    --model FlowNetE \
    --loss=EPELoss \
    --optimizer=Adam \
    --optimizer_lr=1e-4 \
    --crop_size 192 256 \
    --training_dataset MpiSintelClean \
    --training_dataset_root data/training \
    --validation_dataset MpiSintelClean \
    --validation_dataset_root data/validation \
