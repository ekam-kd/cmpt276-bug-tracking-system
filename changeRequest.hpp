/* 
 * File: changeRequest.hpp
 * Author: Qiraa Qadri
 * Created: July 2024
 * Version 1.0
 * Purpose: Class definition for Change Request class
*/

#ifndef CHANGEREQUEST_HPP
#define CHANGEREQUEST_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <limits>
#include "definitions.hpp"

using namespace std;

class ChangeRequest{
    private:
        long int id;
        char customer_name[MAX_NAME];
        char reported_release[MAX_NAME];
        char request_date[MAX_DATE];
    public:
        // constructor
        ChangeRequest();
        // destructor
        ~ChangeRequest();
        // get id
        long int get_id();
        // get customer name
        char* get_customer_name();
        // get reported release
        char* get_reported_release();
        // get request date
        char* get_request_date();
        // set id
        void set_id(long int id);
        // set customer name
        void set_customer_name(char* customer_name);
        // set reported release
        void set_reported_release(char* reported_release);
        // set request date
        void set_request_date(char* request_date);
        // print change request info
        void print_change_request_info();
        // register new change request
        void register_change_request();

};

// helper functions

// initialize change request database
void init_change_request();

// add change request to file
void make_change_request(ChangeRequest changeRequest // change request to add
                        );

// close change request database file
void close_change_request();

#endif