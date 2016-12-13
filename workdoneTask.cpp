#include "workdoneTask.h"

workdoneTask::workdoneTask(string param1, string param2, string param3) {
	workdoneDesc = param3;
	startTime = DateTime(param1).getFormatted();
	endTime = DateTime(param2).getFormatted();
}
workdoneTask::workdoneTask() {
}

void workdoneTask::getTimeAllocation() { //Print out the task details
	cout << "TA-W:" << startTime << " - " << endTime << ", " << workdoneDesc ;
}
