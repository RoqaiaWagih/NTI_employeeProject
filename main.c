/**
 ****************************************************************************************************
 * @file           : Header.h
 * @author         : Roqaia Khalid Wagih
 * @brief          : The program is a simple console-based employee management system written in C.
                   It allows users to perform basic operations such as entering new employee details,
                   displaying the employee database,and searching for employees by various options.
 ****************************************************************************************************
 */

 /* ********************** Includes Section Start ********************** */
#include "header.h"

/* ********************** Global Variables Section Start ************** */
employee e[10];
employee *ptr=e;
int main()
{
    MainMenu(ptr);
    return 0;
}
