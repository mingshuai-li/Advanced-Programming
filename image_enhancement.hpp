/********************************************************************************* 
 
  * FileName:       image_enhancement.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The header file for the image enhancement algorithms
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include <iostream>
#include <opencv2/core/core.hpp>


/*
* Changes each pixel's values by a constant value
* @ Parameter:
*       input_image:    The input image reference
*       delta:          The shift to each pixel's values
* @ Return:
*                       The output image
*/
cv::Mat BrightnessTransform(const cv::Mat& input_image, const double& delta);


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
cv::Mat GammaTransform(const cv::Mat& input_image, const double& coefficient_a, const double& exponent_alpha);


/*
* Applies the log transform to the image, the formula is as follows.
* output_image = a * log(1 + input_image)
* @ Parameter:
*       input_image:    The input image reference
*       coefficient_a:  The coefficient a
* @ Return:
*                       The output image
*/
cv::Mat LogTransform(const cv::Mat& input_image, const double& coefficient_a);


/*
* Applies the normalization transform to the image, the formula is as follows.
* if the pixel's intensities < a:
*     the corresponding pixel's intensities of the output image = 0
* if the pixel's intensities is between a and b:
*     the corresponding pixel's intensities of the output image = k * pixel's intensities + b0,
*     where k = 255 / (b - a), b0 = 255 * a / (a - b)
* if the pixel's intensities > b:
*     the corresponding pixel's intensities of the output image = 255
* @ Parameter:
*       input_image:      The input image reference
*       lower_threshold:  The lower threshold
*       upper_threshold:  The upper threshold
* @ Return:
*                         The output image
*/
cv::Mat NormalizationTransform(const cv::Mat& input_image, const double& lower_threshold, const double& upper_threshold);


/*
* Applies the threshold transform to the image, the formula is as follows.
* if the pixel's intensities < a:
*     the corresponding pixel's intensities of the output image = 0
* else:
*     the corresponding pixel's intensities of the output image = pixel's intensities
* @ Parameter:
*       input_image:    The input image reference
*       threshold:      The threshold
* @ Return:
*                       The output image
*/
cv::Mat ThresholdTransform(const cv::Mat& input_image, const double& threshold);


/*
* Applies the window transform to the image, the formula is as follows.
* if the pixel's intensities < a:
*     the corresponding pixel's intensities of the output image = 0
* if the pixel's intensities is between a and b:
*     the corresponding pixel's intensities of the output image = pixel's intensities
* if the pixel's intensities > b:
*     the corresponding pixel's intensities of the output image = 0
* @ Parameter:
*       input_image:      The input image reference
*       lower_threshold:  The lower threshold
*       upper_threshold:  The upper threshold
* @ Return:
*                      The output image
*/
cv::Mat WindowTransform(const cv::Mat& input_image, const double& lower_threshold, const double& upper_threshold);

