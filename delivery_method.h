#pragma once
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
	DeliveryMethod(const DeliveryMethod& other);
	DeliveryMethod(DeliveryMethod&& other);
	virtual ~DeliveryMethod() = 0;

	virtual void deliver(Consumer* consumer) = 0;

	DeliveryMethod& operator=(const DeliveryMethod& other);
	DeliveryMethod& operator=(DeliveryMethod&& other);
	DeliveryMethod& operator+=(Product* p);
};