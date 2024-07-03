/* 
 * File:   helper_funcs.cpp
 * Author: Qiraa Qadri
 * Created: June 2024
 * Purpose: additional functions for the Bug Tracking System control flow
 *        to be used in main.cpp for readability and modularity
*/

#include "helper_funcs.hpp"
using namespace std;

//todo change the return type of the functions to bool
//-----------------------------------------------------------------------------
// register new customer
void register_customer(){
    system("clear");
    string cus_fname, cus_lname, cus_email, emp_department, phone_number;
    bool employee = false;
    // long int phone_number;

    cout << "-----------------------------------\n";
    cout << "New Customer Menu:" << endl;
    cout << "Continue New Customer Registration? (Y/N): ";
    string confirm_register;
    cin >> confirm_register;
    if(confirm_register[0] == 'N' || confirm_register[0] == 'n'){
        cout << "\nYou will be returned to main menu" << endl;
        sleep(2);
        return;
    } else if (confirm_register[0] != 'Y' && confirm_register[0] != 'y'){
        cout << "\nInvalid selection, please try again" << endl;
        sleep(2);
        return;
    }
    cout << "\n\nAre you an employee of AAA Inc.? (Y/N): ";
    string emp;
    cin >> emp;
    if(emp[0] == 'Y' || emp[0] == 'y'){
        employee = true;
    }
    
    cout << "\n\nPlease Enter Your Name:" << endl;
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
        cout << "Please enter (0) to return to Main Menu: ";
        string return_main;
        cin >> return_main;
        if(return_main[0] == '0'){
            sleep(1);
            return;
        }
    } else{
        cout << "\nUnable to register new Customer, please try again" << endl;
    }
}

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// report a bug
void create_change_request(){
    char cus_name[MAX_NAME], bug_description[MAX_DESCRIPTION]; // [1000] and [100] are arbitrary values, can be changed to [10000] or [1000000
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Change Request Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return;
    }
    cout << "Please enter your name:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(cus_name, MAX_NAME-1);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n\nHello " << cus_name << ", please enter the change description:\n";
    cin.get(bug_description, MAX_DESCRIPTION-1);
    cout << "\n\nChange has been reported." << endl;
    cout << "Thank you for reporting the change! This change ID is XXXXX" << endl;  
    cout << "Please enter (0) to return to Main Menu: ";
    string return_main;
    cin >> return_main;
    if(return_main[0] == '0'){
        sleep(1);
        return;
    }
}

//-----------------------------------------------------------------------------
// check bug status
void check_change_item(){
    long int bug_id;
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Change Item Status Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return;
    }
    cout << "\nPlease enter the change ID: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> bug_id;
    cout << "\n\nChange ID " << bug_id << " is currently in <STATE> state." << endl;
    cout << "Please enter (0) to return to Main Menu: ";
    string return_main;
    cin >> return_main;
    if(return_main[0] == '0'){
        sleep(1);
        return;
    }
}


//-----------------------------------------------------------------------------
// edit change item
void edit_change_item(){
    char product_name[MAX_NAME], product_version[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Edit Change Items Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return;
    }
    cout << "\nPlease enter the product name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_name, MAX_NAME-1);
    cout << "\nPlease enter the product version: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_version, MAX_NAME-1);
    cout << "\n\nThe following change items are pending for " << product_name << " Version " << product_version << ":" << endl;
    cout << "-----------------------------------\n";
    cout << "Change Item ID: XXXXX, Description {...}" << endl;
    cout << "Change Item ID: YXXXX, Description {...}" << endl;
    cout << "Change Item ID: YYXXX, Description {...}" << endl;
    cout << "Change Item ID: YYYXX, Description {...}" << endl;
    cout << "Change Item ID: YYYYY, Description {...}" << endl;
    cout << "-----------------------------------\n";

    while(1){
        cout << "Enter (N) to see more change items, or (P) to see previous, or enter the \nchange id of the item you wish to query: ";
        string change_id;
        cin >> change_id;
        if(change_id[0] == 'N' || change_id[0] == 'n'){
            // flip to next page
            system("clear");
            cout << "\n\nThe following change items are pending for " << product_name << ":" << endl;
            cout << "-----------------------------------\n";
            cout << "this is the next page i promise" << endl;
            cout << "-----------------------------------\n";
            cout << "Change Item ID: XXXXX, Description {...}" << endl;
            cout << "Change Item ID: YXXXX, Description {...}" << endl;
            cout << "Change Item ID: YYXXX, Description {...}" << endl;
            cout << "Change Item ID: YYYXX, Description {...}" << endl;
            cout << "Change Item ID: YYYYY, Description {...}" << endl;
            cout << "-----------------------------------\n";
        } else if(change_id[0] == 'P' || change_id[0] == 'p'){
            // flip to previous page
            system("clear");
            cout << "\n\nThe following change requests are pending for " << product_name << ":" << endl;
            cout << "-----------------------------------\n";
            cout << "this is the previous page i promise" << endl;
            cout << "-----------------------------------\n";
            cout << "Change Item ID: XXXXX, Description {...}" << endl;
            cout << "Change Item ID: YXXXX, Description {...}" << endl;
            cout << "Change Item ID: YYXXX, Description {...}" << endl;
            cout << "Change Item ID: YYYXX, Description {...}" << endl;
            cout << "Change Item ID: YYYYY, Description {...}" << endl;
            cout << "-----------------------------------\n";
        } else{
            // query change item id
            while(1){
                cout << "-----------------------------------\n";
                cout << "Change Item: " << change_id << " has the following details:" << endl;
                cout << "Description: {...}" << endl;
                cout << "Enter the field you would like to modify: " << endl;
                cout << "-----------------------------------\n";
                cout << "0. Exit" << endl;
                cout << "1. Priority" << endl;
                cout << "2. Description" << endl;
                cout << "3. Status" << endl;
                cout << "-----------------------------------\n";
                cout << "Selection: ";
                string selection;
                cin >> selection;
                if(selection[0] == '1'){
                    cout << "Enter the new priority level (1-5): ";
                    int new_priority;
                    cin >> new_priority;
                    cout << "Priority level has been updated to " << new_priority << endl;
                } else if(selection[0] == '2'){
                    cout << "Enter the new description: ";
                    char new_description[MAX_DESCRIPTION];
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(new_description, MAX_DESCRIPTION-1);
                    cout << "Description has been updated to " << new_description << endl;
                } else if(selection[0] == '3'){
                    cout << "Enter the new status: ";
                    char new_status[MAX_NAME];
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get(new_status, MAX_NAME-1);
                    cout << "Status has been updated to " << new_status << endl;
                } else if(selection[0] == '0'){
                    break;
                }
                else{
                    cout << "Invalid selection, please try again" << endl;
                }
            }
            break;
        }
    }
}

