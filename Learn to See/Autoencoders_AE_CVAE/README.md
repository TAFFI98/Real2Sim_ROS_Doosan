## HOW TO RETRIEVE DATA:
In the drive: https://drive.google.com/drive/folders/19M08ITTCRv6AHOMG6eogdmJWtK5i4vYy?usp=sharing
- if there are problems with the shared drive, you can download:
        - the tfrecord data datasets from the latest Github release of this project
        - the model checkpoints can be retrieve from the Docker branch of this repo in /Projects/Learn To See (both for the sim and real images and for the gan and autoencoders)
        - Put this in your desired drive and properly load them in the scripts
        
### CODE:
- AE code: Colab_Notebooks/v9_final/ae_burr_to_contour.ipynb (THE ONE USED)
- CVAE code: Colab_Notebooks/v9_final/cvae_burr_to_contour.ipynb (just if you want to see another implentation)


### tfrecord data DATASET (used then for training in pix2pix code): in folder Learn To See/datasets

### AE TRAIN SETTINGS:
- checkpoints data: Colab_Notebooks/v8_extra/checkpoints_cae/ckpt_cae_flatten' 
- script: ae_burr_to_contour.ipynb
- 20500 dataset from 20000 processed cgan sim images and 500 processed real images . 
- latent =300, 6 epochs on the dataset. [img resolution 240x320]

### CVAE TRAIN SETTINGS:
- checkpoints data: Colab_Notebooks/v8_extra/checkpoints_cvae/ckpt_cvae_latent50_diff_net12' 
- script: cvae_burr_to_contour.ipynb
- 20500 dataset from 20000 processed cgan sim images and 500 processed real images . 
- latent=50, 6 epochs on the dataset. [img resolution 240x320]
