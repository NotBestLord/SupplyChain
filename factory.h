#pragma once

#include "supplier.h"

class Product;

class Factory: public Supplier
{
private:
    Product** ingredients;
    int currentIngredients;
public:
    Factory();
    Factory(const Factory& other);
    Factory(Factory&& other);
    ~Factory();

    void addIngredient(Product* ingredient);
    void produce(Product* product);
};
