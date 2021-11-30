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


