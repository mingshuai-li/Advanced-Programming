/********************************************************************************* 
 
  * FileName:       main.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The main file
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "../include/image_processing_system.hpp"


int main(int argc, char** argv)
{

    //std::unique_ptr<ImageProcessingSystem> image_processing_system = std::make_unique<ImageProcessingSystem>("../NewYork.jpg");

    //cv::Mat output_image = image_processing_system->Run();

    cv::Mat image = cv::Mat::zeros(7, 7, CV_8UC1);
    const int image_height = image.rows;
    const int image_width = image.cols;

    uchar values[7] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            image.at<uchar>(i, j) = values[i];
    
    std::cout << image.at<uchar>(0, 0) << '\n';
    
    Image img = Image(image);
    cv::Mat res = img.LaplacianFilter();

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
            std::cout << static_cast<int>(res.at<uchar>(i, j)) << "   ";
        std::cout << '\n';
    }

    return 0;

}


