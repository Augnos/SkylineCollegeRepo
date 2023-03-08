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
private:
    string model;
    string owner;
    string phoneNumber;

public:
    // constructor
    CellPhone(string model, string owner, string phoneNumber){
        this->model = model;
        this->owner = owner;
        this->phoneNumber = phoneNumber;
    }


    // methods
    void call(){
        cout << this->owner << " calling from " << this->phoneNumber << "\n";
    };

    void hangup(){
        cout << "hanging up cell phone \n";
    }
};


int main() {
    CellPhone phone1("iPhone 14 Pro", "Josh", "(555)-123-4567");
    CellPhone phone2("Samsung Galaxy S22", "Alex", "(555)-987-6543");

    phone1.call();
    phone1.hangup();
    phone2.call();
    phone2.hangup();

    return 0;
}