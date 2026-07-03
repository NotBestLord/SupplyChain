#ifndef __DELIVERY_VEHICLE_H__
#define __DELIVERY_VEHICLE_H__

#include <iostream>
#include "delivery_method.h"

class DeliveryVehicle : public DeliveryMethod
{
public:
	DeliveryVehicle(int maxProducts);
	DeliveryVehicle(const DeliveryVehicle& other) = delete;
	DeliveryVehicle(DeliveryVehicle&& other) = delete;
	const DeliveryVehicle& operator=(const DeliveryVehicle& other) = delete;
	const DeliveryVehicle& operator=(DeliveryVehicle&& other) = delete;
	~DeliveryVehicle();

	void deliver(Consumer* consumer) override;

	friend std::ostream& operator<<(std::ostream& os, const DeliveryVehicle& d);
};

#endif