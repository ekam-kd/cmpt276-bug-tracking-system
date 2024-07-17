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
    cout << "----------UNIT TEST 1----------" << endl;

    cout << "Testing init_customer()" << endl;
    if (init_customer())
    {
        cout << "init_customer() test PASSED" << endl;
    }
    else
    {
        cout << "init_customer() test FAILED" << endl;
    }

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
        cout << "get_phone() test PASSED" << endl;
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
        cout << "get_department() test PASSED" << endl;
    }
    else
    {
        cout << "set_department() test FAILED" << endl;
        cout << "get_department() test FAILED" << endl;
    }

    // print customer info
    new_customer.print_customer_info();

    // register new customer
    // register_customer();

    // helper functions

    // add customer to file
    if (write_customer(new_customer))
    {
        cout << "write_customer() test PASSED" << endl;
    }
    else
    {
        cout << "write_customer() test FAILED" << endl;
    }
    // read customer from file
    if (read_customer(1, new_customer))
    {
        cout << "read_customer() test PASSED" << endl;
    }
    else
    {
        cout << "read_customer() test FAILED" << endl;
    }
    // check if customer exists in database file
    if (check_customer("John Doe"))
    {
        cout << "check_customer() test PASSED" << endl;
    }
    else
    {
        cout << "check_customer test FAILED" << endl;
    }

    if (check_employee("John Doe"))
    {
        cout << "check_employee() test PASSED" << endl;
    }
    else
    {
        cout << "check_employee test FAILED" << endl;
    }

    if (delete_customer(1))
    {
        cout << "delete_customer() test PASSED" << endl;
    }
    else
    {
        cout << "delete_customer() test FAILED" << endl;
    }
    if (close_customer())
    {
        cout << "close_customer() test PASSED" << endl;
    }
    else
    {
        cout << "close_customer() test FAILED" << endl;
    }

    cout << "----------UNIT TEST 2----------" << endl;

    init_release();
    Release new_release = Release();
        // set_department is dependent on get_department to pass.
    cout << "Testing set_productName() and get_productName():" << endl;
    new_release.set_productName("acrobat");
    if (new_release.get_productName() == "acrobat")
    {
        cout << "set_productName() test PASSED" << endl;
        cout << "get_productName()) test PASSED" << endl;
    }
    else
    {
        cout << "set_productName() test FAILED" << endl;
        cout << "get_productName() test FAILED" << endl;
    }


}