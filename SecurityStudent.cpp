#include <iostream>
#include "SecurityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent() :Student() {
	degreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string studID, string fiName, string laName, string emAddr, int a, int* nmDays, DegreeType degreetype) : Student(studID, fiName, laName, emAddr, a, nmDays) {
	degreeType = SECURITY;
}

DegreeType SecurityStudent::getDegreeType() {
	return SECURITY;

}

void SecurityStudent::print() {
	this->Student::print();
	cout << "SECURITY" << "\n";
}
SecurityStudent::~SecurityStudent() {
	Student::~Student();
}