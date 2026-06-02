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
	int currentSupply;
	int maxDeliverers;
	int currentDeliverers;

public:
	Supplier(double balance, int maxOwnedProducts, const char* name, int maxSupply, int maxDeliverers);
	Supplier(const Supplier& other);
	virtual ~Supplier() = 0;

	virtual DeliveryMethod* sell(Consumer* consumer);

	const Product* const* getProducts() const { return supply; }
	const Product* getProduct(const char* name) const;

	Supplier& operator=(const Supplier& other);
	const Consumer& operator+=(Product* p);
	const Consumer& operator+=(DeliveryMethod* p);
};

inline Supplier::~Supplier() {}