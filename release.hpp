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
        char productName[MAX_NAME];
        char version[MAX_NAME];
        char description[MAX_DESCRIPTION];
        char date[MAX_NAME];
    public:
        // constructor
        Release();
        Release(const char productName[MAX_NAME], const char version[MAX_NAME], 
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
        void set_productName(string productName);
        // set version
        void set_version(string version);
        // set description
        void set_description(string description);
        // set date
        void set_date(string date);
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

char* select_product_release(char product_name[MAX_PRODUCT_NAME]);

// file operations
bool write_release(Release &release);
bool read_release(int index ,Release &release);
bool delete_release(int index);

#endif