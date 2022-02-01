# Project: Image Procesing System
# Group: CS
# Contributors: Zichen Zhang, Mingshuai Li

## Motivation
---
Generally image processing is a very comprehensive area and it is also suitable to use C++ to write image processing algorithms. In this project, we implement various operations on images, especially image enhancement, geometric transform and filtering.

### Sprint 1 (Basics)
----

- Input an image using a library such as [OpenCV](https://opencv.org/) or [stb_image](https://github.com/nothings/stb) and implement various operations on images.

Basic types of operations on images: 
- Image Enhancement: brightness transform, inverse transform, gamma transform, log transform, normalization transform, threshold transform, window transform
- Geometric Transform: resizing, rotation, flipping left right, flipping up down
- Filtering: low pass filtering, high pass filtering, band pass filtering, Gaussian Filtering, Laplacian Filtering

Don't use classes. Functions are sufficient.


**Sprint 1: Definition of "done"**

The version will be considered as "complete" if 

- The project contains `README.md` file explaining the project.
- Users can choose which operation to perform on images.
- Users should be able to control the size of some of the filters.
- The operations should be correct.



### Sprint 2 (OOP)
----

- Organize the functions into classes according to the types of the operations.
- Utilize smart pointers instead of raw pointers.


**Sprint 2: Definition of "done"**

The version will be considered as "complete" if 

- All the functions are organized into classes. 
- The class architecture should be reasonable.
- Utilize smart pointers instead of raw pointers.
- The operations should be correct.



### Sprint 3 (Refactoring and Refining)
----

- Refactor the class architecture according to the review in Sprint 2.
- Seperate the files into different folders.
- Refine some code such as the implementation Convole().
- Refine test functions.
- Add CMake.


**Sprint 3: Definition of "done"**

The version will be considered as "complete" if 

- The class architecture are refactored according to the review in Sprint2.
- The files are seperated into different folders.
- Code including test functions are refined.
- CMake is added.

## Optimization results
----

After the architecture is refactored, profile the code using gprof and the results of Geometric Transform are as follows:

Before refactored:
![Before refactored](/image/Geometric_Transform_before.png)
After refactored:
![Before refactored](/image/Geometric_Transform_after.png)
Running time consumption from 0.14 seconds to 0.12 seconds.

Then the convolve function is refined:

Before refined:
![Before refined](/image/convolve.jpg)

After refined:
![After refined](/image/refineconvolve.jpg)

When running all the filtering functions, the time consumption is from 1.51 seconds to 1.18 seconds.





