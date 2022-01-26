/********************************************************************************* 
 
  * FileName:       image.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.1.29
  * Description:    The header file for the class Image
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#ifndef IMAGE_H
#define IMAGE_H


#include <iostream>
#include <opencv2/core/core.hpp>


class GeometricTransform
{

    private:
        static const double PI_;

    public:
        /*
        * Resizes the image to the given scale
        * @ Parameter:
        *       input_image:    The input image reference
        *       height_scaling: The scaling factor alongside the height of the output image
        *       width_scaling:  The scaling factor alongside the width of the output image
        *       output_image:   The output image reference
        */
        cv::Mat Resize(const cv::Mat& input_image, double height_scaling, double width_scaling);


        /*
        * Rotates the image
        * @ Parameter:
        *       input_image:    The input image reference
        *       angle:          The angle that the input image rotates
        *       output_image:   The output image reference
        */
        cv::Mat Rotate(const cv::Mat& input_image, double angle);


        /*
        * Flips the image left to right
        * @ Parameter:
        *       input_image:    The input image reference
        *       output_image:   The output image reference
        */
        cv::Mat FlipLeftRight(const cv::Mat& input_image);


        /*
        * Flips the image up to down
        * @ Parameter:
        *       input_image:    The input image reference
        *       output_image:   The output image reference
        */
        cv::Mat FlipUpDown(const cv::Mat& input_image);

};










#endif









