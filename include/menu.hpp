/********************************************************************************* 
 
  * FileName:       menu.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V3.00
  * Date:           2022.1.29
  * Description:    The header file for the class Menu
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


#ifndef MENU_H
#define MENU_H


#include <iostream>


class Menu
{

    public:
        /*
        * Displays the main menu
        * @ Return:
        *                       The users' choice
        */
        int MainMenu();

        /*
        * Displays the image enhancement section menu
        * @ Return:
        *                       The users' choice
        */
        int ImageEnhancementMenu();

        /*
        * Displays the geometric transform section menu
        * @ Return:
        *                       The users' choice
        */
        int GeometricTransformMenu();

        /*
        * Displays the filtering section menu
        * @ Return:
        *                       The users' choice
        */
        int FilteringMenu();

        /*
        * Displays the update input image section menu
        * @ Return:
        *                       The users' choice
        */
        int UpdateInputImageMenu();

};


#endif


