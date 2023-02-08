// Joshua Valdez
// Assignment 4: Functions
#include <iostream>
#include <queue>
using namespace std;

// Part 1: Separating Digits
// Write void function called splitDigits which prints each digit of an int separated by two spaces. It should take in and int parameter input.
// Each digit can be found by calculating the integer remainder when integer input is divided by 10. (Use %)
// Then you must actually reduce this input by dividing by 10.
// In the main function: Print out the original value and then call your function to show its output
void splitDigits(int input)
{

    while (input <= 0)
    {
        output.push(input % 10);
        input = input / 10;
    }

    for (int i = 0; i < size(output); i++)
    {
        cout << output[i] << "\n";
    }
}

int main()
{
    int input;
    cout << "Input integer: ";
    cin >> input;


    return 0;
}