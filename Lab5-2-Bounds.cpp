//Harrison Bounds
//Calculate average

#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	//Variables
	string name;
	int judges;
	double average;
	int counter = 1;
	double score = 0;
	double total = 0;
	
	
		cout << "Please enter the student's name: ";
		getline(cin, name);

		cout << "How many judges scored " << name << "'s project: ";
		cin >> judges;
		cout << "Enter the score recieved from each judge." << endl;

		while (counter <= judges)
		{
			do
			{
				cout << "Judge " << counter << ": ";
				cin >> score;

				if (score < 0 || score > 20)
					cout << "Invalid score entered: Must be between 0 and 20.\n";
				
				counter++;
			} while (score < 0 || score > 20);
		}
		total = total + score;
		

		average = total / judges;

		cout << setprecision(1) << fixed << showpoint;
		cout << name << "'s Science Fair Project Scores: " << endl;
		cout << "Total Score..............." << total << endl;
		cout << "Average Score..............." << average << endl;


}