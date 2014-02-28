/*
    Prieto, Brenden; McAlpine, Justin
    CS A250
    Feb. 14, 2014
 
    Project 1
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
	Person();
	Person(const string& first, const string& last);
	void setName(const string& first, const string& last);
	string getLastName() const;
	void getName(string&, string&) const;
	void printName() const;
	~Person();
private:
	string lastName, firstName;
};

#endif
