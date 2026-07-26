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

	DeliveryMethod(int maxProducts);
public:
	DeliveryMethod(const DeliveryMethod& other) = delete;
	DeliveryMethod(DeliveryMethod&& other) = delete;
	virtual ~DeliveryMethod();

	virtual void deliver(Consumer& consumer) = 0;

	DeliveryMethod& operator+=(Product* p);
};

#endif