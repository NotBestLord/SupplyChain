#pragma once

#include "customer.h"
#include "supplier.h"

class Store: public Supplier
{
private:
    
public:
    Store(double balance, int maxOwnedProducts, const char* name, int maxDeliverers);
    Store(const Store& other);
    Store(Store&& other);
    ~Store();

    void sellInPerson(Customer& customer);
};
