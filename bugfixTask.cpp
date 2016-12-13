#include "bugfixTask.h"

bugfixTask::bugfixTask(string bStart, string bEnd, int bNo, string fDesc) {
	bugNumber = bNo;
	fixDesc = fDesc;
	startTime = DateTime(bStart).getFormatted();
	endTime = DateTime(bEnd).getFormatted();
}
bugfixTask::bugfixTask() {

}

void bugfixTask::getTimeAllocation() { //Print out the task details
	cout << "TA-B:" << startTime << " - " << endTime << ", " << bugNumber << ", " << fixDesc;
}
