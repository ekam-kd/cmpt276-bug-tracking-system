/*
 * File:   customer.cpp
 * Authors: Ashley Kim, Ekam Dhanoa
 * Created: July 2024
 * Version 1
 * Purpose: Class implementation for Customer class
 */

#include "customer.hpp"
using namespace std;
#include <cstring> // For strcpy, strncpy
#include <fstream> // For file operations
#include "customer.hpp"
fstream customerFile; // global filestream for customer file so it stays open for program duration

//-----------------------------------------------------------------------------
// Constructor
Customer::Customer(const char new_name[MAX_NAME], const char new_email[MAX_EMAIL], const char new_num[MAX_PHONE], 
const char new_dep[MAX_DEPARTMENT]){
    set_name(new_name);
    set_email(new_email);
    set_phone(new_num);
    set_department(new_dep);
}
//-----------------------------------------------------------------------------
// Destructor
Customer::~Customer()
{
    // No dynamic memory to clean up, so this is empty
}
//-----------------------------------------------------------------------------
// Getters
char *Customer::get_name()
{
    return name;
}
char *Customer::get_email()
{
    return email;
}
char *Customer::get_phone()
{
    return phone;
}
char *Customer::get_department()
{
    return department;
}
//-----------------------------------------------------------------------------
// Setters
void Customer::set_name(const char *new_name)
{
    strncpy(name, new_name, MAX_NAME - 1);
    name[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}
void Customer::set_email(const char *new_email)
{
    strncpy(email, new_email, MAX_EMAIL - 1);
    email[MAX_EMAIL - 1] = '\0'; // Ensure null-terminated
}
void Customer::set_phone(const char *new_phone)
{
    strncpy(phone, new_phone, MAX_PHONE - 1);
    phone[MAX_PHONE - 1] = '\0'; // Ensure null-terminated
}
void Customer::set_department(const char *new_department)
{
    strncpy(department, new_department, MAX_NAME - 1);
    department[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}

// Function that opens/creates the customer file for reading and writing
//-----------------------------------------------------------------------------
bool init_customer()
{
    // open file for reading/writing and create it if it doesn't exist
    customerFile.open(CUSTOMER_FILE, ios::in | ios::out | ios::binary);

    // if file opened successfully, return true
    if (customerFile.is_open())
    {
        return true;
    }
    else
    { // otherwise try opening again
        customerFile.clear();
        customerFile.open(CUSTOMER_FILE, ios::out | ios::binary);
        if (customerFile.is_open()) {
            customerFile.close();
            customerFile.open(CUSTOMER_FILE, ios::in | ios::out | ios::binary);
            return true;
        }
        //and if it doesn't work, return false
        return false;
    }
}

//-----------------------------------------------------------------------------
// Check if customer exists in database file
bool check_customer(const char name[MAX_NAME])
{
    if (!customerFile.is_open())
    {
        cerr << "Error opening customer database file!" << endl;
        return false;
    }

    Customer temp_customer("", "", "", "");

    // Move the file pointer to the beginning of the file
    customerFile.seekg(0, ios::beg);

    // Read through the file
    while (customerFile.read(reinterpret_cast<char*>(&temp_customer), sizeof(Customer))) {
        //cout << "Checking customer: " << temp_customer.get_name() << endl;
        if (strcmp(temp_customer.get_name(),name) == 0) {
            //cout << "Oh no! A customer with this name already exists. Please try again with a different name" << endl;
            return true;
        }
    }

    // Reset the file pointer for future operations
    customerFile.clear(); // Clear the EOF flag
    //customerFile.seekg(0, ios::beg);
    return false;
}

//-----------------------------------------------------------------------------
// Check if employee exists
bool check_employee(const char name[MAX_NAME])
{
    if (!customerFile.is_open())
    {
        cerr << "Error opening customer database file!" << endl;
        return false;
    }
    Customer temp_customer("", "", "", "");

    // Move the file pointer to the beginning of the file
    customerFile.seekg(0, ios::beg);

    // Read through the file
    while (customerFile.read(reinterpret_cast<char*>(&temp_customer), sizeof(Customer))) {
        //cout << "Checking employee: " << temp_customer.get_name() << " and their department:" << temp_customer.get_department() << endl;
        if (strcmp(temp_customer.get_name(),name) == 0) {
            if (strcmp(temp_customer.get_department(), "") != 0) {
                cout << "Valid employee." << endl;
                return true;
            }
            cout << "Not valid employee\n";
            return false;
        }
    }
    cout << "This customer does not exist." << endl;
    // Reset the file pointer for future operations
    customerFile.clear(); // Clear the EOF flag
    //customerFile.seekg(0, ios::beg);
    return false;
}
//-----------------------------------------------------------------------------
// Register new customer
void create_customer(const char name[MAX_NAME], const char email[MAX_EMAIL], 
const char phone_num[MAX_PHONE], const char department[MAX_DEPARTMENT])
{
    Customer new_customer(name, email, phone_num, department);
    customerFile.seekp(0, ios::end);
    customerFile.write(reinterpret_cast<char*>(&new_customer), sizeof(Customer));
    customerFile.clear();

    if (customerFile.fail()) {
        cerr << "Error writing to the customer file." << endl;
    }
}

//-----------------------------------------------------------------------------
// Close customer file
bool close_customer()
{
    if (customerFile.is_open())
    {
        customerFile.close();
    }
    return true;
}