/* 
 * File: changeItem.hpp
 * Author: Qiraa Qadri
 * Created: July 2024
 * Version 1.0
 * Purpose: Class definition for Change Item class
*/

#ifndef CHANGEITEM_HPP
#define CHANGEITEM_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <limits>
#include "definitions.hpp"
using namespace std;

class ChangeItem{
    private:
        long int id;
        char productName[MAX_NAME];
        char productReleaseID[MAX_NAME];
        char description[MAX_DESCRIPTION];
        char status[MAX_NAME];
        int priority;
        int requests;
    public:
        // constructor
        ChangeItem();
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
        void set_id(long int id);
        // set product name
        void set_productName(char* productName);
        // set product release ID
        void set_productReleaseID(char* productReleaseID);
        // set description
        void set_description(char* description);
        // set status
        void set_status(char* status);
        // set priority
        void set_priority(int priority);
        // set requests
        void set_requests(int requests);
        // print change item info
        void print_change_item_info();
};

#endif