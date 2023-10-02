#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


void loadFromFile(vector<string>& list, string& fileName);
void printList(vector<string>& list);
void addToList(vector<string>& list, string& newThing);
void removeFromList(vector<string>& list);
int stringToChar(string& letters);
void writeToFile(vector<string>& list, string& fileName);
// in the future, read a from txt file
//void loadList(vector<string>& list);
int main(void) {
	vector<string> list1;
	string response = " ";
	string defaultFile = "currentTasks.txt";
	loadFromFile(list1, defaultFile);

	while (response[0] != 'e') {
		system("cls");
		printList(list1);
		cout << "remove(r), add(a), or exit(e)?\n";
		getline(cin, response);

		char action = response[0];
		if (action == 'r') {
			if (list1.size() == 0) {
				cout << "There are no tasks to remove. Press enter to continue.\n";
				// just wait until it's read, look for better way later
				char a;
				a = getchar();
			}
			else {
				removeFromList(list1);
			}
		}
		else if (action == 'a') {
			string newThing;
			cout << "What is the new task?\n";
			getline(cin, newThing);
			addToList(list1, newThing);
		}
		else if (action == 'e') {
			writeToFile(list1, defaultFile);
		}
	}

	return 0;
}

// print the list
void printList(vector<string>& list) {
	int n = list.size();

	for (int i = 0; i < n; ++i) {
		cout << i + 1 << ") " << list[i] << "\n";
	}
}
// take a new task from console and puts it into list
void addToList(vector<string>& list, string& newThing) {
	// for now doing push_back, may switch later though
	list.push_back(newThing);
}
// remove a task from list
void removeFromList(vector<string>& list) {

	cout << "\nWhich task # do you wish to remove?\n";
	int task;
	string stringNum;
	getline(cin, stringNum);

	task = stringToChar(stringNum);
	list.erase(list.begin() + task - 1);
}

int stringToChar(string &letters) {
	int number = 0;
	for (int i = 0; i < letters.size(); ++i) {
		number *= 10;
		number += (letters[i] - '0');
	}
	return number;
}

void loadFromFile(vector<string>& list, string& fileName) {
	ifstream file (fileName);

	while (!file.eof()) {
		string newTask;
		getline(file, newTask);
		if (!newTask.empty()) {
			addToList(list, newTask);
		}
	}
	file.close();
}

void writeToFile(vector<string>& list, string& fileName) {
	ofstream file (fileName);

	for (int i = 0; i < list.size(); ++i) {
		file << list[i] << "\n";
	}

	file.close();

}
