#pragma once
#include<iostream>

#include "timeAllocations.h"
#include "DateTime.h"

class meetingTask : public timeAllocation
{
private:
	std::string meetingParticipants;
	std::string meetingDesc;
	std::string startTime;
	std::string endTime;
public:
	meetingTask(std::string, std::string, std::string, std::string);
	meetingTask();

	void getTimeAllocation(); //Print out the task details
};
