#pragma once
#include<string>

//using namespace std;

class Person { //Person class - additional functionality
public:
	Person(std::string, std::string);
	std::string getPerson();
	void addPerson(std::string pName, std::string pJob);
private:
	std::string personName;
	std::string jobTitle;
};