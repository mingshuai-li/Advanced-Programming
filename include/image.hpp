/********************************************************************************* 
 
  * FileName:       image.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.1.29
  * Description:    The header file for the class Image
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#ifndef IMAGE_H
#define IMAGE_H


#include <iostream>
#include <opencv2/core/core.hpp>


class Image
{
    private:
        cv::Mat input_image_;
        static const double PI_;
        static const double NATURAL_CONSTANT_;

        /*
        * Reads the image and returns the corresponding data structure
        * @ Parameter:
        *       file_name: The file path of the image
        * @ Return:
        *                  The image that is read in
        */
        cv::Mat ReadImage(const std::string& file_name);

        /*
        * Performs the convolution utilizing the input image and the kernel
        * @ Parameter:
        *       input_image:    The input image reference
        *       kernel:         The kernel
        * @ Return:
        *                       The output image
        */
        cv::Mat Convolve(const cv::Mat& input_image, const cv::Mat& kernel);
    
    public:
        /*
        * The constructor
        * @ Parameter:
        *       file_name:      The file name of the input image
        */
        Image(const std::string& file_name);

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
        *       image:       The image reference
        *       image_title: The title of the image
        */
        void DisplayImage(const cv::Mat& image, const std::string& image_title);

        /*
        * Prints the basic information of the image
        * @ Parameter:
        *       image:     The image reference
        */
        void PrintImageInfo(const cv::Mat& image);

        /*
        * Resizes the image to the given scale
        * @ Parameter:
        *       input_image:    The input image reference
        *       height_scaling: The scaling factor alongside the height of the output image
        *       width_scaling:  The scaling factor alongside the width of the output image
        *       output_image:   The output image reference
        */
        cv::Mat Resize(const cv::Mat& input_image, double height_scaling, double width_scaling);


        /*
        * Rotates the image
        * @ Parameter:
        *       input_image:    The input image reference
        *       angle:          The angle that the input image rotates
        *       output_image:   The output image reference
        */
        cv::Mat Rotate(const cv::Mat& input_image, double angle);


        /*
        * Flips the image left to right
        * @ Parameter:
        *       input_image:    The input image reference
        *       output_image:   The output image reference
        */
        cv::Mat FlipLeftRight(const cv::Mat& input_image);


        /*
        * Flips the image up to down
        * @ Parameter:
        *       input_image:    The input image reference
        *       output_image:   The output image reference
        */
        cv::Mat FlipUpDown(const cv::Mat& input_image);

        /*
        * Changes each pixel's values by a constant value
        * @ Parameter:
        *       input_image:    The input image reference
        *       delta:          The shift to each pixel's values
        * @ Return:
        *                       The output image
        */
        cv::Mat BrightnessTransform(const cv::Mat& input_image, double delta);

        /*
        * Inverses the image
        * @ Parameter:
        *       input_image:    The input image reference
        * @ Return:
        *                       The output image
        */
        cv::Mat InverseTransform(const cv::Mat& input_image);

        /*
        * Applies the gamma transform to the image, the formula is as follows.
        * output_image = a * input_image^alpha
        * @ Parameter:
        *       input_image:    The input image reference
        *       coefficient_a:  The coefficient a
        *       exponent_alpha: The exponent alpha
        * @ Return:
        *                      The output image
        */
        cv::Mat GammaTransform(const cv::Mat& input_image, double coefficient_a, double exponent_alpha);

        /*
        * Applies the log transform to the image, the formula is as follows.
        * output_image = a * log(1 + input_image)
        * @ Parameter:
        *       input_image:    The input image reference
        *       coefficient_a:  The coefficient a
        * @ Return:
        *                       The output image
        */
        cv::Mat LogTransform(const cv::Mat& input_image, double coefficient_a);

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
        *       input_image:      The input image reference
        *       lower_threshold:  The lower threshold
        *       upper_threshold:  The upper threshold
        * @ Return:
        *                         The output image
        */
        cv::Mat NormalizationTransform(const cv::Mat& input_image, double lower_threshold, double upper_threshold);

        /*
        * Applies the threshold transform to the image, the formula is as follows.
        * If the pixel's intensities < a:
        *     The corresponding pixel's intensities of the output image = 0
        * Else:
        *     The corresponding pixel's intensities of the output image = pixel's intensities
        * @ Parameter:
        *       input_image:    The input image reference
        *       threshold:      The threshold
        * @ Return:
        *                       The output image
        */
        cv::Mat ThresholdTransform(const cv::Mat& input_image, double threshold);

        /*
        * Applies the window transform to the image, the formula is as follows.
        * If the pixel's intensities < a:
        *     The corresponding pixel's intensities of the output image = 0
        * If the pixel's intensities is between a and b:
        *     The corresponding pixel's intensities of the output image = pixel's intensities
        * If the pixel's intensities > b:
        *     The corresponding pixel's intensities of the output image = 0
        * @ Parameter:
        *       input_image:      The input image reference
        *       lower_threshold:  The lower threshold
        *       upper_threshold:  The upper threshold
        * @ Return:
        *                      The output image
        */
        cv::Mat WindowTransform(const cv::Mat& input_image, double lower_threshold, double upper_threshold);

        /*
        * Performs the low-pass filtering on the input image
        * @ Parameter:
        *       input_image:    The input image reference
        *       kernel_height:  The height of the kernel
        *       kernel_width:   The width of the kernel
        * @ Return:
        *                       The output image
        */
        cv::Mat LowPassFilter(const cv::Mat& input_image, int kernel_height, int kernel_width);


        /*
        * Performs the high-pass filtering on the input image
        * @ Parameter:
        *       input_image:    The input image reference
        * @ Return:
        *                       The output image
        */
        cv::Mat HighPassFilter(const cv::Mat& input_image);


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
        *       input_image:    The input image reference
        *       central_frea:   The central frequency
        *       band_width:     The bandwidth
        * @ Return:
        *                       The output image
        */
        cv::Mat BandPassFilter(const cv::Mat& input_image, double central_freq, double band_width);


        /*
        * Performs the Gaussian filtering on the input image
        * @ Parameter:
        *       input_image:    The input image reference
        *       kernel_height:  The height of the kernel
        *       kernel_width:   The width of the kernel
        *       kernel_sigma:   The standard deviation of the Gaussian filter
        * @ Return:
        *                       The output image
        */
        cv::Mat GaussianFilter(const cv::Mat& input_image, int kernel_hieght, int kernel_width, double kernel_sigma);


        /*
        * Performs the Laplacian filtering on the input image
        * @ Parameter:
        *       input_image:    The input image reference
        *       kernel_height:  The height of the kernel
        *       kernel_width:   The width of the kernel
        * @ Return:
        *                       The output image
        */
        cv::Mat LaplacianFilter(const cv::Mat& input_image);

}








#endif









