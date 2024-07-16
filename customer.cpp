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
Customer::Customer()
{
    strcpy(name, "NOT_SET");
    strcpy(email, "NOT_SET");
    strcpy(phone, "NOT_SET");
    strcpy(department, "NOT_SET");
}
// destructor
Customer::~Customer()
{
    // nothing to dealloc
}
// get name
char *Customer::get_name()
{
    return name;
}
// get email
char *Customer::get_email()
{
    return email;
}
// get phone
char *Customer::get_phone()
{
    return phone;
}
// get department
char *Customer::get_department()
{
    return department;
}
// set name
void Customer::set_name(char *new_name)
{
    strncpy(name, new_name, MAX_NAME - 1);
    name[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}
// set email
void Customer::set_email(char *new_email)
{
    strncpy(email, new_email, MAX_EMAIL - 1);
    email[MAX_EMAIL - 1] = '\0';
}
// set phone
void Customer::set_phone(char *new_phone)
{
    strncpy(phone, new_phone, MAX_PHONE - 1);
    phone[MAX_PHONE - 1] = '\0';
}
// set department
void Customer::set_department(char *new_department)
{
    strncpy(department, new_department, MAX_DEPARTMENT - 1);
    department[MAX_DEPARTMENT - 1] = '\0';
}
// print customer info
void Customer::print_customer_info()
{
    std::cout << "Customer name: " << name << std::endl;
    std::cout << "Customer email: " << email << std::endl;
    std::cout << "Customer phone: " << phone << std::endl;
    std::cout << "Customer department: " << department << std::endl;
}
// register new customer
void Customer::register_customer()
{
    char input[MAX_NAME];

    std::cout << "Enter customer name: ";
    std::cin.getline(input, MAX_NAME);
    set_name(input);

    std::cout << "Enter customer email: ";
    std::cin.getline(input, MAX_EMAIL);
    set_email(input);

    std::cout << "Enter customer phone: ";
    std::cin.getline(input, MAX_PHONE);
    set_phone(input);

    std::cout << "Enter customer department: ";
    std::cin.getline(input, MAX_NAME);
    set_department(input);
}
