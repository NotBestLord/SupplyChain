#ifndef __SUPPLIER_H__
#define __SUPPLIER_H__

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

	Supplier(double balance, int maxOwnedProducts, const char* name, int maxDeliverers);
	Supplier(const Supplier& other);
	Supplier(Supplier&& other);
	const Supplier& operator=(const Supplier& other);
	const Supplier& operator=(Supplier&& other);
public:
	virtual ~Supplier();

	void buy(Product& product, Supplier& supplier);
	DeliveryMethod* sell(Consumer& consumer);

	const Product** getSupply() const { return (const Product**)supply; }
	const Product* getProduct(const char* name) const;

	Supplier& operator+=(Product* product);
	Supplier& operator-=(Product* product);
	Supplier& operator+=(DeliveryMethod* method);
};

#endif