/********************************************************************************* 
 
  * FileName:       filtering.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The implementation for the class Filtering
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "filtering.hpp"
#include "image_type_conversion.hpp"


const double Filtering::PI_ = 3.141592654;
const double Filtering::NATURAL_CONSTANT_ = 2.7182818284;


cv::Mat Filtering::Convolve(const cv::Mat& input_image, const cv::Mat& kernel)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;
    const int kernel_height = kernel.rows;
    const int kernel_width = kernel.cols;
    const int half_kheight = kernel_height / 2;
    const int half_kwidth = kernel_width / 2;

    // Pads the image so that the convolution computation won't met the edge problems
    cv::Mat padded_image = cv::Mat::zeros(image_height + 2 * half_kheight, image_width + 2 * half_kwidth, CV_8UC1);

    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            padded_image.at<uchar>(i + half_kheight, j + half_kwidth) = input_image.at<uchar>(i, j);
    
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Computes the coefficients for the coordinates mapping in the convolution
    const int coefficient_h = (-2 * half_kheight) / (kernel_height - 1);
    const int coefficient_w = (-2 * half_kwidth) / (kernel_width - 1);
    int padded_i = 0;
    int padded_j = 0;
    int transformed_i = 0;
    int transformed_j = 0;
    double weighted_sum = 0.0;

    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            weighted_sum = 0.0;
            padded_i = i + half_kheight;
            padded_j = j + half_kwidth;
            // Computes the weighted sum in the kernel's region
            for (int k = 0; k < kernel_height; k++)
            {
                for (int l = 0; l < kernel_width; l++)
                {
                    transformed_i = coefficient_h * k + padded_i + half_kheight;
                    transformed_j = coefficient_w * l + padded_j + half_kwidth;
                    weighted_sum += padded_image.at<uchar>(transformed_i, transformed_j) * kernel.at<double>(k, l);
                }
            }
            weighted_sum = ImageTypeConversion::MapDouble2Uchar(weighted_sum);
            output_image.at<uchar>(i, j) = weighted_sum;
        }
    }

    return output_image;

}


cv::Mat Filtering::LowPassFilter(const cv::Mat& input_image, int kernel_height, int kernel_width)
{

    cv::Mat kernel = cv::Mat::ones(kernel_height, kernel_width, CV_64FC1);

    // Computes the uniform kernel
    const double kernel_coefficient = 1 / static_cast<double>(kernel_height * kernel_width);
    for (int i = 0; i < kernel_height; i++)
        for (int j = 0; j < kernel_width; j++)
            kernel.at<double>(i, j) *= kernel_coefficient;
    
    // Performs the convolution
    cv::Mat output_image = Convolve(input_image, kernel);

    return output_image;

}


cv::Mat Filtering::HighPassFilter(const cv::Mat& input_image)
{

    // Computes the kernel for computing the image's gradients in the height direction
    cv::Mat kernel_height = cv::Mat::zeros(3, 3, CV_64FC1);
    kernel_height.at<double>(0, 0) = 1.0; kernel_height.at<double>(0, 1) = 2.0; kernel_height.at<double>(0, 2) = 1.0;
    kernel_height.at<double>(2, 0) = -1.0; kernel_height.at<double>(2, 1) = -2.0; kernel_height.at<double>(2, 2) = -1.0;

    // Computes the kernel for computing the image's gradients in the width direction
    cv::Mat kernel_width = cv::Mat::zeros(3, 3, CV_64FC1);
    kernel_width.at<double>(0, 0) = 1.0; kernel_width.at<double>(1, 0) = 2.0; kernel_width.at<double>(2, 0) = 1.0;
    kernel_width.at<double>(0, 2) = -1.0; kernel_width.at<double>(1, 2) = -2.0; kernel_width.at<double>(2, 2) = -1.0;

    // Performs the convolution
    cv::Mat d_height = Convolve(input_image, kernel_height);
    cv::Mat d_width = Convolve(input_image, kernel_width);

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    // Computes the gradient magnitudes at each pixel's position
    cv::Mat gradient_magnitude = cv::Mat::zeros(image_height, image_width, CV_64FC1);
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            gradient_magnitude.at<double>(i, j) = static_cast<double>(sqrt(pow(d_height.at<uchar>(i, j), 2) + pow(d_width.at<uchar>(i, j), 2)));

    // Finds the minimum gradient and the maximum gradient
    double max_gradient = 0.0;
    double min_gradient = 2 * 255.0;
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            if (gradient_magnitude.at<double>(i, j) > max_gradient)
                max_gradient = gradient_magnitude.at<double>(i, j);
            if (gradient_magnitude.at<double>(i, j) < min_gradient)
                min_gradient = gradient_magnitude.at<double>(i, j);
        }
    }

    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    // Maps the gradient values from [min_gradient, max_gradient] to [0, 255], the linear transform formula is as follows:
    // transformed values([0, 255]) = coefficient1 * values([min_gradient, max_gradient]) + coefficient2
    const double coefficient1 = 255.0 / (max_gradient - min_gradient);
    const double coefficient2 = (-min_gradient) * 255.0 / (max_gradient - min_gradient);
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            output_image.at<uchar>(i, j) = static_cast<uchar>(coefficient1 * gradient_magnitude.at<double>(i, j) + coefficient2);
    
    return output_image;

}


cv::Mat Filtering::BandPassFilter(const cv::Mat& input_image, double central_freq, double band_width)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    cv::Mat input_image_double =  ImageTypeConversion::ConvertUchar2DoubleC1(input_image); 

    cv::Mat frequency_domain_image = cv::Mat::zeros(image_height, image_width, CV_64FC1);

    // Transforms the input image into the Fourier Domain
    cv::dft(input_image_double, frequency_domain_image);

    const int frequency_domain_height = frequency_domain_image.rows;
    const int frequency_domain_width = frequency_domain_image.cols;

    // Filters and keeps only the components that are aligned with the required frequencies
    for (int i = 0; i < frequency_domain_height; i++)
    {
        for (int j = 0; j < frequency_domain_width; j++)
        {
            if ((frequency_domain_image.at<double>(i, j) >= central_freq - band_width / 2) && (frequency_domain_image.at<double>(i, j) <= central_freq + band_width / 2))
                frequency_domain_image.at<double>(i, j) = 0.0;
        }
    }

    // Transforms the output image into the Spatial Domain
    cv::Mat output_image_double = cv::Mat::zeros(image_height, image_width, CV_64FC1);
    cv::idft(frequency_domain_image, output_image_double);

    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            output_image.at<uchar>(i, j) = static_cast<uchar>((output_image_double.at<double>(i, j) > 255.0) ? 255 : output_image_double.at<double>(i, j));

    return output_image;

}


cv::Mat Filtering::GaussianFilter(const cv::Mat& input_image, int kernel_height, int kernel_width, double kernel_sigma)
{

    cv::Mat kernel = cv::Mat::zeros(kernel_height, kernel_width, CV_64FC1);

    const int half_kheight = kernel_height / 2;
    const int half_kwidth = kernel_width / 2;
    // The Gaussian filter formula: value = coefficient1 * e^((-(i - half_kheight)^2 - (j - half_kwidth)^2) * coefficient2)
    const double coefficient1 = 1 / (2 * Filtering::PI_ * kernel_sigma * kernel_sigma);
    const double coefficient2 = 1 / (2 * kernel_sigma * kernel_sigma);
    // Stores the sum of the Gaussian Kernel's values
    double sum = 0.0;
    // Stores the (i - half_kheight)^2 and the (j - half_kwidth)^2
    double offset_i = 0.0;
    double offset_j = 0.0;
    double current_kernel_value = 0.0;

    // Computes the Gaussian Kernel
    for (int i = 0; i < kernel_height; i++)
    {
        offset_i = pow(i - half_kheight, 2);
        for (int j = 0; j < kernel_width; j++)
        {
            offset_j = pow(j - half_kwidth, 2);
            current_kernel_value = coefficient1 * pow(Filtering::NATURAL_CONSTANT_, (-offset_i - offset_j) * coefficient2);
            kernel.at<double>(i, j) = current_kernel_value;
            sum += current_kernel_value;
        }
    }

    for (int i = 0; i < kernel_height; i++)
        for (int j = 0; j < kernel_width; j++)
            kernel.at<double>(i, j) /= sum;
    
    // Performs the convolution
    cv::Mat output_image = Convolve(input_image, kernel);

    return output_image;

}


cv::Mat Filtering::LaplacianFilter(const cv::Mat& input_image)
{

    // Computes the Laplacian Kernel
    cv::Mat kernel = cv::Mat::zeros(3, 3, CV_64FC1);
    kernel.at<double>(0, 1) = -1.0; kernel.at<double>(1, 0) = -1.0;
    kernel.at<double>(1, 2) = -1.0; kernel.at<double>(2, 1) = -1.0;
    kernel.at<double>(1, 1) = 4.0;

    // Computes the convolution
    cv::Mat output_image = Convolve(input_image, kernel);

    return output_image;

}


