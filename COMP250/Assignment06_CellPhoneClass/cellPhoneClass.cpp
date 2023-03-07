// Joshua Valdez
// Assignment 6: Cell Phone Class
#include <iostream>
using namespace std;


/*
Create a class called CellPhone.

A cell phone should have private attributes for model (String), owner (String), and phone number (int). 
Create a constructor which takes in all three of these and sets the values.

Write functions for CellPhone named call() and hangup(). The CellPhone hangup method should print "hanging up cell phone". 
The CellPhone call function should print out that the owner is calling from the phone number (use the member variables for this information).

In a main function, create at least 2 CellPhone objects that have different values for their owner and phone number. 
For each CellPhone object call the call and hangup functions.
*/

class CellPhone {
public:
    void CellPhone(string, string, int);
    void call();
    void hangup();

private:
    string model;
    string owner;
    int phoneNumber;
};

CellPhone::CellPhone(string m, string o, int p){


}

void CellPhone::call(){
    // not sure if we are using "this" yet, but this is how I would use the class to recall owner and phone number of an instance.
    cout << this->owner << " calling from " << this->phoneNumber;
}

void CellPhone::hangup(){
    cout << "hanging up cell phone";
}


int main() {
    CellPhone phone1()

    return 0;
}