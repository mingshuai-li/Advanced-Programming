/********************************************************************************* 
 
  * FileName:       geometric_transform.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.19
  * Description:    The implementation for the geometric transform algorithms
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "geometric_transform.hpp"

cv::Mat Resize(const cv::Mat& input_image, const double& height_scaling, const double& width_scaling)
{

    int output_height = cvRound(input_image.rows * height_scaling);
    int output_width = cvRound(input_image.cols * width_scaling);
	  cv::Mat output_image(output_height, output_width, CV_8UC1);

    int map_row_out_to_in = 0;
    int map_col_out_to_in = 0;

    for (int i = 0; i < output_height; i++)
    {
        for (int j = 0; j < output_width; j++)
        {
            map_row_out_to_in = static_cast<int>((i + 1) / height_scaling + 0.5) - 1;
            map_col_out_to_in = static_cast<int>((j + 1) / width_scaling + 0.5) - 1;
            output_image.at<uchar>(i, j) = input_image.at<uchar>(map_row_out_to_in, map_col_out_to_in);
        }
    }

    return output_image;

}


cv::Mat Rotate(const cv::Mat& input_image, const double& angle)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    int output_size = static_cast<int>(sqrtf(pow(input_image.rows, 2) + pow(input_image.cols, 2)) + 0.5);

    cv::Mat output_image = cv::Mat::zeros(output_size, output_size, CV_8UC1);

    double angle_in_rad = angle * PI / 180;
    double sin_angle = sin(angle_in_rad);
    double cos_angle = cos(angle_in_rad);

    int map_row_out_to_in = 0;
    int map_col_out_to_in = 0;

    for (int i = 0; i < output_size; i++)
    {
        for (int j = 0; j < output_size; j++)
        {
            map_row_out_to_in = static_cast<int>((i - output_size / 2) * cos_angle - (j - output_size / 2) * sin_angle + 0.5);
            map_col_out_to_in = static_cast<int>((i - output_size / 2) * sin_angle + (j - output_size / 2) * cos_angle + 0.5);
            map_row_out_to_in += image_height / 2;
            map_col_out_to_in += image_width / 2;

            if (map_row_out_to_in < 0 || map_row_out_to_in >= image_height || map_col_out_to_in < 0 || map_col_out_to_in >= image_width)
                output_image.at<uchar>(i, j) = static_cast<uchar>(0);
            else
                output_image.at<uchar>(i, j) = input_image.at<uchar>(map_row_out_to_in, map_col_out_to_in);
        }
    }

    return output_image;

}


cv::Mat FlipLeftRight(const cv::Mat& input_image)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            output_image.at<uchar>(i, j) = input_image.at<uchar>(i, image_width - j - 1);
    
    return output_image;

}


cv::Mat FlipUpDown(const cv::Mat& input_image)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            output_image.at<uchar>(i, j) = input_image.at<uchar>(image_height - i - 1, j);
    
    return output_image;

}


