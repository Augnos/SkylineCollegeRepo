// Joshua Valdez
// Assignment 5: Recursive Functions
# include <iostream>
#include <string>
using namespace std;

/* 
Part 1: Reverse String

Write a recursive function named recurseReverse which prints out a string in reverse using recursion. 
To work properly the function will need to take parameters for the string and a start index (int).

In the main function: Test your function on a string at least 6 characters long. 
Print out the original string and then call your function to show its output.
*/

string recurseReverse(string str, string output = "")
{
    // base case
    if (string[0] == void) return output;

    // recursion
    output += output.erase(0,1);
    recurseReverse(string str)


    return output;
}



/* 
Part 2: Max Digit

Write recursive function called maxDigit which returns the largest digit in a number. 
Your function should take in an int parameter input.
The base case should be for any input less than 10 simply return the digit.
You need to save the current last digit. (Use % 10)
Then, to make the problem smaller: (recursive case)
You can get rid of the smallest (least significant digit) input by dividing an integer by 10.
Compare the current last digit to the result of the recursive call on smaller int value.

In the main function: Test your function on a number at least 4 digits long. 
Print out the original value and then call your function and show its output.
*/