#pragma once

class Product;
class Consumer;

class DeliveryMethod {
protected:
	Product** products;
	int maxProducts;
	int productCount;

public:
	DeliveryMethod(int maxProducts);
	DeliveryMethod(const DeliveryMethod& other);
	DeliveryMethod& operator=(const DeliveryMethod& other);
	virtual ~DeliveryMethod() = 0;
	virtual void add(Product* product);
	virtual void deliver(Consumer* consumer);
};

inline DeliveryMethod::~DeliveryMethod() {}