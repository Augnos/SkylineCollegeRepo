// Joshua Valdez
// Assignment 5: Recursive Functions
#include <iostream>
#include <string>
using namespace std;


string recurseReverse(string input, string output = "")
{
    // base case
    if (input.size() == 0)
        return output; // if input is empty, return output

    // add last char of input to output
    output += input[input.size() - 1];

    // erase last char of input
    input.erase(input.size() - 1);

    // recursion
    return recurseReverse(input, output);
}

int maxDigit(int input, int max = 0)
{
    // base cases
    if (max == 9) // if max is already at 9, return it, since no single digit can be larger than 9
        return max;
    if (input < 10) // if input is a single digit..
    {
        if (input > max)
            return input; // ...return the larger of input and max
        else
            return max;
    }

    // sets new max if last digit is larger
    if (input % 10 > max)
        max = input % 10;

    // recursion
    return maxDigit(input / 10, max);
}

int main()
{
    // Part 1
    string input;
    cout << "Part 1: Reverse String\n" << "Input: ";
    cin >> input;

    cout << "Output:" << endl;
    cout << recurseReverse(input) << "\n\n";


    // Part 2
    int number;
    cout << "Part 2: Max Digit\n" << "Input: ";
    cin >> number;

    cout << "Output:" << endl;
    cout << maxDigit(number) << "\n\n";


    return 0;
}