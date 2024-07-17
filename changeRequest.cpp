#include "changeRequest.hpp"

//global filestream for change request file so it stays open for program duration
fstream changeRequestFile;

//-----------------------------------------------------------------------------
//initialize change request database
bool init_change_request() {
    //open file for reading/writing and create it if it doesn't exist
    changeRequestFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);
    
    //if file opened successfully, return true
    if(changeRequestFile.is_open()) {
        return true;
    } else { //otherwise return false
        return false;
    }

}

//-----------------------------------------------------------------------------
// add change request to file
bool make_change_request(ChangeRequest* changeRequest) {
    //write change request to file
    write_change_request(*changeRequest);
    return true;
}

//-----------------------------------------------------------------------------
// close change request database file
bool close_change_request() {
    if (changeRequestFile.is_open()) {
        changeRequestFile.close();
        return true;
    }
    return false;
}

//-----------------------------------------------------------------------------
// constructor
ChangeRequest::ChangeRequest() {
    //initialize all member variables to empty strings
    id = 0;
    strcpy(customer_name, "");
    strcpy(reported_release, "");
    strcpy(request_date, "");
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

// file operations

//-----------------------------------------------------------------------------
// write change request to file
bool write_change_request(ChangeRequest &changeRequest){
    changeRequestFile.seekp(0, ios::end); 
    changeRequestFile.write((char*)&changeRequest, sizeof(ChangeRequest));
    return true;
}

//-----------------------------------------------------------------------------
// read change request from file
bool read_change_request(int index, ChangeRequest &changeRequest){
    changeRequestFile.seekg(index * sizeof(ChangeRequest), ios::beg);
    changeRequestFile.read((char*)&changeRequest, sizeof(ChangeRequest));
    return true;
}

//-----------------------------------------------------------------------------
// delete change request from file
bool delete_change_request(int index){
    fstream tempFile("temp_changereq.dat", ios::out | ios::binary);
    // seek to start of file

    changeRequestFile.seekg(0, ios::beg);

    // copy all records except the one to be deleted
    ChangeRequest tempChangeRequest;
    int i = 0;
    while (changeRequestFile.read((char*)&tempChangeRequest, sizeof(ChangeRequest))) {
        if (i != index) {
            tempFile.write((char*)&tempChangeRequest, sizeof(ChangeRequest));
        }
        i++;
    }

    // Clear the file (truncate to 0 and seek to the beginning)
    changeRequestFile.close();
    changeRequestFile.open(CHANGE_ITEM_FILE, ios::out | ios::trunc);
    changeRequestFile.close();
    changeRequestFile.open(CHANGE_ITEM_FILE, ios::in | ios::out | ios::binary);

    // copy all records back
    tempFile.seekg(0, ios::beg);
    while (tempFile.read((char*)&tempChangeRequest, sizeof(ChangeRequest))) {
        changeRequestFile.write((char*)&tempChangeRequest, sizeof(ChangeRequest));
    }

    // clear and close temp file
    tempFile.close();
    tempFile.open("temp_changereq.dat", ios::out | ios::trunc);
    tempFile.close();

    return true;
}
    