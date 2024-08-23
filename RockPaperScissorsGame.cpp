#include <iostream>
#include <string>
using namespace std;

class Player {
protected:
	string name;
	int choice;
	int score;

public:
	string getName() {
		return name;
	}
	
	int getChoice() {
		return choice;
	}

	int getScore() {
		return score;
	}

	void setName(string name) {
		this->name = name;
	}

	virtual void setChoice() = 0;

	void setScore(int score) {
		this->score = score;
	}
};

class ComputerPlayer {
protected:
	int choice;
	int score;

public:
	int getChoice() {
		return choice;
	}
	
	int getScore() {
		return score;
	}

	virtual void setChoice() = 0;

	int setScore(int score) {
		this->score = score;
	}
};

class HumanPlayer : public Player {
public:
	void setChoice() {
		cout << "Rock: 1 | Paper: 2 | Scissors: 3\nEnter your choice: ";
		cin >> choice;
	}
};

class RandomComputerPlayer : public ComputerPlayer {
public:
	void setChoice() {
		//
	}
};

int main(){




	return 0;
}
