/********************************************************************************* 
 
  * FileName:       unit_test.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V1.00
  * Date:           2021.11.29
  * Description:    The header file for the unit test functions 
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "image_io.hpp"


/*
* Tests the ReadImage()
*/
void TestReadImage();


/*
* Tests the DisplayImage()
*/
void TestDisplayImage();


/*
* Tests the PrintImageInfo()
*/
void TestPrintImageInfo();


/*
* Tests the BrightnessTransform()
*/
void BrightnessTransform();


/*
* Tests the InverseTransform()
*/
void InverseTransform();


/*
* Tests the GammaTransform()
*/
void GammaTransform();


/*
* Tests the LogTransform()
*/
void LogTransform();


/*
* Tests the NormalizationTransform()
*/
void NormalizationTransform();


/*
* Tests the ThresholdTransform()
*/
void ThresholdTransform();


/*
* Tests the WindowTransform()
*/
void WindowTransform();


/*
* Tests the Resize()
*/
void Resize();


/*
* Tests the Rotate()
*/
void Rotate();


/*
* Tests the FlipLeftRight()
*/
void FlipLeftRight();


/*
* Tests the FlipUpDown()
*/
void FlipUpDown();


