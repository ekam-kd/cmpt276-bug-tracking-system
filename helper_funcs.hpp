/* 
 * File:   helper_funcs.hpp
 * Author: Qiraa Qadri
 * Created: June 2024
 * Version 1
 * Purpose: additional functions for the Bug Tracking System control flow
 *         to be used in main.cpp for readability and modularity
*/

#ifndef HELPER_FUNCS_HPP
#define HELPER_FUNCS_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <limits>
#include <cstdio>
#include "customer.hpp"
#include "product.hpp"
#include "changeItem.hpp"
#include "release.hpp"
#include "changeRequest.hpp"
#include "definitions.hpp"
#include <fstream>

// initialize the system
bool start_up();

// register new customer
bool register_customer();

// create a change request
bool create_change_request();

// check change item status
bool check_change_item();

// register new product
bool register_product();

// edit change item
bool edit_change_item();

// send out new product release
bool send_new_product_release();

// see all pending change items
bool see_all_pending_change_items();

// send out report
bool send_report();

// shutdown the system
bool shut_down();


// checks to ensure the string only contains numeric characters.
// used to check phone number attribute for customer class
bool is_digits(string &str);

/* Note: Iterator functions seekToBeginningOfFile() and getRecord() can be included in the 
   corresponding header files once the file access functions are being implemented. As this
   has not yet been started, the iterator functions have not been included in any hpp file */

#endif