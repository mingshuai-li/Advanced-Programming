/********************************************************************************* 
 
  * FileName:       image_processing_system.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.1.29
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
        output_image_ = image_->BrightnessTransform(para1);
    }
    else if (choice == 2)
        output_image_ = image_->InverseTransform();
    else if (choice == 3)
    {
        std::cout << "Please enter the coefficient and the exponent: ";
        std::cin >> para1 >> para2;
        output_image_ = image_->GammaTransform(para1, para2);
    }
    else if (choice == 4)
    {
        std::cout << "Please enter the coefficient: ";
        std::cin >> para1;
        output_image_ = image_->LogTransform(para1);
    }
    else if (choice == 5)
    {
        std::cout << "Please enter the lower threshold and the upper threshold: ";
        std::cin >> para1 >> para2;
        output_image_ = image_->NormalizationTransform(para1, para2);
    }
    else if (choice == 6)
    {
        std::cout << "Please enter the threshold: ";
        std::cin >> para1;
        output_image_ = image_->ThresholdTransform(para1);
    }
    else if (choice == 7)
    {
        std::cout << "Please enter the lower threshold and the upper threshold: ";
        std::cin >> para1 >> para2;
        output_image_ = image_->WindowTransform(para1, para2);
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
        output_image_ = image_->Resize(para1, para2);
    }
    else if (choice == 2)
    {
        std::cout << "Please enter the angle that the input image rotates: ";
        std::cin >> para1;
        output_image_ = image_->Rotate(para1);
    }
    else if (choice == 3)
        output_image_ = image_->FlipLeftRight();
    else if (choice == 4)
        output_image_ = image_->FlipUpDown();
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
        output_image_ = image_->LowPassFilter(kernel_height, kernel_width);
    }
    else if (choice == 2)
        output_image_ = image_->HighPassFilter();
    else if (choice == 3)
    {
        std::cout << "Please enter the central frequency and the bandwidth: ";
        std::cin >> para1 >> para2;
        output_image_ = image_->BandPassFilter(para1, para2);
    }
    else if (choice == 4)
    {
        std::cout << "Please enter the kernel height, the kernel width and the kernel sigma: ";
        std::cin >> kernel_height >> kernel_width >> para1;
        output_image_ = image_->GaussianFilter(kernel_height, kernel_width, para1);
    }
    else if (choice == 5)
        output_image_ = image_->LaplacianFilter();
    else
        std::cout << "ERROR:Wrong choice!\n";

}


void ImageProcessingSystem::UpdateInputImage()
{
    image_->SetNewImage(output_image_);
}


void ImageProcessingSystem::UpdateInputImage(const std::string& file_name)
{
    image_->SetNewImage(file_name);
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
    image_->DisplayImage("Current Input Image");
}


void ImageProcessingSystem::DisplayCurrentOutputImage() const
{
    image_->DisplayImage(output_image_, "Current Output Image");
}


ImageProcessingSystem::ImageProcessingSystem(const std::string& file_name)
{

    image_ = std::make_unique<Image>(file_name);
    menu_ = std::make_unique<Menu>();

    output_image_ = cv::Mat::zeros(image_->GetImageHeight(), image_->GetImageWidth(), CV_8UC1);

}


ImageProcessingSystem::ImageProcessingSystem(const ImageProcessingSystem& image_processing_system)
{

    image_ = std::make_unique<Image>(*(image_processing_system.image_));
    menu_ = std::make_unique<Menu>();

    output_image_ = cv::Mat::zeros(image_->GetImageHeight(), image_->GetImageWidth(), CV_8UC1);

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


