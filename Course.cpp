#include "Course.h"

// default constructor
Course::Course()
{
    courseCredits = 0;
    courseGrade = '*';
}

// setCourseInfo
void Course::setCourseInfo(const string& name, const string& num, char grade, int credit)
{
    courseName = name;
    courseNo = num;
    courseGrade = grade;
    courseCredits = credit;
}

// printCourseInfo
void Course::printCourseInfo(bool printGrade) const
{
    cout << left
    << setw(8) << courseNo << "   "
    << setw(15) << courseName;
    cout.unsetf(ios::left);
    cout << setw(3) << courseCredits << "   "
    << setw(4);
    
    if (printGrade)
        cout << courseGrade << endl;
    else
        cout << "***" << endl;
    
}

// getCourseCredits
int Course::getCourseCredits() const
{
    return courseCredits;
}

// getCourseNumber
string Course::getCourseNumber() const
{
    return courseNo;
}

// getCourseName
string Course::getCourseName() const
{
    return courseName;
}

// getCourseGrade
char Course::getCourseGrade() const
{
    return courseGrade;
}

// destructor
Course::~Course()
{
    
}

