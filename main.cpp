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


int main(int argc, char** argv)
{

    cv::Mat image = ReadImage("NewYork.jpg");
    DisplayImage(image, "New York!");
    PrintImageInfo(image);
    return 0;

}


