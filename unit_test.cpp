/********************************************************************************* 
 
  * FileName:       unit_test.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The implementation for the various unit test classes
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "unit_test.hpp"


UnitTestIoAndTypeConversion::UnitTestIoAndTypeConversion(const std::string& file_name)
{

    image_io_ = std::make_unique<ImageIO>();

    input_image_ = image_io_->ReadImage(file_name);
    output_image_ = cv::Mat::zeros(input_image_.rows, input_image_.cols, CV_8UC1);

}


UnitTestIoAndTypeConversion::~UnitTestIoAndTypeConversion()
{
}


void UnitTestIoAndTypeConversion::TestImageIO()
{

    image_io_->DisplayImage(input_image_, "The Current Input Image");
    image_io_->PrintImageInfo(input_image_);

}


void UnitTestIoAndTypeConversion::TestConvertRGB2GrayScale()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestIoAndTypeConversion::TestConvertUchar2DoubleC1()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    image_io_->PrintImageInfo(output_image_);
    output_image_ = ImageTypeConversion::ConvertUchar2DoubleC1(output_image_);
    image_io_->PrintImageInfo(output_image_);

}


void UnitTestIoAndTypeConversion::TestMapDouble2Uchar()
{

    double n1 = 256.0;
    double n2 = 253.0;
    double n3 = -3.0;
    uchar mapped_n1 = ImageTypeConversion::MapDouble2Uchar(n1);
    uchar mapped_n2 = ImageTypeConversion::MapDouble2Uchar(n2);
    uchar mapped_n3 = ImageTypeConversion::MapDouble2Uchar(n3);
    std::cout << n1 << "   " << n2 << "   " << n3 << '\n';
    std::cout << mapped_n1 << "   " << mapped_n2 << "   " << mapped_n3 << '\n';

}


UnitTestImageEnhancement::UnitTestImageEnhancement(const std::string& file_name)
{

    image_io_ = std::make_unique<ImageIO>();
    
    input_image_ = image_io_->ReadImage(file_name);
    
    output_image_ = cv::Mat::zeros(input_image_.rows, input_image_.cols, CV_8UC1);

    image_enhancement_  = std::make_unique<ImageEnhancement>();

}


UnitTestImageEnhancement::~UnitTestImageEnhancement()
{
}


void UnitTestImageEnhancement::TestBrightnessTransform()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = image_enhancement_->BrightnessTransform(output_image_, 30);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestImageEnhancement::TestInverseTransform()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = image_enhancement_->InverseTransform(output_image_);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestImageEnhancement::TestGammaTransform()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = image_enhancement_->GammaTransform(output_image_, 1, 0.4);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestImageEnhancement::TestLogTransform()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = image_enhancement_->LogTransform(output_image_, 1.2);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestImageEnhancement::TestNormalizationTransform()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = image_enhancement_->NormalizationTransform(output_image_, 100, 150);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestImageEnhancement::TestThresholdTransform()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = image_enhancement_->ThresholdTransform(output_image_, 100);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestImageEnhancement::TestWindowTransform()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = image_enhancement_->WindowTransform(output_image_, 100, 150);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


UnitTestGeometricTransform::UnitTestGeometricTransform(const std::string& file_name)
{

    image_io_ = std::make_unique<ImageIO>();
    
    input_image_ = image_io_->ReadImage(file_name);
    
    output_image_ = cv::Mat::zeros(input_image_.rows, input_image_.cols, CV_8UC1);

    geometric_transform_ = std::make_unique<GeometricTransform>();

}


UnitTestGeometricTransform::~UnitTestGeometricTransform()
{
}


void UnitTestGeometricTransform::TestResize()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = geometric_transform_->Resize(output_image_, 0.5, 0.5);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestGeometricTransform::TestRotate()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = geometric_transform_->Rotate(output_image_, 45);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestGeometricTransform::TestFlipLeftRight()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = geometric_transform_->FlipLeftRight(output_image_);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestGeometricTransform::TestFlipUpDown()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = geometric_transform_->FlipUpDown(output_image_);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


UnitTestFiltering::UnitTestFiltering(const std::string& file_name)
{

    image_io_ = std::make_unique<ImageIO>();
    
    input_image_ = image_io_->ReadImage(file_name);
    
    output_image_ = cv::Mat::zeros(input_image_.rows, input_image_.cols, CV_8UC1);

    filtering_ = std::make_unique<Filtering>();

}


UnitTestFiltering::~UnitTestFiltering()
{
}


void UnitTestFiltering::TestConvolve()
{

    cv::Mat kernel = cv::Mat::ones(3, 3, CV_64FC1);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            kernel.at<double>(i, j) /= 9;

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = filtering_->Convolve(output_image_, kernel);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestFiltering::TestLowPassFilter()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = filtering_->LowPassFilter(output_image_, 3, 3);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestFiltering::TestHighPassFilter()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = filtering_->HighPassFilter(output_image_);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestFiltering::TestBandPassFilter()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = filtering_->BandPassFilter(output_image_, 10, 2);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestFiltering::TestGaussianFilter()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = filtering_->GaussianFilter(output_image_, 3, 3, 1.0);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


void UnitTestFiltering::TestLaplacianFilter()
{

    output_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = filtering_->LaplacianFilter(output_image_);
    image_io_->DisplayImage(output_image_, "The Current Output Image");

}


