/********************************************************************************* 
 
  * FileName:       unit_test.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.2.1
  * Description:    The implementation for the class UnitTest
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "../include/unit_test.hpp"


void UnitTest::TestMapDouble2Uchar()
{

    uchar n1 = image_->MapDouble2Uchar(256.0);
    uchar n2 = image_->MapDouble2Uchar(253.0);
    uchar n3 = image_->MapDouble2Uchar(-3.0);

    uchar n1_correct = static_cast<uchar>(255);
    uchar n2_correct = static_cast<uchar>(253);
    uchar n3_correct = static_cast<uchar>(0);

    if (n1 == n1_correct && n2 == n2_correct && n3 == n3_correct)
        std::cout << "TestMapDouble2Uchar() passed!\n";
    else
        std::cout << "TestMapDouble2Uchar() failed!\n";

}


void UnitTest::TestConvolve()
{

    cv::Mat kernel = cv::Mat::ones(3, 3, CV_64FC1);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            kernel.at<double>(i, j) = 0.1;
    
    cv::Mat convolved_image = image_->Convolve(image_->GetImage(), kernel);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    for (int i = 0; i < 6; i++)
    {
        correct.at<uchar>(i, 0) = 6 * (i + 1);
        correct.at<uchar>(i, 6) = 6 * (i + 1);
        for (int j = 1; j < 6; j++)
        {
            correct.at<uchar>(i, j) = 9 * (i + 1);
        }
    }
    correct.at<uchar>(6, 0) = 26;
    correct.at<uchar>(6, 6) = 26;
    for (int j = 1; j < 6; j++)
        correct.at<uchar>(6, j) = 39;
    
    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(convolved_image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestConvolve() passed!\n";
    else
        std::cout << "TestConvolve() failed!\n";

}


void UnitTest::TestGetImageHeight()
{
    if (image_->GetImageHeight() == 7)
        std::cout << "TestGetImageHeight() passed!\n";
    else
        std::cout << "TestGetImageHeight() failed!\n";
}


void UnitTest::TestGetImageWidth()
{
    if (image_->GetImageWidth() == 7)
        std::cout << "TestGetImageWidth() passed!\n";
    else
        std::cout << "TestGetImageWidth() failed!\n";
}


void UnitTest::TestResize()
{

    cv::Mat resized_image = image_->Resize(0.3, 0.3);

    cv::Mat correct = cv::Mat::zeros(2, 2, CV_8UC1);
    correct.at<uchar>(0, 0) = 30;
    correct.at<uchar>(0, 1) = 30;
    correct.at<uchar>(1, 0) = 70;
    correct.at<uchar>(1, 1) = 70;

    double mean_squared_error = 0.0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            mean_squared_error += pow(resized_image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 4;
    if (mean_squared_error < 0.00001)
        std::cout << "TestResize() passed!\n";
    else
        std::cout << "TestResize() failed!\n";

}


void UnitTest::TestRotate()
{

    cv::Mat rotated_image = image_->Rotate(90);

    cv::Mat correct = cv::Mat::zeros(10, 10, CV_8UC1);

    uchar values[7] = {70, 60, 50, 40, 40, 30, 20};
    for (int i = 2; i < 9; i++)
        for (int j = 2; j < 9; j++)
            correct.at<uchar>(i, j) = values[j - 2];

    double mean_squared_error = 0.0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            mean_squared_error += pow(rotated_image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 100;
    if (mean_squared_error < 0.00001)
        std::cout << "TestRotate() passed!\n";
    else
        std::cout << "TestRotate() failed!\n";

}


void UnitTest::TestFlipLeftRight()
{
    
    cv::Mat flipped_image = image_->FlipLeftRight();

    cv::Mat correct = image_->GetImage().clone();

    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(flipped_image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestFlipLeftRight() passed!\n";
    else
        std::cout << "TestFlipLeftRight() failed!\n";

}


void UnitTest::TestFlipUpDown()
{

    cv::Mat flipped_image = image_->FlipUpDown();

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar values[7] = {70, 60, 50, 40, 30, 20, 10};
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            correct.at<uchar>(i, j) = values[i];
    
    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(flipped_image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestFlipUpDown() passed!\n";
    else
        std::cout << "TestFlipUpDown() failed!\n";

}


void UnitTest::TestBrightnessTransform()
{

    cv::Mat image = image_->BrightnessTransform(30);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar values[7] = {40, 50, 60, 70, 80, 90, 100};
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            correct.at<uchar>(i, j) = values[i];
    
    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestBrightnessTransform() passed!\n";
    else
        std::cout << "TestBrightnessTransform() failed!\n";

}


void UnitTest::TestInverseTransform()
{

    cv::Mat image = image_->InverseTransform();

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar values[7] = {245, 235, 225, 215, 205, 195, 185};
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            correct.at<uchar>(i, j) = values[i];
    
    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestInverseTransform() passed!\n";
    else
        std::cout << "TestInverseTransform() failed!\n";

}


void UnitTest::TestGammaTransform()
{

    cv::Mat image = image_->GammaTransform(1.1, 1.1);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar values[7] = {13, 29, 46, 63, 81, 99, 117};
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            correct.at<uchar>(i, j) = values[i];
    
    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestGammaTransform() passed!\n";
    else
        std::cout << "TestGammaTransform() failed!\n";

}


void UnitTest::TestLogTransform()
{

    cv::Mat image = image_->LogTransform(7);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar values[7] = {16, 21, 24, 25, 27, 28, 29};
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            correct.at<uchar>(i, j) = values[i];
    
    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestLogTransform() passed!\n";
    else
        std::cout << "TestLogTransform() failed!\n";

}


void UnitTest::TestNormalizationTransform()
{

    cv::Mat image = image_->NormalizationTransform(20, 69);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar values[7] = {0, 0, 52, 104, 156, 208, 255};
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            correct.at<uchar>(i, j) = values[i];
    
    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestNormalizationTransform() passed!\n";
    else
        std::cout << "TestNormalizationTransform() failed!\n";

}


void UnitTest::TestThresholdTransform()
{

    cv::Mat image = image_->ThresholdTransform(50);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar values[7] = {0, 0, 0, 0, 50, 60, 70};
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            correct.at<uchar>(i, j) = values[i];
    
    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestThresholdTransform() passed!\n";
    else
        std::cout << "TestThresholdTransform() failed!\n";

}


void UnitTest::TestWindowTransform()
{

    cv::Mat image = image_->WindowTransform(30, 60);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar values[7] = {0, 0, 30, 40, 50, 60, 0};
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            correct.at<uchar>(i, j) = values[i];
    
    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestWindowTransform() passed!\n";
    else
        std::cout << "TestWindowTransform() failed!\n";

}


void UnitTest::TestLowPassFilter()
{

    cv::Mat image = image_->LowPassFilter(3, 3);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar main_values[7] = {10, 19, 29, 40, 50, 60, 43};
    uchar side_values[7] = {6, 13, 19, 26, 33, 40, 28};
    for (int i = 0; i < 7; i++)
    {
        correct.at<uchar>(i, 0) = side_values[i];
        correct.at<uchar>(i, 6) = side_values[i];
        for (int j = 1; j < 6; j++)
            correct.at<uchar>(i, j) = main_values[i];
    }

    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestLowPassFilter() passed!\n";
    else
        std::cout << "TestLowPassFilter() failed!\n";

}


void UnitTest::TestHighPassFilter()
{

    cv::Mat image = image_->HighPassFilter();

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    for (int i = 0; i < 6; i++)
        for (int j = 1; j < 6; j++)
            correct.at<uchar>(i ,j) = 82;
    for (int i = 0; i < 6; i++)
        correct.at<uchar>(i, 6) = 61;
    for (int j = 1; j < 7; j++)
        correct.at<uchar>(6, j) = 0;
    correct.at<uchar>(0, 0) = 74;
    correct.at<uchar>(1, 0) = 103;
    correct.at<uchar>(2, 0) = 138;
    correct.at<uchar>(3, 0) = 176;
    correct.at<uchar>(4, 0) = 215;
    correct.at<uchar>(5, 0) = 255;
    correct.at<uchar>(6, 0) = 206;

    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestHighPassFilter() passed!\n";
    else
        std::cout << "TestHighPassFilter() failed!\n";

}


void UnitTest::TestBandPassFilter()
{

    cv::Mat image = image_->BandPassFilter(15, 10);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            correct.at<uchar>(i, j) = 255;

    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestBandPassFilter() passed!\n";
    else
        std::cout << "TestBandPassFilter() failed!\n";

}


void UnitTest::TestGaussianFilter()
{

    cv::Mat image = image_->GaussianFilter(3, 3, 1);

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar main_values[7] = {10, 20, 30, 40, 50, 60, 48};
    uchar side_values[7] = {7, 14, 21, 29, 36, 43, 34};
    for (int i = 0; i < 7; i++)
    {
        correct.at<uchar>(i, 0) = side_values[i];
        correct.at<uchar>(i, 6) = side_values[i];
        for (int j = 1; j < 6; j++)
            correct.at<uchar>(i, j) = main_values[i];
    }

    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestGaussianFilter() passed!\n";
    else
        std::cout << "TestGaussianFilter() failed!\n";

}


void UnitTest::TestLaplacianFilter()
{

    cv::Mat image = image_->LaplacianFilter();

    cv::Mat correct = cv::Mat::zeros(7, 7, CV_8UC1);
    uchar side_values[7] = {10, 20, 30, 40, 50, 60, 150};
    for (int i = 0; i < 7; i++)
    {
        correct.at<uchar>(i, 0) = side_values[i];
        correct.at<uchar>(i, 6) = side_values[i];
    }
    for (int j = 1; j < 6; j++)
        correct.at<uchar>(6, j) = 80;

    double mean_squared_error = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            mean_squared_error += pow(image.at<uchar>(i, j) - correct.at<uchar>(i, j), 2);
    
    mean_squared_error /= 49;
    if (mean_squared_error < 0.00001)
        std::cout << "TestLaplacianFilter() passed!\n";
    else
        std::cout << "TestLaplacianFilter() failed!\n";

}


UnitTest::UnitTest()
{

    cv::Mat image = cv::Mat::zeros(7, 7, CV_8UC1);
    const int image_height = image.rows;
    const int image_width = image.cols;

    uchar values[7] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; i < image_height; i++)
        for (int j = 0; j < image_width; j++)
            image.at<uchar>(i, j) = values[i];

    image_ = std::make_unique<Image>(image);

}


UnitTest::~UnitTest()
{
}


void UnitTest::RunTest()
{
    TestMapDouble2Uchar();
    TestConvolve();
    TestGetImageHeight();
    TestGetImageWidth();
    TestResize();
    TestRotate();
    TestFlipLeftRight();
    TestFlipUpDown();
    TestBrightnessTransform();
    TestInverseTransform();
    TestGammaTransform();
    TestLogTransform();
    TestNormalizationTransform();
    TestThresholdTransform();
    TestWindowTransform();
    TestLowPassFilter();
    TestHighPassFilter();
    TestBandPassFilter();
    TestGaussianFilter();
    TestLaplacianFilter();
}


