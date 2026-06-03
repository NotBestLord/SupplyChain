#pragma once
#include "consumer.h"

class Product;
class DeliveryMethod;

class Supplier : public Consumer
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
	Supplier(double balance, int maxOwnedProducts, const char* name, int maxDeliverers);
	Supplier(const Supplier& other);
	virtual ~Supplier() = 0;

	DeliveryMethod* sell(Consumer* consumer);

	const Product** getSupply() const { return (const Product**)supply; }
	const Product* getProduct(const char* name) const;

	Supplier& operator=(const Supplier& other);
	const Supplier& operator+=(Product* product);
	const Supplier& operator+=(DeliveryMethod* method);
};

inline Supplier::~Supplier() {}