#pragma once

class Product;
class Consumer;

class DeliveryMethod
{
protected:
	Product** products;
	int maxProducts;
	int currentProducts;

public:
	DeliveryMethod(int maxProducts);
	DeliveryMethod(const DeliveryMethod& other);
	virtual ~DeliveryMethod() = 0;

	virtual void deliver(Consumer* consumer);

	DeliveryMethod& operator=(const DeliveryMethod& other);
	const DeliveryMethod& operator+=(Product* p);
};

inline DeliveryMethod::~DeliveryMethod() {}