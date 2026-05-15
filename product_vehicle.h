#ifndef __PRODUCT_VEHICLE_H__
#define __PRODUCT_VEHICLE_H__

class AbstractVehicle {};
class Product {};

class VehicleProduct : public AbstractVehicle, Product
{
    private:
        bool isUsed;
        int numberOfSeats;
    public:

};

#endif
