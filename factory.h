#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "supplier.h"

class Factory : public Supplier
{
    private:
        
    public:
        void produce();
};

#endif
