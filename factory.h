#pragma once

#include <iostream>
#include "supplier.h"

class Product;

class Factory: public Supplier
{
private:
    Product** ingredients;
    int currentIngredients;
public:
    Factory(double balance, int maxOwnedProducts, const char* name, int maxDeliverers);
    Factory(const Factory& other);
    Factory(Factory&& other);
    ~Factory();

    void addIngredient(Product* ingredient);
    void produce(Product* product);
    const Product** getIngredients() { return ingredients; }
    const int getCurrentIngredients() { return currentIngredients; }

	Factory& operator=(const Factory& other);
	friend ostream& operator<<(ostream& os, const Factory& p);
};
