#pragma once

#include <iostream>
#include "delivery_method.h"

class DeliveryVehicle: public DeliveryMethod
{
private:
    
public:
    DeliveryVehicle();
    DeliveryVehicle(const DeliveryVehicle& other);
    DeliveryVehicle(DeliveryVehicle&& other);
    ~DeliveryVehicle();
	
    void deliver(Consumer* consumer);

	DeliveryVehicle& operator=(const DeliveryVehicle& other);
	friend ostream& operator<<(ostream& os, const DeliveryVehicle& d);
};

