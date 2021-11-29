/********************************************************************************* 
 
  * FileName:       image_io.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The implementation for the image-io-related functions 
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "image_io.hpp"


cv::Mat ReadImage(const std::string& file_name)
{
    return cv::imread(file_name);
}


void DisplayImage(const cv::Mat& image, const std::string& image_title)
{
    cv::imshow(image_title, image);
    cv::waitKey(0);
}


void PrintImageInfo(const cv::Mat& image)
{
    std::cout << "The height of the image is: " << image.rows << '\n';
    std::cout << "The width of the image is: " << image.cols << '\n';
    std::cout << "The number of the channels of the image is " << image.channels() << '\n';
}


