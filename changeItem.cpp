/* 
 * File: changeItem.cpp
 * Author: Qiraa , Ekam Dhanoa
 * Created: July 2024
 * Version 1
 * Purpose: implementation of the Change Item class
*/
#include "changeItem.hpp"
//global filestream for change item file so it stays open for program duration
fstream changeItemFile;

//-----------------------------------------------------------------------------
bool init_change_item() {
    //open file for reading/writing and create it if it doesn't exist
    changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(changeItemFile.is_open()) {
        return true;
    } else { //otherwise return false
        changeItemFile.clear();
        changeItemFile.open(CHANGE_ITEM_FILE, ios::out | ios::binary);
        if (changeItemFile.is_open()) {
            changeItemFile.close();
            changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
            return true;
        }
        //and if it doesn't work, return false
        return false;
    }

}

//-----------------------------------------------------------------------------
bool make_change_item(const long int id, const char productName[MAX_PRODUCT_NAME], const char productReleaseID[MAX_NAME], 
const char description[MAX_DESCRIPTION], const char status[MAX_NAME], const int priority, const int requests) {
    if (!changeItemFile.is_open())
    {
        cerr << "Change Item database file is not open!" << endl;
        return false;
    }
    ChangeItem temp_item(id, productName, productReleaseID, description, status, priority, requests);
    changeItemFile.seekp(0, ios::end);
    // Write product to file
    changeItemFile.write(reinterpret_cast<const char *>(&temp_item), sizeof(ChangeItem));
    changeItemFile.clear();

    if (changeItemFile.fail()) {
        cerr << "Error writing to the change item file." << endl;
        sleep(2);
        return false;
    }
    cout << "Id is: " << temp_item.get_id() << " and product name is: " << temp_item.get_productName();
    cout << " and release is: " << temp_item.get_productReleaseID() << " and priority is: " << temp_item.get_priority() << endl;
    cout << "Change Item successfully created!" << endl;
    return true;
}

//-----------------------------------------------------------------------------
// need to test this function
bool get_change_item(char* productName){
    ChangeItem changeItem;
    int i = 0;
    bool found = false;
    while(!found){
        if(!read_change_item(i, changeItem)){
            break;
        }
        char* name = changeItem.get_productName();
        if(strcmp(name, productName) == 0){
            found = true;
            changeItem.print_change_item_info();
            return true;
        } else {
            i++;
        }
    }
    return false;
}

//-----------------------------------------------------------------------------
// need to test this function
bool see_change_item(long int ch_id){
    ChangeItem changeItem;
    int i = 0;
    bool found = false;
    while(!found){
        if(!read_change_item(i, changeItem)){
            break;
        }
        long int id = changeItem.get_id();
        if(id == ch_id){
            found = true;
            changeItem.print_change_item_info();
            return true;
        } else {
            i++;
        }
    }
    return false;
}

//-----------------------------------------------------------------------------
// need to test this function
bool modify_change_item(long int ch_id){
    // find index of change item
    ChangeItem changeItem;
    int i = 0;
    bool found = false;
    while(!found){
        if(!read_change_item(i, changeItem)){
            return false;
        }
        long int id = changeItem.get_id();
        if(id == ch_id){
            found = true;
            break;
        } else {
            i++;
        }
    }
    
    // print change item info
    changeItem.print_change_item_info();
    // prompt user for changes
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new product name: ";
    string productName;
    char prod_name[MAX_PRODUCT_NAME];
    cin >> productName;
    strcpy(prod_name, productName.c_str());
    changeItem.set_productName(prod_name);
    cout << "Enter new product release ID: ";
    string productReleaseID;
    char release[MAX_NAME];
    cin >> productReleaseID;
    strcpy(release, productReleaseID.c_str());
    changeItem.set_productReleaseID(release);
    cout << "Enter new description: ";
    string description;
    char descr[MAX_DESCRIPTION];
    cin >> description;
    strcpy(descr, description.c_str());
    changeItem.set_description(descr);
    cout << "Enter new status: ";
    string status;
    char official_status[MAX_NAME];
    cin >> status;
    strcpy(official_status, status.c_str());
    changeItem.set_status(official_status);
    cout << "Enter new priority: ";
    int priority;
    cin >> priority;
    changeItem.set_priority(priority);
    cout << "Enter new # of requests: ";
    int requests;
    cin >> requests;
    changeItem.set_requests(requests);
    // modify change item by creating new change item and adding to file
    make_change_item(ch_id, prod_name, release, descr, official_status, priority, requests);

    // delete change item
    delete_change_item(i);
    return true;
}

//-----------------------------------------------------------------------------
// need to test this function
bool see_all_change_items(char* productName){
    ChangeItem changeItem;
    int i = 0;
    while(1){
        if(!read_change_item(i, changeItem)){
            break;
        }
        char* name = changeItem.get_productName();
        if(strcmp(name, productName) == 0){
            changeItem.print_change_item_info();
            i++;
        } else {
            i++;
        }
    }
    return true;
}

//-----------------------------------------------------------------------------
bool create_report(long int ch_id){
    // open changeRequest file + search fo matching ch_id
    // if found, add customerName to a .txt file
    ChangeRequest changeRequest;
    int i = 0;
    while(1){
        if(!read_change_request(i, changeRequest)){
            break;
        }
        long int id = changeRequest.get_id();
        if(id == ch_id){
            string customerName = changeRequest.get_customer_name();
            // find customer name in customer file + get their email
           // Customer customer = select_customer(customerName);
           // string customerEmail = customer.get_email();

            // write customer name and email to report.txt
            ofstream reportFile;
            reportFile.open("report.txt", ios::app);
           // reportFile << customerName << ", "<< customerEmail << endl;
            reportFile.close();
            return true;
        } else {
            i++;
        }
    }

    return true;
}

