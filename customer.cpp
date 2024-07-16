/*
 * File:   customer.cpp
 * Author: Ashley Kim
 * Created: July 2024
 * Version 1.1
 * Purpose: Class implementation for Customer class
*/
#include <iostream>
#include <string>
#include "customer.hpp"
#include "definitions.hpp"
using namespace std;
// public methods
//  constructor
#include <cstring> // For strcpy, strncpy
#include <fstream> // For file operations
#include "customer.hpp"
//global filestream for customer file so it stays open for program duration
fstream customerFile;

bool init_customer() {
    //open file for reading/writing and create it if it doesn't exist
    customerFile.open(CUSTOMER_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(customerFile.is_open()) {
        return true;
    } else { //otherwise return false
        return false;
    }

}

// Constructor
Customer::Customer() {
    strcpy(name, "NOT_SET");
    strcpy(email, "NOT_SET");
    strcpy(phone, "NOT_SET");
    strcpy(department, "NOT_SET");
}

// Destructor
Customer::~Customer() {
    // No dynamic memory to clean up, so this is empty
}

// Getters
char* Customer::get_name() {
    return name;
}

char* Customer::get_email() {
    return email;
}

char* Customer::get_phone() {
    return phone;
}

char* Customer::get_department() {
    return department;
}

// Setters
void Customer::set_name(char* new_name) {
    strncpy(name, new_name, MAX_NAME - 1);
    name[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}

void Customer::set_email(char* new_email) {
    strncpy(email, new_email, MAX_EMAIL - 1);
    email[MAX_EMAIL - 1] = '\0'; // Ensure null-terminated
}

void Customer::set_phone(char* new_phone) {
    strncpy(phone, new_phone, MAX_PHONE - 1);
    phone[MAX_PHONE - 1] = '\0'; // Ensure null-terminated
}

void Customer::set_department(char* new_department) {
    strncpy(department, new_department, MAX_NAME - 1);
    department[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}

// Print customer info
void Customer::print_customer_info() {
    cout << "Customer name: " << name << endl;
    cout << "Customer email: " << email << endl;
    cout << "Customer phone: " << phone << endl;
    cout << "Customer department: " << department << endl;
}

// Register new customer
void Customer::register_customer() {
    char input[MAX_NAME];

    cout << "Enter customer name: ";
    cin.getline(input, MAX_NAME);
    set_name(input);

    cout << "Enter customer email: ";
    cin.getline(input, MAX_EMAIL);
    set_email(input);

    cout << "Enter customer phone: ";
    cin.getline(input, MAX_PHONE);
    set_phone(input);

    cout << "Enter customer department: ";
    cin.getline(input, MAX_NAME);
    set_department(input);
}


// Check if customer exists in database file
bool check_customer(char* name) {
    ifstream infile("customer_db.txt");
    if (!infile) {
        cerr << "Error opening customer database file!" << endl;
        return false;
    }

    string line;
    while (getline(infile, line)) {
        if (line.find(name) != string::npos) {
            infile.close();
            return true;
        }
    }

    infile.close();
    return false;
}

// Add customer to file
bool create_customer(Customer* customer) {
    ofstream outfile("customer_db.txt", ios::app); // Open in append mode
    if (!outfile) {
        cerr << "Error opening customer database file!" << endl;
        return false;
    }
    outfile << customer->get_name() << endl;
    outfile << customer->get_email() << endl;
    outfile << customer->get_phone() << endl;
    outfile << customer->get_department() << endl;
    outfile.close();
    return true;
}

// Check if employee exists
bool check_employee(char* name) {
    ifstream infile("employee_db.txt");
    if (!infile) {
        cerr << "Error opening employee database file!" << endl;
        return false;
    }

    string line;
    while (getline(infile, line)) {
        if (line.find(name) != string::npos) {
            infile.close();
            return true;
        }
    }

    infile.close();
    return false;
}

// Close customer file
bool close_customer() {
    if (customerFile.is_open()) {
        customerFile.close();
        return true;
    }
    return false;
}
