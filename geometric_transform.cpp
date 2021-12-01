/********************************************************************************* 
 
  * FileName:       geometric_transform.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.19
  * Description:    The implementation for the geometric transform algorithms
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "geometric_transform.hpp"

cv::Mat Resize(const cv::Mat& input_image, double kx, double ky)
{  
  /*int image_height = input_image.rows;
  int image_width = input_image.cols;
  cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
  
  cv::resize(input_image, output_image, cv::Size(output_height, output_width));*/

  int row = cvRound(input_image.rows * kx), col = cvRound(input_image.cols * ky);
	cv::Mat output_image(row, col, input_image.type());


  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      int x = static_cast<int>((i + 1) / kx + 0.5) - 1;
      int y = static_cast<int>((j + 1) / ky + 0.5) - 1;
      output_image.at<cv::Vec3b>(i, j) = input_image.at<cv::Vec3b>(x, y);
    }
  }

  return output_image;

}

cv::Mat Rotate(const cv::Mat& input_image, const double& angle)
{
  /*cv::Mat output_image;

  cv::Size input_image_sz = input_image.size();
  cv::Size output_image_sz(input_image_sz.height, input_image_sz.width);
  int len = std::max(input_image.cols, input_image.rows);

  cv::Point2f center(len / 2, len / 2);
  cv::Mat rot_mat = cv::getRotationMatrix2D(center, angle, 1.0);

  cv::warpAffine(input_image, output_image, rot_mat, output_image_sz);*/

	int len = (int)(sqrtf(pow(input_image.rows, 2) + pow(input_image.cols, 2)) + 0.5);
 
	cv::Mat output_image = cv::Mat::zeros(len, len, CV_8UC3);
	double anglePI = angle * CV_PI / 180;
	int xSm, ySm;
 
	for(int i = 0; i < output_image.rows; i++)
  {
		for(int j = 0; j < output_image.cols; j++)
		{
			xSm = (int)((i-output_image.rows/2)*cos(anglePI) - (j-output_image.cols/2)*sin(anglePI) + 0.5);
			ySm = (int)((i-output_image.rows/2)*sin(anglePI) + (j-output_image.cols/2)*cos(anglePI) + 0.5);
			xSm += input_image.rows / 2;
			ySm += input_image.cols / 2;
 
			if(xSm >= input_image.rows || ySm >= input_image.cols || xSm <= 0 || ySm <= 0)
      {
				output_image.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 0);
			}
			else
      {
				output_image.at<cv::Vec3b>(i, j) = input_image.at<cv::Vec3b>(xSm, ySm);
			}
		}
  }


  return output_image;
}
