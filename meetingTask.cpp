#include "meetingTask.h"

meetingTask::meetingTask(string param1, string param2, string param3, string param4) {
	meetingDesc = param1;
	meetingParticipants = param2;
	startTime = DateTime(param3).getFormatted();
	endTime = DateTime(param3).getFormatted();
}
meetingTask::meetingTask() {
}

void meetingTask::getTimeAllocation() { //Print out the task details
	cout << "TA-M:" << startTime << " - " << endTime << ", " << meetingDesc << ", " << meetingParticipants;
}
