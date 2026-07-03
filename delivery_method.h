#ifndef __DELIVERY_METHOD_H__
#define __DELIVERY_METHOD_H__

#include <iostream>

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
	DeliveryMethod(const DeliveryMethod& other) = delete;
	DeliveryMethod(DeliveryMethod&& other) = delete;
	const DeliveryMethod& operator=(const DeliveryMethod& other) = delete;
	const DeliveryMethod& operator=(DeliveryMethod&& other) = delete;
	virtual ~DeliveryMethod() = 0;

	virtual void deliver(Consumer* consumer) = 0;

	DeliveryMethod& operator+=(Product* p);
};

#endif