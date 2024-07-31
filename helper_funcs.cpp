// /* 
//  * File:   helper_funcs.cpp
//  * Authors: Qiraa Qadri, Ekam Dhanoa
//  * Created: June 2024
//  * Version: 2
//  * Purpose: additional functions for the Bug Tracking System control flow
//  *        to be used in main.cpp for readability and modularity
// */

#include "helper_funcs.hpp"
using namespace std;

//system start up
bool start_up() {
    //this function starts up the system by opening all the files
    //opening file for customer records:
    init_customer();

    //opening file for product records:
    init_product();

    //opening file for product release records:
    init_release();

    //opening file for changeRequest records:
    init_change_request();

    //opening file for changeItem records:
    init_change_item();
    return true;
}

//-----------------------------------------------------------------------------
// register new customer
bool register_customer(){
    system("clear");
    string temp_name, temp_email, temp_phone, temp_dep;
    char cus_name[MAX_NAME], cus_email[MAX_EMAIL], emp_department[MAX_DEPARTMENT], cus_phone[MAX_PHONE];
    
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
        return true;
    } else if (confirm_register[0] != 'Y' && confirm_register[0] != 'y'){
        cout << "\nInvalid selection, please try again" << endl;
        sleep(2);
        return true;
    }
    cout << "\n\nAre you an employee of the company? (Y/N): ";
    string emp;
    cin >> emp;
    if(emp[0] == 'Y' || emp[0] == 'y'){
        employee = true;
    }

    
    cout << "\n\nPlease Enter Your Full Name:" << endl;
    cout << "\nName: ";
    getline(cin >> ws,temp_name);
    while (temp_name.length() >= 30) {
        cout << "Name is too long. Please try again." << endl;
        cout << "Name: " << endl;
        getline(cin >> ws,temp_name);
    }
    strcpy(cus_name, temp_name.c_str());
    cout << "Thanks, your name is: " << cus_name << "!" << endl;

    cout << "\nPlease enter your email address" << endl;
    cout << "Email: ";
    getline(cin >> ws,temp_email); 
    while (temp_email.length() >= 64) {
        cout << "Email is too long. Please try again." << endl;
        cout << "Email: ";
        getline(cin >> ws,temp_email); 
    }
    strcpy(cus_email, temp_email.c_str());
    cout << "Thanks, your name is: " << cus_name << "!" << endl;

    cout << "\nPlease enter your phone number" << endl;
    cout << "Note that phone number must be in the format of +1(234)-567-8910 -> 12345678910" << endl;
    cout << "Phone: ";
    getline(cin >> ws,temp_phone);
    cout << "your name is still: " << cus_name << "!" << endl;
    //the following while loop checks to make sure the inputted phone number is valid, in length and character
    while (!is_digits(temp_phone) || temp_phone.length() != 11) {
        if (!is_digits(temp_phone)) {
            cout << "\nPhone number contains alphabetic characters. Please try again with only numeric characters." << endl;
            cout << "Note that phone number must be in the format of +1(234)-567-8910 -> 12345678910" << endl;
            cout << "Phone: ";
            getline(cin >> ws,temp_phone); 
        }
        if (temp_phone.length() != 11) {
            cout << "Phone number must be 11 characters." << endl;
            cout << "Note that phone number must be in the format of +1(234)-567-8910 -> 12345678910" << endl;
            cout << "Phone: ";
            getline(cin >> ws,temp_phone);
        }  
    }
    cout << "your name is still: " << cus_name << "!" << endl;
    strcpy(cus_phone, temp_phone.c_str());
    cout << "your name is still: " << cus_name << "!" << endl;

    char temp[MAX_DEPARTMENT] = " ";

    if(employee){
        cout << "\nPlease enter your department: ";
        getline(cin >> ws,temp_dep);
        while (temp_dep.length() >= 30) {
            cout << "Department name is too long." << endl;
            cout << "Please enter your department: ";
            getline(cin >> ws,temp_dep);
        }
        strcpy(emp_department, temp_dep.c_str());
    } else {
        strcpy(temp, emp_department);
    }
    cout << "Thanks, your name is: " << cus_name << "!" << endl;

    cout << "\n\nPlease confirm the following information:" << endl;
    cout << "\nName: " << cus_name << endl;
    cout << "Email: " << cus_email << endl;
    cout << "Phone: " << cus_phone << endl;
    if(employee){
        cout << "Department: " << emp_department << endl;
    }
    cout << "\nIs this information correct? (Y/N): ";
    char confirm;
    cin >> confirm;
    if(confirm == 'Y' || confirm == 'y'){
        if (!check_customer(cus_name)) {
            cout << "\nThank you for registering with us!" << endl;
            create_customer(cus_name, cus_email, cus_phone, emp_department);
        }
        cout << "Please enter (0) to return to Main Menu: ";
        string return_main;
        cin >> return_main;
        if(return_main[0] == '0'){
            sleep(1);
            return true;
        }
    } else{
        cout << "\nUnable to register new Customer, please try again" << endl;
        cout << "Please enter (0) to return to Main Menu: ";
        string return_main;
        cin >> return_main;
        if(return_main[0] == '0'){
            sleep(1);
            return true;
        }
    }
    return true;
}

