#include <iostream>
#include<iomanip>
#include "Student.h"
using std::cout;
using std::left;
using std::setw;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->age = 0;
	this->emailAddress = "";
	for (int i = 0; i < numDayArraySize; i++) this->numDays[i] = 0;
}

Student::Student(string studID, string fiName, string laName, string emAddr, int a, int* nmDays) {
	studentID = studID;
	firstName = fiName;
	lastName = laName;
	emailAddress = emAddr;
	age = a;
	numDays[0] = nmDays[0];
	numDays[1] = nmDays[1];
	numDays[2] = nmDays[2];
}
//getters
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getNumDays() {
	return numDays;
}

void Student::setStudentID(string studID) {
	studentID = studID;
}

void Student::setFirstName(string fiName)
{
	this->firstName = fiName;
}

void Student::setLastName(string laName)
{
	this->lastName = laName;
}

void Student::setEmailAddress(string emAddr)
{
	this->emailAddress = emAddr;
}

void Student::setAge(int a)
{
	this->age = a;
}

void Student::setNumDays(int day0, int day1, int day2)
{
	Student::numDays[0] = day0;
	Student::numDays[1] = day1;
	Student::numDays[2] = day2;
}

//desplays everything but degree
void Student::print() {
	cout << left << setw(5) << studentID;
	cout << left << setw(10) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(30) << emailAddress;
	cout << left << setw(10) << age;
	cout << left << setw(10) << numDays[0];
	cout << left << setw(10) << numDays[1];
	cout << left << setw(10) << numDays[2];

}

//deconstructor
Student::~Student() {

}