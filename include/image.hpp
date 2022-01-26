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


class ImageIO
{

    public:
        /*
        * Reads the image and returns the corresponding data structure
        * @ Parameter:
        *       file_name: The file path of the image
        * @ Return:
        *                  The image that is read in
        */
        cv::Mat ReadImage(const std::string& file_name);


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

};


class ImageEnhancement
{

    public:
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

};


class GeometricTransform
{

    private:
        static const double PI_;

    public:
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

};










#endif









