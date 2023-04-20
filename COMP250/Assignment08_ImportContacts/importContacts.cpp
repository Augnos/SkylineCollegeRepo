// Joshua Valdez
// Assignment 8: Import Contacts
#include <fstream>
#include <iostream>

using namespace std;

/*
Part 1: ContactCard with phone number
Update the ContactCard class to add a private number variable for phone number. (You can use int or long)
Implement a getter and setter function for the phone number.
Update the print function so that it prints out the phone number in a user-friendly manner. (So the print should now
print name, email and phone number values.)
*/
class ContactCard
{
  private:
    string name, emailAddress;
    long phoneNumber;

  public:
    // constructors
    ContactCard(){};
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
    virtual void print()
    {
        cout << "\nName:\t" << name << endl;
        cout << "Email:\t" << emailAddress << endl;
        cout << "Phone:\t" << phoneNumber << endl;
    };

    /*
    Part 2: Contact Equality
    Update the ContactCard overload of the == operator.
    Two contacts should be equal if:
        They have the same name AND
        They have the same email property OR they have the same phone number
     */
    bool operator==(const ContactCard &another) const
    {
        // returns true if name matches AND email or phone matches.
        return name == another.name && (emailAddress == another.emailAddress || phoneNumber == another.phoneNumber);
    }
};

string trim(const string &input)
{
    // avoids substring trim errors when input is short
    if (input.length() <= 1)
        return input;

    string whiteSpaceChars = " \n\t";
    int start = input.find_first_not_of(whiteSpaceChars);
    int end = input.find_last_not_of(whiteSpaceChars);
    int length = end - start + 1; // plus one so last character is included

    string output = input.substr(start, length);
    return output;
}

/*
Part 3: Import
Using the techniques shown in class create a main method which imports a csv file with ContactCard data (of the format
provided) and creates an array container with the imported ContactCards. (Assume a max number of contacts is 50) You can
use the function from class to trim the whitespace. In case there is a bad phone number, use a try/catch to make sure
that won't crash your program. A ContactCard should not be imported more than once so you may need to check if a new
contact is equal to (==) some other contact already in the array. Once imported you must loop through the array and
print all the ContactCards.
*/
int main()
{
    string tempData;         // to hold a single string value of a contact's data from .csv file
    ContactCard tempContact; // tempData stored here prior to being added to ContactList

    ContactCard contactList[50]; // holds all our contact cards to be printed later
    int nextOpen = 0;            // holds the next open spot in contactList array.

    int counter = 0; // counter used to track which member variable of ContactCard is being populated
    ifstream inFile; // creates an object inFile of type ifstream

    inFile.open("ContactData.csv");        // opens .csv
    while (getline(inFile, tempData, ',')) // getline gathers string in .csv between commas, and sets to tempData
    {
        tempData = trim(tempData); // trims data of leading/trailing whitespace
        if (counter == 0)          // Counter determines which variable to store tempData in
        {
            tempContact.setName(tempData);
        }
        else if (counter == 1)
        {
            tempContact.setEmailAddress(tempData);
        }
        else if (counter == 2)
        {
            try // try is used in case phone number isn't a valid int
            {
                tempContact.setPhoneNumber(stol(tempData));
            }
            catch (...) // when phone number isn't valid, an error message is sent to cout, phoneNumber set to -1
            {
                cout << tempContact.getName() << "'s phone number not valid\n" << tempData << " was not imported.\n";
                tempContact.setPhoneNumber(-1);
            }
        }
        counter++; // counter is incremented after data is stored

        if (counter == 3) // when all variables imported, tempContact is checked against contactList for duplicates
        {
            bool duplicate = false;

            // for loop compares tempContact with every ContactCard in contactList
            for (int i = 0 && !duplicate; i < nextOpen; i++)
            {
                // if tempContact is already in contactList, duplicate becomes true, and moves on to next contact.
                if (tempContact == contactList[i])
                {
                    duplicate = true;
                }
            }

            if (!duplicate)
            {
                contactList[nextOpen] = tempContact;
                nextOpen++;
            }
            counter = 0; // reset counter for next contact in .csv
        }
    }

    inFile.close(); // closes .csv

    for (int i = 0; i < nextOpen; i++)
    {
        contactList[i].print();
    }
    return 0;
}