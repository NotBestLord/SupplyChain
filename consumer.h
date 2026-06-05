#ifndef __CONSUMER_H__
#define __CONSUMER_H__

class Product;
class Supplier;

class Consumer
{
protected:
	double balance;
	Product** ownedProducts;
	int maxOwnedProducts;
	int currentOwnedProducts;

public:
	Consumer(double balance, int maxOwnedProducts);
	Consumer(const Consumer& other);
	Consumer(Consumer&& other);
	virtual ~Consumer() = 0;
	virtual void buy(Product& product, Supplier& supplier);

	void setBalance(double balance) { this->balance = balance; }
	double getBalance() const { return balance; }
	
	const Consumer& operator=(const Consumer& other);
	const Consumer& operator=(Consumer&& other);
};

#endif