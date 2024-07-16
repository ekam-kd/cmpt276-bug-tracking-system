/* 
 * File:   release.hpp
 * Author: Qiraa Qadri
 * Created: Julyy 2024
 * Version 1.0
 * Purpose: Class definition for product release class
*/

#ifndef RELEASE_HPP
#define RELEASE_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <limits>
#include "definitions.hpp"
using namespace std;

class Release{
    private:
        char productName[MAX_NAME];
        char version[MAX_NAME];
        char description[MAX_DESCRIPTION];
        char date[MAX_NAME];
        char status[MAX_NAME];
    public:
        // constructor
        Release();
        // destructor
        ~Release();
        // get product name
        char* get_productName();
        // get version
        char* get_version();
        // get description
        char* get_description();
        // get date
        char* get_date();
        // get status
        char* get_status();
        // set product name
        void set_productName(char* productName);
        // set version
        void set_version(char* version);
        // set description
        void set_description(char* description);
        // set date
        void set_date(char* date);
        // set status
        void set_status(char* status);
        // print release info
        void print_release_info();
};

// helper functions

// initialize release database
bool init_release();

// create a new product release and add to file
bool create_product_release(Release* release // release to initialize
                );

// close release database file
bool close_product_release();

// select anticipated release
bool select_anticipated_release();

// update the anticipated release
bool update_anticipated_release();

#endif