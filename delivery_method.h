#ifndef __DELIVERY_METHOD_H__
#define __DELIVERY_METHOD_H__

#include "product.h"
#include "supplier.h"

class DeliveryMethod
{
    private:
        Product* products;
        int max_products;
        int current_products;
    public:
        void add(Product product);
        void deliver(Supplier supplier);
};

#endif