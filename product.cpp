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
// Constructor
Product::Product(const string name)
: product_name(name) {
}
//-----------------------------------------------------------------------------
// Destructor
Product::~Product()
{
    // No dynamic memory to clean up, so this is empty
}
//-----------------------------------------------------------------------------
// Get name
string Product::get_name() const
{
    return product_name;
}
//-----------------------------------------------------------------------------
// Set name
void Product::set_name(string newName)
{
    product_name = newName;
}
//-----------------------------------------------------------------------------
// Print product info
void Product::print_product_info() const
{
    std::cout << "Product Name: " << product_name << std::endl;
}
//-----------------------------------------------------------------------------
// Displays list of products, allows user to select one
Product select_product()
{
    // Placeholder for actual implementation
    // For simplicity, we will return a product with a hardcoded name
    Product product("");
    product.set_name("Sample Product");
    return product;
}
//-----------------------------------------------------------------------------
// Add product to file
bool add_product(const string prod_name)
{
    if (!productFile.is_open())
    {
        cerr << "Product database file is not open!" << endl;
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
//-----------------------------------------------------------------------------
// Delete product by index
bool delete_product(int index)
{
    // Open temporary file for writing
    ofstream tempFile("temp_product_db.txt", ios::out | ios::binary);
    if (!tempFile)
    {
        cerr << "Error opening temporary file!" << endl;
        return false;
    }

    // Open original file for reading
    ifstream infile(PRODUCT_FILE, ios::in | ios::binary);
    if (!infile)
    {
        cerr << "Error opening product database file!" << endl;
        return false;
    }

    Product product("");
    int currentIndex = 0;
    bool deleted = false;

    // Read each record and write to the temp file if it's not the one to be deleted
    while (infile.read(reinterpret_cast<char *>(&product), sizeof(Product)))
    {
        if (currentIndex != index)
        {
            tempFile.write(reinterpret_cast<char *>(&product), sizeof(Product));
        }
        else
        {
            deleted = true; // Record found and deleted
        }
        currentIndex++;
    }

    // Close files
    infile.close();
    tempFile.close();

    // Replace original file with temporary file if deletion was successful
    if (deleted)
    {
        remove(PRODUCT_FILE);                        // Delete original file
        rename("temp_product_db.txt", PRODUCT_FILE); // Rename temp file to original file name
    }
    else
    {
        remove("temp_product_db.txt"); // Delete temp file if deletion was not successful
    }

    return deleted;
}
//-----------------------------------------------------------------------------
// Close product database file
bool close_product()
{
    if (productFile.is_open())
    {
        productFile.close();
    }
    if (remove(PRODUCT_FILE) == 0)
    {
        //cout << "File successfully deleted." << endl;
        return true;
    }
    else
    {
        cerr << "Error deleting the file." << endl;
        return false;
    }
}
//-----------------------------------------------------------------------------