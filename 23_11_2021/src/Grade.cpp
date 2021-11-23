#include "../include/Grade.hpp"

Grade::Grade(unsigned grade, const Student& student)
: grade(grade)
, student(student)
{
	student.addGrade(grade);
}

void Grade::print() const
{
	std::cout<<"Grade print value="<<grade<<" studentID="<<student.getId()<<std::endl;
}
