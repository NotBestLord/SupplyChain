#ifndef __TRANSACTION_MANAGER_H__
#define __TRANSACTION_MANAGER_H__

class Consumer;
class Product;

class TransactionManager
{
    private:
        Consumer** consumers;
        Product** products;
    public:
        void addConsumer();
        void addProduct();
        
        void transact(Consumer& consumer, Product& product);
        void print();
};

#endif
