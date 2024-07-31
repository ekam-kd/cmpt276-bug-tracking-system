/* 
 * File: changeRequest.hpp
 * Author: Qiraa Qadri
 * Created: July 2024
 * Version 2
 * Purpose: Class definition for Change Request class
*/

#ifndef CHANGEREQUEST_HPP
#define CHANGEREQUEST_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <limits>
#include <fstream>
#include <cstring>
#include "definitions.hpp"

using namespace std;

class ChangeRequest{
    private:
        long int id;
        string customer_name;
        string reported_release;
        string request_date;
    public:
        // constructor
        ChangeRequest();
        // destructor
        ~ChangeRequest();
        // get id
        long int get_id();
        // get customer name
        string get_customer_name();
        // get reported release
        string get_reported_release();
        // get request date
        string get_request_date();
        // set id
        void set_id(long int id);
        // set customer name
        void set_customer_name(string customer_name);
        // set reported release
        void set_reported_release(string reported_release);
        // set request date
        void set_request_date(string request_date);
        // print change request info
        void print_change_request_info();
        // register new change request
        void register_change_request();

};

// helper functions

// initialize change request database
bool init_change_request();

// add change request to file
bool make_change_request(ChangeRequest* changeRequest // change request to add
                        );

// close change request database file
bool close_change_request();

// file operations

// write change request to file
bool write_change_request(ChangeRequest &changeRequest // change request to write
                        );

// read change request from file
bool read_change_request(int index, ChangeRequest &changeRequest // index of change request to read
                        );

// delete change request from file
bool delete_change_request(int index // index of change request to delete
                        );


#endif