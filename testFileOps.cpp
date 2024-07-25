/*
 * File:   testFileOps.cpp
 * Author: Ashley Kim
 * Created: July 2024
 * Version 1
 * Purpose: unit tests for customer and release classes.
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

    if (strcmp(new_customer.get_name(), "John Doe") == 0)
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
    if (strcmp(new_customer.get_email(), "JohnDoe@company.ca") == 0)
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
    if (strcmp(new_customer.get_phone(), "1234567891") == 0)
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
    if (strcmp(new_customer.get_department(), "sales") == 0)
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
    const char *name_of_customer = "John Doe";
    if (check_customer(name_of_customer))
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

    Release new_release = Release();

    //testing initializing the relese database
    cout << "Testing init_release()" << endl;
    if (init_release())
    {
        cout << "init_release() test PASSED" << endl;
    }
    else
    {
        cout << "init_release() test FAILED" << endl;
    }

    // set_productName is dependent on get_productName to pass.
    cout << "Testing set_productName() and get_productName():" << endl;
    new_release.set_productName("acrobat");
    if (strcmp(new_release.get_productName(), "acrobat") == 0)
    {
        cout << "set_productName() test PASSED" << endl;
        cout << "get_productName()) test PASSED" << endl;
    }
    else
    {
        cout << "set_productName() test FAILED" << endl;
        cout << "get_productName() test FAILED" << endl;
    }

    // set_version is dependent on get_version to pass.
    cout << "Testing set_version() and get_version():" << endl;
    new_release.set_version("1.1");
    if (strcmp(new_release.get_version(), "1.1") == 0)
    {
        cout << "set_version() test PASSED" << endl;
        cout << "get_version()) test PASSED" << endl;
    }
    else
    {
        cout << "set_version() test FAILED" << endl;
        cout << "get_version() test FAILED" << endl;
    }

    // set_date is dependent on get_date to pass.
    cout << "Testing set_date() and get_date():" << endl;
    new_release.set_date("11/11/2024");
    if (strcmp(new_release.get_date(), "11/11/2024") == 0)
    {
        cout << "set_date() test PASSED" << endl;
        cout << "get_date() test PASSED" << endl;
    }
    else
    {
        cout << "set_date() test FAILED" << endl;
        cout << "get_date() test FAILED" << endl;
    }

    // set_description is dependent on get_description to pass.
    cout << "Testing set_description() and get_description():" << endl;
    new_release.set_description("lalala");
    if (strcmp(new_release.get_description(), "lalala") == 0)
    {
        cout << "set_description() test PASSED" << endl;
        cout << "get_description() test PASSED" << endl;
    }
    else
    {
        cout << "set_description() test FAILED" << endl;
        cout << "get_description() test FAILED" << endl;
    }

    // print info
    new_release.print_release_info();

    // //testing create product release
    // if (create_product_release(&new_release)){
    //     cout << "create_product_release() test PASSED" << endl;
    // }
    // else
    // {
    //     cout << "create_product_release() test FAILED" << endl;
    // }

    // testing write
    if (write_release(new_release))
    {
        cout << "write_release() test PASSED" << endl;
    }
    else
    {
        cout << "write_release() test FAILED" << endl;
    }

    // testing read
    if (read_release(0, new_release))
    {
        cout << "read_release() test PASSED" << endl;
    }
    else
    {
        cout << "read_release() test FAILED" << endl;
    }

    // testing delete
    if (delete_release(0))
    {
        cout << "delete_release() test PASSED" << endl;
    }
    else
    {
        cout << "delete_release() test FAILED" << endl;
    }

    // testing close
    if (close_product_release())
    {
        cout << "close_product_release() test PASSED" << endl;
    }
    else
    {
        cout << "close_product_release() test FAILED" << endl;
    }
}