//-----------------------------------------------------------------------------
//close change item file
bool close_change_item() {
    if (changeItemFile.is_open()) {
        changeItemFile.close();
        return true;
    }
    return false;
}

//-----------------------------------------------------------------------------
// constructor
ChangeItem::ChangeItem() {
    //initialize all member variables to empty strings
    strcpy(productName, "");
    strcpy(productReleaseID, "");
    strcpy(description, "");
    strcpy(status, "");
    priority = 0;
    requests = 0;
    id = 0;
}
ChangeItem::ChangeItem(const long int id, const char productName[MAX_PRODUCT_NAME], const char productReleaseID[MAX_NAME], 
const char description[MAX_DESCRIPTION], const char status[MAX_NAME], const int priority, const int requests) {
    set_id(id);
    set_productName(productName);
    set_productReleaseID(productReleaseID);
    set_description(description);
    set_status(status);
    set_priority(priority);
    set_requests(requests);
}

//-----------------------------------------------------------------------------
// destructor
ChangeItem::~ChangeItem() {
    //nothing to do here
}

//-----------------------------------------------------------------------------
// get id
long int ChangeItem::get_id() {
    return id;
}

//-----------------------------------------------------------------------------
// get product name
char* ChangeItem::get_productName() {
    return productName;
}

//-----------------------------------------------------------------------------
// get product release ID
char* ChangeItem::get_productReleaseID() {
    return productReleaseID;
}

//-----------------------------------------------------------------------------
// get description
char* ChangeItem::get_description() {
    return description;
}

//-----------------------------------------------------------------------------
// get status
char* ChangeItem::get_status() {
    return status;
}

//-----------------------------------------------------------------------------
// get priority
int ChangeItem::get_priority() {
    return priority;
}   

//-----------------------------------------------------------------------------
// get requests
int ChangeItem::get_requests() {
    return requests;
}

//-----------------------------------------------------------------------------
// set id
void ChangeItem::set_id(long int id) {
    this->id = id;
}

//-----------------------------------------------------------------------------
void ChangeItem::set_productName(const char new_prod_name[MAX_PRODUCT_NAME]) {
    strncpy(productName, new_prod_name, MAX_PRODUCT_NAME - 1);
    productName[MAX_PRODUCT_NAME - 1] = '\0'; // Ensure null-terminated
}
// set product release ID
void ChangeItem::set_productReleaseID(const char new_release[MAX_NAME]) {
    strncpy(productReleaseID, new_release, MAX_NAME - 1);
    productReleaseID[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}
// set description
void ChangeItem::set_description(const char new_descr[MAX_DESCRIPTION]) {
    strncpy(description, new_descr, MAX_DESCRIPTION - 1);
    description[MAX_DESCRIPTION - 1] = '\0'; // Ensure null-terminated
}
// set status
void ChangeItem::set_status(const char new_status[MAX_NAME]) {
    strncpy(status, new_status, MAX_NAME - 1);
    status[MAX_NAME - 1] = '\0'; // Ensure null-terminated
}
// set priority
void ChangeItem::set_priority(const int new_priority) {
    this->priority = new_priority;
}
// set requests
void ChangeItem::set_requests(const int new_requests) {
    this->requests = new_requests;
}

//-----------------------------------------------------------------------------
// print change item info
void ChangeItem::print_change_item_info() {
    cout << "Change Item ID: " << id << endl;
    cout << "Product Name: " << productName << endl;
    cout << "Product Release ID: " << productReleaseID << endl;
    cout << "Description: " << description << endl;
    cout << "Status: " << status << endl;
    cout << "Priority: " << priority << endl;
    cout << "Requests: " << requests << endl;
}

//-----------------------------------------------------------------------------
// write change item to file
bool write_change_item(ChangeItem &changeItem) {
    // assume file is open
    // seek to the end of the file
    changeItemFile.seekp(0, ios::end);
    // write the change item to the file
    changeItemFile.write((char*)&changeItem, sizeof(ChangeItem));
    return true;
}

//-----------------------------------------------------------------------------
// read change item from file
bool read_change_item(int index, ChangeItem &changeItem) {
    // assume file is open
    // make sure index is valid
    changeItemFile.seekg(0, ios::end);
    int numItems = changeItemFile.tellg() / sizeof(ChangeItem);
    if(index >= numItems || index < 0) {
        return false;
    }
    // seek to the correct position in the file
    changeItemFile.seekg(index * sizeof(ChangeItem), ios::beg);
    // read the change item from the file
    changeItemFile.read((char*)&changeItem, sizeof(ChangeItem));
    return true;
}

//-----------------------------------------------------------------------------
// delete change item from file
bool delete_change_item(int index) {
   fstream tempFile("temp_changeitem.dat", ios::out | ios::binary);
    // assume file is open
    // seek to the correct position in the file
    changeItemFile.seekg(0, ios::beg);
    // read the change item from the file
    ChangeItem tempChangeItem;
    int i = 0;
    while(changeItemFile.read((char*)&tempChangeItem, sizeof(ChangeItem))) {
        if(i != index) {
            tempFile.write((char*)&tempChangeItem, sizeof(ChangeItem));
        }
        i++;
    }
    changeItemFile.close();
    changeItemFile.open(CHANGE_ITEM_FILE, ios::out | ios::trunc);
    changeItemFile.close();
    changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);

    tempFile.seekg(0, ios::beg);
    while(tempFile.read((char*)&tempChangeItem, sizeof(ChangeItem))) {
        changeItemFile.write((char*)&tempChangeItem, sizeof(ChangeItem));
    }

    tempFile.close();
    tempFile.open("temp_changeitem.dat", ios::out | ios::trunc);
    tempFile.close();

    return true;

}