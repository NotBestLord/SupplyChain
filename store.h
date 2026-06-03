#pragma once
#include <iostream>
#include "supplier.h"

using namespace std;

class Customer;

class Store : public Supplier
{
public:
	Store(double balance, int maxOwnedProducts, const char* name, int maxDeliverers);
	Store(const Store& other);
	Store(Store&& other);
	~Store();

	void sellInPerson(Customer& customer);

	Store& operator=(const Store& other);
    Store& operator=(Store&& other);
	friend ostream& operator<<(ostream& os, const Store& s);
};