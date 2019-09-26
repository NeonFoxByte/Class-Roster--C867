#include "Roster.h"
#include "Student.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include <iostream>
using std::cout;
using std::cerr;


Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->students = nullptr;
}

Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->students = new Student * [capacity];

}
Student* Roster::getStudentAt(int index) {
	return students[index];

}
void Roster::parseThenAdd(string row) {
	if (lastIndex < capacity) {
		lastIndex++;

		//Parsing through studentData and adding them in temp variables

		//Student ID
		int rhs = row.find(",");
		string studID = row.substr(0, rhs);

		//First Name
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string fiName = row.substr(lhs, rhs - lhs);

		//Last Name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string laName = row.substr(lhs, rhs - lhs);


		//Email Address
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string emAddr = row.substr(lhs, rhs - lhs);


		//Student Age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = stoi(row.substr(lhs, rhs - lhs));


		//Days in Course
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day0 = stoi(row.substr(lhs, rhs - lhs)); 


		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day1 = stoi(row.substr(lhs, rhs - lhs));


		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day2 = stoi(row.substr(lhs, rhs - lhs));
		
		// Setting DegreeType based of 3rd char
		DegreeType degreeType;

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string deg = row.substr(lhs, rhs - lhs);


		if (deg[2] == 'C') {
			degreeType = SECURITY;
		}

		else if (deg[2] == 'T') {
			degreeType = NETWORKING;
		}
		else if (deg[2] == 'F') {
			degreeType = SOFTWARE;
		}
		else {
			cerr << "INVALID DEGREE! EXITING NOW!\n";
			exit(-1);
		}


		add(studID, fiName, laName, emAddr, age, day0, day1, day2, degreeType);

	}
	else {
		cerr << "ERROR";
		exit(-1);

	}
}

void Roster::add(string studID, string fiName, string laName, string emAddr, int a, int day0, int day1, int day2, DegreeType degreeType) {
	int numDays[] = { day0, day1, day2 };

	if (degreeType == NETWORKING) students[lastIndex] = new NetworkStudent(studID, fiName, laName, emAddr, a, numDays, degreeType);
	else if (degreeType == SECURITY) students[lastIndex] = new SecurityStudent(studID, fiName, laName, emAddr, a, numDays, degreeType);
	else students[lastIndex] = new SoftwareStudent(studID, fiName, laName, emAddr, a, numDays, degreeType);
}
void Roster::print_All() {
	for (int i = 0; i <= this->lastIndex; i++) (this->students)[i]->print();

}
bool Roster::remove(string ID) {//REMOVE VIA STUDENT ID
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {

		if (this->students[i]->getStudentID() == ID) {

			found = true;

			delete this->students[i];

			this->students[i] = this->students[lastIndex];
			lastIndex--;
		}
	}
	return found;
}

void Roster::printnumDays(string studID) {//PRINTING AVERAGE NUMBER OF DAYS TO COMPLEATE COURSES

	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->students[i]->getStudentID() == studID) {

			found = true;
			int* d = students[i]->getNumDays();
			cout << "Student with ID: " << studID << " has been in courses for an average of " << (d[0] + d[1]+ d[2]) / 3 << " days." << endl;


		}
	}
	if (!found) cout << "STUDENT NOT FOUND!";
}


void Roster::printBadEmail() {

	cout << "INVALID EMAIL :" << endl;
	for (int i = 0; i < 5; i++) {
		string email = students[i]->getEmailAddress();
		if (email.find("@") == string::npos) {
			cout << email << endl;
		}
		if (email.find(".") == string::npos) {
			cout << email << endl;
		}
		if (email.find(" ") != string::npos) {
			cout << email << endl;
		}
	}
	cout << endl;
}



void Roster::printByDegreeType(DegreeType d) {

	cout << "PRINTING STUDENTS IN THE SOFTWARE DEGREE PROGRAM " << degreeTypesStrings[d] << ":" << '\n';
	cout << endl;

	for (int i = 0; i <= lastIndex; i++) {
		if (this->students[i]->getDegreeType() == d) this->students[i]->print();
	}
	cout << endl;
}

Roster::~Roster() {//destroy students... lul
	for (int i = 0; i <= lastIndex; i++) {

		delete this->students[i];
	}
	delete students;
	cout << "deleted";
}

int main() {

	int numStudents = 5;

	cout << "Scripting and Programing Applications - C867 \nWritten by Jordan Brewer in C++, \nStudent Number: 000893878" << endl;// Printing name and such
	cout << endl;

	const string studentData[5] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jordan,Brewer,Jbrew72@wgu.edu,29,50,30,40,SOFTWARE"
	};

	Roster* classRoster = new Roster(numStudents);//New Roster called classRoster
	cout << "PARSING DATA AND ADDING STUDENTS: \t";

	for (int i = 0; i < numStudents; i++) { //Adding to the new Roster

		classRoster->parseThenAdd(studentData[i]);
	}
	cout << "DONE." << endl;
	cout << endl;
	cout << "DISPLAYING ALL STUDENTS:" << endl;
	cout << endl;
	classRoster->print_All(); //print all
	cout << endl;


	classRoster->printBadEmail();//PRINTS BAD EMAILS




	cout << "PRINTING AVERAGE DAYS IN COURSE:" << endl; // AVERAGE DAYS IN COURSE
	cout << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printnumDays(classRoster->getStudentAt(i)->getStudentID());
	}

	cout << endl;

classRoster->printByDegreeType((SOFTWARE));//SPECIFIC DEGREE TYPES DESPLAYED

	cout << "REMOVING A3... \n" << endl;
	if (classRoster->remove("A3")) {
		classRoster->print_All();
		numStudents--;
		cout << endl;
		cout << "STUDENT WITH ID A3 WAS REMOVED" << endl;
		cout << endl;
	}
	else cout << "STUDENT WITH STUDENT ID:A3 WAS NOT FOUND..." << endl;


	cout << "REMOVING A3... \n" << endl; //REMOVING ITEM TWICE FOR ERROR CHECK
	if (classRoster->remove("A3")) {
		classRoster->print_All();
	}
		else cout << "STUDENT WITH STUDENT ID:A3 WAS NOT FOUND..." << endl; cout << endl;

	system("PAUSE");
	return 0;
}
