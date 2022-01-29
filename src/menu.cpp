/********************************************************************************* 
 
  * FileName:       menu.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The implementation for the class Menu
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "../include/menu.hpp"


int Menu::MainMenu()
{

    int choice = 0;

    std::cout << "Welcome to use this image processing system(Version 2.00)!\n";
    std::cout << "Which kind of operations would you like to perform?\n";
    std::cout << "1.Image Geometric Transform\n2.Image Enhancement\n3.Filtering\n4.Update Input Image\n";
    std::cout << "5.Display Current Input Image\n6.Display Current Output Image\n7.Save Current Output Image\n8.Get Current Output Image and Quit\n";
    std::cin >> choice;

    return choice;

}


int Menu::GeometricTransformMenu()
{

    int choice = 0;

    std::cout << "Which kind of Image Geometric Transform operations would you like to perform?\n";
    std::cout << "1.Resize\n2.Rotate\n3.FlipLeftRight\n4.FlipUpDown\n";
    std::cin >> choice;

    return choice;

}


int Menu::ImageEnhancementMenu()
{

    int choice = 0;

    std::cout << "Which kind of Image Enhancement operations would you like to perform?\n";
    std::cout << "1.Brightness Transform\n2.Inverse Transform\n3.Gamma Transform\n4.Log Transform\n";
    std::cout << "5.Normalization Transform\n6.Threshold Transform\n7.Window Transform\n";
    std::cin >> choice;

    return choice;

}


int Menu::FilteringMenu()
{

    int choice = 0;

    std::cout << "Which kind of Filtering operations would you like to perform?\n";
    std::cout << "1.Low Pass Filtering\n2.High Pass Filtering\n3.Band Pass Filtering\n4.Gaussian Filtering\n5.Laplacian Filtering\n";
    std::cin >> choice;

    return choice;

}


int Menu::UpdateInputImageMenu()
{

    int choice = 0;

    std::cout << "Which option of input image update would you likw to perform?\n";
    std::cout << "1.Using the current output image\n2.Using a new input image\n";
    std::cin >> choice;

    return choice;

}


