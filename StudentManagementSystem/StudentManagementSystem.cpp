#include "Student.h"

int main()
{
	StudentList* myList = new StudentList;
	myList->AddStudent();
	myList->AddStudent();
	myList->getCurr()->GetCourses()->AddSubject();

	return 0;
}