#pragma once
#include <string>
#include "Student.h"
#ifndef	SECURITYSTUDENT_H
#define SECURITYSTUDENT_H


//SecurtityStudent Class
class SecurityStudent : public Student {
public:
	SecurityStudent();
	SecurityStudent(
		string studID,
		string fiName,
		string laName,
		string emAddr,
		int a,
		int* numDays,
		DegreeType
	);

	DegreeType getDegreeType();
	void print();

	//deconstructor
	~SecurityStudent();
};
#endif