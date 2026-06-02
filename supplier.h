#pragma once

#include "consumer.h"

class Product;
class DeliveryMethod;

class Supplier: public Consumer
{
protected:
	char* name;
	Product** supply;
	int maxSupply;
	int currentSupply;
	DeliveryMethod** deliverers;
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
	const Supplier& operator+=(Product* p);
	const Supplier& operator+=(DeliveryMethod* p);
};

inline Supplier::~Supplier() {}