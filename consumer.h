#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "product.h"

class Supplier {};


class Consumer {
    public:
        void buy(Product product, Supplier supplier);
    private:
        double balance;
        Product** owned_products;
        int max_owned_products;
        int current_owned_products;
};

#endif