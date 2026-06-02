#pragma once

#include "consumer.h"

class Product;
class DeliveryMethod;

class Supplier: public Consumer {
protected:
	char* name;
	Product** supply;
	DeliveryMethod** deliverers;
	int maxSupply;
	int supplyCount;
	int maxDeliverers;
	int delivererCount;

public:
	Supplier(double balance, int maxOwnedProducts, const char* name, int maxSupply, int maxDeliverers);
	Supplier(const Supplier& other);
	Supplier& operator=(const Supplier& other);
	virtual ~Supplier() = 0;
	virtual const Product* const* getProducts() const { return supply; }
	virtual const Product* getProduct(const char* name) const;
	virtual DeliveryMethod* sell(Consumer* consumer);
};

inline Supplier::~Supplier() {}