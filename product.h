#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <iostream>

using namespace std;

class Supplier{};

class Product {
private:
    const char* name;
    double cost;
    double weight;
    int minAge;
    Product** ingredients;
	int maxIngredients;
	int currentIngredients;
    Supplier* supplier;
public:
	Product& operator=(const Product& other);
    friend istream& operator>>(istream& is, const Product& p);
    friend ostream& operator<<(ostream& os, const Product& p);
};

#endif