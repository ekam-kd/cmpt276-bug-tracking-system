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
fstream temp_itemFile;
fstream changeRequestFile2;
fstream customerFile2;

//-----------------------------------------------------------------------------
bool init_change_item() {
    //open file for reading/writing and create it if it doesn't exist
    changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    temp_itemFile.open(TEMP_CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    changeRequestFile2.open(CHANGE_REQUEST_FILE, ios::in | ios::out | ios::binary);
    customerFile2.open(CUSTOMER_FILE, ios::in | ios::out | ios::binary);

    //if file opened successfully, return true
    if(changeItemFile.is_open() && temp_itemFile.is_open() && changeRequestFile2.is_open() && customerFile2.is_open()) {
        return true;
    } else { //otherwise try opening again
        changeItemFile.clear();
        temp_itemFile.clear();
        changeRequestFile2.clear();
        customerFile2.clear();

        changeItemFile.open(CHANGE_ITEM_FILE, ios::out | ios::binary);
        temp_itemFile.open(TEMP_CHANGE_ITEM_FILE, ios::out | ios::binary);
        changeRequestFile2.open(CHANGE_REQUEST_FILE, ios::out | ios::binary);
        customerFile2.open(CUSTOMER_FILE, ios::in | ios::out | ios::binary);


        if (changeItemFile.is_open()) {
            changeItemFile.close();
            changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
        }
        if (changeRequestFile2.is_open()) {
            changeRequestFile2.close();
            changeRequestFile2.open(CHANGE_REQUEST_FILE, ios::in | ios::out | ios::binary);
        }
        if (customerFile2.is_open()) {
            customerFile2.close();
            customerFile2.open(CUSTOMER_FILE, ios::in | ios::out | ios::binary);
        }
        if (temp_itemFile.is_open()) {
            temp_itemFile.close();
            temp_itemFile.open(TEMP_CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
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
    // cout << "Id is: " << temp_item.get_id() << " and product name is: " << temp_item.get_productName();
    // cout << " and release is: " << temp_item.get_productReleaseID() << " and priority is: " << temp_item.get_priority() << endl;
    cout << "Change Item successfully created!" << endl;
    return true;
}

//-----------------------------------------------------------------------------
// 
bool display_change_items(const char prod_name[MAX_PRODUCT_NAME], const char release_name[MAX_NAME]){
    ChangeItem temp_changeItem;
    // Move the file pointer to the beginning of the file
    changeItemFile.seekg(0, ios::beg);
    int count = 1;
    // displays list of products
    while (changeItemFile.read(reinterpret_cast<char*>(&temp_changeItem), sizeof(ChangeItem))) {
        if (strcmp(temp_changeItem.get_productName(), prod_name) == 0 
        && strcmp(temp_changeItem.get_productReleaseID(), release_name) == 0) {
            cout << count << ". " << "change ID - " << temp_changeItem.get_id() << " -" << endl;
            cout << "    Description: {" << temp_changeItem.get_description() << "}" << endl;
            count++;
        }
    }
    changeItemFile.clear();
    if (count == 1) {
        cout << "No change items. Returning to main menu..." << endl;
        return false;
    } else {
        return true;
    }
}


//-----------------------------------------------------------------------------
bool check_change_item(const long int id, const char productName[MAX_PRODUCT_NAME], const char productReleaseID[MAX_NAME]) {
    //check to make sure productFile is open
    if (!changeItemFile.is_open())
    {
        cerr << "Change Item database file is not open!" << endl;
        return false;
    }

    ChangeItem temp_item;
    changeItemFile.clear();
    changeItemFile.seekg(0, ios::beg);

    // Read through the file
    while (changeItemFile.read(reinterpret_cast<char*>(&temp_item), sizeof(ChangeItem))) {
        if (strcmp(temp_item.get_productName(), productName) == 0 
        && strcmp(temp_item.get_productReleaseID(), productReleaseID) == 0 
        && temp_item.get_id() == id) {
            changeItemFile.clear();
            return true;
        }
    }

    // Reset the file pointer for future operations
    changeItemFile.clear(); // Clear the EOF flag
    return false;
}

//-----------------------------------------------------------------------------
bool see_change_item(long int ch_id){
    ChangeItem temp_changeItem;
    // Move the file pointer to the beginning of the file
    changeItemFile.seekg(0, ios::beg);
    
    // display change item information
    while (changeItemFile.read(reinterpret_cast<char*>(&temp_changeItem), sizeof(ChangeItem))) {
        if (temp_changeItem.get_id() == ch_id) {
            cout << "Change Item with ID " << temp_changeItem.get_id() << " contains following information: " << endl;
            cout << "    Product and release: " << temp_changeItem.get_productName() << " " << temp_changeItem.get_productReleaseID() << endl;
            cout << "    Description: {" << temp_changeItem.get_description() << "} " << endl;
            cout << "    Status: " << temp_changeItem.get_status() << endl;
            cout << "    Priority: " << temp_changeItem.get_priority() << endl;
            cout << "    Number of requests: " << temp_changeItem.get_requests() << endl;
            changeItemFile.clear();
            return true;
        }
    }
    changeItemFile.clear();
    return false;
}

//-----------------------------------------------------------------------------
// need to test this function
bool modify_change_item(const long int ch_id){
    // find index of change item
    // ChangeItem changeItem;
    // int i = 0;

    ChangeItem temp1;
    ChangeItem chosen_one;
    // Move the file pointer to the beginning of the files
    changeItemFile.seekg(0, ios::beg);
    temp_itemFile.clear();
    temp_itemFile.seekg(0, ios::beg);
    
    // copy change items except the one being edited to a temporary file
    while (changeItemFile.read(reinterpret_cast<char*>(&temp1), sizeof(ChangeItem))) {
        if (temp1.get_id() != ch_id) {
            temp_itemFile.write(reinterpret_cast<const char *>(&temp1), sizeof(ChangeItem));
        } else {
            chosen_one.set_id(temp1.get_id());
            chosen_one.set_productName(temp1.get_productName());
            chosen_one.set_productReleaseID(temp1.get_productReleaseID());
            chosen_one.set_description(temp1.get_description());
            chosen_one.set_status(temp1.get_status());
            chosen_one.set_priority(temp1.get_priority());
            chosen_one.set_requests(temp1.get_requests());
        }
    }
    changeItemFile.close();
    temp_itemFile.close();
    changeItemFile.open(CHANGE_ITEM_FILE, ios::out | ios:: binary | ios::trunc);
    temp_itemFile.open(TEMP_CHANGE_ITEM_FILE, std::ios::in | std::ios::binary);
    if (!changeItemFile.is_open() || !temp_itemFile.is_open()) {
        std::cerr << "Error: Could not reopen files." << std::endl;
        return false;
    }
    ChangeItem temp2;
    //rewrite the contents back, now excluding the change item to be edited
    while (temp_itemFile.read(reinterpret_cast<char*>(&temp2), sizeof(ChangeItem))) {
        changeItemFile.write(reinterpret_cast<const char *>(&temp2), sizeof(ChangeItem));
    }
    temp_itemFile.close();
    temp_itemFile.open(TEMP_CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary | ios::trunc);
    temp_itemFile.close();

    changeItemFile.clear();
    changeItemFile.close();
    changeItemFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);

    while (1) {
        cout << "\nEnter the field you would like to modify: " << endl;
        cout << "------------------------------------------" << endl;
        cout << "0. Exit" << endl << "1. Anticipated Release" << endl << "2. Description" << endl << "3. Status" << endl;
        cout << "4. Priority" << endl << "5. Number of Requests" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Selection: ";
        cin >> ws;
        int selection;
        cin >> selection;
        if (selection == 0) {
            changeItemFile.write(reinterpret_cast<const char *>(&chosen_one), sizeof(ChangeItem));
            changeItemFile.clear();
            return true;
        } else if (selection == 1) {
            string temp_release, temp_date;
            char release[MAX_NAME], date[MAX_DATE];
            cout << "Enter the new release: ";
            getline(cin>>ws, temp_release);
            while (temp_release.length() >= MAX_NAME) {
                cout << "Release name too long. Try again: ";
                getline(cin>>ws, temp_release);
            }
            strcpy(release, temp_release.c_str());
            cout << "Enter today's date with the format of 'mm/dd/yyy': ";
            getline(cin>>ws, temp_date);
            while (temp_date.length() != 10) {
                cout << "Invalid date format. Try again: ";
                getline(cin>>ws, temp_date);
            }
            strcpy(date, temp_date.c_str());
            chosen_one.set_productReleaseID(release);
            create_product_release(chosen_one.get_productName(), release, chosen_one.get_description(), date);
            cout << "Release successfully updated!" << endl;
            continue;
        } else if (selection == 2) {
            string temp_descr;
            char description[MAX_DESCRIPTION];
            cout << "Enter the new description: ";
            getline(cin>>ws, temp_descr);
            while (temp_descr.length() >= MAX_DESCRIPTION) {
                cout << "Description too long. Try again: ";
                getline(cin>>ws, temp_descr);
            }
            strcpy(description, temp_descr.c_str());
            chosen_one.set_description(description);
            cout << "Description successfully updated!" << endl;
            continue;
        } else if (selection == 3) {
            string temp_status;
            char status[MAX_NAME];
            cout << "Enter the new status [Unchecked, Assessed, Cancelled, In Progress, or Complete]: ";
            getline(cin>>ws, temp_status);
            while (temp_status.length() >= MAX_DESCRIPTION) {
                cout << "Description too long. Try again: ";
                getline(cin>>ws, temp_status);
            }
            strcpy(status, temp_status.c_str());
            chosen_one.set_status(status);
            cout << "Status successfully updated!" << endl;
            continue;
        } else if (selection == 4) {
            int new_priority;
            cout << "Enter the new priority: ";
            cin >> ws >> new_priority;
            chosen_one.set_priority(new_priority);
            cout << "Priority successfully updated!" << endl;
            continue;
        } else if (selection == 5) {
            int new_requests;
            cout << "Enter the new number of requests: ";
            cin >> ws >> new_requests;
            chosen_one.set_requests(new_requests);
            cout << "Requests successfully updated!" << endl;
            continue;
        } else {
            cout << "Invalid selection. Please try again." << endl;
        }
    }
    //changeItemFile.write(reinterpret_cast<const char *>(&chosen_one), sizeof(ChangeItem));
    cout << "\nThis better not get printed..." << endl;
    changeItemFile.clear();
    return false;


}

//-----------------------------------------------------------------------------
// displays all pending change items for a specific product release
bool see_pending_change_items(const char prod_name[MAX_PRODUCT_NAME]) {
    ChangeItem temp_changeItem;
    // Move the file pointer to the beginning of the file
    changeItemFile.seekg(0, ios::beg);
    int count = 1;
    // displays list of products
    while (changeItemFile.read(reinterpret_cast<char*>(&temp_changeItem), sizeof(ChangeItem))) {
        if (strcmp(temp_changeItem.get_productName(), prod_name) == 0 
        && (strcmp(temp_changeItem.get_status(), "Unchecked") == 0
        || strcmp(temp_changeItem.get_status(), "Assessed") == 0
        || strcmp(temp_changeItem.get_status(), "In Progress") == 0)) {
            cout << count << ". " << "change ID - " << temp_changeItem.get_id() << " -" << endl;
            cout << "    Description: {" << temp_changeItem.get_description() << "}" << endl;
            count++;
        }
    }
    changeItemFile.clear();
    if (count == 1) {
        cout << "No change items. Returning to main menu..." << endl;
        return false;
    } else {
        return true;
    }
}

//-----------------------------------------------------------------------------
bool create_report(const long int ch_id){
    // open changeRequest file + search fo matching ch_id
    // if found, add customerName to a .txt file
    ChangeRequest temp_request;
    char temp_name[MAX_NAME];
    changeRequestFile2.seekg(0, ios::beg);
    customerFile2.seekg(0, ios::beg);
    

    while (changeRequestFile2.read(reinterpret_cast<char*>(&temp_request), sizeof(ChangeRequest))) {
        if (temp_request.get_id() == ch_id) {
            strcpy(temp_name, temp_request.get_customer_name());
        }
    }
    cout << "\nReport sending to..." << endl;
    Customer temp_customer("", "", "", "");
    while (customerFile2.read(reinterpret_cast<char*>(&temp_customer), sizeof(Customer))) {
        if (strcmp(temp_customer.get_name(), temp_name) == 0) {
            cout << "Customer name: " << temp_customer.get_name() << " and email: " << temp_customer.get_email() << endl;
        }
    }
    changeRequestFile2.clear();
    customerFile2.clear();

    return true;
}

//-----------------------------------------------------------------------------
//close change item file
bool close_change_item() {
    if (temp_itemFile.is_open()) {
        remove(TEMP_CHANGE_ITEM_FILE);
    }
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
