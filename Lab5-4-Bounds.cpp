//Harrison Bounds
//Calculate occupancy for a hotel

#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	//Variables
	int floors, rooms, rooms_occupied;
	int counter = 1;
	double total = 0, total_occupied = 0;
	int empty = 0;
	double occupancy_rate = 0;
	
	do
	{
		cout << "How many floors does the hotel have? ";
		cin >> floors;
		if (floors < 1)
			cout << "You can not enter a number less than 1, please try again\n";
	} while (floors < 1);

	while (counter <= floors)
	{
		do
		{
			cout << "How many rooms are on floor " << counter << "? ";
			cin >> rooms;
			cout << "How many of those rooms are occupied? ";
			cin >> rooms_occupied;

			if (rooms < 1)
				cout << "You can not enter a number less than 1, please try again\n";

		} while (rooms < 1);

		counter++;
		total += rooms;
		total_occupied += rooms_occupied;
		empty = total - total_occupied;
		occupancy_rate = (total_occupied / total) * 100;
	}
	cout << setprecision(1) << fixed << showpoint;
	cout << "The hotel has a total of " << total << " rooms.\n";
	cout << total_occupied << " are occupied.\n";
	cout << empty << " are empty.\n";
	cout << "The occupnacy rate is " << occupancy_rate << "%\n\n";
 
}