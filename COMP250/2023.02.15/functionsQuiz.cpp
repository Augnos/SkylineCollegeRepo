#include <iostream>
using namespace std;

double process(int k ){
    int x = k * 2;
    cout << "k: " << k << endl;

    x = x * 1.0;
    return x;
}

int main (){
    cout << "enter a int: ";
    int input;
    cin >> input;

    cout << process(input) << endl;
    return 0;
}