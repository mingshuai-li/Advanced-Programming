/********************************************************************************* 
 
  * FileName:       filtering.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The header file for the filtering algorithms
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include <iostream>
#include <opencv2/core/core.hpp>


#define PI 3.141592654
#define NATURAL_CONSTANT 2.7182818284


/*
* Performs the convolution utilizing the input image and the kernel
* @ Parameter:
*       input_image:    The input image reference
*       kernel:         The kernel
* @ Return:
*                       The output image
*/
cv::Mat Convolve(const cv::Mat& input_image, const cv::Mat& kernel);


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


