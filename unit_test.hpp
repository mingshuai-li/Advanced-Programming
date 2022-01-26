/********************************************************************************* 
 
  * FileName:       unit_test.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The header file for the various unit test classes
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include <memory>
#include "image_io.hpp"
#include "image_type_conversion.hpp"
#include "image_enhancement.hpp"
#include "geometric_transform.hpp"
#include "filtering.hpp"


class UnitTestIoAndTypeConversion
{

    public:
        std::unique_ptr<ImageIO> image_io_;
        cv::Mat input_image_;
        cv::Mat output_image_;

        /*
        * The constructor
        * @ Parameter:
        *       file_name:    The file name of the input image
        */
        UnitTestIoAndTypeConversion(const std::string& file_name);

        /*
        * The destructor
        */
        ~UnitTestIoAndTypeConversion();

        /*
        * Tests the ReadImage(), the DisplayImage() and the PrintImageInfo()
        */
        void TestImageIO();

        /*
        * Tests the ConvertRGB2GrayScale()
        */
        void TestConvertRGB2GrayScale();

        /*
        * Tests the ConvertUchar2DoubleC1()
        */
        void TestConvertUchar2DoubleC1();

        /*
        * Tests MapDouble2Uchar()
        */
        void TestMapDouble2Uchar();

};


class UnitTestImageEnhancement 
{

    public:
        std::unique_ptr<ImageIO> image_io_;
        cv::Mat input_image_;
        cv::Mat output_image_;
        std::unique_ptr<ImageEnhancement> image_enhancement_;

        /*
        * The constructor
        * @ Parameter:
        *       file_name:    The file name of the input image
        */
        UnitTestImageEnhancement(const std::string& file_name);

        /*
        * The destructor
        */
        ~UnitTestImageEnhancement();

        /*
        * Tests the BrightnessTransform()
        */
        void TestBrightnessTransform();

        /*
        * Tests the InverseTransform()
        */
        void TestInverseTransform();

        /*
        * Tests the GammaTransform()
        */
        void TestGammaTransform();

        /*
        * Tests the LogTransform()
        */
        void TestLogTransform();

        /*
        * Tests the NormalizationTransform()
        */
        void TestNormalizationTransform();

        /*
        * Tests the ThresholdTransform()
        */
        void TestThresholdTransform();

        /*
        * Tests the WindowTransform()
        */
        void TestWindowTransform();
     
};


class UnitTestGeometricTransform 
{

    public:
        std::unique_ptr<ImageIO> image_io_;
        cv::Mat input_image_;
        cv::Mat output_image_;
        std::unique_ptr<GeometricTransform> geometric_transform_;

        /*
        * The constructor
        * @ Parameter:
        *       file_name:    The file name of the input image
        */
        UnitTestGeometricTransform(const std::string& file_name);

        /*
        * The destructor
        */
        ~UnitTestGeometricTransform();

        /*
        * Tests the Resize()
        */
        void TestResize();

        /*
        * Tests the Rotate()
        */
        void TestRotate();

        /*
        * Tests the FlipLeftRight()
        */
        void TestFlipLeftRight();

        /*
        * Tests the FlipUpDown()
        */
        void TestFlipUpDown();

};


class UnitTestFiltering 
{
    public:
        std::unique_ptr<ImageIO> image_io_;
        cv::Mat input_image_;
        cv::Mat output_image_;
        std::unique_ptr<Filtering> filtering_;

        /*
        * The constructor
        * @ Parameter:
        *       file_name:    The file name of the input image
        */
        UnitTestFiltering(const std::string& file_name);

        /*
        * The destructor
        */
        ~UnitTestFiltering();

        /*
        * Tests the Convolve()
        */
        void TestConvolve();

        /*
        * Tests the LowPassFilter()
        */
        void TestLowPassFilter();

        /*
        * Tests the HighPassFilter()
        */
        void TestHighPassFilter();

        /*
        * Tests the BandPassFilter()
        */
        void TestBandPassFilter();

        /*
        * Tests the GaussianFilter()
        */
        void TestGaussianFilter();

        /*
        * Tests the LaplacianFilter()
        */
        void TestLaplacianFilter();

};


