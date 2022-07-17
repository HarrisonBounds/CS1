//Harrison Bounds
//Calculate total and average points for each member of the bowling team

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	string name;
	double points_earned = 0, total = 0, average = 0, bowlers = 0, games = 0, team_total = 0, team_average = 0;
	int player_counter = 1;
	char again;

	cout << "************************************************************" << endl;
	cout << "*        This program calculates the total and average     *" << endl;
	cout << "*          points for each member of a bowling team.       *" << endl;
	cout << "*  The team's total and average points are also calculated.*" << endl;
	cout << "************************************************************" << endl;

	do
	{
		cout << "Please enter the number of bowlers on the team: ";
		cin >> bowlers;
		if (bowlers <= 0)
			cout << "Please enter a non negative number" << endl;
	} while (bowlers <= 0);

	do
	{
		cout << "Please enter the number of games the team competed in: ";
		cin >> games;
		if (games < 0)
			cout << "Please enter a non negative number" << endl;
		
	} while (games < 0);

	do
	{
		for (player_counter; player_counter <= bowlers; player_counter++)
		{
			cin.ignore();
			cout << "Enter bowler " << player_counter << "'s name: ";
			getline(cin, name);
			cout << "Enter the points earned by " << name << " for each game:" << endl;
			total = 0;
			average = 0;

			for (int game_counter = 1; game_counter <= games; game_counter++)
			{
				do
				{
					cout << "Game " << game_counter << ": ";
					cin >> points_earned;
					if (points_earned < 0 || points_earned > 300)
						cout << "*****ERROR - INVALID SCORE - PLEASSE RE-ENTER*****" << endl;
					total = total + points_earned;
				} while (points_earned < 0 || points_earned > 300);
			}

			team_total += total;
			average += total / games;
			team_average += average / bowlers;
			cout << name << ": " << endl;
			cout << "Total Points: " << total << endl;
			cout << "Average Points: " << average << endl;
		}

		cout << "Total team points: " << team_total << endl;
		cout << "Average Team Points per Game: " << team_average << endl;

		cout << "Would you like to calculate the stats on another team? Y or N";
		cin >> again;

	} while (again == 'Y' || again == 'y');

}
