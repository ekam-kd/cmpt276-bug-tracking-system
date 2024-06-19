/* 
 * File:   main.cpp
 * Author: Qiraa Qadri
 * Created: June 2024
 * Purpose: Bug Tracking System for AAA Inc. as a project for CMPT 276
*/

#include <iostream>
#include <string>
#include "helper_funcs.hpp"
using namespace std;
int main()
{   
    int selection_one = -1;
    bool sys_run = true;
    while(sys_run){ 
        system("clear");
        cout << "-----------------------------------\n";
        cout << "Welcome to the Bug Tracking System!" << endl;
        cout << "Please select one of the following to get started:\n " << endl;
        cout << "-----------------------------------\n";
        cout << "-> New Customer (1)" << endl;
        cout << "-> Existing Customer (2)" << endl;
        cout << "-> Exit (3)" << endl;
        cout << "-----------------------------------\n\n";
        cout << "Selection: ";
        cin >> selection_one;
        if(selection_one == 1){
            register_customer();
        } else if(selection_one == 2){
            bool employee = false;
            
            while(1){
                system("clear");
                cout << "\nAre you an employee of AAA Inc.? (Y/N): ";
                string emp1;
                cin >> emp1;  
                if(emp1[0] == 'Y' || emp1[0] == 'y'){
                    employee = true;
                    break;
                } else if(emp1[0] == 'N' || emp1[0] == 'n'){
                    employee = false;
                    break;
                } else{
                    cout << "Invalid selection, please try again" << endl;
                }
            }
            cout << "\nPlease Select one of the following actions:" << endl;
            cout << "-----------------------------------\n\n";
            cout << "-> Return (0)" << endl;
            cout << "-> Report a Bug (1)" << endl;
            cout << "-> Check Bug Status (2)" << endl;
            if(employee){
                cout << "-> Register a New Product (3)" << endl;
                cout << "-> Check current Product Release (4)" << endl;
                cout << "-> Confirm Change Request (5)" << endl;
                cout << "-> Resolve Change Item (6)" << endl;
                cout << "-> Check Change Item Status (7)" << endl;
                cout << "-> Edit Change Item (8)" << endl;
                cout << "-> Make Feature Request (9)" << endl;
                cout << "-> Send out new Product Release (10)" << endl;
                cout << "-> See all Pending Change Items (11)" << endl;
                cout << "-> Search from all Change Items (12)" << endl;
                // cout << "-> See all customers per Change Item ()" << endl;
            }
            cout << "-----------------------------------\n\n";
            int selection_two = -1;
            cout << "Selection: ";
            cin >> selection_two;
            if(employee){
                if(selection_two == 0){
                    cout << "Returning to main menu..." << endl;
                } else if(selection_two == 1){
                    report_bug();
                } else if(selection_two == 2){
                    check_bug_status();
                } else if(selection_two == 3){
                    register_product();
                } else if(selection_two == 4){
                    check_product_release();
                } else if(selection_two == 5){
                    confirm_change_request();
                } else if(selection_two == 6){
                    resolve_change_request();
                } else if(selection_two == 7){
                    check_change_request_status();
                } else if(selection_two == 8){
                    edit_change_request_priority();
                } else if(selection_two == 9){
                    make_feature_request();
                } else if(selection_two == 10){
                    send_new_product_release();
                } else if(selection_two == 11){
                    see_all_pending_change_items();
                } else if(selection_two == 12){
                    search_all_change_items();
                } 
                else{
                    cout << "Invalid selection, please try again" << endl;
                }
            } else{
                if(selection_two == 0){
                    system("clear");
                    cout << "-----------------------------------\n";
                    cout << "Thank you for using the Bug Tracking System!" << endl;
                    cout << "-----------------------------------\n\n";
                    sys_run = false;
                } else if(selection_two == 1){
                    report_bug();
                } else if(selection_two == 2){
                    check_bug_status();
                } else{
                    cout << "Invalid selection, please try again" << endl;
                }
            }
        } else if(selection_one == 3){
            system("clear");
            cout << "-----------------------------------\n";
            cout << "Thank you for using the Bug Tracking System!" << endl;
            cout << "-----------------------------------\n\n";
            sys_run = false;
        } else{
            cout << "Invalid selection, please try again" << endl;
        }

    }
    return 0;
}

