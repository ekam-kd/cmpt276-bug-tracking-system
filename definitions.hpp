/* 
 * File:   definitions.hpp
 * Author: Qiraa Qadri, Ekam Dhanoa
 * Created: July 2024
 * Version 2
 * Purpose: definitions and constants for use in other modules
*/

#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <fstream>

// set in requirements spec
#define MAX_NAME 30 
#define MAX_DESCRIPTION 280
#define MAX_EMAIL 64
#define MAX_PHONE 12
#define MAX_DATE 12
#define MAX_DEPARTMENT 30

// database file names
#define CUSTOMER_FILE "customers.bin"
#define RELEASE_FILE "releases.bin"
#define CHANGE_ITEM_FILE "changeItems.bin"
#define CHANGE_REQUEST_FILE "changeRequests.bin"
#define PRODUCT_FILE "products.bin"


// //global filestream for customer file so it stays open for program duration
// extern std::fstream releaseFile, changeItemFile, changeRequestFile, productFile;


#endif