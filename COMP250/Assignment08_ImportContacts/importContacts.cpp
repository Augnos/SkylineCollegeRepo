// Joshua Valdez
// Assignment 8: Import Contacts
#include <fstream>
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
    // constructors
    ContactCard();
    ContactCard(string name, long phone, string email = "unknown")
    {
        this->name = name;
        phoneNumber = phone;
        emailAddress = email;
    }

    // accessors
    string getName() const
    {
        return name;
    }
    string getEmailAddress() const
    {
        return emailAddress;
    }
    long getPhoneNumber() const
    {
        return phoneNumber;
    }

    // mutators
    void setName(string name)
    {
        this->name = name;
    }
    void setPhoneNumber(long phone)
    {
        phoneNumber = phone;
    }
    void setEmailAddress(string email)
    {
        emailAddress = email;
    }

    // functions
    virtual void print();

    // operator overloads
    bool operator==(const ContactCard &another) const
    {
        return name == another.name && (emailAddress == another.emailAddress || phoneNumber == another.phoneNumber);
    }
};

void ContactCard::print()
{
    cout << "Name: " << name << " at " << emailAddress;
}

string trim(const string &input)
{
    string whiteSpaceChars = " \n\t";
    int start = input.find_first_not_of(whiteSpaceChars);
    int end = input.find_last_not_of(whiteSpaceChars);

    int length = end - start + 1; // plus one so last character is included
    return input.substr(start, length);
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
    string tempData;             // to hold a single string value of a contact's data from .csv file
    ContactCard tempContact;     // tempData stored here prior to being added to ContactList
    ContactCard contactList[50]; // holds all our contact cards to be printed later

    int counter = 0;
    ifstream inFile;                // creates an object inFile of type ifstream
    inFile.open("ContactData.csv"); // opens .csv
    while (getline(inFile, tempData, ','))
    {
        // if/else statements add tempData to tempContact, using counter to determine which variable to store data under
        if (counter == 0)
        {
            tempContact.setName(tempData);
        }
        else if (counter == 1)
        {
            tempContact.setEmailAddress(tempData);
        }
        else if (counter == 2)
        {
            try
            {
                tempContact.setPhoneNumber(stol(tempData));
            }
            catch (...)
            {
                cout << "Phone number not valid\n" << tempData << " could not be stored.\n";
            }
        }
        counter++;

        // when a tempContact is completely filled, check against contactList
        if (counter == 3)
        {
            counter = 0; // reset counter for next contact in .csv
            bool duplicate = false;

            // if tempContact is already in contactList, duplicate becomes true, and contact isn't added to contactlist.
            for (int i = 0 && !duplicate; i < sizeof(contactList) / sizeof(ContactCard); i++)
            {
                if (tempContact == contactList[i]){
                    duplicate = true;
                }
            }

            if (!duplicate){

            }
        }
    }

    inFile.close(); // closes .csv
    return 0;
}