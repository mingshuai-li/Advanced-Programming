# Project: Image Procesing System
# Group: CS
# Contributors: Zichen Zhang, Mingshuai Li

## Motivation
---
Generally image processing is a very comprehensive area and it is also suitable to use C++ to write image processing algorithms. In this project, we implement various operations on images, especially image enhancement, geometric transform and filtering.

### Sprint 1 (basics)
----

Input an image using a library such as [OpenCV](https://opencv.org/) or [stb_image](https://github.com/nothings/stb) and implement various operations on images.

Basic types of operations on images: 
- Image Enhancement: brightness transform, inverse transform, gamma transform, log transform, normalization transform, threshold transform, window transform
- Geometric Transform: resizing, rotation, flipping left right, flipping up down
- Filtering: low pass filtering, high pass filtering, band pass filtering, Gaussian Filtering, Laplacian Filtering

Don't use classes. Functions are sufficient.


### When compiling the files, please remember to add "pkg-config --cflags --libs opencv"

### To install and setup OpenCV, you need a lot of dependencies as follows.
### "sudo apt install build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb2 libtbb-dev libdc1394-22-dev libopenexr-dev \
    libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev\
\
### If you still meet some specific problems, please look up solutions using Google


**Sprint 1: Definition of "done"**

The version will be considered as "complete" if 

- The project contains `README.md` file explaining the project
- Users can choose which operation to perform on images
- Users should be able to control the filter size
- The operations should be correct


