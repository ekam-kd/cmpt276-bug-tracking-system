#include "changeItem.hpp"
#include <fstream>

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
void ChangeItem::set_productName(char* productName) {
    strcpy(this->productName, productName);
}

// set product release ID
void ChangeItem::set_productReleaseID(char* productReleaseID) {
    strcpy(this->productReleaseID, productReleaseID);
}

// set description
void ChangeItem::set_description(char* description) {
    strcpy(this->description, description);
}

// set status
void ChangeItem::set_status(char* status) {
    strcpy(this->status, status);
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
    //open file for writing in binary mode
    changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully
    if(changeItemFile.is_open()) {
        //seek to the end of the file
        changeItemFile.seekp(0, ios::end);
        
        //write the change item to the file
        changeItemFile.write((char*)&changeItem, sizeof(ChangeItem));
        
        //close the file
        changeItemFile.close();
        
        //return true
        return true;
    } else { //otherwise return false
        return false;
    }
}

// read change item from file
bool read_change_item(int index, ChangeItem &changeItem) {
    //open file for reading in binary mode
    changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully
    if(changeItemFile.is_open()) {
        //seek to the correct position in the file
        changeItemFile.seekg(index * sizeof(ChangeItem), ios::beg);
        
        //read the change item from the file
        changeItemFile.read((char*)&changeItem, sizeof(ChangeItem));
        
        //close the file
        changeItemFile.close();
        
        //return true
        return true;
    } else { //otherwise return false
        return false;
    }
}

// delete change item from file
// DOES NOT WORK
bool delete_change_item(int index) {
    //open file for reading/writing in binary mode
    changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully
    if(changeItemFile.is_open()) {
        //seek to the correct position in the file
        changeItemFile.seekg(0, ios::end);
        streampos fileSize = changeItemFile.tellg();
        int numChangeItems = fileSize / sizeof(ChangeItem);
        
        //if index is out of bounds, return false
        if(index < 0 || index >= numChangeItems) {
            return false;
        }
        
        //calculate the number of bytes to shift
        int shiftBytes = (numChangeItems - index - 1) * sizeof(ChangeItem);
        
        //create a buffer to hold the remaining change items
        char* buffer = new char[shiftBytes];
        
        //seek to the position of the change item to delete
        changeItemFile.seekg((index + 1) * sizeof(ChangeItem), ios::beg);
        
        //read the remaining change items into the buffer
        changeItemFile.read(buffer, shiftBytes);
        
        //seek back to the position of the change item to delete
        changeItemFile.seekp(index * sizeof(ChangeItem), ios::beg);
        
        //write the remaining change items back to the file
        changeItemFile.write(buffer, shiftBytes);
        
        //truncate the file to remove the last change item
        // changeItemFile.truncate(fileSize - sizeof(ChangeItem));
        
        //delete the buffer
        delete[] buffer;
        
        //close the file
        changeItemFile.close();
        
        //return true
        return true;
    } else { //otherwise return false
        return false;
    }
}