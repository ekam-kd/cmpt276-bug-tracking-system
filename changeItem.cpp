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

long int crid_official;

//-----------------------------------------------------------------------------
bool init_change_item() {
    //open file for reading/writing and create it if it doesn't exist
    changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(changeItemFile.is_open()) {
        // read to last change item to get the id
        ChangeItem changeItem;
        int i = 0;
        while(1){
            if(!read_change_item(i, changeItem)){
                break;
            }
            i++;
        }
        crid_official = changeItem.get_id();
        return true;
    } else { //otherwise return false
        return false;
    }

}

//-----------------------------------------------------------------------------
bool make_change_item(ChangeItem* changeItem) {
    //write change item to file
    write_change_item(*changeItem);
    return true;
}
bool make_change_item(const long int id, const char prod_name[MAX_PRODUCT_NAME], const char prod_release[MAX_NAME], 
const char description[MAX_DESCRIPTION], const char status[MAX_NAME], const int priority, const int requests) {
    ChangeItem temp_changeItem(id, prod_name, prod_release, description, status, priority, requests);
    write_change_item(temp_changeItem);
    return true;
}


//-----------------------------------------------------------------------------
// need to test this function
bool get_change_items(char* prod_name, char* prod_release){
    //
    ChangeItem temp_changeItem;
    changeItemFile.seekg(0, ios::beg);
    while (changeItemFile.read((char*)&temp_changeItem, sizeof(ChangeItem))) {
        if (strcmp(temp_changeItem.get_productName(), prod_name) == 0 && 
        strcmp(temp_changeItem.get_productReleaseID(), prod_release) == 0) {
            cout << "Change Id: " << temp_changeItem.get_id() << ". Description: " << temp_changeItem.get_description() << "." << endl;
            changeItemFile.clear();
            return true;
        }
    }
    changeItemFile.clear();
    return false;
}

//-----------------------------------------------------------------------------
// need to test this function
bool see_change_item(long int ch_id){
    ChangeItem temp_changeItem;
    changeItemFile.seekg(0, ios::beg);
    while (changeItemFile.read((char*)&temp_changeItem, sizeof(ChangeItem))) {
        if (temp_changeItem.get_id() == ch_id) {
            cout << "Change Id: " << temp_changeItem.get_id() << ". Description: " << temp_changeItem.get_description() << "." << endl;
            cout << "Status: " << temp_changeItem.get_status() << ". Number of Requests: " << temp_changeItem.get_requests() << "." << endl;
            changeItemFile.clear();
            return true;
        }
    }
    changeItemFile.clear();
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
    cin >> productName;
    changeItem.set_productName(productName);
    cout << "Enter new product release ID: ";
    string productReleaseID;
    cin >> productReleaseID;
    changeItem.set_productReleaseID(productReleaseID);
    cout << "Enter new description: ";
    string description;
    cin >> description;
    changeItem.set_description(description);
    cout << "Enter new status: ";
    string status;
    cin >> status;
    changeItem.set_status(status);
    cout << "Enter new priority: ";
    int priority;
    cin >> priority;
    changeItem.set_priority(priority);
    cout << "Enter new # of requests: ";
    int requests;
    cin >> requests;
    changeItem.set_requests(requests);
    // modify change item by creating new change item and adding to file
    make_change_item(&changeItem);

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
bool get_pending_change_items(char* prod_name) {
    ChangeItem temp_changeItem;
    changeItemFile.seekg(0, ios::beg);
    while (changeItemFile.read((char*)&temp_changeItem, sizeof(ChangeItem))) {

        if ((strcmp(temp_changeItem.get_productName(), prod_name) == 0) && 
        ((strcmp(temp_changeItem.get_status(), "Assessed") == 0) || 
        (strcmp(temp_changeItem.get_status(), "In Progress") == 0))) {
            cout << "Change Id: " << temp_changeItem.get_id() << ". Description: " << temp_changeItem.get_description() << "." << endl;
            changeItemFile.clear();
            return true;
        }
    }
    changeItemFile.clear();
    return false;
}


//-----------------------------------------------------------------------------
bool create_report(long int ch_id){
    // if found, add customerName to a .txt file
    ChangeItem temp_changeitem;
    changeItemFile.seekg(0, ios::beg);
    while (changeItemFile.read((char*)&temp_changeitem, sizeof(ChangeItem))) {
        if (temp_changeitem.get_id() == ch_id) { 
            cout << "Change Id: " << temp_changeitem.get_id() << ". Description: " << temp_changeitem.get_description() << "." << endl;
        }
    }
    changeItemFile.clear();
    return false;

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
// default constructor
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
//-----------------------------------------------------------------------------
// constructor
ChangeItem::ChangeItem(const long int id, const char prod_name[MAX_PRODUCT_NAME], const char prod_release[MAX_NAME], 
const char description[MAX_DESCRIPTION], const char status[MAX_NAME], const int priority, const int requests) {
    set_id(id);
    set_productName(prod_name);
    set_productReleaseID(prod_release);
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
// set product name
void ChangeItem::set_productName(string productName) {
    strcpy(this->productName, productName.c_str());
}

//-----------------------------------------------------------------------------
// set product release ID
void ChangeItem::set_productReleaseID(string productReleaseID) {
    strcpy(this->productReleaseID, productReleaseID.c_str());
}

//-----------------------------------------------------------------------------
// set description
void ChangeItem::set_description(string description) {
    strcpy(this->description, description.c_str());
}

//-----------------------------------------------------------------------------
// set status
void ChangeItem::set_status(string status) {
    strcpy(this->status, status.c_str());
}

//-----------------------------------------------------------------------------
// set priority
void ChangeItem::set_priority(int priority) {
    this->priority = priority;
}

//-----------------------------------------------------------------------------
// set requests
void ChangeItem::set_requests(int requests) {
    this->requests = requests;
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
    changeItemFile.clear();
    return true;
}

//-----------------------------------------------------------------------------
// read change item from file
bool read_change_item(int index, ChangeItem &changeItem) {
    // assume file is open
    // make sure index is valid
    // changeItemFile.seekg(0, ios::end);
    // int numItems = changeItemFile.tellg() / sizeof(ChangeItem);
    // if(index >= numItems || index < 0) {
    //     return false;
    // }
    // // seek to the correct position in the file
    // changeItemFile.seekg(index * sizeof(ChangeItem), ios::beg);
    // // read the change item from the file
    // changeItemFile.read((char*)&changeItem, sizeof(ChangeItem));
    // return true;
    ChangeItem tempChangeItem;
    changeItemFile.seekg(0, ios::beg);
    while (changeItemFile.read((char*)&tempChangeItem, sizeof(ChangeItem))) {
        if (tempChangeItem.get_id() == index) {
            changeItem = tempChangeItem;
            return true;
        }
    }

    changeItemFile.clear();
    return false;
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