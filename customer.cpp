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
Customer::Customer(const string name, const string email, const string phone_num, const string department)
    : name(name), email(email), phone(phone_num), department(department) {
}
//-----------------------------------------------------------------------------
// Destructor
Customer::~Customer()
{
    // No dynamic memory to clean up, so this is empty
}
//-----------------------------------------------------------------------------
// Getters
string Customer::get_name() { return name; }

string Customer::get_email() { return email; }

string Customer::get_phone() { return phone; }

string Customer::get_department() { return department; }

//-----------------------------------------------------------------------------
// Setters
void Customer::set_name(const string new_name) { name = new_name; }

void Customer::set_email(const string new_email) { email = new_email; }

void Customer::set_phone(const string new_phone) { phone = new_phone; }

void Customer::set_department(const string new_department) { department = new_department; }

//-----------------------------------------------------------------------------
// Print customer info
//THIS FUNCTION SHOULD TAKE IN NAME AS PARAMETER THEN CALL SEARCH_CUSTOMER OR SMTHN TO FIND THE CUSTOMER AND THEN PRINT THE
//ATTRIBUTES
void Customer::print_customer_info()
{
    cout << "Customer name: " << name << endl;
    cout << "Customer email: " << email << endl;
    cout << "Customer phone: " << phone << endl;
    cout << "Customer department: " << department << endl;
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
bool check_customer(const string name)
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
        cout << "Checking employee: " << temp_customer.get_name() << " and their department:" << temp_customer.get_department() << endl;
        if (temp_customer.get_name() == name) {
            cout << "Oh no! A customer with this name already exists. Please try again with a different name" << endl;
            //customerFile.clear();
            return true;
        }
    }

    // Reset the file pointer for future operations
    customerFile.clear(); // Clear the EOF flag
    //customerFile.seekg(0, ios::beg);
    return false;

    // string line;
    // while (getline(customerFile, line))
    // {
    //     //if the name already exists, the function returns false
    //     if (line == name) {
    //         cout << "\nA customer is already registered under this name! Please try again." << endl;
    //         return false;
    //     }
    // }
    // // otherwise the function returns true
    // return true;
}

//-----------------------------------------------------------------------------
// Check if employee exists
bool check_employee(const string name)
{
    if (!customerFile.is_open())
    {
        cerr << "Error opening customer database file!" << endl;
        return false;
    }
    Customer temp_customer("", "", "", "");

    // Move the file pointer to the beginning of the file
    customerFile.seekg(0, ios::beg);
    const string temp = "sales";

    // Read through the file
    while (customerFile.read(reinterpret_cast<char*>(&temp_customer), sizeof(Customer))) {
        cout << "Checking employee: " << temp_customer.get_name() << " and their department:" << temp_customer.get_department() << endl;
        if (temp_customer.get_department() == temp) {
            if (temp_customer.get_department() != " ") {
                cout << "Valid employee detected." << endl;
                return true;
            }
            cout << "Not an employee. Access denied." << endl;
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
void create_customer(const string name, const string email, const string phone_num, const string department)
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
// bool read_customer(int index, Customer &customer)
// {
//     // assume file is open
//     // seek to the correct position in the file
//     customerFile.seekg(index * sizeof(Customer), ios::beg);
//     // read the change item from the file
//     customerFile.read((char *)&customer, sizeof(Customer));
//     return true;
// }

//-----------------------------------------------------------------------------
// bool delete_customer(int index)
// {
//     fstream tempFile("temp_Customer.dat", ios::out | ios::binary);

//     // Seek to the start of the file
//     customerFile.seekg(0, std::ios::beg);

//     // Read all Customers into memory except the one to be deleted
//     Customer tempCustomer;
//     int currentIndex = 0;
//     while (customerFile.read(reinterpret_cast<string >(&tempCustomer), sizeof(Customer)))
//     {
//         if (currentIndex != index)
//         {
//             tempFile.write(reinterpret_cast<const string >(&tempCustomer), sizeof(Customer));
//         }
//         currentIndex++;
//     }

//     // Clear the file (truncate to 0 and seek to the beginning)
//     customerFile.close();
//     customerFile.open(CUSTOMER_FILE, std::ios::out | std::ios::trunc);
//     customerFile.close();
//     customerFile.open(CUSTOMER_FILE, std::ios::in | std::ios::out | std::ios::binary);

//     // Copy the temp file back to the original file
//     tempFile.seekg(0, std::ios::beg);
//     while (tempFile.read(reinterpret_cast<string >(&tempCustomer), sizeof(Customer)))
//     {
//         customerFile.write(reinterpret_cast<const string >(&tempCustomer), sizeof(Customer));
//     }

//     // Close the temp file
//     tempFile.close();
//     tempFile.open("temp_Customer.dat", std::ios::out | std::ios::trunc);
//     tempFile.close();

//     return true;
// }

//-----------------------------------------------------------------------------
Customer select_customer(const string name)
{
    ifstream customerFile(CUSTOMER_FILE, ios::in | ios::binary);
    string empty_name, empty_email, empty_phone, empty_department;
    if (!customerFile)
    {
        cerr << "Error opening customer database file!" << endl;
        return Customer(empty_name, empty_email, empty_phone, empty_department); // Return a default-constructed Customer object
    }

    Customer temp_customer("", "", "", "");
    while (customerFile.read(reinterpret_cast<char*>(&temp_customer), sizeof(Customer))) {
        if (temp_customer.get_name() == name) {
            return temp_customer;
        }
    }
    return Customer(empty_name, empty_email, empty_phone, empty_department); // Return a default-constructed Customer object
}
//-----------------------------------------------------------------------------
// Close customer file
bool close_customer()
{
    if (customerFile.is_open())
    {
        customerFile.close();
    }
    if (remove(CUSTOMER_FILE) == 0)
    {
        //cout << "File successfully deleted." << endl;
        return true;
    }
    else
    {
        cerr << "Error deleting the file." << endl;
        return false;
    }
}