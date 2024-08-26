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
	int score = 0;

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
		if (name.length() < 12) {
			this->name = name;
		}
		else {
			cout << "\nThe name you entered is longer than 12 characters. Please try again." << endl;
		}
	}

	virtual void setChoice() = 0;

	void setScore(int score) {
		this->score += score;
	}
};

class ComputerPlayer {
protected:
	int choice;
	int score = 0;

public:
	int getChoice() {
		return choice;
	}
	
	int getScore() {
		return score;
	}

	virtual void setChoice() = 0;

	int setScore(int score) {
		this->score += score;
	}
};

class HumanPlayer : public Player {
public:
	void setChoice() {
		cout << "\nRock: 1 | Paper: 2 | Scissors: 3\nEnter your choice: ";
		cin >> this->choice;
	}
};

class RandomComputerPlayer : public ComputerPlayer {
public:
	void setChoice() {
		this->choice = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
	}
};

string ChoiceRotation(int value) {
	
	if (value == 1) {
		return "Rock";
	}
	else if (value == 2) {
		return "Paper";
	}
	else if (value == 3) {
		return "Scissors";
	}
	else {
		return "Invalid Entry";
	}
}

void PrintWinner(int player, int computer, HumanPlayer newPlayer) {
	if (player == computer) {
		cout << "\nDraw" << endl;
	}
	else if (player == 1 && computer == 2) {
		cout << "\nWinner: Computer" << endl;
		cout << "Loser: " << newPlayer.getName() << endl;
	}
	else if (player == 1 && computer == 3) {
		cout << "\nWinner: " << newPlayer.getName() << endl;
		cout << "Loser: Computer" << endl;
	}
	else if (player == 2 && computer == 1) {
		cout << "\nWinner: " << newPlayer.getName() << endl;
		cout << "Loser: Computer" << endl;
	}
	else if (player == 2 && computer == 3) {
		cout << "\nWinner: Computer" << endl;
		cout << "Loser: " << newPlayer.getName() << endl;
	}
	else if (player == 3 && computer == 1) {
		cout << "\nWinner: Computer" << endl;
		cout << "Loser: " << newPlayer.getName() << endl;
	}
	else if (player == 3 && computer == 2) {
		cout << "\nWinner: " << newPlayer.getName() << endl;
		cout << "Loser: Computer" << endl;
	}
}

int main(){
	srand(time(NULL));
	
	string playerName, answer, choiceTrans;

	cout << "\tWelcome to Rock-Paper-Scissors Game!" << endl;

	RandomComputerPlayer newComputer = RandomComputerPlayer();
	HumanPlayer newPlayer = HumanPlayer();

	cout << "\nEnter your name: ";
	cin >> playerName;
	newPlayer.setName(playerName);

	cout << "\n\tThe game has started. Good luck, " << newPlayer.getName() << "!" << endl;

	do {
		newPlayer.setChoice();
		choiceTrans = ChoiceRotation(newPlayer.getChoice());

		cout << "\n" << playerName << ": " << choiceTrans << endl;

		newComputer.setChoice();
		choiceTrans = ChoiceRotation(newComputer.getChoice());

		cout << "Computer: " << choiceTrans << endl;
		
		PrintWinner(newPlayer.getChoice(), newComputer.getChoice(), newPlayer);





		cout << "\nDo you want to continue playing, " << playerName << "? (Yes or No) \nEnter your answer: ";
		cin >> answer;

	} while (answer != "No" && answer != "no" && answer != "NO" && answer != "n" && answer != "N");

	return 0;
}