//-----------------------------------------------------------------------------
// create a change request
// calls check_customer, select_product, make_change_request, and then make_change_item
bool create_change_request(){
    system("clear");
    char cus_name[MAX_NAME];
    cout << "-----------------------------------\n";
    cout << "Change Request Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return true;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return true;
    }
    cout << "Please enter your name: ";
    cin.getline(cus_name, MAX_NAME);
    // getline(cin >> ws,cus_name);
    // while (check_customer(cus_name) || cus_name.length() >= 30) {
    //     cout << "Invalid customer name. Please try again." << endl;
    //     cout << "Name: " << endl;
    //     getline(cin >> ws,cus_name);
    // }
    cout << "Hello " << cus_name << ", please select the product for the report or request you wish to make: " << endl;
    //select_product(); //this function will display a list of the products, the user types in a number and that product is then chosen
    //


    cout << "\n\nHello " << cus_name << ", please enter the change description:\n";
    //cin.get(bug_description, MAX_DESCRIPTION-1);
    cout << "\n\nChange has been reported." << endl;
    cout << "Thank you for reporting the change! This change ID is XXXXX" << endl;  
    cout << "Please enter (0) to return to Main Menu: ";
    string return_main;
    cin >> return_main;
    if(return_main[0] == '0'){
        sleep(1);
        return true;
    }
    return true;
}

//-----------------------------------------------------------------------------
// check bug status
bool check_change_item(){
    long int bug_id;
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Change Item Status Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return true;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return true;
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
        return true;
    }
    return true;
}

//-----------------------------------------------------------------------------
// register new product
// calls check_employee and then add_product
bool register_product(){
    system("clear");
    char product_name[MAX_NAME];
    char emp_name[MAX_NAME];
    cout << "\nEnter Name: ";
    cin.getline(emp_name, MAX_NAME);
    cout << "Name is: " << emp_name;
    check_employee(emp_name);

    cout << "-----------------------------------\n";
    cout << "New Product Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return true;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return true;
    }
    cout << "\nPlease enter the product name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(product_name, MAX_NAME-1);
    cout << "\n\nPlease confirm the following information:" << endl;
    cout << "Product Name: " << product_name << endl;
    cout << "\nIs this information correct? (Y/N): ";
    char confirm;
    cin >> confirm;
    if(confirm == 'Y' || confirm == 'y'){
        cout << "\nThank you for registering the new product!" << endl;
        if(add_product(product_name)){
            cout << "Product " << product_name << " has been added to the system." << endl;
        }
        cout << "Please enter (0) to return to Main Menu: ";
        string return_main;
        cin >> return_main;
        if(return_main[0] == '0'){
            sleep(1);
            return true;
        } else {
            return false;
        }
    } else{
        cout << "\nUnable to register new Product, please try again" << endl;
        cout << "Please enter (0) to return to Main Menu: ";
        string return_main;
        cin >> return_main;
        if(return_main[0] == '0'){
            sleep(1);
            return true;
        }
    }
    return false;
}

