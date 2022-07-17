//Harrison Bounds
//Produce a payroll report

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

const double FEDERAL_TAX_RATE = 0.16,  STATE_TAX_RATE = 0.065;

//Function Prototypes
void getData(int&, string&, double&, double&);
void computeGrossPay(double, double, double&);
void computeDeductions(double, double&, double&);
void computeNetPay(double, double, double, double&);
void displayResults(int, string, double, double, double, double, double, double);

int main()
{
	bool choice;

	do
	{
		//Variables
		int ID;
		string name;
		double hours_worked;
		double hourly_pay_rate;
		double gross_pay, federal_deductions, state_deductions, net_pay;

		//Function Calls
		getData(ID, name, hours_worked, hourly_pay_rate);
		computeGrossPay(hours_worked, hourly_pay_rate, gross_pay);
		computeDeductions(gross_pay, federal_deductions, state_deductions);
		computeNetPay(gross_pay, federal_deductions, state_deductions, net_pay);
		displayResults(ID, name, hours_worked, hourly_pay_rate, gross_pay, federal_deductions, state_deductions, net_pay);

		cout << "\n\n\nWould you like to calculate the net pay for another employee? <1 for Yes> <0 for No> " << endl;
		cin >> choice;
		cin.ignore();
	} while (choice);

}

//This function retrieves the employess's information
void getData(int& ID, string& name, double& hours_worked, double& hourly_pay_rate)
{
	do
	{
		cout << "Please enter the employess's 4-digit ID # and press <Enter>" << endl;
		cin >> ID;
		cin.ignore();

		if (ID >= 9999 || ID <= 5000)
			cout << "ERROR - Enter a number between 5000 and 9999" << endl << endl;
	} while (ID >= 9999 || ID <= 5000);

	cout << "Please enter the employee's name: " << endl;
	getline(cin, name);

	do
	{
		cout << "Please enter the amount of hours worked this week and press <Enter> " << endl;
		cin >> hours_worked;

		if (hours_worked < 0 || hours_worked > 120)
			cout << "ERROR - Enter a number between 0 and 120" << endl << endl;
	} while (hours_worked < 0 || hours_worked > 120);

	do
	{
		cout << "Please enter the hourly pay rate for this employess and press <Enter> " << endl;
		cin >> hourly_pay_rate;

		if (hourly_pay_rate < 0)
			cout << "ERROR - Enter a non negative number" << endl << endl;
	} while (hourly_pay_rate < 0);
}

//This function computes the Gross Pay for the Employee
void computeGrossPay(double hours_worked, double hourly_pay_rate, double& gross_pay)
{
	gross_pay = hours_worked * hourly_pay_rate;
	if (hours_worked > 40)
		gross_pay = ((hours_worked - (hours_worked - 40)) * hourly_pay_rate) + (hours_worked - 40) * (1.5 * hourly_pay_rate);
}

//This function computes the Federal and State Deductions from the employee's Gross Pay
void computeDeductions(double gross_pay, double& federal_deductions, double& state_deductions)
{
	federal_deductions = FEDERAL_TAX_RATE * gross_pay;
	state_deductions = STATE_TAX_RATE * gross_pay;
}

//This function computes the net pay of the Employee
void computeNetPay(double gross_pay, double federal_deductions, double state_deductions, double& net_pay)
{
	net_pay = gross_pay - (federal_deductions + state_deductions);
}

//This function displays the results of the employee
void displayResults(int ID, string name, double hours_worked, double hourly_pay_rate, double gross_pay, double federal_deductions, double state_deductions, double net_pay)
{
	cout << "Employess ID: " << setw(10) << ID << endl;
	cout << "Employee Name: " << setw(10) << name << endl;

	cout << setprecision(2) << fixed << showpoint;
	cout << "Hours Worked: " << setw(10) << hours_worked << endl;
	cout << "Hourly Rate: " << setw(10) << "$   " << hourly_pay_rate << endl;
	cout << "Gross Pay: " << setw(10) << "$   " << gross_pay << endl;

	cout << "\n\n\nDeductions: \n\n\n";

	cout << "Federal Withholding: " << setw(5) << "$   " << federal_deductions << endl;
	cout << "State Withholding: " << setw(5) << "$   " << state_deductions << endl;

	cout << "\n\n\nNET PAY: " << setw(5) << "$   " << net_pay;
}