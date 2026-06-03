#pragma once
#include <iostream>
#include "Date.h"


enum class eGender
{
	Male,
	Female,
	Other
};

class Person
{
protected:
	char* name;
	eGender gender;
	Date& birthDate;

public:
	Person(const char* name, eGender gender, Date& date);
	Person(const Person& other);
	virtual ~Person() = 0;
	
	void setName(const char* name);
	const char* getName() const { return name; }
	
	void setGender(eGender gender) { this->gender = gender; } 
	eGender getGender() const { return gender; }
	
	const Date& getBirthDate() const { return birthDate; }

	Person& operator=(const Person& other);
	friend istream& operator>>(istream& is, const Person& p);
	friend ostream& operator<<(ostream& os, const Person& p);
};

inline Person::~Person() {}