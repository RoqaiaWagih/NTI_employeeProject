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
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Defines a structure named employee
//to store information about an employee,
//including name, salary, and ID.
typedef struct
{
    char name[50];
    float salary;
    int id;


}employee;

typedef enum menu{
 Enter_Employee=1,
 Display_DataBase,
 search
}Menu;


extern employee e[10];
extern employee *ptr;






/* ********************** Sub-Program Declerations Section Start ******* */
void MainMenu(employee *e);
void EnterEmployee(employee *e);
void DisplayDataBase(employee *e);
void Search(employee *e);

void ClearInputBuffer(void);
#endif // HEADER_H_INCLUDED
