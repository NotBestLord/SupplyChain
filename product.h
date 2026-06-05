#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <iostream>
#include "supplier.h"

class Product
{
private:
	char* name;
	double cost;
	double weight;
	int minAge;
	Product** ingredients;
	int maxIngredients;
	int currentIngredients;
	const Supplier& supplier;

public:
    Product(const Supplier& supplier);
	Product(const char* name, double cost, double weight, int minAge, const Supplier& supplier);
	Product(const Product& other);
	Product(Product&& other);
	const Product& operator=(const Product& other);
	const Product& operator=(Product&& other);
	~Product();

	const char* getName() const { return name; }
	double getCost() const { return cost; }
	double getWeight() const { return weight; }
	int getMinAge() const { return minAge; }
	const Supplier& getSupplier() const { return supplier; }

	void addIngredient(Product* ingredient);

	bool operator==(const Product& other) const;
	bool operator!=(const Product& other) const;
	friend std::istream& operator>>(std::istream& is, Product& p);
	friend std::ostream& operator<<(std::ostream& os, const Product& p);
};

#endif