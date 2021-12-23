/********************************************************************************* 
 
  * FileName:       image_type_conversion.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The implementation for some functions related to image-type conversion
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "image_type_conversion.hpp"


cv::Mat ConvertRGB2GrayScale(const cv::Mat& input_image)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;

    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    // The weights utilized to map the RGB channels to the grayscale channel
    double weights[3] = {0.0722, 0.7152, 0.2126};
    double weighted_sum = 0.0;

    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            const cv::Vec3b& channel = input_image.at<cv::Vec3b>(i, j);
            weighted_sum = 0.0;

            // Computes the grayscale channel value
            for (int k = 0; k < 3; k++)
                weighted_sum += channel[k] * weights[k];

            output_image.at<uchar>(i, j) = static_cast<uchar>(weighted_sum);
        }
    }

    return output_image;
  
}


cv::Mat ConvertUchar2DoubleC1(const cv::Mat& input_image)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;

    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_64FC1);

    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            output_image.at<double>(i, j) = static_cast<double>(input_image.at<uchar>(i, j));
    
    return output_image;

}


uchar MapDouble2Uchar(double n)
{
    return (n > 255.0) ? static_cast<uchar>(255) : ((n < 0.0) ? static_cast<uchar>(0) : static_cast<uchar>(n));
}


