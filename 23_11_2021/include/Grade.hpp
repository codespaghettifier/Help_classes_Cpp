#pragma once

#include "Student.hpp"

class Grade
{
public:
	Grade(unsigned grade, const Student& student);
	void print() const;

private:
	const unsigned grade;
	const Student& student;
};
