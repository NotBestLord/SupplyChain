#pragma once
#include <iostream>
#include "Date.h"

using namespace std;

enum class eGender {
	Male,
	Female,
	Other
};

class Person {
protected:
	char* name;
	int age;
	eGender gender;
	Date birthDate; 

public:
	Person(const char* name, eGender gender, const Date& date);
	Person(const Person& other);
	virtual ~Person() = 0;
	
	void setName(const char* name);
	const char* getName() const { return name; }
	
	int getAge() const { return age; }
	
	void setGender(eGender gender) { this->gender = gender; } 
	eGender getGender() const { return gender; }
	
	void setBirthDate(Date birthDate) { this->birthDate = birthDate; }
	const Date& getBirthDate() const { return birthDate; }

	Person& operator=(const Person& other);
	friend ostream& operator<<(ostream& os, const Person& p);
};

inline Person::~Person() {}