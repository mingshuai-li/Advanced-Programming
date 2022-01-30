/********************************************************************************* 
 
  * FileName:       test.cpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.2.1
  * Description:    The test file
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#include "../include/unit_test.hpp"


int main(int argc, char** argv)
{

    std::unique_ptr<UnitTest> tests = std::make_unique<UnitTest>();

    tests->RunTest();

    return 0;

}


