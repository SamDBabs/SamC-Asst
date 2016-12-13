#pragma once
#include<iostream>

#include "timeAllocations.h"
#include "DateTime.h"

class workdoneTask : public timeAllocation
{
private:
	std::string workdoneDesc; 
	std::string startTime;
	std::string endTime;
public:
	workdoneTask(std::string, std::string, std::string);
	workdoneTask();

	void getTimeAllocation(); //Print out the task details
};
