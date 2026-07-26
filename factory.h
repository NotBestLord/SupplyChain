#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <iostream>
#include "supplier.h"

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
	const Factory& operator=(const Factory& other);
	const Factory& operator=(Factory&& other);
	~Factory();

	void addIngredient(Product& ingredient);
	void produce(Product& product);

	const Product** getIngredients() const { return (const Product**)ingredients; }
	int getCurrentIngredients() const { return currentIngredients; }

	friend std::ostream& operator<<(std::ostream& os, const Factory& f);
};

#endif