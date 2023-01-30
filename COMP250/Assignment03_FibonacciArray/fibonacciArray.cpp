// Joshua Valdez
#include <iostream>
using namespace std;

int main()
{
    // while getFib is "y", the app will continue getting fib values
    char getFib= 'y';

    // creates a 30 number array, with the first two indices pre-filled.
    int numbers[30] = {0, 1};
    // for loop fills the remaining array with fibonacci values
    for (int i = 2; i < 30; i++)
    {
        numbers[i] = numbers[i - 1] + numbers[i - 2];
    }

    // numInput is an int input to get which value in the fib sequence
    int numInput;

    // while loop checks getFib to continue app
    while (getFib == 'y')
    {

        cout << "Enter an index number between 0 and 29 to find the Fibonacci value at that place in the sequence: ";
        cin >> numInput;

        while (numInput < 0 || numInput > 29)
        {
            cout << "Invalid input \n";
            cout << "Enter an index number between 0 and 29 to find the Fibonacci value at that place in the sequence: ";
            cin >> numInput;
        }

        cout << "The Fibonacci value is: ";
        cout << numbers[numInput];
        cout << "\n";

        cout << "Would you like to find another value? (y/n) ";
        cin >> getFib;
    }

    return 0;
}
