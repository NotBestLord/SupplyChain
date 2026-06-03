#pragma once
#include "consumer.h"

class Product;
class DeliveryMethod;

class Supplier: public Consumer
{
protected:
	char* name;
	DeliveryMethod** deliverers;
	int maxDeliverers;
	int currentDeliverers;

public:
	Supplier(double balance, int maxOwnedProducts, const char* name, int maxDeliverers);
	Supplier(const Supplier& other);
	virtual ~Supplier() = 0;

	DeliveryMethod* sell(Consumer* consumer);

	const Product** getSupply() { return ownedProducts; }
	const Product* getProduct(const char* name) const;

	Supplier& operator=(const Supplier& other);
	const Supplier& operator+=(Product* supply);
	const Supplier& operator+=(DeliveryMethod* method);
};

inline Supplier::~Supplier() {}