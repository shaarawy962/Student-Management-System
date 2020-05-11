#include "Student.h"

int main()
{
	StudentList* myList = new StudentList;
	myList->AddStudent();
	myList->getHead()->GetCourses()->AddSubject();

	return 0;
}
