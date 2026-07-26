#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include "date.h"

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
	const Date birthDate;

	Person(const char* name, eGender gender, const Date& birthDate);
public:
	Person(const Person& other) = delete;
	Person(Person&& other) = delete;
	virtual ~Person();

	void setName(const char* name);
	const char* getName() const { return name; }

	void setGender(eGender gender) { this->gender = gender; }
	eGender getGender() const { return gender; }

	const Date& getBirthDate() const { return birthDate; }

	friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif