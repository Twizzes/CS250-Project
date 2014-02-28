#include "Student.h"

// default constructor
Student::Student()
{
    studentID = 0;
    numberOfCourses = 0;
    tuitionWasPaid = false;
}

// setStudentInfo
void Student::setStudentInfo(const string& fName, const string& lName, int idNumber, bool tuitionPaid, vector<Course> courses)
{
    setName(fName, lName);
    studentID = idNumber;
    numberOfCourses = static_cast<int>(courses.size());
    tuitionWasPaid = tuitionPaid;
    coursesEnrolled = courses;
}

// getID
int Student::getID() const
{
    return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses() const
{
    return numberOfCourses;
}

// getCreditsEnrolled
int Student::getCreditsEnrolled() const
{
    int size = static_cast<int>(coursesEnrolled.size());
    int totalCredits = 0;
    
    for(int i = 0; i < size; i++)
    {
        totalCredits += coursesEnrolled[i].getCourseCredits();
    }
    
    return totalCredits;
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
    return tuitionWasPaid;
}

// isEnrolledInCourse
bool Student::isEnrolledInCourse(const string& courseNo) const
{
    int size = static_cast<int>(coursesEnrolled.size());
    
    if(size == 0)
    {
        return false;
    }
    
    for(int i = 0; i < size; i++)
    {
        if(coursesEnrolled[i].getCourseNumber() == courseNo)
            return true;
    }
    
    return false;
}

// getGpa
double Student::getGpa() const
{
    int size = static_cast<int>(coursesEnrolled.size());
    double gradeToInt = 0.0;
    double totalCredits = 0.0;
    
    for(int i = 0; i < size; i++)
    {
        switch(coursesEnrolled[i].getCourseGrade())
        {
            case 'A':
                gradeToInt = 4.0;
                break;
            case 'B':
                gradeToInt = 3.0;
                break;
            case 'C':
                gradeToInt = 2.0;
                break;
            case 'D':
                gradeToInt = 1.0;
                break;
            default:
                gradeToInt = 0.0;
                break;
        }
        
        totalCredits += gradeToInt * coursesEnrolled[i].getCourseCredits();
    }
    
    return (totalCredits / getCreditsEnrolled());
}

// billingAmount
double Student::billingAmount(double tuitionRate)
{
    return getCreditsEnrolled() * tuitionRate;
}

// printStudentInfo
void Student::printStudentInfo() const
{
    cout << studentID << " - ";
    printName();
}

// printStudentInfo (overloaded)
void Student::printStudentInfo(double tuitionRate) const
{
    cout << "Student Name: ";
    printName();
    cout << endl;
    
    cout << "Student ID: " << studentID << endl;
    cout << "Number of courses enrolled: " << numberOfCourses << endl
         << endl;
    
    cout << left << setw(11) << "Course No" << setw(13) << "Course Name"
         << setw(8) << "Credits" << setw(5) << "Grade"
         << endl;
    
    int size = static_cast<int>(coursesEnrolled.size());
    
    if(tuitionWasPaid)
    {
        for(int i = 0; i < size; i++)
        {
            cout << left << setw(11) << coursesEnrolled[i].getCourseNumber()
            << setw(17) << coursesEnrolled[i].getCourseName()
            << setw(7) << coursesEnrolled[i].getCourseCredits()
            << coursesEnrolled[i].getCourseGrade() << endl;
        }
        
        cout << "\nTotal number of credit hours: " << getCreditsEnrolled() << endl;
        cout << "Current Term GPA: " << getGpa() << endl << endl;
        
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            cout << left << setw(11) << coursesEnrolled[i].getCourseNumber()
            << setw(17) << coursesEnrolled[i].getCourseName()
            << setw(5) << coursesEnrolled[i].getCourseCredits()
            << "***" << endl;
        }
        
        cout << "\nTotal number of credit hours: " << getCreditsEnrolled() << endl;
        cout << "*** Grades are being held for not paying the tuition. ***" << endl;
        cout << "Amount Due: $" << getCreditsEnrolled() * tuitionRate << endl
             << endl;
        
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;
    }
}

// getCoursesEnrolled
vector<Course> Student::getCoursesEnrolled() const
{
    return coursesEnrolled;
}

// destructor
Student::~Student()
{
    
}