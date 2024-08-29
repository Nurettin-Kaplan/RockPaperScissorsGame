#include <iostream>
#include <string>
#include<ctime>
#include<fstream>
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

	void setScore(int score) {
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

int ReturnWinner(int player, int computer) {

	if (player == computer) {	// draw = 0
		return 0;
	}
	else if (player == 1 && computer == 2) { // winner = computer = 1
		return 1;
	}
	else if (player == 1 && computer == 3) { // winner = player = 2
		return 2;
	}
	else if (player == 2 && computer == 1) {
		return 2;
	}
	else if (player == 2 && computer == 3) {
		return 1;
	}
	else if (player == 3 && computer == 1) {
		return 1;
	}
	else if (player == 3 && computer == 2) {
		return 2;
	}
}

int main(){
	srand(time(NULL));
	
	int winnerNumber, exitAnswer, line = 1, round = 1;
	string playerName, answer, choiceTrans, winner, loser, fileChoice;

	cout << "\tWelcome to Rock-Paper-Scissors Game!" << endl;

	RandomComputerPlayer newComputer = RandomComputerPlayer();
	HumanPlayer newPlayer = HumanPlayer();

	cout << "\nEnter your name: ";
	cin >> playerName;
	newPlayer.setName(playerName);

	cout << "\n\tThe game has started. Good luck, " << newPlayer.getName() << "!" << endl;

	ofstream printFile("PreviousMoves.txt", ios::out);
	do {
		newPlayer.setChoice();
		choiceTrans = ChoiceRotation(newPlayer.getChoice());

		cout << "\n" << playerName << ": " << choiceTrans << endl;

		newComputer.setChoice();
		choiceTrans = ChoiceRotation(newComputer.getChoice());

		cout << "Computer: " << choiceTrans << endl;

		if (printFile.is_open()) {
			printFile << newPlayer.getChoice() << endl << newComputer.getChoice() << endl;
		}
		else {
			perror("\nFile could not be opened.\n");
		}

		winnerNumber = ReturnWinner(newPlayer.getChoice(), newComputer.getChoice());
		
		switch (winnerNumber) {
			case 0:
				cout << "\nDraw" << endl;
				break;
			case 1:
				winner = "Computer";
				loser = newPlayer.getName();
				newComputer.setScore(10);
				break;
			case 2:
				winner = newPlayer.getName();
				loser = "Computer";
				newPlayer.setScore(10);
				break;
			default:
				cout << "\nAn error occurred while determining the winner." << endl;
				break;
		}
		
		if (winnerNumber == 1 || winnerNumber == 2) {
			cout << "\nWinner: " << winner << endl;
			cout << "Loser: " << loser << endl;
		}

		cout << "\nDo you want to continue playing, " << playerName << "? (Yes or No) \nEnter your answer: ";
		cin >> answer;

	} while (answer != "No" && answer != "no" && answer != "NO" && answer != "n" && answer != "N");
	
	printFile.close();

	cout << "\n" << newPlayer.getName() <<  "'s Total Score: " << newPlayer.getScore() << endl;
	cout << "Computer's Total Score: " << newComputer.getScore() << endl;

	cout << "\nTo list previous moves : 1 | To exit the game: 0\nEnter your choice: ";
	cin >> exitAnswer;

	if (exitAnswer == 1) {
		ifstream readFile("PreviousMoves.txt", ios::in);

		if (readFile.is_open()) {
			cout << "\n--------------------------------------------";
			while (getline(readFile, fileChoice)) {
				choiceTrans = ChoiceRotation(stoi(fileChoice));
				
				if (line % 2 != 0) {
					cout << "\nRound " << round << endl;
					cout << "\n" << newPlayer.getName() << ": " << choiceTrans << endl;
					round++;
				}
				else {
					cout << "Computer" << ": " << choiceTrans << endl;
					cout << "\n--------------------------------------------";
				}

				line++;
			}
		}
		else {
			perror("\nFile could not be opened.\n");
		}
		readFile.close();
	}

	return 0;
}
