#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Degree.h"
using namespace std;


class Student {
public:
	const static int numDayArraySize = 3;

protected:

	string firstName;
	string lastName;
	string emailAddress;
	string studentID;
	int age;
	int numDays[numDayArraySize];

	DegreeType degreeType;

public:
	Student();
	Student(string, string, string, string, int, int*);

	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getStudentID();
	int getAge();
	int* getNumDays();
	virtual DegreeType getDegreeType() = 0;

	void setFirstName(string fiName);
	void setLastName(string laName);
	void setEmailAddress(string emAddr);
	void setStudentID(string studID);
	void setAge(int a);
	void setNumDays(int day0, int day1, int day2);
	virtual void print() = 0;


	~Student();
};

#endif //STUDENT_H
