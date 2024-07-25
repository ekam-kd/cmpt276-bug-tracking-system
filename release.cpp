/* 
 * File:   release.hpp
 * Author: Qiraa Qadri, Ekam Dhanoa
 * Created: July 2024
 * Version 1
 * Purpose: Class definition for Release class
*/
#include "release.hpp"
#include <vector>
//global filestream for product release file so it stays open for program duration
fstream releaseFile;

//-----------------------------------------------------------------------------
//initialize product release database
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

//-----------------------------------------------------------------------------
//close product release file
bool close_product_release() {
    if (releaseFile.is_open()) {
        releaseFile.close();
        return true;
    }
    return false;
}

//-----------------------------------------------------------------------------
// constructor
Release::Release() {
    //initialize all member variables to empty strings
    strcpy(productName, "");
    strcpy(version, "");
    strcpy(description, "");
    strcpy(date, "");
}

//-----------------------------------------------------------------------------
// destructor
Release::~Release() {
    //nothing to do here
}

//-----------------------------------------------------------------------------
// get product name
char* Release::get_productName() {
    return productName;
}

//-----------------------------------------------------------------------------
// get version
char* Release::get_version() {
    return version;
}

//-----------------------------------------------------------------------------
// get description
char* Release::get_description() {
    return description;
}

//-----------------------------------------------------------------------------
// get date
char* Release::get_date() {
    return date;
}

//-----------------------------------------------------------------------------
// set product name
void Release::set_productName(string productName) {
    strcpy(this->productName, productName.c_str());
}

//-----------------------------------------------------------------------------
// set version
void Release::set_version(string version) {
    strcpy(this->version, version.c_str());
}

//-----------------------------------------------------------------------------
// set description
void Release::set_description(string description) {
    strcpy(this->description, description.c_str());
}

//-----------------------------------------------------------------------------
// set date
void Release::set_date(string date) {
    strcpy(this->date, date.c_str());
}

//-----------------------------------------------------------------------------
// print release info
void Release::print_release_info() {
    cout << "Product Name: " << productName << endl;
    cout << "Version: " << version << endl;
    cout << "Description: " << description << endl;
    cout << "Date: " << date << endl;
}

//-----------------------------------------------------------------------------
// write release to file
bool write_release(Release &release) {
    // assume file is open
    // seek to the end of the file
    releaseFile.seekp(0, ios::end);
    // write release to file
    releaseFile.write((char*)&release, sizeof(Release));
    return true;
}

//-----------------------------------------------------------------------------
// read release from file
bool read_release(int index, Release &release) {
    // assume file is open
    // seek to the correct position in the file
    releaseFile.seekg(index * sizeof(Release), ios::beg);
    // read release from file
    releaseFile.read((char*)&release, sizeof(Release));
    return true;
}

//-----------------------------------------------------------------------------
// delete release from file
bool delete_release(int index) {
    fstream tempFile("temp_release.dat", ios::out | ios::binary);

    // Seek to the start of the file
    releaseFile.seekg(0, std::ios::beg);

    // Read all releases into memory except the one to be deleted
    Release tempRelease;
    int currentIndex = 0;
    while (releaseFile.read(reinterpret_cast<char*>(&tempRelease), sizeof(Release))) {
        if (currentIndex != index) {
            tempFile.write(reinterpret_cast<const char*>(&tempRelease), sizeof(Release));
        }
        currentIndex++;
    }

    // Clear the file (truncate to 0 and seek to the beginning)
    releaseFile.close();
    releaseFile.open(RELEASE_FILE, ios::out | ios::trunc);
    releaseFile.close();
    releaseFile.open(RELEASE_FILE, ios::in | ios::out | ios::binary);

    // Copy the temp file back to the original file
    tempFile.seekg(0, std::ios::beg);
    while (tempFile.read(reinterpret_cast<char*>(&tempRelease), sizeof(Release))) {
        releaseFile.write(reinterpret_cast<const char*>(&tempRelease), sizeof(Release));
    }

    // Close the temp file
    tempFile.close();
    tempFile.open("temp_release.dat", std::ios::out | std::ios::trunc);
    tempFile.close();

    return true;
}

//-----------------------------------------------------------------------------
// create a new product release and add to file
bool create_product_release(Release* release){
    // write release to file
    write_release(*release);
    return true;
}
