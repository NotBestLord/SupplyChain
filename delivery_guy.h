#ifndef __DELIVERY_GUY_H__
#define __DELIVERY_GUY_H__

#include <iostream>
#include "person.h"
#include "delivery_method.h"

class DeliveryGuy : public Person, public DeliveryMethod
{
public:
	DeliveryGuy(const char* name, eGender gender, const Date& date, int maxProducts);
	DeliveryGuy(const DeliveryGuy& other) = delete;
	DeliveryGuy(DeliveryGuy&& other) = delete;
	~DeliveryGuy();

	void deliver(Consumer& consumer) override;

	friend std::ostream& operator<<(std::ostream& os, const DeliveryGuy& d);
};

#endif