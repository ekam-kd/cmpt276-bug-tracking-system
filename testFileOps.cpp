/*
 * File:   testFileOps.cpp
 * Author: Ashley Kim
 * Created: July 2024
 * Version 1.1
 * Purpose: girl, so COMPUTER [green heart]
 */

#include <iostream>
#include <string>
#include "helper_funcs.hpp"
#include "customer.hpp"
#include "changeItem.hpp"
#include "release.hpp"
#include "changeRequest.hpp"
#include "product.hpp"
#include "definitions.hpp"
using namespace std;

void main_test_ops()
{

    // public methods of product
    //  constructor
    Customer new_customer = Customer();

    // set_name is dependent on get_name to pass.
    cout << "Testing set_name() and get_name():" << endl;
    new_customer.set_name("John Doe");
    if (new_customer.get_name() == "John Doe")
    {
        cout << "set_name() test PASSED" << endl;
        cout << "get_name() test PASSED" << endl;
    }
    else
    {
        cout << "set_name() test FAILED" << endl;
        cout << "get_name() test FAILED" << endl;
    }

    // set_email is dependent on get_email to pass.
    cout << "Testing set_email() and get_email():" << endl;
    new_customer.set_email("JohnDoe@company.ca");
    if (new_customer.get_email() == "JohnDoe@company.ca")
    {
        cout << "set_email() test PASSED" << endl;
        cout << "get_email() test PASSED" << endl;
    }
    else
    {
        cout << "set_email() test FAILED" << endl;
        cout << "get_email() test FAILED" << endl;
    }

    // set_phone is dependent on get_phone to pass.
    cout << "Testing set_phone() and get_phone():" << endl;
    new_customer.set_phone("12345678910");
    if (new_customer.get_phone() == "12345678910")
    {
        cout << "set_phone() test PASSED" << endl;
        cout << "set_phone() test PASSED" << endl;
    }
    else
    {
        cout << "set_phone() test FAILED" << endl;
        cout << "get_phone() test FAILED" << endl;
    }

    // set_department is dependent on get_department to pass.
    cout << "Testing set_department() and get_department():" << endl;
    new_customer.set_department("sales");
    if (new_customer.get_department() == "sales")
    {
        cout << "set_department() test PASSED" << endl;
        cout << "set_department() test PASSED" << endl;
    }
    else
    {
        cout << "set_department() test FAILED" << endl;
        cout << "get_department() test FAILED" << endl;
    }    


    // // print customer info
    // void print_customer_info();



    // // register new customer
    // void register_customer();

    // // helper functions

    // // initialize customer database
    // bool init_customer();

    // // check if customer exists in database file
    // bool check_customer(char *name // name of the customer
    // );

    // // add customer to file
    // bool create_customer(Customer * customer // customer to initialize
    // );
    // // check of employee
    // bool check_employee(char *name // name of the employee
    // );

    // // closes customer database file
    // bool close_customer();
}