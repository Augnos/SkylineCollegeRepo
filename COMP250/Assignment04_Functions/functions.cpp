// Joshua Valdez
// Assignment 4: Functions
#include <cmath>
#include <iostream>
using std::cin;
using std::cout;

void splitDigits(int input)
{
    while (input < 100)
    {
        cout << "Your input needs to be at least 3 digits long. \n";
        cout << "Input integer: ";
        cin >> input;
    }
    while (input > 0)
    {
        cout << input % 10 << " ";
        input = input / 10;
    }
}

double hypotenuse(double sideA, double sideB)
{
    return sqrt(pow(sideA, 2) + pow(sideB, 2));
}

void celcius()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Fahr\t"
             << "Celc\t";
    }
    cout << "\n";

    for (int i = 32; i <= 212; i += 2)
    {
        cout << i << "\t";
        cout << (i - 32) * 5 / 9 << "\t";
        if (i % 10 == 0)
            cout << "\n";
    }
}

int main()
{
    cout << "\n";

    cout << "===== Separating Digits ===== \n";
    int input;
    cout << "Input integer: ";
    cin >> input;
    splitDigits(input);
    cout << "\n\n";

    cout << "===== Hypotenuse Calculation ===== \n";
    double sideA, sideB;
    for (int i = 0; i < 3; i++)
    {
        cout << "Side 1: ";
        cin >> sideA;
        cout << "Side 2: ";
        cin >> sideB;
        cout << "Hypotenuse: " << hypotenuse(sideA, sideB) << "\n\n";
    }

    cout << "===== Temperature Table ===== \n";
    celcius();

    return 0;
}