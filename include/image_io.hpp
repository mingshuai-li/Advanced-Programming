/********************************************************************************* 
 
  * FileName:       image_io.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.1.29
  * Description:    The header file for the class ImageIO 
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#ifndef IMAGE_IO_H
#define IMAGE_IO_H


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


class ImageIO
{

    public:
        /*
        * Reads the image and returns the corresponding data structure
        * @ Parameter:
        *       file_name: The file path of the image
        * @ Return:
        *                  The image that is read in
        */
        cv::Mat ReadImage(const std::string& file_name);


        /*
        * Displays the image
        * @ Parameter:
        *       image:       The image reference
        *       image_title: The title of the image
        */
        void DisplayImage(const cv::Mat& image, const std::string& image_title);


        /*
        * Prints the basic information of the image
        * @ Parameter:
        *       image:     The image reference
        */
        void PrintImageInfo(const cv::Mat& image);

};


#endif


