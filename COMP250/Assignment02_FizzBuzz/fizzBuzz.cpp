// Joshua Valdez

#include <iostream>
using namespace std;

int main()
{
    int input;
    cout << "Enter a number up to 1000: ";
    cin >> input;

    while (input > 1000 || input < 1)
    {
        cout << "Your input is invalid. \n";
        cout << "Enter a number up to 1000: ";
        cin >> input;
    }

    for (int i = 1; i <= input; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            cout << "FizzBuzz \n";

        else if (i % 5 == 0)
            cout << "Buzz \n";

        else if (i % 3 == 0)
            cout << "Fizz \n";

        else
        {
            cout << i;
            cout << "\n";
        }
    }

    return 0;
}