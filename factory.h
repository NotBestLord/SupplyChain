#pragma once
#include <iostream>
#include "supplier.h"

using namespace std;

class Product;

class Factory : public Supplier
{
private:
	Product** ingredients;
	int maxIngredients;
	int currentIngredients;

public:
	Factory(double balance, int maxOwnedProducts, const char* name, int maxDeliverers, int maxIngredients);
	Factory(const Factory& other);
	Factory(Factory&& other);
	~Factory();

	void addIngredient(Product* ingredient);
	void produce(Product* product);

	const Product** getIngredients() const { return (const Product**)ingredients; }
	int getCurrentIngredients() const { return currentIngredients; }

	Factory& operator=(const Factory& other);
	friend ostream& operator<<(ostream& os, const Factory& f);
};