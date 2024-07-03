/* 
 * File:   unit_tests.cpp
 * Author: Qiraa Qadri
 * Created: July 2024
 * Version 1.0
 * Purpose: unit tests for all helper functions in the Bug Tracking System
 *         <DISCLAIMER> these actually dont work because there is no implementation of functions being tested
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

int mainForUnitTests(){
    /* Testing helper_func module */
    // test start_up
    cout << "Testing start_up" << endl;
    if(start_up()){
        cout << "start_up test passed" << endl;
    } else{
        cout << "start_up test failed" << endl;
    }
    
    // test register_customer
    cout << "Testing register_customer" << endl;
    if(register_customer()){
        cout << "register_customer test passed" << endl;
    } else{
        cout << "register_customer test failed" << endl;
    }
    
    // test create_change_request
    cout << "Testing create_change_request" << endl;
    if(create_change_request()){
        cout << "create_change_request test passed" << endl;
    } else{
        cout << "create_change_request test failed" << endl;
    }
    
    // test check_change_item
    cout << "Testing check_change_item" << endl;
    if(check_change_item()){
        cout << "check_change_item test passed" << endl;
    } else{
        cout << "check_change_item test failed" << endl;
    }
    
    // test register_product
    cout << "Testing register_product" << endl;
    if(register_product()){
        cout << "register_product test passed" << endl;
    } else{
        cout << "register_product test failed" << endl;
    }
    
    // test edit_change_item
    cout << "Testing edit_change_item" << endl;
    if(edit_change_item()){
        cout << "edit_change_item test passed" << endl;
    } else{
        cout << "edit_change_item test failed" << endl;
    }
    
    // test send_new_product_release
    cout << "Testing send_new_product_release" << endl;
    if(send_new_product_release()){
        cout << "send_new_product_release test passed" << endl;
    } else{
        cout << "send_new_product_release test failed" << endl;
    }
    
    // test see_all_pending_change_items
    cout << "Testing see_all_pending_change_items" << endl;
    if(see_all_pending_change_items()){
        cout << "see_all_pending_change_items test passed" << endl;
    } else{
        cout << "see_all_pending_change_items test failed" << endl;
    }
    
    // test send_report
    cout << "Testing send_report" << endl;
    if(send_report()){
        cout << "send_report test passed" << endl;
    } else{
        cout << "send_report test failed" << endl;
    }
    
    // test shut_down
    cout << "Testing shut_down" << endl;
    if(shut_down()){
        cout << "shut_down test passed" << endl;
    } else{
        cout << "shut_down test failed" << endl;
    }

    /*-----------------------------------------------------------------------------------------------*/
    /* Testing Customer Module */

    // test init_customer
    cout << "Testing init_customer" << endl;
    if(init_customer()){
        cout << "init_customer test passed" << endl;
    } else{
        cout << "init_customer test failed" << endl;
    }

    // test check_customer
    cout << "Testing check_customer" << endl;
    // case 1 real customer
    if(check_customer("Qiraa Qadri")){
        cout << "check_customer test passed" << endl;
    } else{
        cout << "check_customer test failed" << endl;
    }

    // case 2 fake customer
    if(!check_customer("Fake Customer")){
        cout << "check_customer test passed" << endl;
    } else{
        cout << "check_customer test failed" << endl;
    }

    // test create_customer
    cout << "Testing create_customer" << endl;
    if(create_customer(new Customer())){
        cout << "create_customer test passed" << endl;
    } else{
        cout << "create_customer test failed" << endl;
    }

    // test check_employee
    cout << "Testing check_employee" << endl;
    // case 1 real employee
    if(check_employee("Qiraa Qadri")){
        cout << "check_employee test passed" << endl;
    } else{
        cout << "check_employee test failed" << endl;
    }

    // case 2 fake employee
    if(!check_employee("Fake Employee")){
        cout << "check_employee test passed" << endl;
    } else{
        cout << "check_employee test failed" << endl;
    }

    // test close_customer
    cout << "Testing close_customer" << endl;
    if(close_customer()){
        cout << "close_customer test passed" << endl;
    } else{
        cout << "close_customer test failed" << endl;
    }
    
    /*-----------------------------------------------------------------------------------------------*/
    /* Testing Product Module */

    // test init_product
    cout << "Testing init_product" << endl;
    if(init_product()){
        cout << "init_product test passed" << endl;
    } else{
        cout << "init_product test failed" << endl;
    }

    // test select_product
    cout << "Testing select_product" << endl;
    if(select_product().get_name() != ""){
        cout << "select_product test passed" << endl;
    } else{
        cout << "select_product test failed" << endl;
    }

    // test add_product
    cout << "Testing add_product" << endl;
    if(add_product(new Product())){
        cout << "add_product test passed" << endl;
    } else{
        cout << "add_product test failed" << endl;
    }

    // test close_product
    cout << "Testing close_product" << endl;
    if(close_product()){
        cout << "close_product test passed" << endl;
    } else{
        cout << "close_product test failed" << endl;
    }

    /*-----------------------------------------------------------------------------------------------*/
    /* Testing Product Release Module*/

    // test init_release
    cout << "Testing init_release" << endl;
    if(init_release()){
        cout << "init_release test passed" << endl;
    } else{
        cout << "init_release test failed" << endl;
    }

    // test create_product_release 
    cout << "Testing create_product_release" << endl;
    if(create_product_release(new Release())){
        cout << "create_product_release test passed" << endl;
    } else{
        cout << "create_product_release test failed" << endl;
    }

    // test close_product_release
    cout << "Testing close_product_release" << endl;
    if(close_product_release()){
        cout << "close_product_release test passed" << endl;
    } else{
        cout << "close_product_release test failed" << endl;
    }

    /*-----------------------------------------------------------------------------------------------*/
    /* Testing Change Request Module */

    // test init_change_request
    cout << "Testing init_change_request" << endl;
    if(init_change_request()){
        cout << "init_change_request test passed" << endl;
    } else{
        cout << "init_change_request test failed" << endl;
    }

    // test make_change_request
    cout << "Testing make_change_request" << endl;
    if(make_change_request(new ChangeRequest())){
        cout << "make_change_request test passed" << endl;
    } else{
        cout << "make_change_request test failed" << endl;
    }

    // test close_change_request
    cout << "Testing close_change_request" << endl;
    if(close_change_request()){
        cout << "close_change_request test passed" << endl;
    } else{
        cout << "close_change_request test failed" << endl;
    }

    /*-----------------------------------------------------------------------------------------------*/
    /* Testing Change Item Module */

    // test init_change_item
    cout << "Testing init_change_item" << endl;
    if(init_change_item()){
        cout << "init_change_item test passed" << endl;
    } else{
        cout << "init_change_item test failed" << endl;
    }

    // test make_change_item
    cout << "Testing make_change_item" << endl;
    if(make_change_item(new ChangeItem())){
        cout << "make_change_item test passed" << endl;
    } else{
        cout << "make_change_item test failed" << endl;
    }

    // test get_change_items
    // case 1 real product
    cout << "Testing get_change_items" << endl;
    if(get_change_items("Product")){
        cout << "get_change_items test passed" << endl;
    } else{
        cout << "get_change_items test failed" << endl;
    }

    // case 2 fake product
    if(!get_change_items("Fake Product")){
        cout << "get_change_items test passed" << endl;
    } else{
        cout << "get_change_items test failed" << endl;
    }

    // test see_change_item
    // case 1 real change item
    cout << "Testing see_change_item" << endl;
    if(see_change_item(1)){
        cout << "see_change_item test passed" << endl;
    } else{
        cout << "see_change_item test failed" << endl;
    }

    // case 2 fake change item
    if(!see_change_item(0)){
        cout << "see_change_item test2 passed" << endl;
    } else{
        cout << "see_change_item test2 failed" << endl;
    }

    // test modify_change_item
    // case 1 real change item
    cout << "Testing modify_change_item" << endl;
    if(modify_change_item(1)){
        cout << "modify_change_item test1 passed" << endl;
    } else{
        cout << "modify_change_item test1 failed" << endl;
    }

    // case 2 fake change item
    if(!modify_change_item(0)){
        cout << "modify_change_item test2 passed" << endl;
    } else{
        cout << "modify_change_item test2 failed" << endl;
    }

    // test see_all_change_items
    cout << "Testing see_all_change_items" << endl;
    // case 1 real product
    if(see_all_change_items("Product")){
        cout << "see_all_change_items test passed" << endl;
    } else{
        cout << "see_all_change_items test failed" << endl;
    }

    // case 2 fake product
    if(!see_all_change_items("Fake Product")){
        cout << "see_all_change_items test passed" << endl;
    } else{
        cout << "see_all_change_items test failed" << endl;
    }

    // test create_report
    cout << "Testing create_report" << endl;
    // case 1 real change item
    if(create_report(1)){
        cout << "create_report test1 passed" << endl;
    } else{
        cout << "create_report test1 failed" << endl;
    }

    // case 2 fake change item
    if(!create_report(0)){
        cout << "create_report test2 passed" << endl;
    } else{
        cout << "create_report test2 failed" << endl;
    }

    // test close_change_item
    cout << "Testing close_change_item" << endl;
    if(close_change_item()){
        cout << "close_change_item test passed" << endl;
    } else{
        cout << "close_change_item test failed" << endl;
    }

    return 0;
}