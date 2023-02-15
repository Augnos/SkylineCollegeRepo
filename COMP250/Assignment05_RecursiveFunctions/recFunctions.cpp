// Joshua Valdez
// Assignment 5: Recursive Functions
#include <iostream>
#include <string>
using namespace std;

/*      Part 1: Reverse String
Write a recursive function named recurseReverse which prints out a string in reverse using recursion.
To work properly the function will need to take parameters for the string and a start index (int).
*/

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

/*      Part 2: Max Digit
Write recursive function called maxDigit which returns the largest digit in a number.
Your function should take in an int parameter input.
The base case should be for any input less than 10 simply return the digit.
You need to save the current last digit. (Use % 10)
Then, to make the problem smaller: (recursive case)
You can get rid of the smallest (least significant digit) input by dividing an integer by 10.
Compare the current last digit to the result of the recursive call on smaller int value.
*/

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
    /* ========== Part 1 ==========
    In the main function: Test your function on a string at least 6 characters long.
    Print out the original string and then call your function to show its output.
    */
    
    string input;
    cout << "Part 1: Reverse String\n" << "Input: ";
    cin >> input;

    cout << "Output:" << endl;
    cout << recurseReverse(input) << "\n\n";

    /* ========== Part 2 ==========
    In the main function: Test your function on a number at least 4 digits long.
    Print out the original value and then call your function and show its output.
    */

    int number;
    cout << "Part 2: Max Digit\n" << "Input: ";
    cin >> number;

    cout << "Output:" << endl;
    cout << maxDigit(number) << "\n\n";

    return 0;
}