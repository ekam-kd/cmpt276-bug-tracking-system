/*
 * File:   product.hpp
 * Author: Qiraa Qadri
 * Created: July 2024
 * Version 2
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
#include <fstream>
using namespace std;

class Product
{
private:
    char product_name[MAX_PRODUCT_NAME];

public:
    // constructor
    Product(const char name[MAX_PRODUCT_NAME]);
    // destructor
    ~Product();
    // get name
    char* get_name();
    // set name
    void set_name(const char name[MAX_PRODUCT_NAME]);
    // print product info
    void print_product_info() const;
};

// helper functions

// initialize product database
bool init_product();

bool check_product(const char prod_name[MAX_PRODUCT_NAME]);

// add product to file
bool add_product(const char prod_name[MAX_PRODUCT_NAME]);

// displays list of products, allows user to select one
char* select_product();

bool read_product(int index, Product &product);

//bool delete_product(int index);

// close product database file
bool close_product();

#endif