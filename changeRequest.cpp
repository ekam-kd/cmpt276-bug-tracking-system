#include "changeRequest.hpp"
#include <fstream>
//global filestream for customer file so it stays open for program duration
fstream changeRequestFile;

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
