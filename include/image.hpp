/********************************************************************************* 
 
  * FileName:       image.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.2.1
  * Description:    The header file for the class Image
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#ifndef IMAGE_H
#define IMAGE_H


#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>


class Image
{
    private:
        cv::Mat input_image_;
        static const double PI_;
        static const double NATURAL_CONSTANT_;
        friend class UnitTest;

        /*
        * Reads the image and returns the corresponding data structure
        * @ Parameter:
        *       file_name: The file path of the image
        * @ Return:
        *                  The image that is read in
        */
        cv::Mat ReadImage(const std::string& file_name);

        /*
        * Converts the RGB image to the gray scale image
        * @ Parameter:
        *       input_image:    The input image reference
        * @ Return:
        *                       The output image
        */
        cv::Mat ConvertRGB2GrayScale(const cv::Mat& input_image);


        /*
        * Converts the image type from uchar channel 1 to double channel1 
        * @ Parameter:
        *       input_image:    The input image reference
        * @ Return:
        *                       The output image
        */
        cv::Mat ConvertUchar2DoubleC1(const cv::Mat& input_image) const;


        /*
        * Maps the double n to the value range of uchar according to the following rules:
        * If n > 255.0:
        *     maps n to uchar 255
        * Else if n < 0.0:
        *     maps n to uchar 0
        * Else
        *     maps to static_cast<uchar>(n)
        * @ Parameter:
        *       n:              The input double value
        * @ Return:
        *                       The output value
        */
        uchar MapDouble2Uchar(double n) const;

        /*
        * Performs the convolution utilizing the input image and the kernel
        * @ Parameter:
        *       input_image:    The input image reference
        *       kernel:         The kernel
        * @ Return:
        *                       The output image
        */
        cv::Mat Convolve(const cv::Mat& input_image, const cv::Mat& kernel) const;

        /*
        * Performs the refined convolution utilizing the input image and the kernel
        * @ Parameter:
        *       input_image:    The input image reference
        *       kernel:         The kernel
        * @ Return:
        *                       The output image
        */
        cv::Mat RefinedConvolve(const cv::Mat& input_image, const cv::Mat& kernel) const;
    
    public:
        /*
        * The constructor
        * @ Parameter:
        *       file_name:      The file name of the input image
        */
        Image(const std::string& file_name);

        /*
        * The constructor
        * @ Parameter:
        *       image:          The input image reference
        */
        Image(const cv::Mat& image);

        /*
        * The copy constructor
        * @ Parameter:
        *       image:          The image object that is going to be copied
        */
        Image(const Image& image);

        /*
        * The destructor
        */
        ~Image();

        /*
        * Displays the image
        * @ Parameter:
        *       image_title: The title of the image
        */
        void DisplayImage(const std::string& image_title) const;

        /*
        * Displays the image
        * @ Parameter:
        *       image:       The image reference
        *       image_title: The title of the image
        */
        void DisplayImage(const cv::Mat& image, const std::string& image_title) const;

        /*
        * Prints the basic information of the image
        */
        void PrintImageInfo() const;

        /*
        * Gets the height of the image
        * @ Return:
        *                  The height of the image
        */
        int GetImageHeight() const;

        /*
        * Gets the width of the image
        * @ Return:
        *                  The width of the image
        */
        int GetImageWidth() const;

        /*
        * Gets a copy of the image
        * @ Return:
        *                  The copy of the image
        */
        cv::Mat GetImage() const;

        /*
        * Saves the image as a file
        * @ Parameter:
        *       file_path: The path of the image file
        */
        void SaveImage(const std::string& file_path) const;

        /*
        * Sets a new image
        * @ Parameter:
        *       file_name:      The file name of the input image
        *     
        */
        void SetNewImage(const std::string& file_name);

        /*
        * Sets a new image
        * @ Parameter:
        *       new_image:      The new image
        *     
        */
        void SetNewImage(const cv::Mat& new_image);

        /*
        * Resizes the image to the given scale
        * @ Parameter:
        *       height_scaling: The scaling factor alongside the height of the output image
        *       width_scaling:  The scaling factor alongside the width of the output image
        * @ Return:
        *                       The resized image
        */
        cv::Mat Resize(double height_scaling, double width_scaling) const;

        /*
        * Rotates the image
        * @ Parameter:
        *       angle:          The angle that the input image rotates
        * @ Return:
        *                       The rotated image
        */
        cv::Mat Rotate(double angle) const;

        /*
        * Flips the image left to right
        * @ Return:
        *                       The left-right flipped image
        */
        cv::Mat FlipLeftRight() const;

        /*
        * Flips the image up to down
        * @ Return:
        *                       The up-down flipped image
        */
        cv::Mat FlipUpDown() const;

        /*
        * Changes each pixel's values by a constant value
        * @ Parameter:
        *       delta:          The shift to each pixel's values
        * @ Return:
        *                       The output image
        */
        cv::Mat BrightnessTransform(double delta) const;

        /*
        * Inverses the image
        * @ Return:
        *                       The output image
        */
        cv::Mat InverseTransform() const;

        /*
        * Applies the gamma transform to the image, the formula is as follows.
        * output_image = a * input_image^alpha
        * @ Parameter:
        *       coefficient_a:  The coefficient a
        *       exponent_alpha: The exponent alpha
        * @ Return:
        *                      The output image
        */
        cv::Mat GammaTransform(double coefficient_a, double exponent_alpha) const;

        /*
        * Applies the log transform to the image, the formula is as follows.
        * output_image = a * log(1 + input_image)
        * @ Parameter:
        *       coefficient_a:  The coefficient a
        * @ Return:
        *                       The output image
        */
        cv::Mat LogTransform(double coefficient_a) const;

        /*
        * Applies the normalization transform to the image, the formula is as follows.
        * If the pixel's intensities < a:
        *     The corresponding pixel's intensities of the output image = 0
        * If the pixel's intensities is between a and b:
        *     The corresponding pixel's intensities of the output image = k * pixel's intensities + b0,
        *     where k = 255 / (b - a), b0 = 255 * a / (a - b)
        * If the pixel's intensities > b:
        *     The corresponding pixel's intensities of the output image = 255
        * @ Parameter:
        *       lower_threshold:  The lower threshold
        *       upper_threshold:  The upper threshold
        * @ Return:
        *                         The output image
        */
        cv::Mat NormalizationTransform(double lower_threshold, double upper_threshold) const;

        /*
        * Applies the threshold transform to the image, the formula is as follows.
        * If the pixel's intensities < a:
        *     The corresponding pixel's intensities of the output image = 0
        * Else:
        *     The corresponding pixel's intensities of the output image = pixel's intensities
        * @ Parameter:
        *       threshold:      The threshold
        * @ Return:
        *                       The output image
        */
        cv::Mat ThresholdTransform(double threshold) const;

        /*
        * Applies the window transform to the image, the formula is as follows.
        * If the pixel's intensities < a:
        *     The corresponding pixel's intensities of the output image = 0
        * If the pixel's intensities is between a and b:
        *     The corresponding pixel's intensities of the output image = pixel's intensities
        * If the pixel's intensities > b:
        *     The corresponding pixel's intensities of the output image = 0
        * @ Parameter:
        *       lower_threshold:  The lower threshold
        *       upper_threshold:  The upper threshold
        * @ Return:
        *                      The output image
        */
        cv::Mat WindowTransform(double lower_threshold, double upper_threshold) const;

        /*
        * Performs the low-pass filtering on the input image
        * @ Parameter:
        *       kernel_height:  The height of the kernel
        *       kernel_width:   The width of the kernel
        * @ Return:
        *                       The output image
        */
        cv::Mat LowPassFilter(int kernel_height, int kernel_width) const;


        /*
        * Performs the high-pass filtering on the input image
        * @ Return:
        *                       The output image
        */
        cv::Mat HighPassFilter() const;


        /*
        * Performs the band-pass filtering on the input image, the criteria is as follows:
        * In the frequency domain, filter using the following criteria:
        * If the frequency < central frequency - bandwidth / 2:
        *                       frequency = frequency * 1
        * If the frequency >= central frequency - bandwidth / 2 and the frequency <= central frequency + bandwidth / 2:
        *                       frequency = frequency * 0
        * If the frequency > central frequency + bandwidth / 2:
        *                       frequency = frequency * 1
        * @ Parameter:
        *       central_frea:   The central frequency
        *       band_width:     The bandwidth
        * @ Return:
        *                       The output image
        */
        cv::Mat BandPassFilter(double central_freq, double band_width) const;

        /*
        * Performs the Gaussian filtering on the input image
        * @ Parameter:
        *       kernel_height:  The height of the kernel
        *       kernel_width:   The width of the kernel
        *       kernel_sigma:   The standard deviation of the Gaussian filter
        * @ Return:
        *                       The output image
        */
        cv::Mat GaussianFilter(int kernel_hieght, int kernel_width, double kernel_sigma) const;

        /*
        * Performs the Laplacian filtering on the input image
        * @ Return:
        *                       The output image
        */
        cv::Mat LaplacianFilter() const;

};


#endif


