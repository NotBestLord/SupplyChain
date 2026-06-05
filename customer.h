#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <iostream>

class Person;
class Consumer;

class Customer : public Person, public Consumer
{
public:
	Customer(const char* name, eGender gender, const Date& date, double balance);
	Customer(const Customer& other) = delete;
	Customer(Customer&& other) = delete;
	const Customer& operator=(const Customer& other) = delete;
	const Customer& operator=(Customer&& other) = delete;
	~Customer();

	void buy(Product& product, Supplier& supplier);

	friend std::ostream& operator<<(std::ostream& os, const Customer& c);
};

#endif