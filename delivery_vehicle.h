#pragma once
#include <iostream>
#include "delivery_method.h"

using namespace std;

class DeliveryVehicle : public DeliveryMethod
{
public:
	DeliveryVehicle(int maxProducts);
	DeliveryVehicle(const DeliveryVehicle& other);
	DeliveryVehicle(DeliveryVehicle&& other);
	~DeliveryVehicle();

	void deliver(Consumer* consumer) override;

	DeliveryVehicle& operator=(const DeliveryVehicle& other);
	DeliveryVehicle& operator=(DeliveryVehicle&& other);
	friend ostream& operator<<(ostream& os, const DeliveryVehicle& d);
};