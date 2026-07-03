#ifndef __TRANSACTION_MANAGER_H__
#define __TRANSACTION_MANAGER_H__

#include <iostream>

class Consumer;
class Product;
class Customer;
class Supplier;
class Factory;
class Store;

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
	void printProducts() const;
	void printConsumers() const;
	void printCustomers() const;
	void printSuppliers() const;
	void printStores() const;
	void printFactories() const;

	Consumer* getConsumer(int index);
	const Consumer* getConsumer(int index) const;
	Product* getProduct(const char* name);
	const Product* getProduct(const char* name) const;

	Customer* getCustomer(int index);
	Supplier* getSupplier(int index);
	Factory* getFactory(int index);
	Store* getStore(int index);

	TransactionManager& operator+=(Consumer& consumer);
	TransactionManager& operator+=(Product& product);
	friend std::ostream& operator<<(std::ostream& os, const TransactionManager& tm);
};

#endif