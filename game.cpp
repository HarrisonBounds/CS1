//Harrison Bounds
//Guess the number game

#include<iostream>
#include<iomanip>
#include<ctime>
#include<string>

using namespace std;

const int NUMBER_POSSIBLE = 100;

//Function Prototypes
string getPlayerName();
void playTheGame(string, int, int, int);

int main()
{
	int userGuess = 0, rand_number = 0, numberOfAttempts = 0;
	string player_name;
	bool repeat;

	do
	{
		//function calls
		player_name = getPlayerName();
		playTheGame(player_name, userGuess, rand_number, numberOfAttempts);

		cout << "\nWould you like to play again? (1 for Yes, 0 for No):  ";
		cin >> repeat;
		cin.ignore();
		cout << endl;
	} while (repeat);

}

string getPlayerName()
{
	string player_name;

	cout << "Welcome to the Guess the Number Game" << endl;

	cout << "Please enter your name: ";
	getline(cin, player_name);

	return player_name;
}

void playTheGame(string player_name, int userGuess, int rand_number, int numberOfAttempts)
{
	srand(time(0));

	rand_number = rand() % NUMBER_POSSIBLE + 1;

	numberOfAttempts = 0;

	while (userGuess != rand_number && numberOfAttempts < 7)
	{
		do
		{
			cout << "\n" << player_name << ", Guess a Number Between 1 and 100: ";
			cin >> userGuess;
			if (userGuess < 1 || userGuess > NUMBER_POSSIBLE)
				cout << "Invalid number entered - Must be between 1 - 100";
		} while (userGuess < 1 || userGuess > NUMBER_POSSIBLE);
		numberOfAttempts++;

		if (userGuess == rand_number)
		{
			cout << "Congratulations you guessed the number " << rand_number << " in " << numberOfAttempts << " tries" << endl;
		}
		else if (numberOfAttempts == 7)
		{
			cout << "\nSorry you did not guess the number " << rand_number << endl;
		}
		else if (userGuess < rand_number)
		{
			cout << "HINT: Guess HIGHER!" << endl;
		}
		else if (userGuess > rand_number)
		{
			cout << "HINT: Guess LOWER! " << endl;
		}
	}
}