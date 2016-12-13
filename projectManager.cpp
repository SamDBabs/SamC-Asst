//ProgjectManagement
//Samuel D Baba
//b5045441

#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <sstream>
#include <iomanip>

#include "timeAllocations.h"
#include "Project.h"

using namespace std;


class reportingTask :public timeAllocation { //Anothe type derived from timeAllocation - additional functionality
private:
	string reportTitle;
	string reporter;
	string startTime;
	string endTime;
public:
	reportingTask(string rStart, string rEnd, string rTitle, string rRep) {
		reportTitle = rTitle;
		reporter = rRep;
		//startTime = DateTime(rStart).getFormatted();
		//endTime = DateTime(rEnd).getFormatted();
	}
	reportingTask() {

	}
	void getTimeAllocation() { //Print out the task details
		cout << "TA-W" << startTime << " - " << endTime << ", " << reportTitle;
	}
};

void readProjectFile(string projectFile, vector<Project> &inProjects) { //This function will be called to read the input file
	string txtLine, token, subText, pTitle, pStart, pEnd;
	string tTitle, tDesc, tStart, tEnd;
	string mName, mDesc, mStart, mEnd, bNum;
	
	char delimiter;
	int delimiterPos, i, bugNo;
	ifstream file(projectFile);
	Project pTemp, pTemp2;
	

	i = 0;
	cout << "Reading file " << projectFile << " into memory...\n";
	while (getline(file, txtLine)) {
		//Examine the line that has been read from file
		delimiter = ':'; //The character used to demarcate the "Project" keyword from the rest of the text
		delimiterPos = txtLine.find(delimiter); //locate the position of the delimiter
		token = txtLine.substr(0, delimiterPos ); //extract the keyword/token from the text
		subText = txtLine.substr(delimiterPos + 1); //store the remaining text to identify other project details

		if (token == "Project") {
			pTitle = subText.substr(0, subText.find(",")); //get the project title/description
			subText = subText.substr(subText.find(",") + 1);
			pStart = subText.substr(0, subText.find("-")); //get the start date
			pEnd = subText.substr(subText.find("-") + 1); //get the end date

			pTemp = Project(pTitle, pStart, pEnd); //create a project object
			//inProjects.push_back(pTemp); //add new project to the vector
			cout << "Project " << pTitle << " found...\n";

			while (getline(file, txtLine)) {
				if (txtLine == "") {
					break;
				}
				delimiter = ':';
				delimiterPos = txtLine.find(delimiter); 
				token = txtLine.substr(0, delimiterPos); 
				subText = txtLine.substr(delimiterPos + 1); 

				if (token == "Task") {
					tTitle = token;
					tDesc = subText;

					pTemp.newTask(tDesc);
					//int k2 = pTemp.getProectTasks().size();
//					pTemp.newTask(tDesc, tStart, tEnd);
					cout << "Task " << tDesc << " found...   added to project " << pTitle << "\n";

					while (getline(file, txtLine)) {
						if (txtLine == "") {
							break;
						}
						delimiter = ':';
						delimiterPos = txtLine.find(delimiter);
						token = txtLine.substr(0, delimiterPos);
						subText = txtLine.substr(delimiterPos + 1);

						if (token == "TA-M") {
							mStart = subText.substr(0, subText.find("-"));
							subText = subText.substr(subText.find("-") + 1);
							mEnd = subText.substr(0, subText.find(","));
							subText = subText.substr(subText.find(",") + 1);
							mDesc = subText.substr(0, subText.find(","));
							mName = subText.substr(subText.find(",") + 1);

							pTemp.getCurrentTask().allocateTime(mName, mDesc, mStart, mEnd);

							cout << "Meeting time allocated - " << mDesc << "\n";
						}
						else if (token == "TA-W") {
							mStart = subText.substr(0, subText.find("-") - 1);
							subText = subText.substr(subText.find("-") + 1);
							mEnd = subText.substr(0, subText.find(",") - 1);
							subText = subText.substr(subText.find(",") + 1);
							mDesc = subText;

							pTemp.getCurrentTask().allocateTime(mDesc, mStart, mEnd);

							cout << "Workdone time allocated - " << mDesc << "\n";
						}
						else if (token == "TA-B") {
							mStart = subText.substr(0, subText.find("-") - 1);
							subText = subText.substr(subText.find("-") + 1);
							mEnd = subText.substr(0, subText.find(",") - 1);
							subText = subText.substr(subText.find(",") + 1);
							bugNo = stoi(subText.substr(0, subText.find(",") - 1));
							mDesc = subText.substr(subText.find(",") + 1);

							pTemp.getCurrentTask().allocateTime(mStart, mEnd, bugNo, mDesc);

							cout << "Bugfix time allocated - " << mDesc << "\n";
						}
					}
				}
			}
			inProjects.push_back(pTemp); //add new project to the vector
		}
	};
	cout << "Completed reading file to memory";
	cin >> txtLine;
}

