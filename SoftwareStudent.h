#pragma once
#include <string>
#include "Student.h"
#ifndef	SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H


//SoftwareStudent Class
class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	SoftwareStudent(
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
	~SoftwareStudent();
};
#endif