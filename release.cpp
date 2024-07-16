/* 
 * File:   customer.hpp
 * Author: Qiraa Qadri
 * Created: July 2024
 * Version 1.1
 * Purpose: Class definition for Release class
*/
#include "release.hpp"
//global filestream for product release file so it stays open for program duration
fstream releaseFile;

bool init_release() {
    //open file for reading/writing and create it if it doesn't exist
    releaseFile.open(RELEASE_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(releaseFile.is_open()) {
        return true;
    } else { //otherwise return false
        return false;
    }

}

//close product release file
bool close_product_release() {
    if (releaseFile.is_open()) {
        releaseFile.close();
        return true;
    }
    return false;
}

// constructor
Release::Release() {
    //initialize all member variables to empty strings
    strcpy(productName, "");
    strcpy(version, "");
    strcpy(description, "");
    strcpy(date, "");
    strcpy(status, "");
}

// destructor
Release::~Release() {
    //nothing to do here
}

// get product name
char* Release::get_productName() {
    return productName;
}

// get version
char* Release::get_version() {
    return version;
}

// get description
char* Release::get_description() {
    return description;
}

// get date
char* Release::get_date() {
    return date;
}

// get status
char* Release::get_status() {
    return status;
}

// set product name
void Release::set_productName(string productName) {
    strcpy(this->productName, productName.c_str());
}

// set version
void Release::set_version(string version) {
    strcpy(this->version, version.c_str());
}

// set description
void Release::set_description(string description) {
    strcpy(this->description, description.c_str());
}

// set date
void Release::set_date(string date) {
    strcpy(this->date, date.c_str());
}

// set status
void Release::set_status(string status) {
    strcpy(this->status, status.c_str());
}

// print release info
void Release::print_release_info() {
    cout << "Product Name: " << productName << endl;
    cout << "Version: " << version << endl;
    cout << "Description: " << description << endl;
    cout << "Date: " << date << endl;
    cout << "Status: " << status << endl;
}


// write release to file
bool write_release(Release &release) {
    // assume file is open
    // seek to the end of the file
    releaseFile.seekp(0, ios::end);
    // write release to file
    releaseFile.write((char*)&release, sizeof(Release));
    return true;
}

// read release from file
bool read_release(int index, Release &release) {
    // assume file is open
    // seek to the correct position in the file
    releaseFile.seekg(index * sizeof(Release), ios::beg);
    // read release from file
    releaseFile.read((char*)&release, sizeof(Release));
    return true;
}

// delete release from file
// DOES NOT WORK
bool delete_release(int index) {
    // assume file is open
    // seek to the correct position in the file
    
    releaseFile.seekg(0, ios::end);
    streampos fileSize = releaseFile.tellg();
    int numReleases = fileSize / sizeof(Release);

    if(index < 0 || index >= numReleases) {
        return false;
    }

    // move all releases after the one to be deleted
    Release last_release;
    releaseFile.seekg((numReleases - 1) * sizeof(Release), ios::beg);
    releaseFile.read((char*)&last_release, sizeof(Release));
    releaseFile.seekp(index * sizeof(Release), ios::beg);
    releaseFile.write((char*)&last_release, sizeof(Release));

    // truncate the file
    if(truncate(RELEASE_FILE, (numReleases - 1)* sizeof(Release)) != 0) {
        return false;
    }

    return true;

}