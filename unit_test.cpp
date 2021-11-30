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
    cv::Mat image = ReadImage("NewYork.jpg");
    DisplayImage(image, "New York!");
    PrintImageInfo(image);
}


void TestConvertRGB2GrayScale()
{
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


