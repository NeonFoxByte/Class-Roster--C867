#pragma once
#include <string>
#include "Student.h"
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H


//NetworkStudent Class
class NetworkStudent : public Student {
public:
	NetworkStudent();
	NetworkStudent(
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
	~NetworkStudent();
};
#endif