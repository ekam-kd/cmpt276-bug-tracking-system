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
// constructor
Release::Release(const char productName[MAX_PRODUCT_NAME], const char version[MAX_NAME], 
        const char description[MAX_DESCRIPTION], const char date[MAX_DATE]) {
    //initialize all member variables to empty strings
    set_productName(productName);
    set_version(version);
    set_description(description);
    set_date(date);
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
void Release::set_productName(const char newName[MAX_PRODUCT_NAME]) {
    strncpy(productName, newName, MAX_PRODUCT_NAME - 1);
    productName[MAX_PRODUCT_NAME - 1] = '\0'; // Ensure null-terminated
}

//-----------------------------------------------------------------------------
// set version
void Release::set_version(const char new_version[MAX_PRODUCT_NAME]) {
    strncpy(version, new_version, MAX_PRODUCT_NAME - 1);
    version[MAX_PRODUCT_NAME - 1] = '\0'; // Ensure null-terminated
}

//-----------------------------------------------------------------------------
// set description
void Release::set_description(const char new_description[MAX_DESCRIPTION]) {
    strncpy(description, new_description, MAX_DESCRIPTION - 1);
    description[MAX_DESCRIPTION - 1] = '\0'; // Ensure null-terminated
}

//-----------------------------------------------------------------------------
// set date
void Release::set_date(const char new_date[MAX_DATE]) {
    strncpy(date, new_date, MAX_DATE - 1);
    date[MAX_DATE - 1] = '\0'; // Ensure null-terminated
}

//-----------------------------------------------------------------------------
//initialize product release database
bool init_release() {
    //open file for reading/writing and create it if it doesn't exist
    releaseFile.open(RELEASE_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(releaseFile.is_open()) {
        return true;
    } else { //otherwise return false
        releaseFile.clear();
        releaseFile.open(RELEASE_FILE, ios::out | ios::binary);
        if (releaseFile.is_open()) {
            releaseFile.close();
            releaseFile.open(RELEASE_FILE, ios::in | ios::out | ios::binary);
            return true;
        }
        //and if it doesn't work, return false
        return false;
    }

}

//-----------------------------------------------------------------------------
// displays product releases of a particular product
bool display_product_releases(const char prod_name[MAX_PRODUCT_NAME]) {
    Release temp_release("", "", "", "");
    // Move the file pointer to the beginning of the file
    releaseFile.seekg(0, ios::beg);
    int count = 1;
    // displays list of products
    while (releaseFile.read(reinterpret_cast<char*>(&temp_release), sizeof(Release))) {
        if (strcmp(temp_release.get_productName(), prod_name) == 0) {
            cout << "Release " << count << ". " << temp_release.get_version() << "    Date: " << temp_release.get_date() << endl;
            count++;
        }
    }
    if (count == 1) {
        cout << "No versions. Returning to main menu..." << endl;
        releaseFile.clear();
        return false;
    } else {
        releaseFile.clear();
        return true;
    }
}

//-----------------------------------------------------------------------------
// check that a release exists
bool check_release(const char productName[MAX_PRODUCT_NAME], const char version[MAX_NAME]) {
    if (!releaseFile.is_open())
    {
        cerr << "Product database file is not open!" << endl;
        return false;
    }

    Release temp_release("", "", "", "");
    releaseFile.clear();
    releaseFile.seekg(0, ios::beg);

    // Read through the file
    while (releaseFile.read(reinterpret_cast<char*>(&temp_release), sizeof(Release))) {
        if ((strcmp(temp_release.get_productName(), productName) == 0) && (strcmp(temp_release.get_version(), version) == 0)) {
            releaseFile.clear();
            return true;
        }
    }
   // cout << "product not found?" << endl;

    // Reset the file pointer for future operations
    releaseFile.clear(); // Clear the EOF flag
    return false;
}


//-----------------------------------------------------------------------------
// create a new product release and add to file
bool create_product_release(const char productName[MAX_PRODUCT_NAME], const char version[MAX_NAME], 
const char description[MAX_DESCRIPTION], const char date[MAX_DATE]){
    if (!releaseFile.is_open())
    {
        cerr << "Release database file is not open!" << endl;
        return false;
    }
    Release new_release(productName, version, description, date);
    releaseFile.seekp(0, ios::end);
    // Write product to file
    releaseFile.write(reinterpret_cast<const char *>(&new_release), sizeof(Release));
    releaseFile.clear();

    if (releaseFile.fail()) {
        cerr << "Error writing to the release file." << endl;
        sleep(2);
        return false;
    }
    cout << "Product Release successfully created!" << endl;
    return true;
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
