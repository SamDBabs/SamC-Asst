#pragma once
#include "Task.h"
#include "DateTime.h"

#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <sstream>
#include <iomanip>

class Project
{

private:
	std::string projectTitle;
	std::string projectStart;
	std::string projectEnd;

	vector<Task> projectTasks; //vector to hold tasks for a project

public:
	Project(std::string, std::string, std::string); //user defined constructor

	Project(); //Default constructor

	vector<Task> getProectTasks();

	string getProjectTitle();
	string getProjectStart();
	string getProjectEnd();
	vector<Task> getTasks();

	void newTask(string); //function to add a new task to the project

	Task getCurrentTask(); // Return the latest task

	void listTasks(); //Print out the tasks under a project
};