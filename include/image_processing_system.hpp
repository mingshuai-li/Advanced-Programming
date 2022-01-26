/********************************************************************************* 
 
  * FileName:       image_processing_system.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.1.29
  * Description:    The header file for the class ImageProcessingSystem
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#ifndef IMAGE_PROCESSING_SYSTEM_H
#define IMAGE_PROCESSING_SYSTEM_H


#include <memory>
#include "image_io.hpp"
#include "image_type_conversion.hpp"
#include "image_enhancement.hpp"
#include "geometric_transform.hpp"
#include "filtering.hpp"
#include "menu.hpp"


class ImageProcessingSystem
{

    private:
        std::unique_ptr<ImageIO> image_io_;
        std::unique_ptr<ImageEnhancement> image_enhancement_;
        std::unique_ptr<GeometricTransform> geometric_transform_;
        std::unique_ptr<Filtering> filtering_;
        std::unique_ptr<Menu> menu_;
        cv::Mat input_image_;
        cv::Mat output_image_;
        /*
        * Runs the image enhancement section of the system
        */
        void RunImageEnhancement();

        /*
        * Runs the geometric transform section of the system
        */
        void RunGeometricTransform();

        /*
        * Runs the filtering section of the system
        */
        void RunFiltering();

        /*
        * Updates the input_image_ using the current output_image_
        */
        void UpdateInputImage();

        /*
        * Updates the input_image_ using the image file
        * @ Parameter:
        *       file_name:    The file name of the new input image
        */
        void UpdateInputImage(const std::string& file_name);

        /*
        * Runs the update input image section of the system
        */
        void RunUpdateInputImage();

        /*
        * Displays the current input image in the system
        */
        void DisplayCurrentInputImage() const;

        /*
        * Displays the current input image in the system
        */
        void DisplayCurrentOutputImage() const;
    
    public:
        /*
        * The constructor
        * @ Parameter:
        *       file_name:    The file name of the input image
        */
        ImageProcessingSystem(const std::string& file_name);

        /*
        * The copy constructor
        * @ Parameter:
        *       image_processing_system:    The image processing system object that is going to be copied
        */
        ImageProcessingSystem(const ImageProcessingSystem& image_processing_system);

        /*
        * The destructor
        */
        ~ImageProcessingSystem();

        /*
        * Runs the system
        */
        cv::Mat Run();

};


#endif


