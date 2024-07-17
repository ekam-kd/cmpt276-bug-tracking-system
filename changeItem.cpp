#include "changeItem.hpp"
#include <fstream>
#include <cstring>

//global filestream for change item file so it stays open for program duration
fstream changeItemFile;

bool init_change_item() {
    //open file for reading/writing and create it if it doesn't exist
    changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(changeItemFile.is_open()) {
        return true;
    } else { //otherwise return false
        return false;
    }

}

//close change item file
bool close_change_item() {
    if (changeItemFile.is_open()) {
        changeItemFile.close();
        return true;
    }
    return false;
}

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

// destructor
ChangeItem::~ChangeItem() {
    //nothing to do here
}

// get id
long int ChangeItem::get_id() {
    return id;
}

// get product name
char* ChangeItem::get_productName() {
    return productName;
}

// get product release ID
char* ChangeItem::get_productReleaseID() {
    return productReleaseID;
}

// get description
char* ChangeItem::get_description() {
    return description;
}

// get status
char* ChangeItem::get_status() {
    return status;
}

// get priority
int ChangeItem::get_priority() {
    return priority;
}   

// get requests
int ChangeItem::get_requests() {
    return requests;
}

// set id
void ChangeItem::set_id(long int id) {
    this->id = id;
}

// set product name
void ChangeItem::set_productName(string productName) {
    strcpy(this->productName, productName.c_str());
}

// set product release ID
void ChangeItem::set_productReleaseID(string productReleaseID) {
    strcpy(this->productReleaseID, productReleaseID.c_str());
}

// set description
void ChangeItem::set_description(string description) {
    strcpy(this->description, description.c_str());
}

// set status
void ChangeItem::set_status(string status) {
    strcpy(this->status, status.c_str());
}

// set priority
void ChangeItem::set_priority(int priority) {
    this->priority = priority;
}

// set requests
void ChangeItem::set_requests(int requests) {
    this->requests = requests;
}

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

// write change item to file
bool write_change_item(ChangeItem &changeItem) {
    // assume file is open
    // seek to the end of the file
    changeItemFile.seekp(0, ios::end);
    // write the change item to the file
    changeItemFile.write((char*)&changeItem, sizeof(ChangeItem));
    return true;
}

// read change item from file
bool read_change_item(int index, ChangeItem &changeItem) {
    // assume file is open
    // seek to the correct position in the file
    changeItemFile.seekg(index * sizeof(ChangeItem), ios::beg);
    // read the change item from the file
    changeItemFile.read((char*)&changeItem, sizeof(ChangeItem));
    return true;
}

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