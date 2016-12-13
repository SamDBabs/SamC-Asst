#include <vector>

#include "Task.h"
#include "meetingTask.h"
#include "bugfixTask.h"
#include "workdoneTask.h"
#include "timeAllocations.h"

vector<timeAllocation> timeAllocations;

Task::Task(std::string newDesc) {
	taskDescription = newDesc;
}
Task::Task() {

};

std::string Task::getTaskTescription() {
	return taskDescription;
}

void Task::allocateTime(string tName, string tDesc, string tStart, string tEnd) { //Overloaded function to allocate time for tasks
	meetingTask newMeeting;
	newMeeting = meetingTask(tDesc, tName, tStart, tEnd);
	timeAllocations.push_back(newMeeting);
}

void Task::allocateTime(string tWorkDone, string tStart, string tEnd) { //Overloaded function to allocate time for tasks
	workdoneTask newWorkdone;
	newWorkdone = workdoneTask(tStart, tEnd, tWorkDone);
	timeAllocations.push_back(newWorkdone);
}

void Task::allocateTime(string bStart, string bEnd, int bugNumber, string fixDesc) { //Overloaded function to allocate time for tasks
	bugfixTask newBugfix;
	newBugfix = bugfixTask(bStart, bEnd, bugNumber, fixDesc);
	timeAllocations.push_back(newBugfix);
}

void Task::listTimeAllocations() { //Print out time allocations for tasks
	Task oTask;
	timeAllocation oTimeAlloc;

	vector<timeAllocation>::iterator it;

	if (timeAllocations.size() > 0) {
		cout << "Time Allocations\n";
		cout << "-------------------------\n";
		for (it = timeAllocations.begin(); it < timeAllocations.end(); it++) {
			oTimeAlloc = *it;
			oTimeAlloc.getTimeAllocation();
			cout << "\n";
		}
	}
	else {
		cout << "Task has no time allocations.";
	}
}