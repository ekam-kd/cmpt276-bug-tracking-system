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
    string name;
    string email;
    string phone;
    string department;

public:
    // constructor
    Customer(const string name, const string email, const string phone_number, const string department);
    // destructor
    ~Customer();
    // get name
    string get_name();
    // get email
    string get_email();
    // get phone
    string get_phone();
    // get department
    string get_department();
    // set name
    void set_name(const string new_name);
    // set email
    void set_email(const string new_email);
    // set phone
    void set_phone(const string new_phone);
    // set department
    void set_department(const string new_department);
    // print customer info
    void print_customer_info();
    // register new customer
    //void register_customer();
    
};

// helper functions

// initialize customer database
bool init_customer();

// check if customer exists in database file
bool check_customer(const string name // name of the customer
);

bool check_employee(const string name);

// // add customer to file
// bool write_customer(Customer &customer // customer to initialize
// );
void add_customer(const string name, const string email, const string phone_num, const string department);

// read customer from file
bool read_customer(int index, Customer &customer);

//bool delete_customer(int index);

// closes customer database file
bool close_customer();

// select customer
Customer select_customer(const string name);

        

#endif