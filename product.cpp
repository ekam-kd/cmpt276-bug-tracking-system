/*
 * File:   product.cpp
 * Author: Ashley Kim, Ekam Dhanoa
 * Created: July 2024
 * Version 1
 * Purpose: implementation of the Product class
 */

#include "product.hpp"
#include <cstring> // For strcpy, strncpy
#include <fstream> // For file operations
using namespace std;

// global filestream for product file
fstream productFile;


//-----------------------------------------------------------------------------
// Constructor
Product::Product(const char name[MAX_PRODUCT_NAME]) {
    set_name(name);
}
//-----------------------------------------------------------------------------
// Destructor
Product::~Product()
{
    // No dynamic memory to clean up, so this is empty
}
//-----------------------------------------------------------------------------
// Get name
char* Product::get_name()
{
    return product_name;
}
//-----------------------------------------------------------------------------
// Set name
void Product::set_name(const char* newName)
{
    strncpy(product_name, newName, MAX_PRODUCT_NAME - 1);
    product_name[MAX_PRODUCT_NAME - 1] = '\0'; // Ensure null-terminated
}
//-----------------------------------------------------------------------------
// Print product info
void Product::print_product_info() const
{
    std::cout << "Product Name: " << product_name << std::endl;
}

//-----------------------------------------------------------------------------
bool init_product()
{
    productFile.open(PRODUCT_FILE, ios::in | ios::out | ios::binary);

    // if file opened successfully, return true
    if (productFile.is_open())
    {
        return true;
    }
    else
    { // otherwise try opening again
        productFile.clear();
        productFile.open(PRODUCT_FILE, ios::out | ios::binary);
        if (productFile.is_open()) {
            productFile.close();
            productFile.open(PRODUCT_FILE, ios::in | ios::out | ios::binary);
            return true;
        }
        //and if it doesn't work, return false
        return false;
    }
}

//-----------------------------------------------------------------------------
// Checks to ensure product name is unique; used in add_product
bool check_product(const char prod_name[MAX_PRODUCT_NAME]) {
    //check to make sure productFile is open
    if (!productFile.is_open())
    {
        cerr << "Product database file is not open!" << endl;
        return false;
    }
    Product temp_product("");
    productFile.seekg(0, ios::beg);

    // Read through the file
    while (productFile.read(reinterpret_cast<char*>(&temp_product), sizeof(Product))) {
        if (strcmp(temp_product.get_name(),prod_name) == 0) {
            cout << "A product with this name already exists." << endl;
            return true;
        }
    }

    // Reset the file pointer for future operations
    productFile.clear(); // Clear the EOF flag
    return false;

}

//-----------------------------------------------------------------------------
// Add product to file
bool add_product(const char prod_name[MAX_PRODUCT_NAME])
{
    if (!productFile.is_open())
    {
        cerr << "Product database file is not open!" << endl;
        return false;
    }
    //if a product with the name provided already exists, return false
    if (check_product(prod_name)) {
        return false;
    }
    
    Product new_product(prod_name);
    productFile.seekp(0, ios::end);
    // Write product to file
    productFile.write(reinterpret_cast<const char *>(&new_product), sizeof(Product));
    productFile.clear();

    if (productFile.fail()) {
        cerr << "Error writing to the product file." << endl;
        return false;
    }
    return true;
}

//-----------------------------------------------------------------------------
// Displays list of products, allows user to select one
// OOH it could return a struct, with
bool select_product(const char prod_name[MAX_PRODUCT_NAME])
{
    Product temp_product("");

    // Move the file pointer to the beginning of the file
    productFile.seekg(0, ios::beg);

    int count = 1;

    // print out all the products for user to see
    cout << "List of products: " << endl;
    while (productFile.read(reinterpret_cast<char*>(&temp_product), sizeof(Product))) {
        cout << count << ". " << temp_product.get_name() << endl;
        count++;
    }
    if (count == 1) {
        cout << "No products registered." << endl;
        return false;
    }

    Product temp2("");
    productFile.seekg(0, ios::beg);
    while (productFile.read(reinterpret_cast<char*>(&temp2), sizeof(Product))) {
        if (strcmp(temp2.get_name(), prod_name) == 0) {
            productFile.clear(); // Clear the EOF flag
            return true;
        }
    }
    cout << "You entered a product that does not exist." << endl;
    // Reset the file pointer for future operations
    productFile.clear(); // Clear the EOF flag
    cout << "Invalid product selection" << endl;
    return false;
}

//-----------------------------------------------------------------------------
// Read product from file
bool read_product(int index, Product &product)
{
    if (!productFile.is_open())
    {
        cerr << "Product database file is not open!" << endl;
        return false;
    }

    // Seek to the correct position in the file
    productFile.seekg(index * sizeof(Product), ios::beg);
    // Read product from file
    productFile.read(reinterpret_cast<char *>(&product), sizeof(Product));
    return true;
}

// Close product database file
bool close_product()
{
    if (productFile.is_open())
    {
        productFile.close();
    }
    return true;
}
//-----------------------------------------------------------------------------