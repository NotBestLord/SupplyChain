#pragma once
#include <iostream>
#include "person.h"
#include "consumer.h"

using namespace std;

class Customer : public Person, public Consumer
{
public:
	Customer(const char* name, eGender gender, Date& date, double balance);
	Customer(const Customer& other) = delete;
	Customer(Customer&& other) = delete;
	Customer& operator=(const Customer& other) = delete;
	Customer& operator=(Customer&& other) = delete;
	~Customer();

	friend ostream& operator<<(ostream& os, const Customer& c);
};