/******************************************************************************
Author        :  Harrison Bounds  Course & Section :
Creation Date :                  Assignment Number:  B5-1
Description   :
********************************C**********************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std; //introduces namespace std

const int NUMBER_OF_JUDGES = 5;

int main(void)
{
	//Stores score from each judge, total scores, average, and name
	int score[NUMBER_OF_JUDGES] = { 0 };
	int total = 0;
	double average = 0;
	bool repeat;
	string name, dummy;

	//Allow user to run program again
	do
	{
		//Resets total to process another contestant if desired
		total = 0;

		//Reads contestant's name
		cout << "\nPlease enter the contestants name: ? ";
		getline(cin, name);

		cout << "\nPlease enter the scores from the judges." << endl;

		//Reads scores from each judge
		for (int i = 0; i < NUMBER_OF_JUDGES; i++)
		{

			cout << "\nScore from Judge " << i + 1 << ": ? ";
			cin >> score[i];
			total = total + score[i];
		}

		//Format output
		cout << setprecision(1) << fixed << showpoint;

		//Calcualtes the average score for the contestant
		average = total / double(NUMBER_OF_JUDGES);
		cout << "\n\nThe average score for " << name << " is " << average << endl << endl;
		for (int i = 0; i < NUMBER_OF_JUDGES; i++)
		{

			cout << "\nScore from Judge " << i + 1 << ": ? " << score[i];
			
		}
		cout << "\nWould you like to calculate the average for another contestant? 1 fo Yes or 0 for No ";
		cin >> repeat;
		getline(cin, dummy);

	} while (repeat);

	return 0;
}






