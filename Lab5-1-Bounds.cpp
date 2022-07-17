//Harrison Bounds
//Report How far the source of the sound was away from the detection location

#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	//Variables
	const double air = 331.5, carbon_dioxide = 258.0, helium = 972.0, hydrogen = 1270.0;
	double seconds;
	char choice;
	double distance_traveled = 0;
	string gas = "skip";

	do
	{

		cout << "Enter number of seconds: ";
		cin >> seconds;

		if (seconds < 0 || seconds > 30)
		{
			cout << "*****Seconds must be between 0 and 30*****" << endl;
			cout << "Please run program again" << endl;
		}

	} while (seconds < 0 || seconds > 30);

	cout << "Select one of the following gases:" << endl;
	cout << "A. Air" << endl;
	cout << "B. Carbon Dioxide" << endl;
	cout << "C. Helium" << endl;
	cout << "D. Hydrogen" << endl;
	cout << "E. Quit" << endl << endl;

	cout << "Enter your choice: ";
	cin >> choice;


	    switch (choice)
		{
			case 'A':
			case 'a': distance_traveled = air * seconds;
				gas = "air";
				break;
			case 'B':
			case 'b': distance_traveled = carbon_dioxide * seconds;
				gas = "carbon dioxide";
				break;
			case 'C':
			case 'c': distance_traveled = helium * seconds;
				gas = "helium";
				break;
			case 'D':
			case 'd': distance_traveled = hydrogen * seconds;
				gas = "hydrogen";
				break;
			case 'E':
			case 'e':
				gas = "skip";
				break;
			default: cout << "*****The valid choice are A, B, C, D, and E*****" << endl;
				cout << "Run the program again and select one of those." << endl;
		}
	
		cout << setprecision(1) << fixed << showpoint << endl;
		if (gas != "skip")
		cout << "A sound wave travels " << distance_traveled << " meters in " << seconds << " seconds "
			<< "through " << gas << "." << endl << endl;

}