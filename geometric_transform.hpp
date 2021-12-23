/********************************************************************************* 
 
  * FileName:       geometric_transform.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The header file for the geometric transform algorithms
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include <iostream>
#include <opencv2/core/core.hpp>


#define PI 3.141592654


/*
* Resizes the image to the given scale
* @ Parameter:
*       input_image:    The input image reference
*       height_scaling: The scaling factor alongside the height of the output image
*       width_scaling:  The scaling factor alongside the width of the output image
*       output_image:   The output image reference
*/
cv::Mat Resize(const cv::Mat& input_image, const double& height_scaling, const double& width_scaling);


/*
* Rotates the image
* @ Parameter:
*       input_image:    The input image reference
*       angle:          The angle that the input image rotates
*       output_image:   The output image reference
*/
cv::Mat Rotate(const cv::Mat& input_image, const double& angle);


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


