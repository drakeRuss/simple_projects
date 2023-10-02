#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int stringToNum(string& letters);


class list {
public:
	list(string& fileName) {
		loadFromFile(fileName);
	}
	// load from a file
	void loadFromFile(string& fileName) {
		ifstream file(fileName);

		while (!file.eof()) {
			string newTask;
			getline(file, newTask);
			if (!newTask.empty()) {
				addToList(newTask);
			}
		}
		file.close();
	}
	// print the list
	void printList() {
		// keeps accessing out of range
		cout << "length is " << length << "\n";
		for (int i = 0; i < length; ++i) {
			cout << i + 1 << ") " << todo[i] << " i is " << i << "\n";
		}
	}
	// take a new task from console and puts it into list
	void addToList(string& newThing) {
		// for now doing push_back, may switch later though
		todo.push_back(newThing);
		++length;
	}
	// remove a task from the list
	void removeFromList() {
		// should check if it isn't a valid one in future
		cout << "\nWhich task # do you wish to remove?\n";
		int task;
		string stringNum;
		getline(cin, stringNum);

		task = stringToNum(stringNum);
		todo.erase(todo.begin() + task - 1);
		--length;
	}
	void writeToFile(string& fileName) {
		ofstream file(fileName);

		for (int i = 0; i < todo.size(); ++i) {
			file << todo[i] << "\n";
		}

		file.close();
	}
	int length = 0;
private:
	vector<string> todo;
};


int main(void) {
	string defaultFile = "currentTasks.txt";
	list list1 (defaultFile);
	string response = " ";

	while (response[0] != 'e') {
		system("cls");
		list1.printList();
		cout << "remove(r), add(a), or exit(e)?\n";
		getline(cin, response);

		char action = response[0];
		if (action == 'r') {
			if (list1.length == 0) {
				cout << "There are no tasks to remove. Press enter to continue.\n";
				// just wait until it's read, look for better way later
				char a;
				a = getchar();
			}
			else {
				list1.removeFromList();
			}
		}
		else if (action == 'a') {
			string newThing;
			cout << "What is the new task?\n";
			getline(cin, newThing);
			list1.addToList(newThing);
		}
		else if (action == 'e') {
			list1.writeToFile(defaultFile);
		}
	}

	return 0;
}


int stringToNum(string &letters) {
	int number = 0;
	for (int i = 0; i < letters.size(); ++i) {
		number *= 10;
		number += (letters[i] - '0');
	}
	return number;
}
