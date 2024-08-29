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
	
	int winnerNumber;
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
		
		winnerNumber = ReturnWinner(newPlayer.getChoice(), newComputer.getChoice());
		
		cout << "Winner Number: " << winnerNumber << endl;



		





		// printwinner fonksiyonunu dowhile bloğunun içinde winner loser yazıp kodu kısaltmaya çalış önce
		// printwinner fonksiyonu kazananı return etmesi sağlanmalı bir şekilde..
		// ScoreCalculate ile kazananın skoru güncellenmesii yapılmalı 
		// doWhile bloğunundan çıktığında kullanıcı toplam puanlar ekrana yazdırılsın.
		// 
		// "Oyun boyunca yapılan hamleler kaydedilecek ve geçmiş hamleler görüntülenebilecek." 
		// yukarıdaki gereksinimi ya dosya işlemleri ile yada node yapısı ile yapabilirsin
		// son gereksinimi tamamladığında proje gereksinim dosyasını açıp programı kontrol et ve bitti

		cout << "\nDo you want to continue playing, " << playerName << "? (Yes or No) \nEnter your answer: ";
		cin >> answer;

	} while (answer != "No" && answer != "no" && answer != "NO" && answer != "n" && answer != "N");

	return 0;
}
