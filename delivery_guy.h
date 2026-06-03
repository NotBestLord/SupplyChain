#pragma once

#include <iostream>
#include "person.h"
#include "delivery_method.h"

class DeliveryGuy: public DeliveryMethod, public Person
{
private:
    
public:
    DeliveryGuy(const char* name, eGender gender, Date& date);
    DeliveryGuy(const DeliveryGuy& other);
    DeliveryGuy(DeliveryGuy&& other);
    ~DeliveryGuy();
	
    void deliver(Consumer* consumer);

    friend ostream& operator<<(ostream& os, const DeliveryGuy& d);
};
