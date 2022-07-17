//Harrison Bounds
//Computes average score for a bowler

#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
	string name;
	double score = 0;
	double games_bowled = 0;
	double total = 0;
	double average = 0;
	char again;

	do
	{
		cout << "Enter the bowler name: ";
		getline(cin, name);

		do
		{ 
		cout << "Number of games bowled: ";
		cin >> games_bowled;

		if (games_bowled < 0)
			cout << "*****ERROR: Negative number for games.******" << endl;
		} while (games_bowled < 0);

		cout << "Enter " << name << "'s score for each of the following games: " << endl;

		int counter = 1;

		for (counter; counter <= games_bowled; counter++)
		{
			
			do
			{
				
				cout << "Game " << counter << ": ";
				cin >> score;
				
				if (score < 0 || score > 300)
					cout << "*****ERROR: Score must be from 1 to 300*****" << endl;
				
			} while (score < 0 || score > 300);
			total = total + score;
		}
		
		average = total / games_bowled;

		cout << setprecision(1) << fixed << showpoint;
		cout << "Bowler Results: " << endl;
		cout << "Name: " << name << endl;
		cout << "Total Score: " << total << endl;
		cout << "Average: " << average << endl << endl;

		cout << "Would you like to calculate the average of another bowler? Y or N:  ";
		cin >> again;

		cin.ignore();


	} while (again == 'Y' || again == 'y');


}