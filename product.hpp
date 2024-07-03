/* 
 * File:   product.hpp
 * Author: Qiraa Qadri
 * Created: July 2024
 * Version 1.0
 * Purpose: implementation of the Product class
*/

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ios>
#include <limits>
#include "definitions.hpp"
using namespace std;

class Product{
    private:
        char name[MAX_NAME];
    public:
        // constructor
        Product();
        // destructor
        ~Product();
        // get name
        char* get_name();
        // set name
        void set_name(char* name);
        // print product info
        void print_product_info();
};

// helper functions

// initialize product database
bool init_product();

// displays list of products, allows user to select one
Product select_product();

// add product to file
bool add_product(Product* product // product to add
                );

// close product database file
bool close_product();

#endif