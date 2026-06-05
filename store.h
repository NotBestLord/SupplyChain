#ifndef __STORE_H__
#define __STORE_H__

#include <iostream>
#include "supplier.h"

class Customer;

class Store : public Supplier
{
public:
	Store(double balance, int maxOwnedProducts, const char* name, int maxDeliverers);
	~Store();

	void sellInPerson(Customer& customer);

	friend std::ostream& operator<<(std::ostream& os, const Store& s);
};

#endif