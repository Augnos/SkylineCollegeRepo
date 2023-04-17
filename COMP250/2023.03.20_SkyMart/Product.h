#include <iostream>
using std::string;

class Product
{
  private:
    string name;
    float price;

  public:
    Product(string);
    Product(string, float);
    string getName() const;
    float getPrice() const;
    void setName(string);
    void setPrice(float);
    virtual void print();
    bool operator==(const Product &) const;
};

class FoodProduct : public Product
{
  private:
    string type;        // category of food, e.g. Dairy, Fruit, etc.
    int expirationDate; // formatted YYYYMMDD
  public:
    FoodProduct(string, int);
    FoodProduct(string, float, int);
    string getType() const;
    int getExpirationDate() const;
    void setType(string);
    void setExpirationDate(int);
    void print();
};

class Cart
{
  private:
    Product *prodList[99];
    int count;

  public:
    Cart();
    bool addProduct(Product *);
    bool removeProduct(Product *);
    int getProductCount();
    float getTotal();
    int findProduct(Product *);
    void print();
};