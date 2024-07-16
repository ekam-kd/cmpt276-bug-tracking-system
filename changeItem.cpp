#include "changeItem.hpp"
#include <fstream>
//global filestream for customer file so it stays open for program duration
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
