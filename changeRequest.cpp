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
fstream changeIdFile;
long int id_official;
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
void ChangeRequest::set_customer_name(string customer_name) {
    strcpy(this->customer_name, customer_name.c_str());
}

//-----------------------------------------------------------------------------
// set reported release
void ChangeRequest::set_reported_release(string reported_release) {
    strcpy(this->reported_release, reported_release.c_str());
}

//-----------------------------------------------------------------------------
// set request date
void ChangeRequest::set_request_date(string request_date) {
    strcpy(this->request_date, request_date.c_str());
}

//-----------------------------------------------------------------------------
// print change request info
void ChangeRequest::print_change_request_info() {
    cout << "Change Request ID: " << id << endl;
    cout << "Customer Name: " << customer_name << endl;
    cout << "Reported Release: " << reported_release << endl;
    cout << "Request Date: " << request_date << endl;
}
//-----------------------------------------------------------------------------
// register new change request
void ChangeRequest::register_change_request() {
    //prompt user for change request information
    cout << "Enter Customer Name: ";
    string customer_name;
    cin.ignore();
    getline(cin, customer_name);
    set_customer_name(customer_name);

    cout << "Enter Reported Release: ";
    string reported_release;
    cin >> reported_release;
    set_reported_release(reported_release);

    cout << "Enter Request Date (YYYY-MM-DD): ";
    string request_date;
    cin >> request_date;
    set_request_date(request_date);
}
//-----------------------------------------------------------------------------
//initialize change request database
bool init_change_request() {
    //open file for reading/writing and create it if it doesn't exist
    changeRequestFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(changeRequestFile.is_open()) {
        return true;
    } else { //otherwise return false
        changeRequestFile.clear();
        changeRequestFile.open(PRODUCT_FILE, ios::out | ios::binary);
        if (changeRequestFile.is_open()) {
            changeRequestFile.close();
            changeRequestFile.open(PRODUCT_FILE, ios::in | ios::out | ios::binary);
            return true;
        }
        //and if it doesn't work, return false
        return false;
    }

}
//-----------------------------------------------------------------------------
//generates change id
long int generate_id() {
    changeIdFile.open(CHANGE_ID_FILE, ios::in | ios::out);
    long change_id = 1;

    // Check if the file exists and can be opened for reading and writing
    if (changeIdFile) {
        // Read the current change_id from the file
        changeIdFile >> change_id;

        // Move the file pointer to the beginning for writing the new value
        changeIdFile.seekp(0, std::ios::beg);
    } else {
        // If the file doesn't exist, create it and set change_id to 1
        changeIdFile.open(CHANGE_ID_FILE, std::ios::out);
    }

    long old_value = change_id;

    // Increment the change_id
    change_id++;

    // Write the new change_id back to the file
    changeIdFile << change_id;
    changeIdFile.close();

    // Return the old value (before the increment)
    return old_value;
}

//-----------------------------------------------------------------------------
// add change request to file
bool make_change_request(const long int id, const char customer_name[MAX_NAME], 
const char reported_release[MAX_NAME], const char request_date[MAX_DATE]) {
    ChangeRequest temp_request(id, customer_name, reported_release, request_date);
    //write change request to file
    write_change_request(temp_request);
    return true;
}

//-----------------------------------------------------------------------------
// close change request database file
bool close_change_request() {
    if (changeRequestFile.is_open()) {
        changeRequestFile.close();
        //return true;
    }
    return true;
}

//-----------------------------------------------------------------------------
bool create_report(long int ch_id){
    // if found, add customerName to a .txt file
    ChangeRequest temp_changerequest;
    changeRequestFile.seekg(0, ios::beg);
    while (changeRequestFile.read((char*)&temp_changerequest, sizeof(ChangeRequest))) {
        if (temp_changerequest.get_id() == ch_id) { 
            cout << "Name: " << temp_changerequest.get_customer_name() << endl;
        }
    }
    changeRequestFile.clear();
    return false;

}

//-----------------------------------------------------------------------------
// write change request to file
bool write_change_request(ChangeRequest &changeRequest){
    changeRequestFile.seekp(0, ios::end); 
    changeRequestFile.write((char*)&changeRequest, sizeof(ChangeRequest));
    changeRequestFile.clear();
    if (changeRequestFile.fail()) {
        cout << "Error writing to change request file." << endl;
        return false;
    }
    return true;
}

//-----------------------------------------------------------------------------
// read change request from file
bool read_change_request(int index, ChangeRequest &changeRequest){
    changeRequestFile.seekg(index * sizeof(ChangeRequest), ios::beg);
    changeRequestFile.read((char*)&changeRequest, sizeof(ChangeRequest));
    return true;
}

// //-----------------------------------------------------------------------------
// // delete change request from file
// bool delete_change_request(int index){
//     fstream tempFile("temp_changereq.dat", ios::out | ios::binary);
//     // seek to start of file

//     changeRequestFile.seekg(0, ios::beg);

//     // copy all records except the one to be deleted
//     ChangeRequest tempChangeRequest;
//     int i = 0;
//     while (changeRequestFile.read((char*)&tempChangeRequest, sizeof(ChangeRequest))) {
//         if (i != index) {
//             tempFile.write((char*)&tempChangeRequest, sizeof(ChangeRequest));
//         }
//         i++;
//     }

//     // Clear the file (truncate to 0 and seek to the beginning)
//     changeRequestFile.close();
//     changeRequestFile.open(CHANGE_ITEM_FILE, ios::out | ios::trunc);
//     changeRequestFile.close();
//     changeRequestFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);

//     // copy all records back
//     tempFile.seekg(0, ios::beg);
//     while (tempFile.read((char*)&tempChangeRequest, sizeof(ChangeRequest))) {
//         changeRequestFile.write((char*)&tempChangeRequest, sizeof(ChangeRequest));
//     }

//     // clear and close temp file
//     tempFile.close();
//     tempFile.open("temp_changereq.dat", ios::out | ios::trunc);
//     tempFile.close();

//     return true;
// }
    