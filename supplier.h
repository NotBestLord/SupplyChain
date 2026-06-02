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
	const Product* const* getProducts() const { return supply; }
	const Product* getProduct(const char* name) const;
	virtual DeliveryMethod* sell(Consumer* consumer);

	virtual ~Supplier() = 0;
	const Consumer& operator+=(Product* p);
	const Consumer& operator+=(DeliveryMethod* p);
};

inline Supplier::~Supplier() {}