#include "../include/Student.hpp"

Student::Student(int id)
: id(id)
, gradesSize(new unsigned(0))
, grades(new unsigned*) {}

void Student::print() const
{
	std::cout<<"Student print ID="<<id<<" grades:";
	for(unsigned i = 0; i < *gradesSize; i++)
	{
		std::cout<<" "<<(*grades)[i];
	}
	std::cout<<std::endl;
}

void Student::addGrade(unsigned grade) const
{
	unsigned* temp = *grades;
	*grades = new unsigned[*gradesSize + 1];
	for(unsigned i = 0; i < *gradesSize; i++)
	{
		(*grades)[i] = temp[i];
	}
	(*grades)[*gradesSize] = grade;
	if(*gradesSize != 0) delete[] temp;
	(*gradesSize)++;
}

Student::~Student()
{
	delete[] *grades;
	delete grades;
	delete gradesSize;
}
