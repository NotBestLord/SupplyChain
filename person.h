#ifndef __PERSON_H__
#define __PERSON_H__

#include "date.h"

class Person {
    public:
        enum eGender { MALE, FEMALE, OTHER };
    private:
        char* name;
        int age;
        eGender gender;
        Date birth_date;
};

#endif