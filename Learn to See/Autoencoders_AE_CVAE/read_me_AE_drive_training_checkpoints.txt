HOW TO RETRIEVE DATA:
in the drive: https://drive.google.com/drive/folders/19M08ITTCRv6AHOMG6eogdmJWtK5i4vYy?usp=sharing
if there are problems with the shared drive, you can take:
        - the tfrecord data datsets from the folder specified below
        - the model checkpoint can be retrieve from the Docker branch of this repo (or in the docker folder if you downloaded) in /Projects/Learn To See (both for the sim and real images and for the gan and autoencoders)
        So you can put this in your desired drive and properly load them in the scripts
        
CODE:
-AE code: Colab_Notebooks/v9_final/ae_burr_to_contour.ipynb (THE ONE USED IN THE END)
-CVAE code: Colab_Notebooks/v9_final/cvae_burr_to_contour.ipynb (just if you wnat to see another implentation)


tfrecord data DATASET (used then for trining in pix2pix code): in folder Learn To See/datasets

AE TRAIN SETTINGS:
checkpoints data: Colab_Notebooks/v8_extra/checkpoints_cae/ckpt_cae_flatten' 
script: ae_burr_to_contour.ipynb
20500 dataset from 20000 processed cgan sim images and 500 processed real images . 
latent =300, 6 epochs on the dataset. [img resolution 240x320]

CVAE TRAIN SETTINGS:
checkpoints data: Colab_Notebooks/v8_extra/checkpoints_cvae/ckpt_cvae_latent50_diff_net12' 
script: cvae_burr_to_contour.ipynb
20500 dataset from 20000 processed cgan sim images and 500 processed real images . 
latent=50, 6 epochs on the dataset. [img resolution 240x320]
