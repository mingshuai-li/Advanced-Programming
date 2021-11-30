/********************************************************************************* 
 
  * FileName:       unit_test.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The implementation for the unit test functions
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "unit_test.hpp"


void TestImageIO()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    DisplayImage(input_image, "New York!");
    PrintImageInfo(input_image);
}


void TestConvertRGB2GrayScale()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat output_image = ConvertRGB2GrayScale(input_image);
    DisplayImage(output_image, "New York!");
}


void TestConvertUchar2DoubleC1()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    PrintImageInfo(input_image);
    cv::Mat output_image = ConvertUchar2DoubleC1(grayscale_input_image);
    PrintImageInfo(output_image);
}


void TestMapDouble2Uchar()
{
    double n1 = 256.0;
    double n2 = 253.0;
    double n3 = -3.0;
    uchar mapped_n1 = MapDouble2Uchar(n1);
    uchar mapped_n2 = MapDouble2Uchar(n2);
    uchar mapped_n3 = MapDouble2Uchar(n3);
    std::cout << n1 << "   " << n2 << "   " << n3 << '\n';
    std::cout << mapped_n1 << "   " << mapped_n2 << "   " << mapped_n3 << '\n';
}


void BrightnessTransform()
{
}


void InverseTransform()
{
}


void GammaTransform()
{
}


void LogTransform()
{
}


void NormalizationTransform()
{
}


void ThresholdTransform()
{
}


void WindowTransform()
{
}


void Resize()
{
}


void Rotate()
{
}


void FlipLeftRight()
{
}


void FlipUpDown()
{
}


