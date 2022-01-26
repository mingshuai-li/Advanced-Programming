/********************************************************************************* 
 
  * FileName:       main.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The main file
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "image_processing_system.hpp"


int main(int argc, char** argv)
{

    std::unique_ptr<ImageProcessingSystem> image_processing_system = std::make_unique<ImageProcessingSystem>("NewYork.jpg");

    cv::Mat output_image = image_processing_system->Run();

    return 0;

}


