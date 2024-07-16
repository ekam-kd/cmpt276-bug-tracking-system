/* 
 * File:   testFileOps.cpp
 * Author: Ashley Kim
 * Created: July 2024
 * Version 1.1
 * Purpose: girl, so COMPUTER [green heart]
 */

#include <iostream>
#include <string>
#include "helper_funcs.hpp"
#include "customer.hpp"
#include "changeItem.hpp"
#include "release.hpp"
#include "changeRequest.hpp"
#include "product.hpp"
#include "definitions.hpp"
using namespace std;

void main_test_ops(){
// constructor
        ChangeItem new_item = ChangeItem();
        // // destructor
        // ~ChangeItem();


        // testing set_id()
        cout << "testing set_id() -- set to '12345" << endl;
        if(new_item.set_id(12345)){
            cout << "Set id test passed." << endl;
        }
        // testing set_productName() to acrobat
        cout << "testing set_productName() -- set to Acrobat" << endl;
        if(new_item.set_productName('Acrobat')){
            cout << "Set product name passed." << endl;
        }
        // Testing set product release ID -- to rel1
        if(new_item.set_productReleaseID('rel1')){
            
        }
        // set description
        void set_description(char* description);
        // set status
        void set_status(char* status);
        // set priority
        void set_priority(int priority);
        // set requests
        void set_requests(int requests);




        // get id
        long int get_id();
        // get product name
        char* get_productName();
        // get product release ID
        char* get_productReleaseID();
        // get description
        char* get_description();
        // get status
        char* get_status();
        // get priority
        int get_priority();
        // get requests
        int get_requests();
        // set id
        void set_id(long int id);
        // set product name
        void set_productName(char* productName);
        // set product release ID
        void set_productReleaseID(char* productReleaseID);
        // set description
        void set_description(char* description);
        // set status
        void set_status(char* status);
        // set priority
        void set_priority(int priority);
        // set requests
        void set_requests(int requests);
        // print change item info
        void print_change_item_info();


}