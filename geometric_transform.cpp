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

    int rows = cvRound(input_image.rows * height_scaling);
    int cols = cvRound(input_image.cols * width_scaling);
    // Make a copy of the input image
	cv::Mat output_image(rows, cols, CV_8UC1);
    int x = 0;
    int y = 0;
    // Loop over all pixels' intensities
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            x = static_cast<int>((i + 1) / height_scaling + 0.5) - 1;
            y = static_cast<int>((j + 1) / width_scaling + 0.5) - 1;
            output_image.at<uchar>(i, j) = input_image.at<uchar>(x, y);
            // change the scale of the output image with given size
        }
    }

    return output_image;

}


cv::Mat Rotate(const cv::Mat& input_image, const double& angle)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    int half_image_height = image_height / 2;
    int half_image_width = image_width / 2;

	int output_image_size = static_cast<int>(sqrtf(pow(input_image.rows, 2) + pow(input_image.cols, 2)) + 0.5);
    int half_output_size = output_image_size / 2;
    // Make a copy of the input image
	cv::Mat output_image = cv::Mat::zeros(output_image_size, output_image_size, CV_8UC1);

	double angle_rad = angle * PI / 180;
    double sin_angle = sin(angle_rad);
    double cos_angle = cos(angle_rad);

	int input_image_row = 0;
    int input_image_col = 0;
    // Loop over all pixels' intensities
	for (int i = 0; i < output_image_size; i++)
    {
		for (int j = 0; j < output_image_size; j++)
		{
			// Move to the new coordinates relative to the center of rotation. The transformed image is multiplied by the original image transformation matrix
            input_image_row = static_cast<int>((i - half_output_size) * cos_angle - (j - half_output_size) * sin_angle + 0.5);
			input_image_col = static_cast<int>((i- half_output_size) * sin_angle + (j - half_output_size) * cos_angle + 0.5);
            // Restore to the old coordinates relative to the origin of the upper left corne
			input_image_row += half_image_height;
			input_image_col += half_image_width;

            if (input_image_row <= 0 || input_image_row >= image_height || input_image_col <= 0 || input_image_col >= image_width)
                output_image.at<uchar>(i, j) = static_cast<uchar>(0);
            else
                output_image.at<uchar>(i, j) = input_image.at<uchar>(input_image_row, input_image_col);
		}
    }

    return output_image;

}


cv::Mat FlipLeftRight(const cv::Mat& input_image)
{
    int image_height = input_image.rows;
    int image_width = input_image.cols;
    // Make a copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Loop over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            // Flip along Y axis
            output_image.at<uchar>(i, j) = input_image.at<uchar>(i, image_width - j -1);

    return output_image;
}


cv::Mat FlipUpDown(const cv::Mat& input_image)
{
    int image_height = input_image.rows;
    int image_width = input_image.cols;
    // Make a copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Loop over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            // Flip along X axis
            output_image.at<uchar>(i, j) = input_image.at<uchar>(image_height - i - 1, j);

    return output_image;
}