#include "StudentList.h"



// default constructor
StudentList::StudentList()
{
	first = NULL;
	last = NULL;
	count = 0;
}


// addStudent
void StudentList::addStudent(const Student& newStudent)
{
	if(first == NULL)
	{
		Node* newNode = new Node;
		newNode->setStudent(newStudent);
		newNode->setNext(NULL);
		first = newNode;
		last = newNode;
	}
	else
	{
		Node* newNode = new Node;
		newNode->setStudent(newStudent);
		newNode->setNext(first);
		first = newNode;
	}
	count++;
}


// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return count;
}


// printStudentByID
void StudentList::printStudentByID(int studentID, double tuitionRate) const
{
	if(first == NULL)
	{
		cerr << "List is empty.";
	}
	else
	{
		Node* temp = first;
		bool found = false;

		while(temp != NULL && !found)
		{
			if(temp->getStudent().getID() == studentID)
			{
				found = true;
			}

			temp = temp->getNext();
		}

		if(!found)
		{
			cout << "No student with ID " << studentID << " found in the list.";
		}
	}
	
}


// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& courseNo) const
{
	if(first == NULL)
	{
		cerr << "List is empty.";
	}
	else
	{
		Node* temp = first;
		bool enrolled = false;

		while(temp != NULL && !enrolled)
		{
			if(temp->getStudent().getNumberOfCourses() == 0)
			{
			}
			else
			{
				vector<Course> studentCourse = temp->getStudent().getCoursesEnrolled();
				int size = static_cast<int>(studentCourse.size());
				int i = 0;

				while(i < size && !enrolled)
				{
					if(studentCourse[i].getCourseName() == courseNo)
					{
						enrolled = true;
						temp->getStudent().printStudentInfo();
					}

					i++;
				}
			}

			temp = temp->getNext();
		}

		if(!enrolled)
		{
			cout << "No student enrolled in " << courseNo << " is in the list.";
		}
	}
}


// printStudentsByName
void StudentList::printStudentsByName(const string& lastName) const
{
	if(first == NULL)
	{
		cerr << "List is empty.";
	}
	else
	{
		Node* temp = first;
		bool found = false;

		while(temp != NULL && !found)
		{
			if(temp->getStudent().getLastName() == lastName)
			{
				found = true;
				temp->getStudent().printStudentInfo();
			}

			temp = temp->getNext();
		}

		if(!found)
		{
			cout << "No student with last name " << lastName << " is in the list.";
		}
	}
}


// printStudentsOnHold
void StudentList::printStudentsOnHold(double tuitionRate) const
{
	if(first == NULL)
	{
		cerr << "No students in the list.";
	}
	else
	{
		Node* temp = first;

		while(temp != NULL)
		{
			if(!temp->getStudent().isTuitionPaid())
			{
				(temp->getStudent()).printStudentInfo();
				cout << " - " << temp->getStudent().billingAmount(tuitionRate)
					 << endl;
			}

			temp = temp->getNext();
		}
	}
}


// printAllStudents
void StudentList::printAllStudents(double tuitionRate) const
{
	Node* temp = first;

	while(temp != NULL)
	{
		temp->getStudent().printStudentInfo(tuitionRate);
		temp = temp->getNext();
	}
}


// printStudentsToFile



// destroyStudentList
void StudentList::destroyStudentList()
{
	Node* temp;

	while(first != NULL)
	{
		temp = first;
		first = first->getNext();
		delete temp;
		temp = NULL;
	}

	last = NULL;
	count = 0;
}


// destructor
StudentList::~StudentList()
{
	destroyStudentList();
}
