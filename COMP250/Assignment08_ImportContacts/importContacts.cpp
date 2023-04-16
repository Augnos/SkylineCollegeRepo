// Joshua Valdez
// Assignment 8: Import Contacts
#include <iostream>
using namespace std;

/*
Assignment: Make a class named ContactCard.
• Create private member variables to contain name and email address values.
• Write a constructor that takes in the name value and email. Provide a default value for the email parameter.
• Write getter functions for name and email variables.
• Implement an overload to the == operator for ContactCard objects. Both email and name should be the same for two
ContactCards to be equal.
*/

class ContactCard
{
private:
    string name, emailAddress;
    long phoneNumber;

public:
    // constructor
    ContactCard(string name, long phone, string email = "unknown")
    {
        this->name = name;
        phoneNumber = phone;
        emailAddress = email;
    }

    // getters/accessors
    string getName() const{
        return name;
    }
    string getEmailAddress() const{
        return emailAddress;
    }
    long getPhoneNumber() const{
        return phoneNumber;
    }

    // setters/mutators
    void setName(string n){
        name = n;
    }
    void setEmailAddress(string e){
        emailAddress = e;
    }
    void setPhoneNumber(long p){
        phoneNumber = p;
    }


    virtual void print();
    bool operator==(const ContactCard &) const;
};

void ContactCard::print()
{
    cout << "Name: " << name << " at " << emailAddress;
}

bool ContactCard::operator==(const ContactCard &another) const
{
    return name == another.name && (emailAddress == another.emailAddress || phoneNumber == another.phoneNumber);
}


/*
Part 1: ContactCard with phone number
Update the ContactCard class to add a private number variable for phone number. (You can use int or long)
Implement a getter and setter function for the phone number.
Update the print function so that it prints out the phone number in a user-friendly manner. (So the print should now
print name, email and phone number values.)

Part 2: Contact Equality
Update the ContactCard overload of the == operator.
Two contacts should be equal if:
    They have the same name AND
    They have the same email property OR they have the same phone number

Part 3: Import
Using the techniques shown in class create a main method which imports a csv file with ContactCard data (of the format
provided) and creates an array container with the imported ContactCards. (Assume a max number of contacts is 50) You can
use the function from class to trim the whitespace. In case there is a bad phone number, use a try/catch to make sure
that won't crash your program. A ContactCard should not be imported more than once so you may need to check if a new
contact is equal to (==) some other contact already in the array. Once imported you must loop through the array and
print all the ContactCards.*/

int main()
{
    return 0;
}