/* 
 * File:   helper_funcs.hpp
 * Author: Qiraa Qadri
 * Created: June 2024
 * Version 1.0
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
#include "customer.hpp"
#include "changeItem.hpp"
#include "release.hpp"
#include "changeRequest.hpp"
#include "definitions.hpp"

// initialize the system
void start_up();

// register new customer
void register_customer();

// create a change request
void create_change_request();

// check change item status
void check_change_item();

// register new product
void register_product();

// edit change item
void edit_change_item();

// send out new product release
void send_new_product_release();

// see all pending change items
void see_all_pending_change_items();

// send out report
void send_report();

// shutdown the system
void shut_down();

#endif