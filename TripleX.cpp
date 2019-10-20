#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Prototype
void printInterduction(int levelDifficulty);
void printExplantion(int sum, int product);
void geuessInput(int& gaussA, int& gaussB, int& gaussC);
bool playTheGame(int levelDifficulty);


int main() {
	int levelDifficulty = 1;
	const int MAX_DIFFICULT = 5;
	printInterduction(levelDifficulty);
	while (levelDifficulty<=MAX_DIFFICULT) {
		cout << "You are now at level:" << levelDifficulty << endl;
		bool blevelComplete = playTheGame(levelDifficulty);
		cin.clear();
		cin.ignore();
		if (blevelComplete) {
			++levelDifficulty;
		}
	}

	cout << "Mission success!, you broke all the locks, now escape undetected. ***\n";
	return 0;
}

//Opening massages prints.	
void printInterduction(int levelDifficulty) {
	cout << "Hello Special agent." << endl;
	cout << "Your task is to break all the codes ,to steal the special diamond." << endl;
	cout << "Escape the building when the mission is done." << endl;
}

	//Prints the explantion
void printExplantion(int sum,int product) {
		cout << endl;
		cout << "There are three numbers in the code" << endl;
		cout << "The codes adds up to:";
		cout << sum << endl;
		cout << "The codes multiply to:";
		cout << product << endl;
}

	//Get the user input
void geuessInput(int &gaussA,int &gaussB,int &gaussC) {
	cout << "enter three numbers:";
		cin >> gaussA;
		cin >> gaussB;
		cin >> gaussC;
		cout << "You entered:" << gaussA <<" "<< gaussB << " " << gaussC<< endl;
}

bool playTheGame(int levelDifficulty) {
	//Const variable declaration
	int num = 3 + levelDifficulty;
	const int codeA = rand() % num, codeB = rand() % num, codeC = rand() % num;
	const int sum = codeA + codeB + codeC;
	const int product = codeA * codeB * codeC;
	printExplantion(sum, product);

	//Player guess numbers
	int guessA, guessB, guessC;
	geuessInput(guessA, guessB, guessC);
	int geussSum = guessA + guessB + guessC;
	int geussProduct = guessA * guessB * guessC;

	//Check valid guess
	if (geussSum == sum && geussProduct == product) {
		cout << "****You had passed the level !!**** \n\n";
		return true;
	}
	else {
		cout << "****Wrong password try again...****\n";
		return false;
	}
}
