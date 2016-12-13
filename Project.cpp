#include "Project.h"

Project::Project(string newName, string newStart, string newEnd) { //user defined constructor
	projectTitle = newName;
	projectStart = DateTime(newStart).getFormatted();
	projectEnd = DateTime(newEnd).getFormatted();
}

Project::Project() { //Default constructor
};

vector<Task> Project::getProectTasks() {
	return projectTasks;
}

string Project::getProjectTitle() {
	return projectTitle;
}
string Project::getProjectStart() {
	return projectStart;
}
string Project::getProjectEnd() {
	return projectEnd;
}
vector<Task> Project::getTasks() {
	return projectTasks;
}

void Project::newTask(string newDesc) { //function to add a new task to the project
	Task newTask = Task(newDesc);
	int i = projectTasks.size();
	projectTasks.push_back(newTask);
}
Task Project::getCurrentTask() { // Return the latest task
	return projectTasks.back();
}


void Project::listTasks() { //Print out the tasks under a project
	Project oProj;
	Task oTask;
	vector<Task>::iterator it;

	if (projectTasks.size() > 0) {
		for (it = projectTasks.begin(); it < projectTasks.end(); it++) {
			oTask = *it;
			cout << "Task : " << oTask.getTaskTescription() << "\n";
			oTask.listTimeAllocations();
		}
	}
	else {
		cout << "\nProject has no tasks.";
	}
}