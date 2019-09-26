#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include "Student.h"
#include <iostream>

class Roster {
private:
	int lastIndex;
	int capacity;
	Student** students;
	Student* classRosterArray[5];

public:
	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);
	void parseThenAdd(string datarow);
	void add(string studID, string fiName, string laName, string emAddr, int a, int day0, int day1, int day2, DegreeType);
	void print_All();
	bool remove(string studID);
	void printBadEmail();
	void printnumDays(string);
	void printByDegreeType(DegreeType);

	//deconstructor
	~Roster();
};


#endif // !ROSTER_H
