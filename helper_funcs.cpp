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

    cout << "\nPlease enter your email address" << endl;
    cout << "Email: ";
    getline(cin >> ws,temp_email); 
    while (temp_email.length() >= 64) {
        cout << "Email is too long. Please try again." << endl;
        cout << "Email: ";
        getline(cin >> ws,temp_email); 
    }
    strcpy(cus_email, temp_email.c_str());

    cout << "\nPlease enter your phone number" << endl;
    cout << "Note that phone number must be in the format of +1(234)-567-8910 -> 12345678910" << endl;
    cout << "Phone: ";
    getline(cin >> ws,temp_phone);
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
    strcpy(cus_phone, temp_phone.c_str());

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
        strcpy(emp_department, "");
    }

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
    cout << "-----------------------------------\n";
    cout << "Change Request Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return true;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection. Returning to main menu..." << endl;
        sleep(2);
        return true;
    }
    string temp_name;
    string temp_prod_name, temp_release;
    string temp_description;
    string temp_date;
    char cus_name[MAX_NAME];
    char prod_name[MAX_PRODUCT_NAME], release[MAX_NAME];
    char change_description[MAX_DESCRIPTION];
    char date[11];
    
    cout << "Please enter your name: ";
    getline(cin>>ws, temp_name);
    strcpy(cus_name, temp_name.c_str());
    while (!check_customer(cus_name) || temp_name.length() >= MAX_NAME) {
        cout << "Invalid customer name. Please try again." << endl;
        cout << "Name: " << endl;
        getline(cin >> ws,temp_name);
        strcpy(cus_name, temp_name.c_str());
    }
    if (!display_products()) {
        sleep(2);
        return false;
    }
    cout << "Based on the products above, enter the product that the report/request you wish to make is for: ";
    getline(cin>>ws, temp_prod_name);
    strcpy(prod_name, temp_prod_name.c_str());
    while (!check_product(prod_name)) {
        cout << "Invalid product name. Please try again: ";
        getline(cin >> ws,temp_prod_name);
        strcpy(prod_name, temp_prod_name.c_str());
    }
    if (!display_product_releases(prod_name)) {
        sleep(2);
        return false;
    }
    cout << "Based on the releases above, choose and enter a release [probably best to choose the latest possible date]: ";
    getline(cin>>ws, temp_release);
    strcpy(release, temp_release.c_str());
    while (!check_release(prod_name, release)) {
        cout << "Invalid release. Please try again: ";
        getline(cin >> ws,temp_release);
        strcpy(release, temp_release.c_str());
    }
    cout << "Please describe the bug report or feature request [in less than 280 characters]: ";
    getline(cin>>ws, temp_description);
    while (temp_description.length() >= MAX_DESCRIPTION) {
        cout << "Description too long. Try again." << endl;
        cout << "Describe the bug report or feature request: ";
        getline(cin>>ws, temp_description);
    }
    strcpy(change_description, temp_description.c_str());

    cout << "Enter today's date with the format of 'mm/dd/yyy': ";
    getline(cin>>ws, temp_date);
    while (temp_date.length() != 10) {
        cout << "Invalid date format. Try again: ";
        getline(cin>>ws, temp_date);
    }
    strcpy(date, temp_date.c_str());
    
    long int temp_changeid = generate_changeId();
    cout << "Change id is: " << temp_changeid << endl;
    make_change_request(temp_changeid, cus_name, release, date);
    make_change_item(temp_changeid, prod_name, release, change_description, "Unchecked", 1, 1);

    
    cout << "Thank you for reporting the change! This change ID is: " << temp_changeid << endl;  
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
// check change item information
bool check_change_item(){
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Check Change Item Mernu:" << endl;
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
    long int change_id;
    string temp_prod_name, temp_release;
    char prod_name[MAX_PRODUCT_NAME], release[MAX_NAME];
    
    if (!display_products()) {
        sleep(2);
        return false;
    }
    cout << "Based on the products above, enter the product that the report/request you wish to see is for: ";
    getline(cin>>ws, temp_prod_name);
    strcpy(prod_name, temp_prod_name.c_str());
    while (!check_product(prod_name)) {
        cout << "Invalid product name. Please try again: ";
        getline(cin >> ws,temp_prod_name);
        strcpy(prod_name, temp_prod_name.c_str());
    }
    if (!display_product_releases(prod_name)) {
        sleep(2);
        return false;
    }
    cout << "Based on the releases above, choose and enter a release: ";
    getline(cin>>ws, temp_release);
    strcpy(release, temp_release.c_str());
    while (!check_release(prod_name, release)) {
        cout << "Invalid release. Please try again: ";
        getline(cin >> ws,temp_release);
        strcpy(release, temp_release.c_str());
    }
    if (!display_change_items(prod_name, release)) {
        sleep(2);
        return false;
    }
    cout << "Choose a change item and enter it's id: ";
    cin >> ws;
    cin >> change_id;
    while (!check_change_item(change_id, prod_name, release)) {
        cout << "Invalid id entered. Try again: ";
        cin >> ws >> change_id;
    }
    see_change_item(change_id);
    
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
    system("clear"); //clears the screen
    cout << "-----------------------------------\n";
    cout << "Register Product Menu:" << endl;
    cout << "Please enter (0) to return to Main Menu, or (1) to Continue: ";
    string return_m;
    cin >> return_m;
    if(return_m[0] == '0'){
        sleep(1);
        return true;
    } else if(return_m[0] != '1'){
        cout << "Invalid selection. Returning to main..." << endl;
        sleep(2);
        return true;
    }
    string temp_product;
    char product_name[MAX_PRODUCT_NAME];
    cout << "\nEnter Product Name: ";
    getline(cin >> ws, temp_product);
    strcpy(product_name, temp_product.c_str());
    if (!add_product(product_name)) {
        cout << "Returning to main menu...";
        sleep(2);
        return false;
    }

    cout << "\n\nPlease confirm the following information:" << endl;
    cout << "Product Name: " << product_name << endl;
    cout << "\nIs this information correct? (Y/N): ";
    char confirm;
    cin >> confirm;
    if(confirm == 'Y' || confirm == 'y'){
        cout << "\nThank you for registering the new product!" << endl;
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
// select_product(), select_product_release(), get_change_items(), modify_change_item()
bool edit_change_item(){
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
    long int change_id;
    string temp_prod_name, temp_release;
    char prod_name[MAX_PRODUCT_NAME], release[MAX_NAME];
    
    if (!display_products()) {
        sleep(2);
        return false;
    }
    cout << "Based on the products above, enter the product that the report/request you wish to edit is for: ";
    getline(cin>>ws, temp_prod_name);
    strcpy(prod_name, temp_prod_name.c_str());
    while (!check_product(prod_name)) {
        cout << "Invalid product name. Please try again: ";
        getline(cin >> ws,temp_prod_name);
        strcpy(prod_name, temp_prod_name.c_str());
    }
    if (!display_product_releases(prod_name)) {
        sleep(2);
        return false;
    }
    cout << "Based on the releases above, choose and enter a release: ";
    getline(cin>>ws, temp_release);
    strcpy(release, temp_release.c_str());
    while (!check_release(prod_name, release)) {
        cout << "Invalid release. Please try again: ";
        getline(cin >> ws,temp_release);
        strcpy(release, temp_release.c_str());
    }
    if (!display_change_items(prod_name, release)) {
        sleep(2);
        return false;
    }
    cout << "Choose a change item and enter it's id: ";
    cin >> ws;
    cin >> change_id;
    while (!check_change_item(change_id, prod_name, release)) {
        cout << "Invalid id entered. Try again: ";
        cin >> ws >> change_id;
    }
    cout << endl;
    see_change_item(change_id);
    modify_change_item(change_id);
    cout << "\nNew results: " << endl;
    see_change_item(change_id);

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
// send out new product release
bool send_new_product_release(){
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
    string temp_prod_name, temp_version, temp_description, temp_date;
    char prod_name[MAX_PRODUCT_NAME], version[MAX_NAME], description[MAX_DESCRIPTION], date[MAX_DATE];
    
    if (!display_products()) {
        sleep(2);
        return false;
    }
    cout << "Based on the products above, enter the one you wish to create a release for: ";
    getline(cin>>ws, temp_prod_name);
    strcpy(prod_name, temp_prod_name.c_str());
    while (!check_product(prod_name)) {
        cout << "Invalid product name. Please try again: ";
        getline(cin >> ws,temp_prod_name);
        strcpy(prod_name, temp_prod_name.c_str());
    }
    cout << "What is the new release called: ";
    getline(cin>>ws, temp_version);
    while (temp_version.length() >= 30) {
        cout << "Release name is too long. Please try again: " << endl;
        getline(cin >> ws,temp_version);
    }
    strcpy(version, temp_version.c_str());

    cout << "Please describe the new release [in less than 280 characters]: ";
    getline(cin>>ws, temp_description);
    while (temp_description.length() >= MAX_DESCRIPTION) {
        cout << "Description too long. Try again: ";
        getline(cin>>ws, temp_description);
    }
    strcpy(description, temp_description.c_str());
    cout << "Enter today's date with the format of 'mm/dd/yyy': ";
    getline(cin>>ws, temp_date);
    while (temp_date.length() != 10) {
        cout << "Invalid date format. Try again: ";
        getline(cin>>ws, temp_date);
    }
    strcpy(date, temp_date.c_str());
    create_product_release(prod_name, version, description, date);

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
// see all pending change items for a particular product release
bool see_all_pending_change_items(){
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
    long int change_id;
    string temp_prod_name;
    char prod_name[MAX_PRODUCT_NAME];
    
    if (!display_products()) {
        sleep(2);
        return false;
    }
    cout << "Based on the products above, enter the product that the change items you wish to see is for: ";
    getline(cin>>ws, temp_prod_name);
    strcpy(prod_name, temp_prod_name.c_str());
    while (!check_product(prod_name)) {
        cout << "Invalid product name. Please try again: ";
        getline(cin >> ws,temp_prod_name);
        strcpy(prod_name, temp_prod_name.c_str());
    }
    cout << endl;
    see_pending_change_items(prod_name);

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
//select_product(), see_all_change_items(), create_report()
bool send_report(){
    system("clear");
    cout << "-----------------------------------\n";
    cout << "Send Report Menu:" << endl;
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
    long int change_id;
    string temp_prod_name, temp_release;
    char prod_name[MAX_PRODUCT_NAME], release[MAX_NAME];
    
    if (!display_products()) {
        sleep(2);
        return false;
    }
    cout << "Based on the products above, enter the product that the report/request you wish to see is for: ";
    getline(cin>>ws, temp_prod_name);
    strcpy(prod_name, temp_prod_name.c_str());
    while (!check_product(prod_name)) {
        cout << "Invalid product name. Please try again: ";
        getline(cin >> ws,temp_prod_name);
        strcpy(prod_name, temp_prod_name.c_str());
    }
    if (!display_product_releases(prod_name)) {
        sleep(2);
        return false;
    }
    cout << "Based on the releases above, choose and enter a release: ";
    getline(cin>>ws, temp_release);
    strcpy(release, temp_release.c_str());
    while (!check_release(prod_name, release)) {
        cout << "Invalid release. Please try again: ";
        getline(cin >> ws,temp_release);
        strcpy(release, temp_release.c_str());
    }
    if (!display_change_items(prod_name, release)) {
        sleep(2);
        return false;
    }

    cout << "Please enter the change item that the report is for: ";
    cin >> ws >> change_id;

    create_report(change_id);

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


long int generate_changeId() {
    fstream change_id_file(CHANGE_ID_FILE, ios::in | ios::out);
    // If the file does not exist or could not be opened
    if (!change_id_file.is_open()) {
        // Create the file and initialize the ID to 1
        std::ofstream create_file(CHANGE_ID_FILE);
        if (create_file.is_open()) {
            create_file << 1;
            create_file.close();
            return 1;
        } else {
            cout << "Error: Could not create the file." << endl;
            return -1; // Indicate failure
        }
    }
    long int temp_id = 0;

    // Read the current ID from the file
    change_id_file >> temp_id;

    // Increment the ID
    temp_id++;

    // Move the file pointer to the beginning and overwrite with the new ID
    change_id_file.clear(); // Clear any errors from reading
    change_id_file.seekp(0, std::ios::beg);
    change_id_file << temp_id;

    // Close the file
    change_id_file.close();

    return temp_id;
}


bool is_digits(string &str) {
    for (char ch : str) {
        if (!isdigit(ch)){
            return false;
        }
    }
    return true;

}