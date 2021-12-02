/********************************************************************************* 
 
  * FileName:       main.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The main file
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "image_io.hpp"
#include "image_type_conversion.hpp"
#include "image_enhancement.hpp"
#include "geometric_transform.hpp"
#include "filtering.hpp"


int main(int argc, char** argv)
{

    cv::Mat input_image = cv::imread("01.jpg");
    cv::Mat output_image = ConvertRGB2GrayScale(input_image);
    input_image = output_image;
  
    int choice = 0;
    double para1 = 0.0;
    double para2 = 0.0;
    int kernel_height = 0;
    int kernel_width = 0;

    std::cout << "Welcome to use this image processing system(Version 1.00)!\n";
    std::cout << "Which kind of operations would you like to perform?\n";
    std::cout << "1.Image Enhancement\n2.Image Geometric Transform\n3.Filtering\n";;
    std::cin >> choice;
    return 0;

}


