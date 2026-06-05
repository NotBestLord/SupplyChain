#ifndef __TRANSACTION_MANAGER_H__
#define __TRANSACTION_MANAGER_H__

#include <iostream>

class Consumer;
class Product;

class TransactionManager
{
private:
	Consumer** consumers;
	int maxConsumers;
	int currentConsumers;
	Product** products;
	int maxProducts;
	int currentProducts;

public:
	TransactionManager();
	TransactionManager(const TransactionManager& other);
	TransactionManager(TransactionManager&& other);
    const TransactionManager& operator=(const TransactionManager& other);
	const TransactionManager& operator=(TransactionManager&& other);
	~TransactionManager();

	void transact(Consumer& consumer, Product& product);
	void printConsumers() const;
	void printProducts() const;

	Consumer* getConsumer(int index);
	const Consumer* getConsumer(int index) const;

	Product* getProduct(const char* name);
	const Product* getProduct(const char* name) const;

	TransactionManager& operator+=(Consumer& consumer);
	TransactionManager& operator+=(Product& product);
	friend std::ostream& operator<<(std::ostream& os, const TransactionManager& tm);
};

#endif