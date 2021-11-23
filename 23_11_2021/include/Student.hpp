#pragma once

#include <iostream>

class Student
{
public:
	Student(int id);
	void print() const;
	void addGrade(unsigned grade) const;
	inline int getId() const;
	~Student();

private:
	const int id;
	unsigned* const gradesSize;
	unsigned** const grades;
};

inline int Student::getId() const
{
	return id;
}
