#include <iostream>
#include "NetworkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent() :Student() {
	degreeType = NETWORKING;
}

NetworkStudent::NetworkStudent(string studID, string fiName, string laName, string emAddr, int a, int* nmDays, DegreeType degreetype) : Student(studID, fiName, laName, emAddr, a, nmDays) {
	degreeType = NETWORKING;
}

DegreeType NetworkStudent::getDegreeType() {
	return NETWORKING;

}

void NetworkStudent::print() {
	this->Student::print();
	cout << "NETWORKING" << "\n";
}
NetworkStudent::~NetworkStudent() {
	Student::~Student();
}