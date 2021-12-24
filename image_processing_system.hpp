/********************************************************************************* 
 
  * FileName:       image_processing_system.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The header file for the class ImageProcessingSystem
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "image_io.hpp"
#include "image_type_conversion.hpp"
#include "image_enhancement.hpp"
#include "geometric_transform.hpp"
#include "filtering.hpp"
#include "menu.hpp"


class ImageProcessingSystem
{
    private:
        ImageIO* image_io_;
        ImageEnhancement* image_enhancement_;
        GeometricTransform* geometric_transform_;
        Filtering* filtering_;
        Menu* menu_;
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
    
    public:
        /*
        * The constructor
        * @ Parameter:
        *       file_name:    The file name of the input image
        */
        ImageProcessingSystem(const std::string& file_name);

        /*
        * The destructor
        */
        ~ImageProcessingSystem();

        /*
        * Runs the system
        */
        cv::Mat Run();

};


