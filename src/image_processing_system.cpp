/********************************************************************************* 
 
  * FileName:       image_processing_system.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The implementation for the class ImageProcessingSystem
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "image_processing_system.hpp"


void ImageProcessingSystem::RunImageEnhancement()
{

    int choice = menu_->ImageEnhancementMenu();

    double para1 = 0.0;
    double para2 = 0.0;

    if (choice == 1)
    {
        std::cout << "Please enter the change of the brightness: ";
        std::cin >> para1;
        output_image_ = image_enhancement_->BrightnessTransform(input_image_, para1);
    }
    else if (choice == 2)
        output_image_ = image_enhancement_->InverseTransform(input_image_);
    else if (choice == 3)
    {
        std::cout << "Please enter the coefficient and the exponent: ";
        std::cin >> para1 >> para2;
        output_image_ = image_enhancement_->GammaTransform(input_image_, para1, para2);
    }
    else if (choice == 4)
    {
        std::cout << "Please enter the coefficient: ";
        std::cin >> para1;
        output_image_ = image_enhancement_->LogTransform(input_image_, para1);
    }
    else if (choice == 5)
    {
        std::cout << "Please enter the lower threshold and the upper threshold: ";
        std::cin >> para1 >> para2;
        output_image_ = image_enhancement_->NormalizationTransform(input_image_, para1, para2);
    }
    else if (choice == 6)
    {
        std::cout << "Please enter the threshold: ";
        std::cin >> para1;
        output_image_ = image_enhancement_->ThresholdTransform(input_image_, para1);
    }
    else if (choice == 7)
    {
        std::cout << "Please enter the lower threshold and the upper threshold: ";
        std::cin >> para1 >> para2;
        output_image_ = image_enhancement_->WindowTransform(input_image_, para1, para2);
    }
    else
        std::cout << "ERROR:Wrong choice!\n";

}


void ImageProcessingSystem::RunGeometricTransform()
{

    int choice = menu_->GeometricTransformMenu();

    double para1 = 0.0;
    double para2 = 0.0;
  
    if (choice == 1)
    {
        std::cout << "Please enter the height scaling factor and the width scaling factor: ";
        std::cin >> para1 >> para2;
        output_image_ = geometric_transform_->Resize(input_image_, para1, para2);
    }
    else if (choice == 2)
    {
        std::cout << "Please enter the angle that the input image rotates: ";
        std::cin >> para1;
        output_image_ = geometric_transform_->Rotate(input_image_, para1);
    }
    else if (choice == 3)
        output_image_ = geometric_transform_->FlipLeftRight(input_image_);
    else if (choice == 4)
        output_image_ = geometric_transform_->FlipUpDown(input_image_);
    else
        std::cout << "ERROR:Wrong choice!\n";

}


void ImageProcessingSystem::RunFiltering()
{

    int choice = menu_->FilteringMenu();

    double para1 = 0.0;
    double para2 = 0.0;
    int kernel_height = 0;
    int kernel_width = 0;

    if (choice == 1)
    {
        std::cout << "Please enter the kernel height and the kernel width: ";
        std::cin >> kernel_height >> kernel_width;
        output_image_ = filtering_->LowPassFilter(input_image_, kernel_height, kernel_width);
    }
    else if (choice == 2)
        output_image_ = filtering_->HighPassFilter(input_image_);
    else if (choice == 3)
    {
        std::cout << "Please enter the central frequency and the bandwidth: ";
        std::cin >> para1 >> para2;
        output_image_ = filtering_->BandPassFilter(input_image_, para1, para2);
    }
    else if (choice == 4)
    {
        std::cout << "Please enter the kernel height, the kernel width and the kernel sigma: ";
        std::cin >> kernel_height >> kernel_width >> para1;
        output_image_ = filtering_->GaussianFilter(input_image_, kernel_height, kernel_width, para1);
    }
    else if (choice == 5)
        output_image_ = filtering_->LaplacianFilter(input_image_);
    else
        std::cout << "ERROR:Wrong choice!\n";

}


void ImageProcessingSystem::UpdateInputImage()
{
    input_image_ = output_image_.clone();
}


void ImageProcessingSystem::UpdateInputImage(const std::string& file_name)
{
    input_image_ = image_io_->ReadImage(file_name);
    input_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
}


void ImageProcessingSystem::RunUpdateInputImage()
{

    int choice = menu_->UpdateInputImageMenu();

    if (choice == 1)
        UpdateInputImage();
    else if (choice == 2)
    {
        std::string file_name = "";
        std::cout << "Please enter the file name of the new input image: ";
        std::cin >> file_name;
        UpdateInputImage(file_name);
    }
    else
        std::cout << "ERROR:Wrong choice!\n";

}


void ImageProcessingSystem::DisplayCurrentInputImage() const
{
    image_io_->DisplayImage(input_image_, "Current Input Image");
}


void ImageProcessingSystem::DisplayCurrentOutputImage() const
{
    image_io_->DisplayImage(output_image_, "Current Output Image");
}


ImageProcessingSystem::ImageProcessingSystem(const std::string& file_name)
{

    image_io_ = std::make_unique<ImageIO>();
    image_enhancement_ = std::make_unique<ImageEnhancement>();
    geometric_transform_ = std::make_unique<GeometricTransform>();
    filtering_ = std::make_unique<Filtering>();
    menu_ = std::make_unique<Menu>();

    input_image_ = image_io_->ReadImage(file_name);
    input_image_ = ImageTypeConversion::ConvertRGB2GrayScale(input_image_);
    output_image_ = cv::Mat::zeros(input_image_.rows, input_image_.cols, CV_8UC1);

}


ImageProcessingSystem::ImageProcessingSystem(const ImageProcessingSystem& image_processing_system)
{

    image_io_ = std::make_unique<ImageIO>();
    image_enhancement_ = std::make_unique<ImageEnhancement>();
    geometric_transform_ = std::make_unique<GeometricTransform>();
    filtering_ = std::make_unique<Filtering>();
    menu_ = std::make_unique<Menu>();

    input_image_ = image_processing_system.input_image_.clone();
    output_image_ = cv::Mat::zeros(input_image_.rows, input_image_.cols, CV_8UC1);

}


ImageProcessingSystem::~ImageProcessingSystem()
{
}


cv::Mat ImageProcessingSystem::Run()
{

    int choice = 0;

    while (true)
    {
        choice = menu_->MainMenu();

        if (choice == 1)
            RunImageEnhancement();
        else if (choice == 2)
            RunGeometricTransform();
        else if (choice == 3)
            RunFiltering();
        else if (choice == 4)
            RunUpdateInputImage();
        else if (choice == 5)
            DisplayCurrentInputImage();
        else if (choice == 6)
            DisplayCurrentOutputImage();
        else if (choice == 7)
            return output_image_;
        else
            std::cout << "ERROR:Wrong choice!\n";
    }

}


