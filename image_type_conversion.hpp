/********************************************************************************* 
 
  * FileName:       image_type_conversion.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The header file for some functions related to image-type conversion
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include <iostream>
#include <opencv2/core/core.hpp>


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
cv::Mat ConvertUchar2DoubleC1(const cv::Mat& input_image);


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
uchar MapDouble2Uchar(double n);
