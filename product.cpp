/* 
 * File:   product.cpp
 * Author: Ashley Kim
 * Created: July 2024
 * Version 1.1
 * Purpose: implementation of the Product class
*/

#include "product.hpp"
#include <cstring> // For strcpy, strncpy
#include <fstream> // For file operations

//global filestream for product file so it stays open for program duration
fstream productFile;

bool init_product() {
    //open file for reading/writing and create it if it doesn't exist
    productFile.open(PRODUCT_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(productFile.is_open()) {
        return true;
    } else { //otherwise return false
        return false;
    }
}

// Constructor
Product::Product() {
    strcpy(name, "NOT_SET");
}

// Destructor
Product::~Product() {
    // No dynamic memory to clean up, so this is empty
}

// Get name
const char* Product::get_name() const {
    return name;
}

// Set name
void Product::set_name(const char* newName) {
    strncpy(name, newName, MAX_NAME - 1);
    name[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}

// Print product info
void Product::print_product_info() const {
    std::cout << "Product Name: " << name << std::endl;
}


// Displays list of products, allows user to select one
Product select_product() {
    // Placeholder for actual implementation
    // For simplicity, we will return a product with a hardcoded name
    Product product;
    product.set_name("Sample Product");
    return product;
}

// Add product to file
bool add_product(const Product& product) {
    ofstream outfile("product_db.txt", ios::app); // Open in append mode
    if (!outfile) {
        cerr << "Error opening product database file!" << endl;
        return false;
    }
    outfile << product.get_name() << endl;
    outfile.close();
    return true;
}

// Close product database file
bool close_product() {
    // Placeholder for any cleanup code
    // For example, closing a file or a database connection
    return true;
}