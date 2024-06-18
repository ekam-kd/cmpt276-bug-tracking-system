/* 
 * File:   main.cpp
 * Author: Qiraa Qadri
 * Created: June 2024
 * Purpose: Bug Tracking System for AAA Inc. as a project for CMPT 276
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{   
    int selection_one = -1;
    long int phone_number;
    string cus_fname, cus_lname, cus_email, emp_department;
    bool sys_run = true;
    bool employee = false;
    while(sys_run){ 
        cout << "Welcome to the Bug Tracking System!" << endl;
        cout << "Please select one of the following to get started: " << endl;
        cout << "-> New Customer (1)" << endl;
        cout << "-> Existing Customer (2)" << endl;
        cout << "-> Exit (3)" << endl;
        cout << "Selection: ";
        cin >> selection_one;
        if(selection_one == 1){
            cout << "New Customer Menu:" << endl;
            cout << "Note that this is a placeholder for the registration process." << endl;
            cout << "Are you an employee of AAA Inc.? (Y/N): ";
            char emp;
            cin >> emp;
            if(emp == 'Y' || emp == 'y'){
                employee = true;
            }
            
            cout << "Please Enter Your Name:" << endl;
            cout << "Note that customer name must be in the format of Firstname Lastname" << endl;
            cout << "\nFirst Name: ";
            cin >> cus_fname;
            cout << "Last Name: ";
            cin >> cus_lname;
            cout << "\nPlease enter your email address" << endl;
            cout << "Email: ";
            cin >> cus_email;
            cout << "\nPlease enter your phone number" << endl;
            cout << "Note that phone number must be in the format of +1(234)-567-8910 -> 12345678910" << endl;
            cout << "Phone: ";
            cin >> phone_number;
            if(employee){
                cout << "\nPlease enter your department: ";
                cin >> emp_department;
            } 
            cout << "\nPlease confirm the following information:" << endl;
            cout << "\nName: " << cus_fname << " " << cus_lname << endl;
            cout << "Email: " << cus_email << endl;
            cout << "Phone: " << phone_number << endl;
            if(employee){
                cout << "Department: " << emp_department << endl;
            }
            cout << "\nIs this information correct? (Y/N): ";
            char confirm;
            cin >> confirm;
            if(confirm == 'Y' || confirm == 'y'){
                cout << "\nThank you for registering with us!" << endl;
                cout << "You will be returned to main menu" << endl;
            } else{
                cout << "\nUnable to register new Customer, please try again" << endl;
            }
        } else if(selection_one == 2){
            cout << "\nAre you an employee of AAA Inc.? (Y/N): ";
            char emp1;
            cin >> emp1;
            if(emp1 == 'Y' || emp1 == 'y'){
                employee = true;
            }
            cout << "\nPlease Select one of the following actions:" << endl;
            cout << "-> Exit (0)" << endl;
            cout << "-> Report a Bug (1)" << endl;
            cout << "-> Check Bug Status (2)" << endl;
            if(employee){
                cout << "-> Register a New Product (3)" << endl;
                cout << "-> Check current Product Release (4)" << endl;
                cout << "-> Confirm Change Request (5)" << endl;
                cout << "-> Resolve Change Item (6)" << endl;
                cout << "-> Check Change Status (7)" << endl;
                cout << "-> Edit Change Item Priority (8)" << endl;
                cout << "-> Make Feature Request (9)" << endl;
                cout << "-> Send out new Product Release (10)" << endl;
            }
        } else if(selection_one == 3){
            cout << "Thank you for using the Bug Tracking System!" << endl;
            sys_run = false;
        } else{
            cout << "Invalid selection, please try again" << endl;
        }

    }
    return 0;
}

