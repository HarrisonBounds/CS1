/******************************************************************************
Author        : 
Using a Sentinel value 
********************************C**********************************************/
#include <iostream>               
#include <iomanip> 
#include <string>

using namespace std;            //introduces namespace std

int main(void)
{
	// Declaration and Initialization Statements
	int number = 0, total = 0;

	cout << "\n\nWhen prompted, enter the numbers to be added together. \nEnter a -999 when you are finished.";

	//Accumulates total of numbers 
	while (number != -999)
	{
		cout << "\n\nPlease enter a number to be added: ";
		cin >> number;
		if (number == -999)
			break;
		total += number;
	}

	//Displays the calculated total 
	cout << endl << endl;
	cout << "The total of the numbers entered is: " << total << endl;
			
    cout << "\n\nEnd of Program.";

	cout << endl << endl;

	return 0;
}









