/******************************************************************************
Author        :  Karen Thessing  Course & Section :
Creation Date :                  Assignment Number:  B5-1
Description   :
********************************C**********************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std; //introduces namespace std

const int NUMBER_OF_JUDGES = 100;

int main(void)
{
	//Stores score from each judge, total scores, average, and name
	int score[NUMBER_OF_JUDGES] = { 0 };
	int total = 0;
	double average = 0;
	char repeat;
	string name, dummy;

	//Allow user to run program again
	do
	{
		//Resets total to process another contestant if desired
		total = 0;

		//Reads contestant's name
		cout << "\nPlease enter the contestants name: ? ";
		getline(cin, name);

		cout << "\nPlease enter the scores from the judges. Enter a -1 when finished" << endl;
		int i;
		//Reads scores from each judge
		for (i = 0; i < NUMBER_OF_JUDGES; i++)
		{

			cout << "\nScore from Judge " << i + 1 << ": ? ";
			cin >> score[i];
			if (score[i] == -1)
				break;
			total = total + score[i];
		}

		//Format output
		cout << setprecision(1) << fixed << showpoint;

		//Calcualtes the average score for the contestant
		average = total / double(i);
		cout << "\n\nThe scores for " << name << " are " << endl;
		for (int j = 0; j < i; j++)
		{

			cout << " " << score[j];
		}
		cout << "\n\nThe average score for " << name << " is " << average << endl << endl;

		cout << "\nWould you like to calculate the average for another contestant? Y or N ";
		cin >> repeat;
		getline(cin, dummy);

	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}






