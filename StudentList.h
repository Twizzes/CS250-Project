#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	Node( ): student( ), next(NULL) {} 
    Node(const Student& newStudent, Node *newNext) 
		: student(newStudent), next(newNext){}
    Student getStudent( ) const { return student; }
	Node* getNext( ) const { return next; }	
    void setStudent(const Student& newStudent) { student = newStudent; }
	void setNext(Node *newNext) { next = newNext; }
private:
    Student student;	
    Node *next;		
};

class StudentList
{
public:

	// default constructor
	StudentList();

	// addStudent
	void addStudent(const Student&);

	// getNoOfStudents
	int getNoOfStudents() const;

	// printStudentByID
	void printStudentByID(int, double) const;

	// printStudentsByCourse
	void printStudentsByCourse(const string&) const;

	// printStudentsByName
	void printStudentsByName(const string&) const;

	// printStudentsOnHold
	void printStudentsOnHold(double) const;

	// printAllStudents
	void printAllStudents(double) const;

	// printStudentsToFile


	// destroyStudentList
	void destroyStudentList();

	// destructor
	~StudentList();

private:
	Node *first;
	Node *last;
	int count;
};

#endif

