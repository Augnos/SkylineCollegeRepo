#include <iostream>
using std::string;

class Product {
private:
    string name;
    float price;
public:
    Product(string);
    Product(string, float);
    string getName();
    float getPrice();
    void setName(string);
    void setPrice(float);
    void print();
};

class FoodProduct : public Product{
private:
    string type;    // category of food, e.g. Dairy, Fruit, etc.
    int expirationDate; // formatted YYYYMMDD
public:
    FoodProduct(string, int);
    FoodProduct(string, float, int);
    string getType();
    int getExpirationDate();
    void setType(string);
    void setExpirationDate(int);
    void print();
};