#pragma once

#include "customer.h"
#include "supplier.h"

class Store: public Supplier
{
private:
    
public:
    void sellInPerson(Customer& customer);
};
