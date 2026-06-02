#pragma once

class Product;
class Supplier;

class Consumer {
protected:
	double balance;
	Product** ownedProducts;
	int maxOwnedProducts;
	int ownedProductCount;

public:
	Consumer(double balance, int maxOwnedProducts);
	Consumer(const Consumer& other);
	Consumer& operator=(const Consumer& other);
	virtual ~Consumer() = 0;
	virtual void buy(Product* product, Supplier* supplier);
};

inline Consumer::~Consumer() {}