//Harrison Bounds
//Display quotient and remainder of two numbers

#include<iostream>

using namespace std;

//Function Prototypes
void getIntegers(int&, int&);
void findLargeandSmall(int, int, int&, int&);
void calcQuotient(int, int, int&);
void calcRemainder(int, int, int&);
void displayResults(int, int, int, int);

int main()
{
	char choice;

	cout << "**********************************************************" << endl;
	cout << "This program will ask you to enter two positive integers." << endl;
	cout << "It will divide the larger by the smaller and display the" << endl;
	cout << "result as a quotient and remainder." << endl;
	cout << "**********************************************************" << endl;

	do
	{
		//Variables
		int num1, num2;
		int larger, smaller;
		int quotient, remainder;

		//Function calls
		getIntegers(num1, num2);
		findLargeandSmall(num1, num2, larger, smaller);
		calcQuotient(larger, smaller, quotient);
		calcRemainder(larger, smaller, remainder);
		displayResults(larger, smaller, quotient, remainder);

		cout << "\n\n\nWould you like to process another set of numbers?(Y or N):   ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');
}

//This function retrieves of the two numbers being used
void getIntegers(int& num1, int& num2)
{
	cout << "Please enter your first integer and press <Enter>: ";
	cin >> num1;
	cout << "Please enter your second integer and press <Enter>: ";
	cin >> num2;		
}

//This function tell us which is the larger number and which is the smaller number
void findLargeandSmall(int num1, int num2, int& larger, int& smaller)
{
	if (num1 > num2)
	{
		larger = num1;
		smaller = num2;
	}
	else if (num1 < num2)
	{
		larger = num2;
		smaller = num1;
	}
}

//This function calculates the quotient of the two numbers
void calcQuotient(int larger, int smaller, int& quotient)
{
	quotient = larger / smaller;
}

//This function calculates the remainder if there is one
void calcRemainder(int larger, int smaller, int& remainder)
{
	remainder = larger % smaller;
}

//This function displays the quotient and remainder
void displayResults(int larger, int smaller, int quotient, int remainder)
{
	cout << "\n\n\nThe answer for " << larger << "/" << smaller << " is " << quotient << " R " << remainder;
}