#ifndef __TRANSACTION_MANAGER_H__
#define __TRANSACTION_MANAGER_H__

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
    void print();
    friend ostream& operator>>(ostream& os, const TransactionManager& set)
    {
        return os;
    };
    const TransactionManager& operator+=(Consumer& consumer);
    const TransactionManager& operator+=(Product& product);
};

#endif
