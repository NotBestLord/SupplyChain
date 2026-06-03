#pragma once

#include <iostream>
#include "person.h"
#include "consumer.h"

class Customer: public Consumer, public Person
{
private:
    
public:
	Customer(const char* name, eGender gender, Date& date, double balance);
    Customer(const Customer& other);
    Customer(Customer&& other);
    ~Customer();


	friend ostream& operator<<(ostream& os, const Customer& c);
};

