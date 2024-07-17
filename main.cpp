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
using namespace std;

// main for testing:
int main(){
    // init rel
    init_release();
    // testing release class
    Release release, release1, blank;
    release.set_productName("Product 1");
    release.set_version("1.0");
    release.set_description("This is a test product");
    release.set_date("01/01/2021");
    release.set_status("Active");
    release.print_release_info();

    release1.set_productName("Product 2");
    release1.set_version("2.0");
    release1.set_description("This is a test product");
    release1.set_date("01/01/2021");
    release1.set_status("Inactive");
    release1.print_release_info();


    // write release to file
    write_release(release);
    write_release(release1);

    // read release from file
    Release release2, release3;
    read_release(0, release2);
    read_release(1, release3);

    // print release info
    cout << "\nReading from file: " << endl;
    release2.print_release_info();
    release3.print_release_info();
    
    // delete release from file
    if(delete_release(0)) cout << "Release 0 deleted" << endl;
    if(delete_release(0)) cout << "Release 1 deleted" << endl;

    init_customer();

    Customer cust1 = Customer();
    Customer cust2 = Customer();
    Customer cust3 = Customer();

    cust1.set_name("John Doe");
    cust1.set_phone("12345678910");
    cust1.set_email("johndoe@abc.ca");
    cust1.set_department("sales");
    cust1.print_customer_info();


    cust2.set_name("Jane Smith");
    cust2.set_phone("9999999999");
    cust2.set_email("janesmith@abc.ca");
    cust2.set_department("hr");

    cust3.set_name("Trac Pham");
    cust3.set_phone("7777777777");
    cust3.set_email("tracpham@abc.ca");
    cust3.set_department("tracbucks");

    write_customer(cust1);
    write_customer(cust2);
    write_customer(cust3);
    cout <<  "reading customer from file..." << endl;
    if (read_customer(1, cust1)){
        cout << "read customer 1 successfully!" << endl;
    }
    if (read_customer(2, cust2)){
        cout << "read customer 2 successfully!" << endl;
    }
    if (read_customer(3, cust3)){
        cout << "read customer 3 successfully!" << endl;
    }

    bool deleted = delete_customer(3);

    if (deleted == true){
        cout <<"deleted succesfully" <<endl;
    }

    cust1 ;




    return 0;
}

// real main
// int main()
// {   
//     start_up(); // initialize the system and database files
//     int selection_one = -1; // intialize selection variable
//     bool sys_run = true; // boolean to keep the system running

//     // main menu loop
//     while(sys_run){ 
//         system("clear"); // clear the screen

//         // main menu
//         cout << "-----------------------------------\n";
//         cout << "Welcome to the Bug Tracking System!" << endl;
//         cout << "Please select one of the following to get started:\n " << endl;
//         cout << "-----------------------------------\n";
//         cout << "-> New Customer (1)" << endl;
//         cout << "-> Existing Customer (2)" << endl;
//         cout << "-> Exit (3)" << endl;
//         cout << "-----------------------------------\n\n";
//         cout << "Selection: "; // prompt user for selection

//         // get user selection
//         cin >> selection_one;

//         // check user selection -> call appropriate submenu / function
//         if(selection_one == 1){
//             // register new customer
//             register_customer();
//         } else if(selection_one == 2){
//             // existing customer
//             bool employee = false; // boolean to check if user is an employee
            
//             // check if user is an employee, loops for possible invalid input
//             while(1){
//                 system("clear"); // clear the screen
//                 cout << "\nAre you an employee of AAA Inc.? (Y/N): ";

//                 // get user input and check if they are an employee
//                 string emp1;
//                 cin >> emp1;  
//                 if(emp1[0] == 'Y' || emp1[0] == 'y'){
//                     employee = true;
//                     break;
//                 } else if(emp1[0] == 'N' || emp1[0] == 'n'){
//                     employee = false;
//                     break;
//                 } else{
//                     cout << "Invalid selection, please try again" << endl;
//                 }
//             }

//             // submenu for existing customers
//             cout << "\nPlease Select one of the following actions:" << endl;
//             cout << "-----------------------------------\n\n";
//             cout << "-> Return (0)" << endl;
//             cout << "-> Create a Change Request (1)" << endl;
//             cout << "-> Check Change Items (2)" << endl;

//             // menu options for employees
//             if(employee){
//                 cout << "-> Register a New Product (3)" << endl;
//                 cout << "-> Edit Change Item (4)" << endl;
//                 cout << "-> Send out new Product Release (5)" << endl;
//                 cout << "-> See all Pending Change Items (6)" << endl;
//                 cout << "-> Send out Report for Change Item (7)" << endl;
//             }
//             cout << "-----------------------------------\n\n";
//             int selection_two = -1; // intialize selection variable
//             cout << "Selection: "; // prompt user for selection
//             cin >> selection_two; // get user selection

//             // check user selection -> call appropriate submenu / function
//             if(employee){ // if user is an employee -> call employee functions
//                 if(selection_two == 0){
//                     cout << "Returning to main menu..." << endl;
//                 } else if(selection_two == 1){
//                     create_change_request();
//                 } else if(selection_two == 2){
//                     check_change_item();
//                 } else if(selection_two == 3){
//                     register_product();
//                 } else if(selection_two == 4){
//                     edit_change_item();
//                 } else if(selection_two == 5){
//                     send_new_product_release();
//                 } else if(selection_two == 6){
//                     see_all_pending_change_items();
//                 } else if(selection_two == 7){
//                     send_report();
//                 }
//                 else{
//                     cout << "Invalid selection, please try again" << endl;
//                 }
//             } else{ // if user is not an employee -> call customer functions
//                 if(selection_two == 0){ 
//                     system("clear"); // clear the screen
//                     cout << "-----------------------------------\n";
//                     cout << "Thank you for using the Bug Tracking System!" << endl;
//                     cout << "-----------------------------------\n\n";
//                     sys_run = false; // terminate UI loop
//                 } else if(selection_two == 1){
//                     create_change_request(); // create a change request
//                 } else if(selection_two == 2){
//                     check_change_item(); // check change items
//                 } else{
//                     cout << "Invalid selection, please try again" << endl;
//                 }
//             }
//         } else if(selection_one == 3){
//             system("clear"); // clear the screen
//             cout << "-----------------------------------\n";
//             cout << "Thank you for using the Bug Tracking System!" << endl;
//             cout << "-----------------------------------\n\n";
//             sys_run = false; // terminate UI loop
//         } else{
//             cout << "Invalid selection, please try again" << endl;
//         }

//     }
//     shut_down(); // close the system and database files
//     return 0;
// }

