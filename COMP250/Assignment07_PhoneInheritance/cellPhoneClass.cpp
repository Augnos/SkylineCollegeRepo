// Joshua Valdez
// Assignment 7: Phone Inheritance
#include <iostream>
using namespace std;

/*
You can use your CellPhone class from the previous assignment as a starting point for this assignment.

Create two new classes FlipPhone and SmartPhone. 
FlipPhone and SmartPhone should be subclasses of CellPhone.

Change the CellPhone functions hangup() to make it virtual.

FlipPhone should override hangup() and print "close phone". 
You will need to make a constructor for FlipPhone. 
It only needs arguments for owner and phone number. 
(You need a 3rd argument for model. You can use "FlipPhone" or "Unknown".)

SmartPhone should also override hangup() and print "press end button". 
SmartPhone should also have properties for operating system and memory size. 
Create a constructor for SmartPhone that will take the attributes owner, phone number, operating system and memory size.

In a main function, create an array of CellPhone pointers that contains at least 1 FlipPhone pointer, 2 SmartPhone pointers and 1 CellPhone pointer. 
Run the array through a for loop calling call() and hangup() on each phone.
*/

class CellPhone {
private:
    string model;

protected:
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
        cout << this->owner << " calling from " << this->phoneNumber << "...\n";
    };

    void virtual hangup(){
        cout << "Hanging up cell phone. \n";
    }
};

class FlipPhone : public CellPhone{
public:
    // constructor
    FlipPhone(string owner, string phoneNumber) : CellPhone("Flip Phone", owner, phoneNumber){
        this->owner = owner;
        this->phoneNumber = phoneNumber;
    };

    // methods
    void virtual hangup(){
        cout << "Closing phone. \n";
    }
};

class SmartPhone : public CellPhone{
private:
    string os;
    int memorySize;

public:
    // constructor
    SmartPhone(string owner, string phoneNumber, string os, int memorySize) : CellPhone("SmartPhone", owner, phoneNumber){
        this->owner = owner;
        this->phoneNumber = phoneNumber;
        this->os = os;
        this->memorySize = memorySize;
    };

    // methods
    void virtual hangup(){
        cout << "Press end button.";
    }
};


int main() {
    CellPhone* 


    for (i = 0, i < )

    return 0;
}