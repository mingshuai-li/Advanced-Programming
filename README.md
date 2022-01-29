# Project: Image Procesing System
# Group: CS
# Contributors: Zichen Zhang, Mingshuai Li

## Motivation
---
Generally image processing is a very comprehensive area and it is also suitable to use C++ to write image processing algorithms. In this project, we implement various operations on images, especially image enhancement, geometric transform and filtering.

### Sprint 1 (Basics)
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

- The project contains `README.md` file explaining the project.
- Users can choose which operation to perform on images.
- Users should be able to control the size of some of the filters.
- The operations should be correct.



### Sprint 2 (OOP)
----

Organize the functions into classes according to the types of the operations.

Utilize smart pointers instead of raw pointers.


**Sprint 2: Definition of "done"**

The version will be considered as "complete" if 

- All the functions are organized into classes. 
- The class architecture should be reasonable.
- Utilize smart pointers instead of raw pointers.
- The operations should be correct.



### Sprint 3 (Refactoring and Refining)
----

Refactor the class architecture according to the review in Sprint 2.

Seperate the files into different folders.

Refine some code such as the implementation Convole().

Refine test functions.

Add CMake.


**Sprint 3: Definition of "done"**

The version will be considered as "complete" if 

- The class architecture are refactored according to the review in Sprint2.
- The files are seperated into different folders.
- Code including test functions are refined.
- CMake is added.

### TO DO LIST
1.CMake


2.Unit tests aren't really tests if they're not testing anything automatically. Ideally, you should have reference output images for each process you want to test (e.g. generated with python or imagej or some other established general purpose tool). Then, instead of displaying the resulting image, you should compare the reference output and yout output (with some accuracy, esp if using floats) and return a value (e.g. bool) telling whether your operation worked as expected or not. You could then also use a testing framework, but I guess here that's unnecessary, as long as you report which tests have passed and which - failed.


3.Having multiple classes in the same source file is not good style. Consider a folder of separate source and header files for each class (so like a folder tests with file inside TestGeometric.cpp TestGeometric.hpp TestFiltering.cpp TestGeometric.hpp


4.The namespace matter


5.Convolve

