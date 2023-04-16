#include <iostream>
#include "Product.h"

using namespace std;

// ========== Product Functions ==========
// +++++ Product Constructors +++++
Product::Product(string name) {
    this->name = name;
}
Product::Product(string name, float price) {
    this->name = name;
    this->price = price;
}

// +++++ Product Accessors +++++
string Product::getName(){
    return name;
}
float Product::getPrice(){
    return price;
}

// +++++ Product Mutators +++++
void Product::setName(string name){
    this->name = name;
}
void Product::setPrice(float price){
    this->price = price;
}

// +++++ Product Functions +++++
void Product::print(){
    cout << "Product: " << name << " ($" << price << ")\n";
}


// ========== FoodProduct Functions ==========
// +++++ FoodProduct Constructors +++++
FoodProduct::FoodProduct(string name, int expirationDate) : Product(name) {
    this->expirationDate = expirationDate;
    type = "Unknown";
}
FoodProduct::FoodProduct(string name, float price, int expirationDate) : Product(name, price) {
    this->expirationDate = expirationDate;
    type = "Unknown";
}

// +++++ FoodProduct Accessors +++++
string FoodProduct::getType(){
    return type;
}
int FoodProduct::getExpirationDate(){
    return expirationDate;
}

// +++++ FoodProduct Mutators +++++
void FoodProduct::setType(string type){
    this->type = type;
}
void FoodProduct::setExpirationDate(int expirationDate){
    this->expirationDate = expirationDate;
}

// +++++ FoodProduct Functions +++++
void FoodProduct::print(){
    Product::print();
    cout << "Food type: " << type << endl;
}


int main (){
    Product soapObj("Dove Hand Wash", 4.69);
    soapObj.print();

    FoodProduct foodObj("Apple", 0.79, 20230416);
    foodObj.print();

    Product inventory[2] = {soapObj, foodObj};
    cout << endl << "Inventory printout\n";
    for (int i = 0; i < 2; i++){
        inventory[i].print();
    }


    return 0;
}