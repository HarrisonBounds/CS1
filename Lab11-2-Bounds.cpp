//Harrison Bounds
//Write a program to get the names of quarterbacks, their completions, attempts, passing average, and totals
//Also display the quarterback with the highest passing average

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

const int QUARTERBACKS = 7;

struct QuarterbackRecord
{
	string name;
	int completions;
	int attempts;
	double average;
};

//Function Prototypes

void getName(QuarterbackRecord[]);
void getCompletionsAndAttempts(QuarterbackRecord[]);
void getAverageAndTotal(QuarterbackRecord[], int&, int&, double&);
void getHighestAverage(QuarterbackRecord[], double, string&);
void display(QuarterbackRecord[], int, int, double, string);

int main()
{
	QuarterbackRecord quarterbacks[QUARTERBACKS];
	double highest = 0;
	string name_average;
	int completion_total = 0, attempts_total = 0;
	double overall_total;

	//Function Calls

	getName(quarterbacks);
	getCompletionsAndAttempts(quarterbacks);
	getAverageAndTotal(quarterbacks, completion_total, attempts_total, overall_total);
	getHighestAverage(quarterbacks, highest, name_average);
	display(quarterbacks, completion_total, attempts_total, overall_total, name_average);
}

//Function Headers

//This function gets the names of the 7 quarterbacks

void getName(QuarterbackRecord quarterbacks[])
{
	cout << "Enter the name of each quarterback:\n\n";
	for (int i = 0; i < QUARTERBACKS; i++)
	{
		cout << "Quarterback #" << i + 1 << ": ";
		getline(cin, quarterbacks[i].name);
		cout << endl;
	}
}

//This function gets the completions and attempts for each quarterback

void getCompletionsAndAttempts(QuarterbackRecord quarterbacks[])
{
	cout << "Enter the completion and attempts for each quarterback: \n\n";

	for (int i = 0; i < QUARTERBACKS; i++)
	{
		cout << quarterbacks[i].name << endl;

		cout << "Completions: ";
		cin >> quarterbacks[i].completions;

		cout << "Attempts: ";
		cin >> quarterbacks[i].attempts;

		cout << endl;
	}
}

//This function gets the individual players average, the completion and attempt totals, and the overall average

void getAverageAndTotal(QuarterbackRecord quarterbacks[], int& completion_total, int& attempts_total, double& overall_total)
{
	for (int i = 0; i < QUARTERBACKS; i++)
	{
		quarterbacks[i].average = quarterbacks[i].completions / double(quarterbacks[i].attempts);
	}

	for (int i = 0; i < QUARTERBACKS; i++)
	{
		completion_total += quarterbacks[i].completions;
	}

	for (int i = 0; i < QUARTERBACKS; i++)
	{
		attempts_total += quarterbacks[i].attempts;
	}

	overall_total = double(completion_total) / attempts_total;
}

//This function determines which quarterback had the highest passing average

void getHighestAverage(QuarterbackRecord quarterbacks[], double highest, string& name_average)
{
	highest = quarterbacks[0].average;
	name_average = quarterbacks[0].name;
	for (int i = 0; i < QUARTERBACKS; i++)
	{
		if (quarterbacks[i].average > highest)
		{
			highest = quarterbacks[i].average;
			name_average = quarterbacks[i].name;
		}
	}
}

//This function displays the quarterbacks name, their completions and attempts, their average, 
//the overall total for the completion and attempts, and the overall average

void display(QuarterbackRecord quarterbacks[], int completion_total, int attempts_total, double overall_total, string name_average)
{
	cout << "\n\nQuarterBack" << setw(20) << "Completions" << setw(20) << "Attempts" << setw(20) << "AVE\n";
	cout << "-----------" << setw(20) << "-----------" << setw(20) << "--------" << setw(20) << "----\n\n";

	for (int i = 0; i < QUARTERBACKS; i++)
	{
		cout << setw(25) << left << quarterbacks[i].name;
		cout << setw(20) << quarterbacks[i].completions;
		cout << setw(20) << quarterbacks[i].attempts;
		cout << setprecision(3) << fixed << showpoint;
		cout << setw(20) << quarterbacks[i].average;
		cout << endl;
	}

	cout << endl << endl;
	cout << setw(25) << "Totals" << setw(20) << completion_total << setw(20) << attempts_total << setw(20) << overall_total;

	cout << endl << endl;

	cout << name_average << " wins the ESPY award for the highest average of completed passes.\n\n\n";
}