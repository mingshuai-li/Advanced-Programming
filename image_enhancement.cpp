/********************************************************************************* 
 
  * FileName:       image_enhancement.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The implementation for the image enhancement algorithms
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "image_enhancement.hpp"
#include "image_type_conversion.hpp"


cv::Mat BrightnessTransform(const cv::Mat& input_image, const double& delta)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    // Make a empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    double new_value = 0.0;


    // Loop over all pixel values 
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            new_value = static_cast<double>(input_image.at<uchar>(i, j)) + delta;
            output_image.at<uchar>(i, j) = MapDouble2Uchar(new_value);
            // The point process is addition with a constant
        }
    }

    return output_image;  

}


cv::Mat InverseTransform(const cv::Mat& input_image)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    // Make a empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Loop over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            output_image.at<uchar>(i, j) = 255 - input_image.at<uchar>(i, j);
            // The point process is be substracted from the 255 to inverse the pixel value

    return output_image;

}


cv::Mat GammaTransform(const cv::Mat& input_image, const double& coefficient_a, const double& exponent_alpha)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    // Make a empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    double new_value = 0.0;
    // Loop over all pixels' intensities
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            new_value = coefficient_a * pow(static_cast<double>(input_image.at<uchar>(i, j)), exponent_alpha);
            output_image.at<uchar>(i, j) = MapDouble2Uchar(new_value);
            // output_image = a * input_image^alpha
        }
    }

    return output_image;

}


cv::Mat LogTransform(const cv::Mat& input_image, const double& coefficient_a)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    // Make a empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    double new_value = 0.0;
    // Loop over all pixels' intensities
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            new_value = coefficient_a * log(static_cast<double>(input_image.at<uchar>(i, j)) + 1);
            output_image.at<uchar>(i, j) = MapDouble2Uchar(new_value);
            // output_image = a * log(1 + input_image) 
        }
    }

    return output_image;

}


cv::Mat NormalizationTransform(const cv::Mat& input_image, const double& lower_threshold, const double& upper_threshold)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    // Make a empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Judge the value of lower_threshold and upper_threshold
    if (lower_threshold > upper_threshold)
        std::cout << "ERROR: a should be <= b\n";
    else
    {
        double k = 255.0 / (upper_threshold - lower_threshold);
        double b = 255.0 * lower_threshold / (lower_threshold - upper_threshold);
        // Loop over all pixels' intensities
        for (int i = 0; i < image_height; i++)
        {
            for (int j = 0; j < image_width; j++)
            {
                if (static_cast<double>(input_image.at<uchar>(i, j)) > upper_threshold)
                    output_image.at<uchar>(i, j) = static_cast<uchar>(255);
                else if (static_cast<double>(input_image.at<uchar>(i, j)) >= lower_threshold)
                    output_image.at<uchar>(i, j) = static_cast<uchar>(k * input_image.at<uchar>(i, j) + b);
                // We modify the intensity values of pixels to make the image more appealing to the senses
            }
        }
    }

    return output_image;

}


cv::Mat ThresholdTransform(const cv::Mat& input_image, const double& threshold)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;
    // Make a empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Loop over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            if (static_cast<double>(input_image.at<uchar>(i, j)) >= threshold)
                output_image.at<uchar>(i, j) = input_image.at<uchar>(i, j);
            // If the pixel value is less than threshold, it is set to zero, otherwise it remains.

    return output_image;

}


cv::Mat WindowTransform(const cv::Mat& input_image, const double& lower_threshold, const double& upper_threshold)
{

    int image_height = input_image.rows;
    int image_width = input_image.cols;

    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Make a empty copy of the input image
    if (lower_threshold > upper_threshold)
        std::cout << "ERROR: a should be <= b\n";
    else
    {
        // Loop over all pixels' intensities
        for (int i = 0; i < image_height; i++)
            for (int j = 0; j < image_width; j++)
                if ((static_cast<double>(input_image.at<uchar>(i, j)) >= lower_threshold) && (static_cast<double>(input_image.at<uchar>(i, j)) <= upper_threshold))
                    output_image.at<uchar>(i, j) = input_image.at<uchar>(i, j);
                // Only remain the values between the range given by Users
    }

    return output_image;

}


