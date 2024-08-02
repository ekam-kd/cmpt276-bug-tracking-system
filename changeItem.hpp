/* 
 * File: changeItem.hpp
 * Author: Qiraa Qadri
 * Created: July 2024
 * Version 2
 * Purpose: Class definition for Change Item class
*/

#ifndef CHANGEITEM_HPP
#define CHANGEITEM_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <limits>
#include <fstream>
#include <cstring>
#include "definitions.hpp"
#include "changeRequest.hpp"
#include "customer.hpp"
using namespace std;


class ChangeItem{
    private:
        long int id;
        char productName[MAX_PRODUCT_NAME];
        char productReleaseID[MAX_NAME];
        char description[MAX_DESCRIPTION];
        char status[MAX_NAME];
        int priority;
        int requests;
    public:
        // default constructor
        ChangeItem();
        //constructor
        ChangeItem(const long int id, const char prod_name[MAX_PRODUCT_NAME], const char prod_release[MAX_NAME], 
        const char description[MAX_DESCRIPTION], const char status[MAX_NAME], const int priority, const int requests);
        // destructor
        ~ChangeItem();
        // get id
        long int get_id();
        // get product name
        char* get_productName();
        // get product release ID
        char* get_productReleaseID();
        // get description
        char* get_description();
        // get status
        char* get_status();
        // get priority
        int get_priority();
        // get requests
        int get_requests();
        // set id
        void set_id(const long int id);
        // set product name
        void set_productName(const char* productName);
        // set product release ID
        void set_productReleaseID(const char* productReleaseID);
        // set description
        void set_description(const char* description);
        // set status
        void set_status(const char* status);
        // set priority
        void set_priority(const int priority);
        // set requests
        void set_requests(const int requests);
        // print change item info
        void print_change_item_info();
};

// helper functions

// initialize change item database
bool init_change_item();

// writes change item to file MIGHT DELETE L8ER
bool write_change_item(ChangeItem &changeItem);

// create a new change item and add to file
//bool make_change_item(const long int id, const char prod_name[MAX_PRODUCT_NAME], const char prod_release[MAX_NAME], 
//const char description[MAX_DESCRIPTION], const char status[MAX_NAME], const int priority, const int requests);
bool make_change_item(ChangeItem &ChangeItem);
// display to user all the pending change items for a product
bool get_change_items(char* prod_name, char* prod_release);

// search through changeItem file for a specific change item 
// then print info to screen
bool see_change_item(long int ch_id // id of the change item
                );

// modify a change item
bool modify_change_item(long int ch_id // id of the change item
                    );

// see all change items (pending AND completed) for a product
bool see_all_change_items(char* productName // name of the product
                    );


// takes product name and lists all pending change items for a product
bool get_pending_change_items(char* prod_name);

// close change item database file
bool close_change_item();

// file operations
bool create_report(long int ch_id);
bool read_change_item(int index, ChangeItem &changeItem);
bool delete_change_item(int index);

#endif