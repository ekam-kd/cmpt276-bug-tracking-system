#include <iostream>
#include <string>
using namespace std;
int main()
{   
    int selection_one = -1;
    long int phone_number;
    string cus_fname, cus_lname, cus_email, emp_department;
    bool sys_run = true;
    bool employee = false;
    while(sys_run){
        
        cout << "Welcome to the Bug Tracking System!" << endl;
        cout << "Please select one of the following to get started: " << endl;
        cout << "-> New Customer (1)" << endl;
        cout << "-> Existing Customer (2)" << endl;
        cout << "-> Exit (3)" << endl;
        cout << "Selection: ";
        cin >> selection_one;
        switch(selection_one)
        {
            case 1:
                cout << "New Customer Menu:" << endl;
                cout << "Note that this is a placeholder for the registration process." << endl;
                cout << "Are you an employee of AAA Inc.? (Y/N): ";
                char emp;
                cin >> emp;
                if(emp == 'Y' || emp == 'y'){
                    employee = true;
                }
                
                cout << "Please Enter Your Name:" << endl;
                cout << "Note that customer name must be in the format of Firstname Lastname" << endl;
                cout << "\nFirst Name: ";
                cin >> cus_fname;
                cout << "Last Name: ";
                cin >> cus_lname;
                cout << "\nPlease enter your email address" << endl;
                cout << "Email: ";
                cin >> cus_email;
                cout << "\nPlease enter your phone number" << endl;
                cout << "Note that phone number must be in the format of +1(234)-567-8910 -> 12345678910" << endl;
                cout << "Phone: ";
                cin >> phone_number;
                if(employee){
                    cout << "\nPlease enter your department: ";
                    cin >> emp_department;
                } 
                cout << "Please confirm the following information:" << endl;
                cout << "Name: " << cus_fname << " " << cus_lname << endl;
                cout << "Email: " << cus_email << endl;
                cout << "Phone: " << phone_number << endl;
                if(employee){
                    cout << "Department: " << emp_department << endl;
                }
                cout << "Is this information correct? (Y/N): ";
                char confirm;
                cin >> confirm;
                if(confirm == 'Y' || confirm == 'y'){
                    cout << "Thank you for registering with us!" << endl;
                    cout << "You will be returned to main menu" << endl;
                } else{
                    cout << "Unable to register new Customer, please try again" << endl;
                }
                break;
            case 2:
                cout << "Are you an employee of AAA Inc.? (Y/N): ";
                char emp;
                cin >> emp;
                if(emp == 'Y' || emp == 'y'){
                    employee = true;
                }
                cout << "Please Select one of the following actions:" << endl;
                break;
            case 3:
                cout << "Exiting System" << endl;
                sys_run = false;
                break;
            default:
                cout << "Invalid selection" << endl;
                break;
        }
    }
    return 0;
}

