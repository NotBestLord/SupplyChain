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

	Consumer(double balance, int maxOwnedProducts);
	Consumer(const Consumer& other);
	Consumer(Consumer&& other);
	const Consumer& operator=(const Consumer& other);
	const Consumer& operator=(Consumer&& other);
public:
	virtual ~Consumer();
	
	virtual void buy(Product& product, Supplier& supplier);

	void setBalance(double balance) { this->balance = balance; }
	double getBalance() const { return balance; }
};

#endif