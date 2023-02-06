// Joshua Valdez
#include <iostream>
using namespace std;

int minimumOfThree( int x, int y, int z){
    int min = x;
    if (y < min)
        min = y;
    if (z < min)
        min = z;
    
    return min;
}