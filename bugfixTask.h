#pragma once
#include<iostream>

#include "timeAllocations.h"
#include "DateTime.h"

class bugfixTask : public timeAllocation
{
private:
	int bugNumber;
	std::string fixDesc; 
	std::string startTime;
	std::string endTime;
public:
	bugfixTask(std::string, std::string, int, std::string);
	bugfixTask();

	void getTimeAllocation(); //Print out the task details
};