void displayProjects(vector<Project> &inProjects) { //Print out the data
	Project oProj;
	vector<Project>::iterator it;

	for (it = inProjects.begin(); it < inProjects.end(); it++) {
		oProj = *it;
		cout << "\n\nProject : " << oProj.getProjectTitle() << "\n";
		cout << "=============================================================================\n";
		cout << "Start Time: " << oProj.getProjectStart() << "\n";
		cout << "End Time  : " << oProj.getProjectEnd() << "\n";

		oProj.listTasks();
	}
	char cWait;
	cin >> cWait;
}

void displayMenu() {
	system("cls");
	cout << "\t\tProject Management Application - Main Menu\n";
	cout << "\t\t======================================================\n";
	cout << "\t\tRead file passed as Command Line Argument... Press [1]\n\n";
	cout << "\t\tDisplay content of project file...           Press [2]\n\n";
	cout << "\t\tInput data another file...                   Press [3]\n\n";
	cout << "\t\tAdd project from keyboard (Interactive)...   Press [4]\n\n";
	cout << "\t\tTo exit the program...                       Press [0]\n\n";
	cout << "\t\t======================================================\n";

	cout << "\t\tEnter you choice and press <ENTER> key: ";
}

void addProject(vector<Project> &inProjects) { //Additional functionality - interactive additing of projects
	string projTitle, startTime, endTime;
	Project newProject;

	cout << "Add new project (Interactive)\n";
	cout << "============================================\n";
	cout << "Input Project Title: ";
	cin >> projTitle;
	cout << "\nInput Project Start time: ";
	cin >> startTime;
	cout << "\nInput Project End time: ";
	cin >> endTime;
	newProject = Project(projTitle, startTime, endTime); //create a project object
	inProjects.push_back(newProject); //add new project to the vector

	char cWait;
	cout << "\n\nProject has been added... press any key and <ENTER> to continue.";
	cin >> cWait;
}

int main(int argc, char* argv[]) {
	char menuChoice = '1';
	string fileName;

	vector<Project> myProjects; //This vector will hold identified projects as they are read from the input file

	while (menuChoice != '0') {
		displayMenu();
		cin >> menuChoice; //Get the user's input or desired action

		switch (menuChoice) {
		case '1':
			system("cls");
			myProjects.clear();
			readProjectFile(argv[1], myProjects); //argv[1] retrieves the input file passed as a command line argument
			break;
		case '2':
			system("cls");
			displayProjects(myProjects);
			break;
		case '3':
			cout << "\n\nInput the full filename (including path) : ";

			cin >> fileName;
			if (!fileName.empty()) {
				myProjects.clear();
				readProjectFile(fileName, myProjects);
			}
			break;
		case '4':
			system("cls");
			addProject(myProjects);
			break;
		case '0':
			break;
		default:
			cout << "\n\t\tInvalid choice... Press any key and <ENTER> to continue! ";
			char cWait;
			cin >> cWait;
			break;
		}
	}
	return 0;
}