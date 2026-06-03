#pragma once
#include <iostream>
#include "date.h"

using namespace std;

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
	Person(const Person& other) = delete;
	Person(Person&& other) = delete;
	Person& operator=(const Person& other) = delete;
	Person& operator=(Person&& other) = delete;
	virtual ~Person() = 0;

	void setName(const char* name);
	const char* getName() const { return name; }

	void setGender(eGender gender) { this->gender = gender; }
	eGender getGender() const { return gender; }

	const Date& getBirthDate() const { return birthDate; }

	friend ostream& operator<<(ostream& os, const Person& p);
};

inline Person::~Person() {}