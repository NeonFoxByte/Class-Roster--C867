#include <iostream>
#include "SoftwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent() :Student() {
	degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studID, string fiName, string laName, string emAddr, int a, int* nmDays, DegreeType degreetype) : Student(studID, fiName, laName, emAddr, a, nmDays) {
	degreeType = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeType() {
	return SOFTWARE;

}

void SoftwareStudent::print() {
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}
SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}