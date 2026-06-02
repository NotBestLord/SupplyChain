#ifndef __PRODUCT_H__
#define __PRODUCT_H__

using namespace std;

class Supplier{};

class Product {
private:
    const char* name;
    double cost;
    double weight;
    int minAge;
    Product** ingredients;
    Supplier* supplier;
public:
	Product& operator=(const Product& other);
    friend ostream& operator>>(ostream& os, const Product& set)
    {
        return os;
    };
    friend ostream& operator<<(ostream& os, const Product& set)
    {
        return os;
    };
};

#endif