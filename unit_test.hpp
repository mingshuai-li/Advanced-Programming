/********************************************************************************* 
 
  * FileName:       unit_test.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The header file for the class UnitTest
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "image_io.hpp"
#include "image_type_conversion.hpp"
#include "image_enhancement.hpp"
#include "geometric_transform.hpp"
#include "filtering.hpp"


class UnitTest
{

    public:

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
        void LaplacianFilter();

};