//-----------------------------------------------------------------------------
// send out new product release
void send_new_product_release(){
    char product_name[MAX_NAME], product_version[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Product Release Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return;
    }
    cout << "\nPlease enter the product name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_name, MAX_NAME-1);
    cout << "\nPlease enter the product version: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_version, MAX_NAME-1);
    cout << "\nProduct " << product_name << " version " << product_version << " has been released." << endl;
    cout << "\nThank you for releasing the product!" << endl;
    cout << "Please enter (0) to return to Main Menu: ";
    string return_main;
    cin >> return_main;
    if(return_main[0] == '0'){
        sleep(1);
        return;
    }
}

//-----------------------------------------------------------------------------
void see_all_pending_change_items(){
    char product_name[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Pending Change Items Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return;
    }
    cout << "\nPlease enter the product name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_name, MAX_NAME-1);
    cout << "\n\nThe following change requests are pending for " << product_name << ":" << endl;
    cout << "Change Request ID: XXXXX" << endl;
    cout << "{...}" << endl;
    cout << "Change Request ID: YYYYY" << endl;

    cout << "\n\nPlease enter (0) to return to Main Menu: ";
    string return_main;
    cin >> return_main;
    if(return_main[0] == '0'){
        sleep(1);
        return;
    }

}

//-----------------------------------------------------------------------------
void send_report(){
    char product_name[MAX_NAME], product_version[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Search Change Items Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return;
    }
    cout << "\nPlease enter the product name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_name, MAX_NAME-1);
    cout << "\nPlease enter the product version: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_version, MAX_NAME-1);
    cout << "\n\nThe following change items are pending for " << product_name << " Version " << product_version << ":" << endl;
    cout << "-----------------------------------\n";
    cout << "Change Item ID: XXXXX, Description {...}" << endl;
    cout << "Change Item ID: YXXXX, Description {...}" << endl;
    cout << "Change Item ID: YYXXX, Description {...}" << endl;
    cout << "Change Item ID: YYYXX, Description {...}" << endl;
    cout << "Change Item ID: YYYYY, Description {...}" << endl;
    cout << "-----------------------------------\n";

    // flip through pages?
    // enter change item id to see more details?
    while(1){
        cout << "Enter (N) to see more change items, or (P) to see previous, or enter the \nchange id of the item you wish to query: ";
        string change_id;
        cin >> change_id;
        if(change_id[0] == 'N' || change_id[0] == 'n'){
            // flip to next page
            system("clear");
            cout << "\n\nThe following change requests are pending for " << product_name << ":" << endl;
            cout << "-----------------------------------\n";
            cout << "this is the next page i promise" << endl;
            cout << "-----------------------------------\n";
            cout << "Change Item ID: XXXXX, Description {...}" << endl;
            cout << "Change Item ID: YXXXX, Description {...}" << endl;
            cout << "Change Item ID: YYXXX, Description {...}" << endl;
            cout << "Change Item ID: YYYXX, Description {...}" << endl;
            cout << "Change Item ID: YYYYY, Description {...}" << endl;
            cout << "-----------------------------------\n";
        } else if(change_id[0] == 'P' || change_id[0] == 'p'){
            // flip to previous page
            system("clear");
            cout << "\n\nThe following change items are pending for " << product_name << ":" << endl;
            cout << "-----------------------------------\n";
            cout << "this is the previous page i promise" << endl;
            cout << "-----------------------------------\n";
            cout << "Change Item ID: XXXXX, Description {...}" << endl;
            cout << "Change Item ID: YXXXX, Description {...}" << endl;
            cout << "Change Item ID: YYXXX, Description {...}" << endl;
            cout << "Change Item ID: YYYXX, Description {...}" << endl;
            cout << "Change Item ID: YYYYY, Description {...}" << endl;
            cout << "-----------------------------------\n";
        } else{
            // query change item id
            cout << "-----------------------------------\n";
            cout << "Change Item: " << change_id << " has the following details:" << endl;
            cout << "Description: {...}" << endl;
            break;
        }
    }

    cout << "\n\nPlease enter (0) to return to Main Menu: ";
    string return_main;
    cin >> return_main;
    if(return_main[0] == '0'){
        sleep(1);
        return;
    }

}