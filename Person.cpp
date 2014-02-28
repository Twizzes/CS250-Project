#include "Person.h"

Person::Person()
{
	firstName = "N/A";
	lastName = "N/A";
}

Person::Person(const string& first, const string& last)
{
	firstName = first;
	lastName = last;
}

void Person::setName(const string& first, const string& last)
{
	firstName = first;
	lastName = last;
}

string Person::getLastName() const
{
	return lastName;
}

void Person::getName(string& fName, string& lName) const
{
	fName = firstName;
    lName = lastName;
}

void Person::printName() const
{
	cout << lastName << ", " << firstName << endl;
}

Person::~Person()
{

}

