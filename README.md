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

- The project contains `README.md` file explaining the project.
- Users can choose which operation to perform on images.
- Users should be able to control the size of some of the filters.
- The operations should be correct.



### Sprint 2 (OOP)
----

Organize the functions into classes according to the types of the operations.

Utilize smart pointers instead of raw pointers.



Unit tests aren't really tests if they're not testing anything automatically. Ideally, you should have reference output images for each process you want to test (e.g. generated with python or imagej or some other established general purpose tool). Then, instead of displaying the resulting image, you should compare the reference output and yout output (with some accuracy, esp if using floats) and return a value (e.g. bool) telling whether your operation worked as expected or not. You could then also use a testing framework, but I guess here that's unnecessary, as long as you report which tests have passed and which - failed.


Having multiple classes in the same source file is not good style. Consider a folder of separate source and header files for each class (so like a folder tests with file inside TestGeometric.cpp TestGeometric.hpp TestFiltering.cpp TestGeometric.hpp




I think most of your classes don't need to be classes at all. Or they can be static classes. They are not encapsulating data, only containing functions.


A better approach could be, for example, to have a single Image class containing your raw image, processed image, and a vector of some sort noting operations that have been applied to the image. All image transformation functions would then be part of this class as well, put them in the header. All your constants will also only need to be defined in this one central place. It will be especially important to have include guards in thei header if you decide to try an approach like this.


Then you could keep your current source files and simply include that header in each, thus having a feature-rich Image container and processor, with functions separated among the source files for readability. You would then do something like





auto image = Image("some/path/image.png");
image.ApplySomeTransformation();
Like the other reviewer mentioned, having a better build system would be helpful. Especially when you have multiple executables (the main and the test).
That's it from me for now. I really like your project! I'll see later in the week if I can go through more of the code, but at first glance it seems the functions themselves are written well.



One more thing, your menus might be easier to read and edit if they were using switch and enums instead of ifs with numbers. So you would do something like enum GeometricTransformation(Resize,Rotate,FlipLeftRight,FlipUpDown);
Then, if you wanna get fancy, you could instead of the normal enums use better enums and then all your menus would boil down to a single function that prints the name of the enum, the numbers and names of its possible values and parses them accordingly.




Hi,first congrats for the detailed and different project.
I looked at your code and it seems very well designed and I couldn't really find something to add.
But I will try to give some different approaches that I would use if I had taken that project.
1- Using virtual functions and make image_processing_system abstract class is one idea for runtime polymorphism. That way filtering, image_enhancement and geometric_transform will be child classes of image_processing_system which make it better design in my opinion.
2- A development can be option to apply different transformations and display them side by side.
3- Also taking a file of images and apply some transforms and save them will be very useful in for data augmentation in computer vision. Since C++ is faster than python or Matlab it may be a goal for this project.
I will try to add more comments in the following days if I can find some!



























**Sprint 2: Definition of "done"**

The version will be considered as "complete" if 

- All the functions are organized into classes. 
- The class architecture should be reasonable.
- Utilize smart pointers instead of raw pointers.
- The operations should be correct. 


