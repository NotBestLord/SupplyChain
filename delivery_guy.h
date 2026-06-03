#pragma once
#include <iostream>
#include "person.h"
#include "delivery_method.h"

using namespace std;

class DeliveryGuy : public Person, public DeliveryMethod
{
public:
	DeliveryGuy(const char* name, eGender gender, Date& date, int maxProducts);
	DeliveryGuy(const DeliveryGuy& other) = delete;
	DeliveryGuy(DeliveryGuy&& other) = delete;
	DeliveryGuy& operator=(const DeliveryGuy& other) = delete;
	DeliveryGuy& operator=(DeliveryGuy&& other) = delete;
	~DeliveryGuy();

	void deliver(Consumer* consumer) override;

	friend ostream& operator<<(ostream& os, const DeliveryGuy& d);
};