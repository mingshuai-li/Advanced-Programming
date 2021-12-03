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

    cv::Mat input_image = cv::imread("NewYork.jpg");
    cv::Mat output_image = ConvertRGB2GrayScale(input_image);
    input_image = output_image;
  
    // Stores the users' choices and the functions' arguments
    int choice = 0;
    double para1 = 0.0;
    double para2 = 0.0;
    int kernel_height = 0;
    int kernel_width = 0;

    std::cout << "Welcome to use this image processing system(Version 1.00)!\n";
    std::cout << "Which kind of operations would you like to perform?\n";
    std::cout << "1.Image Enhancement\n2.Image Geometric Transform\n3.Filtering\n";;
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "Which kind of Image Enhancement operations would you like to perform?\n";
        std::cout << "1.Brightness Transform\n2.Inverse Transform\n3.Gamma Transform\n4.Log Transform\n";
        std::cout << "5.Normalization Transform\n6.Threshold Transform\n7.Window Transform\n";
        std::cin>> choice;

        if (choice == 1)
        {
            std::cout << "Please enter the change of the brightness: ";
            std::cin >> para1;
            output_image = BrightnessTransform(input_image, para1);
        }
        else if (choice == 2)
            output_image = InverseTransform(input_image);
        else if (choice == 3)
        {
            std::cout << "Please enter the coefficient and the exponent: ";
            std::cin >> para1 >> para2;
            output_image = GammaTransform(input_image, para1, para2);
        }
        else if (choice == 4)
        {
            std::cout << "Please enter the coefficient: ";
            std::cin >> para1;
            output_image = LogTransform(input_image, para1);
        }
        else if (choice == 5)
        {
            std::cout << "Please enter the lower threshold and the upper threshold: ";
            std::cin >> para1 >> para2;
            output_image = NormalizationTransform(input_image, para1, para2);
        }
        else if (choice == 6)
        {
            std::cout << "Please enter the threshold: ";
            std::cin >> para1;
            output_image = ThresholdTransform(input_image, para1);
        }
        else if (choice == 7)
        {
            std::cout << "Please enter the lower threshold and the upper threshold: ";
            std::cin >> para1 >> para2;
            output_image = WindowTransform(input_image, para1, para2);
        }
        else
            std::cout << "ERROR:Wrong choice!\n";
    }
    else if (choice == 2)
    {
        std::cout << "Which kind of Image Geometric Transform operations would you like to perform?\n";
        std::cout << "1.Resize\n2.Rotate\n3.FlipLeftRight\n4.FlipUpDown\n";
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Please enter the height scaling factor and the width scaling factor: ";
            std::cin >> para1 >> para2;
            output_image = Resize(input_image, para1, para2);
        }
        else if (choice == 2)
        {
            std::cout << "Please enter the angle that the input image rotates: ";
            std::cin >> para1;
            output_image = Rotate(input_image, para1);
        }
        else if (choice == 3)
        {
            output_image = FlipLeftRight(input_image);
        }
        else if (choice == 4)
        {
            output_image = FlipUpDown(input_image);
        }
        else
            std::cout << "ERROR:Wrong choice!\n";
    }
    else if (choice == 3)
    {
        std::cout << "Which kind of Filtering operations would you like to perform?\n";
        std::cout << "1.Low Pass Filtering\n2.High Pass Filtering\n3.Band Pass Filtering\n4.Gaussian Filtering\n5.Laplacian Filtering\n";
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Please enter the kernel height and the kernel width: ";
            std::cin >> kernel_height >> kernel_width;
            output_image = LowPassFilter(input_image, kernel_height, kernel_width);
        }
        else if (choice == 2)
            output_image = HighPassFilter(input_image);
        else if (choice == 3)
        {
            std::cout << "Please enter the central frequency and the bandwidth: ";
            std::cin >> para1 >> para2;
            output_image = BandPassFilter(input_image, para1, para2);
        }
        else if (choice == 4)
        {
            std::cout << "Please enter the kernel height, the kernel width and the kernel sigma: ";
            std::cin >> kernel_height >> kernel_width >> para1;
            output_image = GaussianFilter(input_image, kernel_height, kernel_width, para1);
        }
        else if (choice == 5)
            output_image = LaplacianFilter(input_image);
        else
            std::cout << "ERROR:Wrong choice!\n";
    }
    else
        std::cout << "ERROR:Wrong choice!\n";

    DisplayImage(output_image, "New York!");

    return 0;

}


