#ifndef __STORE_H__
#define __STORE_H__

#include "customer.h"
#include "supplier.h"

class Store : public Supplier
{
    private:
        
    public:
        void sellInPerson(Customer& customer);
};

#endif
