/*
 * File:   customer.hpp
 * Author: Qiraa Qadri
 * Created: July 2024
 * Version 2
 * Purpose: Class definition for Customer class
 */

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <limits>
#include "definitions.hpp"
#include "helper_funcs.hpp"
using namespace std;

class Customer
{
private:
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    char phone[MAX_PHONE];
    char department[MAX_DEPARTMENT];

public:
    // constructor
    Customer(const char name[MAX_NAME], const char email[MAX_EMAIL], const char phone_number[MAX_PHONE], 
    const char department[MAX_DEPARTMENT]);
    // destructor
    ~Customer();
    // get name
    char *get_name();
    // get email
    char *get_email();
    // get phone
    char *get_phone();
    // get department
    char *get_department();
    // set name
    void set_name(const char *new_name);
    // set email
    void set_email(const char *new_email);
    // set phone
    void set_phone(const char *new_phone);
    // set department
    void set_department(const char *new_department);
};

// helper functions

// initialize customer database
bool init_customer();

// check if customer exists in database file
bool check_customer(const char name[MAX_NAME] // name of the customer
);

// check if the customer exists and is an employee
bool check_employee(const char name[MAX_NAME]);

// // add customer to file
// bool write_customer(Customer &customer // customer to initialize
// );
void create_customer(const char name[MAX_NAME], const char email[MAX_EMAIL], const char phone_num[MAX_PHONE], const char department[MAX_DEPARTMENT]);

// closes customer database file
bool close_customer();

#endif