HOW TO RETRIEVE DATA:
in the drive: https://drive.google.com/drive/folders/19M08ITTCRv6AHOMG6eogdmJWtK5i4vYy?usp=sharing
if there are problems with the shared drive, you can take:
        - the tfrecord data datsets from the folder specified below
        - the model checkpoint can be retrieve from the Docker branch of this repo (or in the docker folder if you downloaded) in /Projects/Learn To See (both for the sim and real images and for the gan and autoencoders)
        So you can put this in your desired drive and properly load them in the scripts
        
CODE:
- dataset processing code: Colab_Notebooks/v8_extra/dataset_processing_and_storage.ipynb
-GAN code: Colab_Notebooks/v9_final/pix2pix_sole_to_burr.ipynb

image DATASETS (to create processed tf datasets):
-sim_dataset: Colab_Notebooks/20k_dataset_v8.tar
-real_dataset: Colab_Notebooks/500_dataset_real_v8.tar

tfrecord data DATASET (used then for trining in pix2pix code): in folder Learn To See/datasets

TRAIN SETTINGS:
-sim train settings: dataset=sim_dataset, gamma=0.5, lambda=500, resol=512x512, total=120k epochs (steps=20000)
-real few-shots train settings: dataset=real_dataset, start from pre-trained network=sim trained_checkpoins,  gamma=0.5, lambda=500, resol=512x512, total=4k epochs (steps=500)
-real direct train setting: dataset=real_dataset, gamma=0.5, lambda=500, resol=512x512, total=40k epochs (steps=500)

TRAINED NETWORKS CHECKPOINTS
-sim trained checkpoints: Colab_Notebooks/v8/checkpoints_gan_20k/512x512_gamma0.5_lambda500_120k_it_best_on_sim
-real few-shots checkpoints: Colab_Notebooks/v8/checkpoints_gan_20k/phase2-real_500real_ds-4000epochs_steps500
-real direct trained checkpoints: Colab_Notebooks/v8/just_real_gan_ep40000_step500
