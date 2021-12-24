/********************************************************************************* 
 
  * FileName:       menu.hpp
  * Author:         Zichen Zhang, Mingshuai Li
  * Version:        V2.00
  * Date:           2021.12.23
  * Description:    The header file for the class Menu
  * Project:        The group project for the WS2021 course IN1503 Advanced Programming

**********************************************************************************/


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

};


