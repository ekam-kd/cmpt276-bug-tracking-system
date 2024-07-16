#include "release.hpp"
#include <fstream>
//global filestream for customer file so it stays open for program duration
fstream releaseFile;

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
