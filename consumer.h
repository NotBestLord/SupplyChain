#pragma once

class Product;
class Supplier;

class Consumer {
protected:
	double balance;
	Product** ownedProducts;
	int maxOwnedProducts;
	int currentOwnedProducts;

public:
	Consumer(double balance, int maxOwnedProducts);
	Consumer(const Consumer& other);
	virtual ~Consumer() = 0;
	virtual void buy(Product* product, Supplier* supplier);
	
	Consumer& operator=(const Consumer& other);
};

inline Consumer::~Consumer() {}