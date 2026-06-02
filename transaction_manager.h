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
    int max_consumers; // if reached, double consumers array size and copy original values
    int current_consumers;
    Product** products;
    int max_products; // if reached, double products array size and copy original values
    int current_products;
public:
    TransactionManager();
    TransactionManager(const TransactionManager& other);
    TransactionManager(TransactionManager&& other);
    ~TransactionManager();

    void transact(Consumer& consumer, Product& product);
    void printConsumers();
    void printProducts();
    Consumer* getConsumer(int index);
    Product* getProduct(const char *name);

    friend ostream& operator<<(ostream& os, const TransactionManager& set);
    const TransactionManager& operator+=(Consumer& consumer);
    const TransactionManager& operator+=(Product& product);
};

#endif
