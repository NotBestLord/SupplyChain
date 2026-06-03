#pragma once
#include <iostream>

using namespace std;

class Supplier;

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
	const Supplier* supplier;

public:
    Product();
	Product(const char* name, double cost, double weight, int minAge, const Supplier* supplier);
	Product(const Product& other);
	Product(Product&& other);
	~Product();

	const char* getName() const { return name; }
	double getCost() const { return cost; }
	double getWeight() const { return weight; }
	int getMinAge() const { return minAge; }
	const Supplier* getSupplier() const { return supplier; }

	void addIngredient(Product* ingredient);

	Product& operator=(const Product& other);
	Product& operator=(Product&& other);
	friend istream& operator>>(istream& is, const Product& p);
	friend ostream& operator<<(ostream& os, const Product& p);
};