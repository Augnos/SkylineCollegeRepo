// Joshua Valdez
#include <iostream>
#include <array>
using namespace std;

// Ask a user for 10 integer values.
// Save them into an array.
// Find the largest item in the array using a for loop.

int main()
{
    int arr[10];
    cout << sizeof(arr)/sizeof(int);

    cout << "Enter an integer: ";
    cin >> arr[0];
    int max = arr[0];


    for (int i = 1; i < 10; i++)
    {
        cout << "Enter an integer: ";
        cin >> arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    cout << "Largest number is: " << max << "\n";

    return 0;
}