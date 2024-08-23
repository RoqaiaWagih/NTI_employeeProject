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


//The MainMenu function serves as main function for the employee management system.
//It displays a user-friendly menu with options for different operations related to employee management.
//The menu includes choices to:
//1.Enter details for a new employee.
//2.Display the existing database of employees.
//3.Search for a specific employee by ID, salary, or name. Exit the program.
//The function continuously asks the user for input until they choose to exit (entering '0').
void MainMenu(employee *e)
{

    Menu choice;
    do{
    printf("***_______choices_______***\n");
    printf("1.Enter New Employee\n");
    printf("2.Display Database Of the company\n");
    printf("3.Search for employee\n");
    printf("_____Enter 0 to exit_____");
    scanf("%d",(int*)&choice);
    //enum assign

    //enum Menu CHOICE =choice;
    switch(choice){
       case 1:
          EnterEmployee(ptr);
          break;
       case 2:
          DisplayDataBase(ptr);
          break;
       case 3:
          Search(ptr);
          break;
       default:
           printf("Invalid option Please try again");
    }
    }
    while(choice!=0);



}
void ClearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//Allows the user to enter details for a new employee.
//inputs are = name, salary, and ID,
//and increments the employee counter. [i++]
void EnterEmployee(employee *e) {
    bool invalidInput;
    static int i = 0;
    system("cls");

    printf("***_____number of employees = %d_____***\n", i);
    printf("***_____employees:%d_____***\n", i);

    do {
        printf("please enter employee name: ");
        if ((scanf(" %[^\n]", e[i].name) != 1) || (strlen(e[i].name) >= 50)) {
            printf("Invalid input for Name.\n");
            invalidInput = true;
        } else {
            invalidInput = false;
        }
        ClearInputBuffer();
    } while (invalidInput);

    do {
        printf("please enter employee salary: ");
        if ((scanf("%f", &e[i].salary) != 1) || e[i].salary < 6000) {
            printf("Invalid input for employee salary.\n");
            invalidInput = true;
        } else {
            invalidInput = false;
        }
        ClearInputBuffer();
    } while (invalidInput);

    do {
        printf("please enter employee Id [1-200]: ");
        if (scanf("%d", &e[i].id) != 1 || !(e[i].id > 0 && e[i].id < 201)) {
            printf("Invalid input for employee ID.\n");
            invalidInput = true;
        } else {
            invalidInput = false;
        }
        ClearInputBuffer();
    } while (invalidInput);

    printf("Employee details entered successfully.\n");
    printf("______________________________________\n");
    printf("______________________________________\n");

    i++;
}

//Displays the information of all employees
//in a  format looks like excel sheet on the console screen.
void DisplayDataBase(employee *e){
    system("cls");

   printf("Employee\tName\t\tSalary\t\tID\n");
    printf("--------------------------------------------------\n");

for(int i=0;i<10;i++){
    printf("Employee %d\t%-15s\t$%.2f\t%d\n", i, e[i].name, e[i].salary, e[i].id);

}


}

//Provides options to search for an employee
//by ID, salary, or name.
//Displays the found employee's details
//or a message if not found.
void Search(employee *e) {
    int searchId;
    float searchSalary;
    char searchName[50];
    system("cls");

    printf("***_____Search Employee_____***\n");
    printf("1. Search by ID\n");
    printf("2. Search by Salary\n");
    printf("3. Search by Name\n");
    printf("Enter your choice: ");

    int searchChoice;
    scanf("%d", &searchChoice);

    switch (searchChoice) {
        case 1:
            system("cls");
            printf("Enter Employee ID to search: ");
            scanf("%d", &searchId);
            for (int i = 0; i < 10; i++) {
                if (e[i].id == searchId) {
                    printf("Employee found:\n");
                    printf("Name: %s\n", e[i].name);
                    printf("Salary: $%.2f\n", e[i].salary);
                    printf("ID: %d\n", e[i].id);
                    return;
                }
            }
            printf("Employee with ID %d not found.\n", searchId);




            break;

        case 2:
            system("cls");
            printf("Enter Employee Salary to search: ");
            scanf("%f", &searchSalary);
            for (int i = 0; i < 10; i++) {
                if (e[i].salary == searchSalary) {
                    printf("Employee found:\n");
                    printf("Name: %s\n", e[i].name);
                    printf("Salary: $%.2f\n", e[i].salary);
                    printf("ID: %d\n", e[i].id);
                    return;
                }
            }
            printf("Employee with Salary $%.2f not found.\n", searchSalary);
            break;

        case 3:
            system("cls");
            printf("Enter Employee Name to search: ");
            scanf(" %49[^\n]", searchName);
            for (int i = 0; i < 10; i++) {
                if (strcmp(e[i].name, searchName) == 0) {
                    printf("Employee found:\n");
                    printf("Name: %s\n", e[i].name);
                    printf("Salary: $%.2f\n", e[i].salary);
                    printf("ID: %d\n", e[i].id);
                    return;
                }
            }
            printf("Employee with Name %s not found.\n", searchName);
            break;

        default:
            printf("Invalid option for search.\n");
            break;
    }
}
