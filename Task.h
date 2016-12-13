#pragma once
#include<string>
#include<vector>

#include "timeAllocations.h"
using namespace std;

class Task {
public:
	int tasksInProject = 0;

	Task(std::string);
	Task();
	std::string getTaskTescription();

	void allocateTime(string, string, string, string); //Overloaded function to allocate time for tasks

	void allocateTime(string, string, string); //Overloaded function to allocate time for tasks

	void allocateTime(string, string, int, string); //Overloaded function to allocate time for tasks

	void listTimeAllocations(); //Print out time allocations for tasks

private:
	string taskName;
	string taskDescription;
	string taskStart;
	string taskEnd;
	vector<timeAllocation> timeAllocations;
};