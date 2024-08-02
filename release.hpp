/* 
 * File:   release.hpp
 * Author: Qiraa Qadri
 * Created: Julyy 2024
 * Version 2
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
#include <fstream>
#include <cstring>
using namespace std;

class Release{
    private:
        char productName[MAX_PRODUCT_NAME];
        char version[MAX_NAME];
        char description[MAX_DESCRIPTION];
        char date[MAX_NAME];
    public:
        // constructor
        Release(const char productName[MAX_PRODUCT_NAME], const char version[MAX_NAME], 
        const char description[MAX_DESCRIPTION], const char date[MAX_NAME]);
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
        // set product name
        void set_productName(const char productName[MAX_PRODUCT_NAME]);
        // set version
        void set_version(const char version[MAX_NAME]);
        // set description
        void set_description(const char description[MAX_DESCRIPTION]);
        // set date
        void set_date(const char date[MAX_NAME]);
        // print release info
        void print_release_info();
};

// helper functions

// initialize release database
bool init_release();

bool display_product_releases(const char prod_name[MAX_PRODUCT_NAME]);

// create a new product release and add to file
bool create_product_release(Release* release // release to initialize
                );

// close release database file
bool close_product_release();

// file operations
bool write_release(Release &release);
bool read_release(int index ,Release &release);
bool delete_release(int index);

#endif