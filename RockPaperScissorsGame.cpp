#include <iostream>
#include <string>
#include<ctime>
#define MIN_NUM 1
#define MAX_NUM 3
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
		cout << "\nRock: 1 | Paper: 2 | Scissors: 3\nEnter your choice: ";
		cin >> choice;
	}
};

class RandomComputerPlayer : public ComputerPlayer {
public:
	void setChoice() {
		this->choice = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
	}
};

int main(){
	srand(time(NULL));
	
	string playerName, answer;

	cout << "\tWelcome to Rock-Paper-Scissors Game!" << endl;

	RandomComputerPlayer newComputer = RandomComputerPlayer();
	HumanPlayer newPlayer = HumanPlayer();

	cout << "\nEnter your name: ";
	cin >> playerName;
	newPlayer.setName(playerName);

	cout << "\n\tThe game has started. Good luck, " << playerName << "!" << endl;

	do {
		//newPlayer.setChoice();


		cout << "\nDo you want to continue playing, " << playerName << "? (Yes or No) \nEnter your answer: ";
		cin >> answer;

	} while (answer != "No");

	return 0;
}
