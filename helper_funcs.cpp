/* 
 * File:   helper_funcs.cpp
 * Author: Qiraa Qadri
 * Created: June 2024
 * Purpose: additional functions for the Bug Tracking System
*/

#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <limits>
#include "helper_funcs.hpp"
using namespace std;

#define MAX_NAME 100
#define MAX_DESCRIPTION 1000

// register new product
void register_product(){
    string product_name, product_version;
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Please enter the product name: ";
    cin >> product_name;
    cout << "\nPlease enter the product version: ";
    cin >> product_version;
    cout << "\n\nProduct " << product_name << " version " << product_version << " has been registered." << endl;
    cout << "You will be returned to main menu" << endl;
    sleep(2);
}
// register new customer
void register_customer(){
    system("clear");
    string cus_fname, cus_lname, cus_email, emp_department, phone_number;
    bool employee = false;
    // long int phone_number;

    cout << "-----------------------------------\n";
    cout << "New Customer Menu:" << endl;
    cout << "Note that this is a placeholder for the registration process." << endl;
    cout << "\n\nAre you an employee of AAA Inc.? (Y/N): ";
    char emp;
    cin >> emp;
    if(emp == 'Y' || emp == 'y'){
        employee = true;
    }
    
    cout << "\n\nPlease Enter Your Name:" << endl;
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
    cout << "\n\nPlease confirm the following information:" << endl;
    cout << "\n\nName: " << cus_fname << " " << cus_lname << endl;
    cout << "Email: " << cus_email << endl;
    cout << "Phone: " << phone_number << endl;
    if(employee){
        cout << "Department: " << emp_department << endl;
    }
    cout << "\n\nIs this information correct? (Y/N): ";
    char confirm;
    cin >> confirm;
    if(confirm == 'Y' || confirm == 'y'){
        cout << "\nThank you for registering with us!" << endl;
        cout << "You will be returned to main menu" << endl;
        sleep(2);
    } else{
        cout << "\nUnable to register new Customer, please try again" << endl;
    }
}
// report a bug
void report_bug(){
    char cus_name[MAX_NAME], bug_description[MAX_DESCRIPTION]; // [1000] and [100] are arbitrary values, can be changed to [10000] or [1000000
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Bug Report Menu:" << endl;
    cout << "Note that this is a placeholder for the bug reporting process." << endl;
    cout << "Please enter your name:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(cus_name, MAX_NAME-1);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n\nHello " << cus_name << ", please enter the bug description:\n";
    cin.get(bug_description, MAX_DESCRIPTION-1);
    cout << "\n\nBug has been reported." << endl;
    cout << "Thank you for reporting the bug! This bug request ID is XXXXX" << endl;  
    cout << "\nYou will be returned to main menu" << endl;
    sleep(2);
}
// check bug status
void check_bug_status(){
    long int bug_id;
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Bug Status Menu:" << endl;
    cout << "Note that this is a placeholder for the bug status checking process." << endl;
    cout << "\nPlease enter the bug ID: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> bug_id;
    cout << "\n\nBug ID " << bug_id << " is currently in <STATE> state." << endl;
    cout << "\nYou will be returned to main menu" << endl;
    sleep(2);
}
// check product release
void check_product_release(){
    char product_name[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Product Release Menu:" << endl;
    cout << "Note that this is a placeholder for the product release checking process." << endl;
    cout << "\nPlease enter the product name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> product_name;
    cout << "\nThe latest release of " << product_name << " is version <VERSION>." << endl;
    cout << "\nYou will be returned to main menu" << endl;
    sleep(2);
}
// confirm change request
void confirm_change_request(){
    long int change_id;
    int priority;
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Change Request Confirmation Menu:" << endl;
    cout << "Note that this is a placeholder for the change request confirmation process." << endl;
    cout << "\nPlease enter the change request ID: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> change_id;
    cout << "\nPlease enter the priority level (1-5) for this change request: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> priority;
    cout << "\n\nChange Request ID " << change_id << " has been confirmed with priority level " << priority << "." << endl;   
    cout << "\nYou will be returned to main menu" << endl;
    sleep(2); 
}
// check change request status
void check_change_request_status(){
    long int change_id;
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Change Request Status Menu:" << endl;
    cout << "Note that this is a placeholder for the change request status checking process." << endl;
    cout << "\nPlease enter the change request ID: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> change_id;
    cout << "\nChange Request ID " << change_id << " is currently in <STATE> state." << endl;
    cout << "\nYou will be returned to main menu" << endl;
    sleep(2);
}
// resolve change request
void resolve_change_request(){
    long int change_id;
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Change Request Resolution Menu:" << endl;
    cout << "Note that this is a placeholder for the change request resolution process." << endl;
    cout << "\nPlease enter the change request ID: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> change_id;
    cout << "\nChange Request ID " << change_id << " has been resolved." << endl;
    cout << "\nYou will be returned to main menu" << endl;
    sleep(2);
}
// edit change request priority
void edit_change_request_priority(){
    long int change_id;
    int priority;
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Change Request Priority Edit Menu:" << endl;
    cout << "Note that this is a placeholder for the change request priority editing process." << endl;
    cout << "\nPlease enter the change request ID: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> change_id;
    cout << "\nPlease enter the new priority level (1-5) for this change request: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> priority;
    cout << "\nChange Request ID " << change_id << " has been updated with new priority level " << priority << "." << endl;
    cout << "\nYou will be returned to main menu" << endl;
    sleep(2);
}
// make feature request
void make_feature_request(){
    char feature_name[MAX_NAME], feature_description[MAX_DESCRIPTION];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Feature Request Menu:" << endl;
    cout << "Note that this is a placeholder for the feature request process." << endl;
    cout << "\nPlease enter the feature name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(feature_name, MAX_NAME-1);
    cout << "\nPlease enter the feature description: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(feature_description, MAX_DESCRIPTION-1);
    cout << "\nFeature " << feature_name << " has been requested." << endl;
    cout << "\nThank you for requesting the feature! This feature request ID is XXXXX" << endl;
    cout << "\nYou will be returned to main menu" << endl;
    sleep(2);
}
// send out new product release
void send_new_product_release(){
    char product_name[MAX_NAME], product_version[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Product Release Menu:" << endl;
    cout << "Note that this is a placeholder for the product release process." << endl;
    cout << "\nPlease enter the product name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_name, MAX_NAME-1);
    cout << "\nPlease enter the product version: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_version, MAX_NAME-1);
    cout << "\nProduct " << product_name << " version " << product_version << " has been released." << endl;
    cout << "\nThank you for releasing the product!" << endl;
    cout << "\nYou will be returned to main menu" << endl;
    sleep(2);
}
