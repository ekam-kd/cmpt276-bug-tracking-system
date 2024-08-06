/* 
 * File: changeRequest.cpp
 * Author: Qiraa Qadri, Ekam Dhanoa
 * Created: July 2024
 * Version 1
 * Purpose: Implementation for Change Item class
*/
#include "changeRequest.hpp"

//global filestream for change request file so it stays open for program duration
fstream changeRequestFile;

//-----------------------------------------------------------------------------
// constructor
ChangeRequest::ChangeRequest(const long int new_id, const char new_name[MAX_NAME], 
        const char new_release[MAX_NAME], const char new_date[MAX_DATE]) {
    //initialize all member variables to empty strings
    set_id(new_id);
    set_customer_name(new_name);
    set_reported_release(new_release);
    set_request_date(new_date);
}

ChangeRequest::ChangeRequest() {
    //nothing to do here
}
//-----------------------------------------------------------------------------
// destructor
ChangeRequest::~ChangeRequest() {
    //nothing to do here
}

//-----------------------------------------------------------------------------
// get id
long int ChangeRequest::get_id() {
    return id;
}

//-----------------------------------------------------------------------------
// get customer name
char* ChangeRequest::get_customer_name() {
    return customer_name;
}   

//-----------------------------------------------------------------------------
// get reported release
char* ChangeRequest::get_reported_release() {
    return reported_release;
}

//-----------------------------------------------------------------------------
// get request date
char* ChangeRequest::get_request_date() {
    return request_date;
}

//-----------------------------------------------------------------------------
// set id
void ChangeRequest::set_id(long int id) {
    this->id = id;
}

//-----------------------------------------------------------------------------
// set customer name
void ChangeRequest::set_customer_name(const char new_name[MAX_NAME]) {
    strncpy(customer_name, new_name, MAX_NAME - 1);
    customer_name[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}
// set reported release
void ChangeRequest::set_reported_release(const char new_release[MAX_NAME]) {
    strncpy(reported_release, new_release, MAX_NAME - 1);
    reported_release[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}
// set request date
void ChangeRequest::set_request_date(const char new_date[MAX_DATE]) {
    strncpy(request_date, new_date, MAX_DATE - 1);
    request_date[MAX_DATE - 1] = '\0'; // Ensure null-terminated
}

//-----------------------------------------------------------------------------
//initialize change request database
bool init_change_request() {
    //open file for reading/writing and create it if it doesn't exist
    changeRequestFile.open(CHANGE_REQUEST_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(changeRequestFile.is_open()) {
        return true;
    } else { //otherwise return false
        changeRequestFile.clear();
        changeRequestFile.open(CHANGE_REQUEST_FILE, ios::out | ios::binary);
        if (changeRequestFile.is_open()) {
            changeRequestFile.close();
            changeRequestFile.open(CHANGE_REQUEST_FILE, ios::in | ios::out | ios::binary);
            return true;
        }
        //and if it doesn't work, return false
        return false;
    }

}

//-----------------------------------------------------------------------------
// add change request to file
bool make_change_request(const long int id, const char customer_name[MAX_NAME], 
const char reported_release[MAX_NAME], const char request_date[MAX_DATE]) {
    if (!changeRequestFile.is_open())
    {
        cerr << "Change Request database file is not open!" << endl;
        return false;
    }
    ChangeRequest temp_request(id, customer_name, reported_release, request_date);
    changeRequestFile.seekp(0, ios::end);
    // Write product to file
    changeRequestFile.write(reinterpret_cast<const char *>(&temp_request), sizeof(ChangeRequest));
    changeRequestFile.clear();

    if (changeRequestFile.fail()) {
        cerr << "Error writing to the change request file." << endl;
        sleep(2);
        return false;
    }
    // cout << "Id is: " << temp_request.get_id() << " and name is: " << temp_request.get_customer_name();
    // cout << " and release is: " << temp_request.get_reported_release() << " and date is: " << temp_request.get_request_date() << endl;
    cout << "Change Request successfully created!" << endl;
    return true;
}


//-----------------------------------------------------------------------------
// close change request database file
// APPROVED
bool close_change_request() {
    if (changeRequestFile.is_open()) {
        changeRequestFile.close();
        return true;
    }
    return false;
}
