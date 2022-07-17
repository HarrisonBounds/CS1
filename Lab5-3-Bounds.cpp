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
	const double pack_A = 39.99, pack_B = 59.99, pack_C = 69.99;
	const double pack_A_min = 450, pack_B_min = 900;
	const double pack_A_rate = 0.45, pack_B_rate = 0.40;
	string name;
	string month;
	double minutes;
	int choice;
	double amount_due = 0;
	

	cout << "Please enter the customer's name: ";
	getline(cin, name);
	cout << "Please enter the current billing month: ";
	cin >> month;

	do
	{
		cout << "How many minutes were used? ";
		cin >> minutes;

		if (minutes < 0)
			cout << "ERROR MESSAGE: Minutes has to be greater than 0";
	} while (minutes < 0);

	cout << "Select a subscription package:\n\n";
	cout << "1. Package A" << endl;
	cout << "2. Package B" << endl;
	cout << "3. Package C" << endl;
	cout << "4. Quit" << endl;

	cout << "Menu Option: ";
	cin >> choice;



	switch (choice)
	{
		case 1: 
			amount_due = pack_A + (minutes - pack_A_min) * pack_A_rate;
			if ((minutes - pack_A_min) < 0)
				amount_due = pack_A;
			break;
		case 2: 
			amount_due = pack_B + (minutes - pack_B_min) * pack_B_rate;
			if ((minutes - pack_B_min) < 0)
				amount_due = pack_B;
			break;
		case 3: 
			amount_due = pack_C;
			break;
		case 4:
			break;
		default: 
			cout << "The valid choice are 1 through 4. Run the program again and select one of those\n\n";

	}
	if (amount_due)
	{
		cout << "The Mobile Phone bill for " << month << endl;
		cout << "Customer's name: " << name << endl;
		cout << "Minutes Used: " << minutes << endl;
		cout << "Amount Due: $" << amount_due << endl;
	}
}