//-----------------------------------------------------------------------------
// edit change item
bool edit_change_item(){
    char product_name[MAX_NAME], product_version[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Edit Change Items Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return true;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return true;
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
    return true;
}

//-----------------------------------------------------------------------------
// send out new product release
bool send_new_product_release(){
    char product_name[MAX_NAME], product_version[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Product Release Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return true;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return true;
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
        return true;
    }
    return true;
}

//-----------------------------------------------------------------------------
bool see_all_pending_change_items(){
    char product_name[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Pending Change Items Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return true;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return true;
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
        return true;
    }
    return true;
}

//-----------------------------------------------------------------------------
bool send_report(){
    char product_name[MAX_NAME], product_version[MAX_NAME];
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Search Change Items Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return true;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection, please try again" << endl;
        sleep(2);
        return true;
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

//     // flip through pages?
//     // enter change item id to see more details?
//     while(1){
//         cout << "Enter (N) to see more change items, or (P) to see previous, or enter the \nchange id of the item you wish to query: ";
//         string change_id;
//         cin >> change_id;
//         if(change_id[0] == 'N' || change_id[0] == 'n'){
//             // flip to next page
//             system("clear");
//             cout << "\n\nThe following change requests are pending for " << product_name << ":" << endl;
//             cout << "-----------------------------------\n";
//             cout << "this is the next page i promise" << endl;
//             cout << "-----------------------------------\n";
//             cout << "Change Item ID: XXXXX, Description {...}" << endl;
//             cout << "Change Item ID: YXXXX, Description {...}" << endl;
//             cout << "Change Item ID: YYXXX, Description {...}" << endl;
//             cout << "Change Item ID: YYYXX, Description {...}" << endl;
//             cout << "Change Item ID: YYYYY, Description {...}" << endl;
//             cout << "-----------------------------------\n";
//         } else if(change_id[0] == 'P' || change_id[0] == 'p'){
//             // flip to previous page
//             system("clear");
//             cout << "\n\nThe following change items are pending for " << product_name << ":" << endl;
//             cout << "-----------------------------------\n";
//             cout << "this is the previous page i promise" << endl;
//             cout << "-----------------------------------\n";
//             cout << "Change Item ID: XXXXX, Description {...}" << endl;
//             cout << "Change Item ID: YXXXX, Description {...}" << endl;
//             cout << "Change Item ID: YYXXX, Description {...}" << endl;
//             cout << "Change Item ID: YYYXX, Description {...}" << endl;
//             cout << "Change Item ID: YYYYY, Description {...}" << endl;
//             cout << "-----------------------------------\n";
//         } else{
//             // query change item id
//             cout << "-----------------------------------\n";
//             cout << "Change Item: " << change_id << " has the following details:" << endl;
//             cout << "Description: {...}" << endl;
//             break;
//         }
//     }

    cout << "\n\nPlease enter (0) to return to Main Menu: ";
    string return_main;
    cin >> return_main;
    if(return_main[0] == '0'){
        sleep(1);
        return true;
    }
    return true;

}

bool shut_down() {
    //this function shuts down the system by closing all the files
    //MAKE THIS FUNCTION DELETE THE FILES TOO
        //to justify, say that the clients load the files from backup to the system every time it starts up
    close_customer();
    close_product();
    close_product_release();
    close_change_request();
    close_change_item();
    return true;
}

bool is_digits(string &str) {
    for (char ch : str) {
        if (!isdigit(ch)){
            return false;
        }
    }
    return true;

}