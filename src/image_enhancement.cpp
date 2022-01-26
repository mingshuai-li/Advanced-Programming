/********************************************************************************* 
 
  * FileName:       image_enhancement.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The implementation for the class ImageEnhancement
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "image_enhancement.hpp"
#include "image_type_conversion.hpp"


cv::Mat ImageEnhancement::BrightnessTransform(const cv::Mat& input_image, double delta)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    double new_value = 0.0;

    // Loops over all pixels' values 
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            new_value = static_cast<double>(input_image.at<uchar>(i, j)) + delta;
            output_image.at<uchar>(i, j) = ImageTypeConversion::MapDouble2Uchar(new_value);
            // Adds a constant to each pixel's value
        }
    }

    return output_image;  

}


cv::Mat ImageEnhancement::InverseTransform(const cv::Mat& input_image)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            output_image.at<uchar>(i, j) = 255 - input_image.at<uchar>(i, j);
            // Each pixel's value is subtracted by 255

    return output_image;

}


cv::Mat ImageEnhancement::GammaTransform(const cv::Mat& input_image, double coefficient_a, double exponent_alpha)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    double new_value = 0.0;
    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            new_value = coefficient_a * pow(static_cast<double>(input_image.at<uchar>(i, j)), exponent_alpha);
            output_image.at<uchar>(i, j) = ImageTypeConversion::MapDouble2Uchar(new_value);
            // output_image = a * input_image^alpha
        }
    }

    return output_image;

}


cv::Mat ImageEnhancement::LogTransform(const cv::Mat& input_image, double coefficient_a)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    double new_value = 0.0;
    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            new_value = coefficient_a * log(static_cast<double>(input_image.at<uchar>(i, j)) + 1);
            output_image.at<uchar>(i, j) = ImageTypeConversion::MapDouble2Uchar(new_value);
            // output_image = a * log(1 + input_image) 
        }
    }

    return output_image;

}


cv::Mat ImageEnhancement::NormalizationTransform(const cv::Mat& input_image, double lower_threshold, double upper_threshold)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Judges whether the values of lower_threshold and upper_threshold are reasonable
    if (lower_threshold > upper_threshold)
        std::cout << "ERROR: a should be <= b\n";
    else
    {
        const double k = 255.0 / (upper_threshold - lower_threshold);
        const double b = 255.0 * lower_threshold / (lower_threshold - upper_threshold);
        // Loops over all pixels' intensities
        for (int i = 0; i < image_height; i++)
        {
            for (int j = 0; j < image_width; j++)
            {
                if (static_cast<double>(input_image.at<uchar>(i, j)) > upper_threshold)
                    output_image.at<uchar>(i, j) = static_cast<uchar>(255);
                else if (static_cast<double>(input_image.at<uchar>(i, j)) >= lower_threshold)
                    output_image.at<uchar>(i, j) = static_cast<uchar>(k * input_image.at<uchar>(i, j) + b);
                // Modifies the intensity values of pixels to make the image more appealing to the senses
            }
        }
    }

    return output_image;

}


cv::Mat ImageEnhancement::ThresholdTransform(const cv::Mat& input_image, double threshold)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            if (static_cast<double>(input_image.at<uchar>(i, j)) >= threshold)
                output_image.at<uchar>(i, j) = input_image.at<uchar>(i, j);
            // If the pixel value is less than threshold, it is set to zero, otherwise it remains.

    return output_image;

}


cv::Mat ImageEnhancement::WindowTransform(const cv::Mat& input_image, double lower_threshold, double upper_threshold)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Makes an empty copy of the input image
    if (lower_threshold > upper_threshold)
        std::cout << "ERROR: a should be <= b\n";
    else
    {
        // Loops over all pixels' intensities
        for (int i = 0; i < image_height; i++)
            for (int j = 0; j < image_width; j++)
                if ((static_cast<double>(input_image.at<uchar>(i, j)) >= lower_threshold) && (static_cast<double>(input_image.at<uchar>(i, j)) <= upper_threshold))
                    output_image.at<uchar>(i, j) = input_image.at<uchar>(i, j);
                // Keeps the pixels' values between the range defined by lower_threshold and upper_threshold, sets others to zero
    }

    return output_image;

}


