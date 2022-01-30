/********************************************************************************* 
 
  * FileName:       unit_test.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.2.1
  * Description:    The header file for the class UnitTest
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#ifndef UNIT_TEST_H
#define UNIT_TEST_H


#include <memory>
#include "image.hpp"


class UnitTest
{

    private:
        std::unique_ptr<Image> image_;

        /*
        * Tests MapDouble2Uchar()
        */
        void TestMapDouble2Uchar();

        /*
        * Tests the Convolve()
        */
        void TestConvolve();

        /*
        * Tests the GetImageHeight()
        */
        void TestGetImageHeight();

        /*
        * Tests the GetImageWidth()
        */
        void TestGetImageWidth();

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
    
    public:
        /*
        * The constructor
        */
        UnitTest();

        /*
        * The destructor
        */
        ~UnitTest();

        /*
        * Runs the unit tests
        */
        void RunTest();

};


#endif


