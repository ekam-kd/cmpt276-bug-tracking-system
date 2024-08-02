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
        char customer_name[MAX_NAME];
        char reported_release[MAX_NAME];
        char request_date[MAX_DATE];
    public:
        ChangeRequest();
        // constructor
        ChangeRequest(const long int id, const char customer_name[MAX_NAME], 
        const char reported_release[MAX_NAME], const char request_date[MAX_DATE]);
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
        void set_customer_name(const char customer_name[MAX_NAME]);
        // set reported release
        void set_reported_release(const char reported_release[MAX_NAME]);
        // set request date
        void set_request_date(const char request_date[MAX_DATE]);
        // print change request info
        void print_change_request_info();
        // register new change request
        void register_change_request();

};

// helper functions

// initialize change request database
bool init_change_request();

// add change request to file
bool make_change_request(const long int id, const char customer_name[MAX_NAME], 
        const char reported_release[MAX_NAME], const char request_date[MAX_DATE]
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
// bool delete_change_request(int index // index of change request to delete
//                         );


#endif