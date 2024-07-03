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
#include "definitions.hpp"

// register new customer
void register_customer();

// create a change request
void create_change_request();

// check change item status
void check_change_item_status();

// register new product
void register_product();


// check product release
void check_product_release();

// edit change item
void edit_change_item();

// send out new product release
void send_new_product_release();


void see_all_pending_change_items();
void send_report();

// search for customer from file
Customer search_customer(char* email);
// edit customer info
bool edit_customer(Customer customer);

// search for release from file
Release search_release(char* version);
// edit release info
bool edit_release(Release release);

// search for change item from file
ChangeItem search_change_item(long int id);

// edit change item info
bool edit_change_item(ChangeItem changeItem);



#endif