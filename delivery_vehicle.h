#ifndef __DELIVERY_VEHICLE_H__
#define __DELIVERY_VEHICLE_H__

#include <iostream>
#include "delivery_method.h"

class DeliveryVehicle : public DeliveryMethod
{
public:
	DeliveryVehicle(int maxProducts);
	~DeliveryVehicle();

	void deliver(Consumer* consumer) override;

	friend std::ostream& operator<<(std::ostream& os, const DeliveryVehicle& d);
};

#endif