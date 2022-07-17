//Harrison Bounds
//calculate gross pay

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//Function Prototypes

string getName();
double getTime();
double computePay(double, double);
void displayPay(string, double , double);

const double HOURLY_PAY = 7.50;

int main(void)
{
	//Variables
	string name;
	double time = 0, overtime = 0;
	double gross_pay = 0, overtime_pay = 0;
	char repeat;

	do
	{
		//FunctionCalls 

		name = getName();
		time = getTime();
		gross_pay = computePay(time, HOURLY_PAY);
		displayPay(name, time, gross_pay);

		cout << "\n\nWould you like to calculate another employee's pay?(Y or N)";
		cin >> repeat;
		cin.ignore();
	} while (repeat == 'y' || repeat == 'Y');

}
	//Function Definitions

	string getName()
	{
	
		string name;
		cout << "Enter the employee's name: ";
		getline(cin, name);
		

		return name;
	}

	
	double getTime()
	{
		
		double time;
		do
		{
			
			cout << "Please enter the time worked for this pay period: ";
			cin >> time;
			
			if (time < 0)
				cout << "ERROR, Enter a value that is not negative\n\n";
		} while (time < 0);
		return time;
	}

	double computePay(double time, double HOURLY_PAY)
	{
		
		double overtime;
		double gross_pay;
		double overtime_pay;

		overtime = time - 40;
		if (overtime < 0)
			overtime = 0;
		overtime_pay = overtime * (HOURLY_PAY * 1.5);
		gross_pay = (HOURLY_PAY * (time - overtime)) + overtime_pay;

		return gross_pay;
	}

	void displayPay(string name , double time , double gross_pay)
	{
		cout << setprecision(2) << fixed << showpoint;
		cout << "Employee's name: " << name << endl;
		cout << "The time worked in this pay period is: " << time << endl;
		cout << "The gross pay earned for this pay period is: $" << gross_pay << endl;
	}