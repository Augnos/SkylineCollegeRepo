#include "Product.h"
#include <iostream>
#include <string>

// ========== Product Functions ==========
// +++++ Product Constructors +++++
Product::Product(string name)
{
    this->name = name;
}
Product::Product(string name, float price)
{
    this->name = name;
    this->price = price;
}

// +++++ Product Accessors +++++
string Product::getName() const
{
    return name;
}
float Product::getPrice() const
{
    return price;
}

// +++++ Product Mutators +++++
void Product::setName(string name)
{
    this->name = name;
}
void Product::setPrice(float price)
{
    this->price = price;
}

// +++++ Product Functions +++++
void Product::print()
{
    std::cout << "Product: " << name << " ($" << price << ")\n";
}

// ========== FoodProduct Functions ==========
// +++++ FoodProduct Constructors +++++
FoodProduct::FoodProduct(string name, int expirationDate) : Product(name)
{
    this->expirationDate = expirationDate;
    type = "Unknown";
}
FoodProduct::FoodProduct(string name, float price, int expirationDate) : Product(name, price)
{
    this->expirationDate = expirationDate;
    type = "Unknown";
}

// +++++ FoodProduct Accessors +++++
string FoodProduct::getType() const
{
    return type;
}
int FoodProduct::getExpirationDate() const
{
    return expirationDate;
}

// +++++ FoodProduct Mutators +++++
void FoodProduct::setType(string type)
{
    this->type = type;
}
void FoodProduct::setExpirationDate(int expirationDate)
{
    this->expirationDate = expirationDate;
}

// +++++ FoodProduct Functions +++++
void FoodProduct::print()
{
    Product::print();
    std::cout << "Food type: " << type << std::endl;
}

// ========== Cart Functions ==========
// +++++ Cart Constructors +++++
Cart::Cart()
{
    for (int i = 0; i < 99; i++)
    {
        prodList[i] = nullptr;
    }
    count = 0;
}

// +++++ Cart Accessors +++++
int Cart::getProductCount()
{
    return count;
}
float Cart::getTotal()
{
    float total = 0;
    for (int i = 0; i < count; i++)
    {
        total += prodList[i]->getPrice();
    }
    return total;
}

// +++++ Cart Mutators +++++
bool Cart::addProduct(Product *prodPtr)
{
    if (count < 99)
    {
        prodList[count] = prodPtr;
        count++;
        return true;
    }
    return false;
}
bool Cart::removeProduct(Product *prodPtr ){
    int index = findProduct(prodPtr);
    if (index == -1)
    {
        return false;
    }
    for (int j = index + 1; j < count; j++)
    {
        prodList[index] = prodList[j];
        index++;
    }
    count--;
    return true;
}

// +++++ Cart Functions +++++
void Cart::print()
{
    for (int i = 0; i < count; i++)
    {
        prodList[i]->print();
    }
    std::cout << "Total: $" << getTotal();
}
int Cart::findProduct(Product *prodPtr){
    for (int i = 0; i < count; i++)
    {
        if (*prodList[i] == *prodPtr)
            return i;
    }
    return -1;
}

// +++++ Operator Overloads +++++
bool Product::operator==(const Product &anotherProduct) const
{
    return (name == anotherProduct.getName()) ? true : false;
}


int main()
{
    Product soapObj("Dove Hand Wash", 4.69);
    soapObj.print();

    FoodProduct foodObj("Apple", 0.79, 20230416);
    foodObj.print();

    Product inventory[2] = {soapObj, foodObj};
    std::cout << "Inventory printout\n";
    for (int i = 0; i < 2; i++)
    {
        inventory[i].print();
    }

    Product *productPtr[2];
    productPtr[0] = &soapObj;
    productPtr[1] = &foodObj;
    for (int i = 0; i < 2; i++)
    {
        productPtr[i]->print();
    }

    return 0;
}