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

    // getter methods
    string getName() const{
        return name;
    }
    string getEmailAddress() const{
        return emailAddress;
    }
    long getPhoneNumber() const{
        return phoneNumber;
    }

    // setter methods
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
    return name == another.name && emailAddress == another.emailAddress;
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

class FlipPhone : public CellPhone
{
  public:
    // constructor
    FlipPhone(string owner, string phoneNumber) : CellPhone("FlipPhone", owner, phoneNumber){};

    // methods
    void hangup()
    {
        cout << "Closing phone.\n\n";
    }
};

class SmartPhone : public CellPhone
{
  private:
    string os;
    int memorySize;

  public:
    // constructor
    SmartPhone(string owner, string phoneNumber, string os, int memorySize)
        : CellPhone("SmartPhone", owner, phoneNumber)
    {
        this->os = os; // operating system
        this->memorySize = memorySize;
    };

    // methods
    void hangup()
    {
        cout << "Pressing END button.\n\n";
    }
};

int main()
{
    // constructing CellPhone objects
    FlipPhone flip1("Josh", "415-555-1111");
    SmartPhone smart1("Jacob", "415-555-1234", "android", 8);
    SmartPhone smart2("Celeste", "415-555-2345", "iOS", 64);
    CellPhone cell1("Nokia", "Gabby", "415-555-4567");

    // creating array of CellPhone pointers
    CellPhone *ptrArr1[] = {&flip1, &smart1, &smart2, &cell1};

    // for loop calling and hanging up each CellPhone in the pointer array
    for (int i = 0; i < sizeof(ptrArr1) / sizeof(ptrArr1[0]); i++)
    {
        ptrArr1[i]->call();
        ptrArr1[i]->hangup();
    }

    return 0;
}