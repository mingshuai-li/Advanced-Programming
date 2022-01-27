/********************************************************************************* 
 
  * FileName:       image.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.1.29
  * Description:    The implementation for the class Image
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "../include/image.hpp"


const double Image::PI_ = 3.141592654;
const double Image::NATURAL_CONSTANT_ = 2.718281828459;


cv::Mat Image::ReadImage(const std::string& file_name)
{
    return cv::imread(file_name);
}


cv::Mat Image::ConvertRGB2GrayScale(const cv::Mat& input_image)
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    // The weights utilized to map the RGB channels to the grayscale channel
    const double weights[3] = {0.0722, 0.7152, 0.2126};
    double weighted_sum = 0.0;

    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            const cv::Vec3b& channel = input_image.at<cv::Vec3b>(i, j);
            weighted_sum = 0.0;

            // Computes the grayscale channel value
            for (int k = 0; k < 3; k++)
                weighted_sum += channel[k] * weights[k];

            output_image.at<uchar>(i, j) = static_cast<uchar>(weighted_sum);
        }
    }

    return output_image;
  
}


cv::Mat Image::ConvertUchar2DoubleC1(const cv::Mat& input_image) const
{

    const int image_height = input_image.rows;
    const int image_width = input_image.cols;

    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_64FC1);

    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            output_image.at<double>(i, j) = static_cast<double>(input_image.at<uchar>(i, j));
    
    return output_image;

}


uchar Image::MapDouble2Uchar(double n) const
{
    return (n > 255.0) ? static_cast<uchar>(255) : ((n < 0.0) ? static_cast<uchar>(0) : static_cast<uchar>(n));
}


cv::Mat Image::Convolve(const cv::Mat& input_image, const cv::Mat& kernel) const
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
            weighted_sum = MapDouble2Uchar(weighted_sum);
            output_image.at<uchar>(i, j) = weighted_sum;
        }
    }

    return output_image;

}


Image::Image(const std::string& file_name)
{
    input_image_ = ReadImage(file_name);
    input_image_ = ConvertRGB2GrayScale(input_image_);
}


Image::Image(const Image& image)
{
    input_image_ = image.input_image_.clone();
}


Image::~Image()
{
}


void Image::DisplayImage(const std::string& image_title) const
{
    cv::imshow(image_title, input_image_);
    cv::waitKey(0);
}


void Image::DisplayImage(const cv::Mat& image, const std::string& image_title) const
{
    cv::imshow(image_title, image);
    cv::waitKey(0);
}


void Image::PrintImageInfo() const
{
    std::cout << "The height of the image is: " << input_image_.rows << '\n';
    std::cout << "The width of the image is: " << input_image_.cols << '\n';
    std::cout << "The number of the channels of the image is " << input_image_.channels() << '\n';
}


int Image::GetImageHeight() const
{
    return input_image_.rows;
}


int Image::GetImageWidth() const
{
    return input_image_.cols;
}


cv::Mat Image::GetImage() const
{
    cv::Mat new_image = input_image_.clone();
    return new_image;
}


void Image::SetNewImage(const std::string& file_name)
{
    input_image_ = ReadImage(file_name);
    input_image_ = ConvertRGB2GrayScale(input_image_);
}


void Image::SetNewImage(const cv::Mat& new_image)
{
    input_image_ = new_image;
}


cv::Mat Image::Resize(double height_scaling, double width_scaling) const
{  

    const int rows = cvRound(input_image_.rows * height_scaling);
    const int cols = cvRound(input_image_.cols * width_scaling);

    // Makes a copy of the input image
	cv::Mat output_image(rows, cols, CV_8UC1);
    int x = 0;
    int y = 0;

    // Loops over all pixels' intensities
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            x = static_cast<int>((i + 1) / height_scaling + 0.5) - 1;
            y = static_cast<int>((j + 1) / width_scaling + 0.5) - 1;
            output_image.at<uchar>(i, j) = input_image_.at<uchar>(x, y);
            // changes the scale of the output image with given size
        }
    }

    return output_image;

}


cv::Mat Image::Rotate(double angle) const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;
    const int half_image_height = image_height / 2;
    const int half_image_width = image_width / 2;

	const int output_image_size = static_cast<int>(sqrtf(pow(input_image_.rows, 2) + pow(input_image_.cols, 2)) + 0.5);
    const int half_output_size = output_image_size / 2;

    // Makes a copy of the input image
	cv::Mat output_image = cv::Mat::zeros(output_image_size, output_image_size, CV_8UC1);

	const double angle_rad = angle * Image::PI_ / 180;
    const double sin_angle = sin(angle_rad);
    const double cos_angle = cos(angle_rad);

	int input_image_row = 0;
    int input_image_col = 0;
    // Loops over all pixels' intensities
	for (int i = 0; i < output_image_size; i++)
    {
		for (int j = 0; j < output_image_size; j++)
		{
			// Transforms to the new coordinates whose origin is at the center of rotation
            // The transformed image is multiplied by the original image transformation matrix
            input_image_row = static_cast<int>((i - half_output_size) * cos_angle - (j - half_output_size) * sin_angle + 0.5);
			input_image_col = static_cast<int>((i- half_output_size) * sin_angle + (j - half_output_size) * cos_angle + 0.5);

            // Transforms to the original coordinates whose origin is at the upper left corner
			input_image_row += half_image_height;
			input_image_col += half_image_width;

            if (input_image_row <= 0 || input_image_row >= image_height || input_image_col <= 0 || input_image_col >= image_width)
                output_image.at<uchar>(i, j) = static_cast<uchar>(0);
            else
                output_image.at<uchar>(i, j) = input_image_.at<uchar>(input_image_row, input_image_col);
		}
    }

    return output_image;

}


cv::Mat Image::FlipLeftRight() const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

    // Makes a copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            // Flips along Y axis
            output_image.at<uchar>(i, j) = input_image_.at<uchar>(i, image_width - j -1);

    return output_image;

}


cv::Mat Image::FlipUpDown() const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

    // Make a copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            // Flips along X axis
            output_image.at<uchar>(i, j) = input_image_.at<uchar>(image_height - i - 1, j);

    return output_image;

}


cv::Mat Image::BrightnessTransform(double delta) const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    double new_value = 0.0;

    // Loops over all pixels' values 
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            new_value = static_cast<double>(input_image_.at<uchar>(i, j)) + delta;
            output_image.at<uchar>(i, j) = MapDouble2Uchar(new_value);
            // Adds a constant to each pixel's value
        }
    }

    return output_image;  

}


cv::Mat Image::InverseTransform() const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            output_image.at<uchar>(i, j) = 255 - input_image_.at<uchar>(i, j);
            // Each pixel's value is subtracted by 255

    return output_image;

}


cv::Mat Image::GammaTransform(double coefficient_a, double exponent_alpha) const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    double new_value = 0.0;
    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            new_value = coefficient_a * pow(static_cast<double>(input_image_.at<uchar>(i, j)), exponent_alpha);
            output_image.at<uchar>(i, j) = MapDouble2Uchar(new_value);
            // output_image = a * input_image^alpha
        }
    }

    return output_image;

}


cv::Mat Image::LogTransform(double coefficient_a) const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);

    double new_value = 0.0;
    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            new_value = coefficient_a * log(static_cast<double>(input_image_.at<uchar>(i, j)) + 1);
            output_image.at<uchar>(i, j) = MapDouble2Uchar(new_value);
            // output_image = a * log(1 + input_image) 
        }
    }

    return output_image;

}


cv::Mat Image::NormalizationTransform(double lower_threshold, double upper_threshold) const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

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
                if (static_cast<double>(input_image_.at<uchar>(i, j)) > upper_threshold)
                    output_image.at<uchar>(i, j) = static_cast<uchar>(255);
                else if (static_cast<double>(input_image_.at<uchar>(i, j)) >= lower_threshold)
                    output_image.at<uchar>(i, j) = static_cast<uchar>(k * input_image_.at<uchar>(i, j) + b);
                // Modifies the intensity values of pixels to make the image more appealing to the senses
            }
        }
    }

    return output_image;

}


cv::Mat Image::ThresholdTransform(double threshold) const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

    // Makes an empty copy of the input image
    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Loops over all pixels' intensities
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            if (static_cast<double>(input_image_.at<uchar>(i, j)) >= threshold)
                output_image.at<uchar>(i, j) = input_image_.at<uchar>(i, j);
            // If the pixel value is less than threshold, it is set to zero, otherwise it remains.

    return output_image;

}


cv::Mat Image::WindowTransform(double lower_threshold, double upper_threshold) const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

    cv::Mat output_image = cv::Mat::zeros(image_height, image_width, CV_8UC1);
    // Makes an empty copy of the input image
    if (lower_threshold > upper_threshold)
        std::cout << "ERROR: a should be <= b\n";
    else
    {
        // Loops over all pixels' intensities
        for (int i = 0; i < image_height; i++)
            for (int j = 0; j < image_width; j++)
                if ((static_cast<double>(input_image_.at<uchar>(i, j)) >= lower_threshold) && (static_cast<double>(input_image_.at<uchar>(i, j)) <= upper_threshold))
                    output_image.at<uchar>(i, j) = input_image_.at<uchar>(i, j);
                // Keeps the pixels' values between the range defined by lower_threshold and upper_threshold, sets others to zero
    }

    return output_image;

}


cv::Mat Image::LowPassFilter(int kernel_height, int kernel_width) const
{

    cv::Mat kernel = cv::Mat::ones(kernel_height, kernel_width, CV_64FC1);

    // Computes the uniform kernel
    const double kernel_coefficient = 1 / static_cast<double>(kernel_height * kernel_width);
    for (int i = 0; i < kernel_height; i++)
        for (int j = 0; j < kernel_width; j++)
            kernel.at<double>(i, j) *= kernel_coefficient;
    
    // Performs the convolution
    cv::Mat output_image = Convolve(input_image_, kernel);

    return output_image;

}


cv::Mat Image::HighPassFilter() const
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
    cv::Mat d_height = Convolve(input_image_, kernel_height);
    cv::Mat d_width = Convolve(input_image_, kernel_width);

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

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


cv::Mat Image::BandPassFilter(double central_freq, double band_width) const
{

    const int image_height = input_image_.rows;
    const int image_width = input_image_.cols;

    cv::Mat input_image_double = ConvertUchar2DoubleC1(input_image_); 

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


cv::Mat Image::GaussianFilter(int kernel_height, int kernel_width, double kernel_sigma) const
{

    cv::Mat kernel = cv::Mat::zeros(kernel_height, kernel_width, CV_64FC1);

    const int half_kheight = kernel_height / 2;
    const int half_kwidth = kernel_width / 2;

    // The Gaussian filter formula: value = coefficient1 * e^((-(i - half_kheight)^2 - (j - half_kwidth)^2) * coefficient2)
    const double coefficient1 = 1.0 / (2 * Image::PI_ * kernel_sigma * kernel_sigma);
    const double coefficient2 = 1.0 / (2 * kernel_sigma * kernel_sigma);

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
            current_kernel_value = coefficient1 * pow(Image::NATURAL_CONSTANT_, (-offset_i - offset_j) * coefficient2);
            kernel.at<double>(i, j) = current_kernel_value;
            sum += current_kernel_value;
        }
    }

    for (int i = 0; i < kernel_height; i++)
        for (int j = 0; j < kernel_width; j++)
            kernel.at<double>(i, j) /= sum;
    
    // Performs the convolution
    cv::Mat output_image = Convolve(input_image_, kernel);

    return output_image;

}


cv::Mat Image::LaplacianFilter() const
{

    // Computes the Laplacian Kernel
    cv::Mat kernel = cv::Mat::zeros(3, 3, CV_64FC1);
    kernel.at<double>(0, 1) = -1.0; kernel.at<double>(1, 0) = -1.0;
    kernel.at<double>(1, 2) = -1.0; kernel.at<double>(2, 1) = -1.0;
    kernel.at<double>(1, 1) = 4.0;

    // Computes the convolution
    cv::Mat output_image = Convolve(input_image_, kernel);

    return output_image;

}












