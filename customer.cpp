/* 
 * File:   customer.cpp
 * Author: Qiraa Qadri
 * Created: Julyy 2024
 * Version 1.0
 * Purpose: Class implementation for Customer class
*/
#include "customer.hpp"
//global filestream for customer file so it stays open for program duration
fstream customerFile;

bool init_customer() {
    //open file for reading/writing and create it if it doesn't exist
    customerFile.open(CUSTOMER_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(customerFile.is_open()) {
        return true;
    } else { //otherwise return false
        return false;
    }

}