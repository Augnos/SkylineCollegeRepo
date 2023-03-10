#include <iostream>
using namespace std;

class Animal {
public:
    Animal(string n, string s, bool f, int legs);
    void move();
    void makeSound();
private:
    int numLegs;
    bool hasFur;
    string name;
    string species;
};

Animal:: Animal(string n, string s, bool f, int legs){
    name = n;
    hasFur = f;
    numLegs = legs;
    species = s;
}

class Whale : public Animal{
public:
    // constructor
    Whale(string type, string n) : Animal(n, type, false, 0){}

    void move(){
        cout << "The whale swims. \n";
    }
private:
    string type;
    string name;
};