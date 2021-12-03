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


void TestBrightnessTransform()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = BrightnessTransform(input_image, 30);
    DisplayImage(output_image, "New York!");
}


void TestInverseTransform()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = InverseTransform(input_image);
    DisplayImage(output_image, "New York!");
}


void TestGammaTransform()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = GammaTransform(input_image, 1, 0.4);
    DisplayImage(output_image, "New York!");
}


void TestLogTransform()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = LogTransform(input_image, 1.2);
    DisplayImage(output_image, "New York!");
}


void TestNormalizationTransform()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = NormalizationTransform(input_image, 100, 150);
    DisplayImage(output_image, "New York!");
}


void TestThresholdTransform()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = ThresholdTransform(input_image, 100);
    DisplayImage(output_image, "New York!");
}


void TestWindowTransform()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = WindowTransform(input_image, 100, 150);
    DisplayImage(output_image, "New York!");
}


void TestResize()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = Resize(input_image, 500, 500);
    DisplayImage(output_image, "New York!");
}


void TestRotate()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = Rotate(input_image, 45);
    DisplayImage(output_image, "New York!");
}


void TestFlipLeftRight()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = FlipLeftRight(input_image);
    DisplayImage(output_image, "New York!");
}


void TestFlipUpDown()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = FlipUpDown(input_image);
    DisplayImage(output_image, "New York!");
}


void TestConvolve()
{
    cv::Mat kernel = cv::Mat::ones(3, 3, CV_64FC1);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            kernel.at<double>(i, j) /= 9;
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = Convolve(grayscale_input_image, kernel);
    DisplayImage(output_image, "New York!");
}


void TestLowPassFilter()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = LowPassFilter(grayscale_input_image, 3, 3);
    DisplayImage(output_image, "New York!");
}


void TestHighPassFilter()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = HighPassFilter(grayscale_input_image);
    DisplayImage(output_image, "New York!");
}


void TestBandPassFilter()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = BandPassFilter(grayscale_input_image, 10, 2);
    DisplayImage(output_image, "New York!");
}


void TestGaussianFilter()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = GaussianFilter(grayscale_input_image, 3, 3, 1.0);
    DisplayImage(output_image, "New York!");
}


void LaplacianFilter()
{
    cv::Mat input_image = ReadImage("NewYork.jpg");
    cv::Mat grayscale_input_image = ConvertRGB2GrayScale(input_image);
    cv::Mat output_image = LaplacianFilter(grayscale_input_image);
    DisplayImage(output_image, "New York!");
}


