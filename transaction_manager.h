#ifndef __TRANSACTION_MANAGER_H__
#define __TRANSACTION_MANAGER_H__

#include <iostream>

using namespace std;

class Consumer;
class Product;

class TransactionManager
{
private:
    Consumer** consumers;
    int max_consumers;
    int current_consumers;
    Product** products;
    int max_products;
    int current_products;
public:
    void transact(Consumer& consumer, Product& product);

    friend ostream& operator<<(ostream& os, const TransactionManager& set);
    const TransactionManager& operator+=(Consumer& consumer);
    const TransactionManager& operator+=(Product& product);
};

#endif
