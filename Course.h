/*
    McAlpine, Justin; Prieto, Brenden;
    CS A250
    Feb. 14, 2014
 
    Project 1
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Course
{
public:

	// default constructor
	Course();

	// setCourseInfo
	void setCourseInfo(const string&, const string&, char, int);

	// printCourseInfo
	void printCourseInfo(bool) const;

	// getCourseCredits
	int getCourseCredits() const;

	// getCourseNumber
	string getCourseNumber() const;

	// getCourseName
	string getCourseName() const;

	// getCourseGrade
	char getCourseGrade() const;

	// destructor
	~Course();

private:
	string courseName;
	string courseNo;
	char courseGrade;
	int courseCredits;
};

#endif

