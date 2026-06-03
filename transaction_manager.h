#pragma once
#include <iostream>

using namespace std;

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
	~TransactionManager();

	void transact(Consumer& consumer, Product& product);
	void printConsumers() const;
	void printProducts() const;

	Consumer* getConsumer(int index);
	const Consumer* getConsumer(int index) const;

	Product* getProduct(const char* name);
	const Product* getProduct(const char* name) const;

	friend ostream& operator<<(ostream& os, const TransactionManager& tm);
	const TransactionManager& operator+=(Consumer& consumer);
	const TransactionManager& operator+=(Product& product);
};