//Harrison Bounds
//Determine whether a number is even or odd and negative or positive

#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

//Function Prototypes

int getNumber();
string determineEvenOrOdd(int);
string determinePositiveOrNegative(int);
void displayResults(int, string, string);

int main(void)
{
	//Variables
	int num;
	string even_odd, positive_negative;
	char repeat;

	do
	{
		//Function Calls
		num = getNumber();
		even_odd = determineEvenOrOdd(num);
		positive_negative = determinePositiveOrNegative(num);
		displayResults(num, even_odd, positive_negative);

		cout << "Would you like to process another number? <Y or N>   ";
		cin >> repeat;
	} while (repeat == 'y' || repeat == 'Y');
}

//Function Defintions


int getNumber()
{
	int num;
	do
	{
		
		cout << "Please enter the number to be determined as even/odd value or positive/negative: ";
		cin >> num;

		if (num > 10000 || num < -10000)
			cout << "ERROR, Please enter a number within the range\n\n";		

	} while (num > 10000 || num < -10000);

	return num;
}

string determineEvenOrOdd(int num)
{
	
	string even_odd;
	if (num % 2)
		even_odd = "odd";
	else
		even_odd = "even";

	return even_odd;

}

string determinePositiveOrNegative(int num)
{
	
	string positive_negative;
	if (num >= 0)
		positive_negative = "positive";
	else
		positive_negative = "negative";

	return positive_negative;
}

void displayResults(int num, string even_odd, string positive_negative)
{
	cout << "The number you entered, " << num << " is a " << positive_negative << ", " << even_odd << " value.\n\n";
}
