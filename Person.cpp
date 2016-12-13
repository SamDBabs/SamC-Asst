#include "Person.h"
#include<string>

using namespace std;

Person::Person(string pName, string pJob) {
	personName = pName;
	jobTitle = pJob;
}
std::string Person::getPerson() {
	return "Name: " + personName + " Job Title: " + jobTitle;
}
void Person::addPerson(string pName, string pJob) {
	personName = pName;
	jobTitle = pJob;
}

