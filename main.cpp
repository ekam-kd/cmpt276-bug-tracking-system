/* 
 * File:   main.cpp
 * Author: Qiraa Qadri
 * Created: June 2024
 * Version 1.0
 * Purpose: Bug Tracking System for AAA Inc. as a project for CMPT 276
*/

#include <iostream>
#include <string>
#include "helper_funcs.hpp"
//#include "testFileOps.cpp"
using namespace std;

int main()
{   
    start_up(); // initialize the system and database files
    string selection_one; // intialize selection variable
    bool sys_run = true; // boolean to keep the system running

    // main menu loop
    while(sys_run){ 
        system("clear"); // clear the screen

        // main menu
        cout << "-----------------------------------\n";
        cout << "Welcome to the Bug Tracking System!" << endl;
        cout << "Please select one of the following to get started:\n " << endl;
        cout << "-----------------------------------\n";
        cout << "-> New Customer (1)" << endl;
        cout << "-> Existing Customer (2)" << endl;
        cout << "-> Exit (3)" << endl;
        cout << "-----------------------------------\n\n";
        cout << "Selection: "; // prompt user for selection

        // get user selection

        cin >> selection_one;

        // check user selection -> call appropriate submenu / function
        if(selection_one == "1"){
            // register new customer
            register_customer();
        } else if(selection_one == "2"){
            // existing customer
            bool employee = false; // boolean to check if user is an employee
            system("clear"); // clear the screen
            // check if user is an employee, loops for possible invalid input
            while(1){
                cout << "\nAre you an employee of AAA Inc.? (Y/N): ";
                string emp1;
                cin >> emp1;  
                if(emp1[0] == 'Y' || emp1[0] == 'y'){
                    string temp_name;
                    char emp_name[MAX_NAME];
                    cout << "Enter your name: ";
                    getline(cin >> ws, temp_name);
                    strcpy(emp_name, temp_name.c_str());
                    if (!check_employee(emp_name)) {
                        employee = false;
                        continue;
                    } else {
                        employee = true;
                        break;
                    }
                } else if(emp1[0] == 'N' || emp1[0] == 'n'){
                    employee = false;
                    break;
                } else{
                    cout << "Invalid input, please try again" << endl;
                }
            }

            // submenu for existing customers
            cout << "\nPlease Select one of the following actions:" << endl;
            cout << "-----------------------------------\n\n";
            cout << "-> Return (0)" << endl;
            cout << "-> Create a Change Request (1)" << endl;
            cout << "-> Check Change Items (2)" << endl;

            // menu options for employees
            if(employee){
                cout << "-> Register a New Product (3)" << endl;
                cout << "-> Edit Change Item (4)" << endl;
                cout << "-> Send out new Product Release (5)" << endl;
                cout << "-> See all Pending Change Items (6)" << endl;
                cout << "-> Send out Report for Change Item (7)" << endl;
            }
            cout << "-----------------------------------\n\n";
            string selection_two; // intialize selection variable
            cout << "Selection: "; // prompt user for selection
            cin >> selection_two; // get user selection

            // check user selection -> call appropriate submenu / function
            if(employee){ // if user is an employee -> call employee functions
                if(selection_two == "0"){
                    cout << "Returning to main menu..." << endl;
                    sleep(1);
                } else if(selection_two == "1"){
                    create_change_request();
                } else if(selection_two == "2"){
                    check_change_item();
                } else if(selection_two == "3"){
                    register_product();
                } else if(selection_two == "4"){
                    edit_change_item();
                } else if(selection_two == "5"){
                    send_new_product_release();
                } else if(selection_two == "6"){
                    see_all_pending_change_items();
                } else if(selection_two == "7"){
                    send_report();
                }
                else{
                    cout << "Invalid selection. Returning to main menu." << endl;
                    sleep(1);
                }
            } else{ // if user is not an employee -> call customer functions
                if(selection_two == "0"){ 
                    cout << "Returning to main menu..." << endl;
                    sleep(1);
                } else if(selection_two == "1"){
                    create_change_request(); // create a change request
                } else if(selection_two == "2"){
                    check_change_item(); // check change items
                } else{
                    cout << "Invalid selection. Returning to main menu." << endl;
                    sleep(1);
                }
            }
        } else if(selection_one == "3"){
            system("clear"); // clear the screen
            cout << "-----------------------------------\n";
            cout << "Thank you for using the Bug Tracking System!" << endl;
            cout << "-----------------------------------\n\n";
            sys_run = false; // terminate UI loop
        } else {
            system("clear");
            cout << "Invalid selection, please try again" << endl;
            sleep(1);
        }

    }
    shut_down(); // close the system and database files
    return 0;
}

