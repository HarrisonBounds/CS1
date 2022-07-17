

//Name: Harrison Bounds

#include<iostream>
#include<string>
#include <iomanip>

using namespace std;  //introduces namespace std

const int COUNT = 3;

struct Date
{
	int month, day, year;
};

struct Student
{
	int ID;
	string name;
	string address;
	string city;
	string state;
	int zip;
	Date birth;
	Date enter;
	Date grad;
};

void getStudentInfo(Student student[COUNT]);
void displayStudentInfo(Student student[COUNT]);

int main()
{
	Student student[COUNT];

	getStudentInfo(student);
	displayStudentInfo(student);

	cout << endl << endl;
	return 0;
}

void getStudentInfo(Student student[COUNT])
{
	string dummy;
	for (int i = 0; i < COUNT; i++)
	{
		cout << "Enter Student " << i + 1 << " ID: ";
		cin >> student[i].ID;
		getline(cin, dummy);
		cout << "Enter Student " << i + 1 << " name: ";
		getline(cin, student[i].name);
		cout << "Enter Student " << i + 1 << " Address: ";
		getline(cin, student[i].address);
		cout << "Enter Student " << i + 1 << " City: ";
		getline(cin, student[i].city);
		cout << "Enter Student " << i + 1 << " State: ";
		cin >> student[i].state;
		cout << "Enter Student " << i + 1 << " Zip: ";
		cin >> student[i].zip;
		cout << "Enter Student " << i + 1 << " Birth date (ex. 12 25 2016)";
		cin >> student[i].birth.month >> student[i].birth.day >> student[i].birth.year;
		cout << "Enter Student " << i + 1 << " Entrance date (ex. 12 25 2016)";
		cin >> student[i].enter.month >> student[i].enter.day >> student[i].enter.year;
		cout << "Enter Student " << i + 1 << " Graduation date (ex. 12 25 2016)";
		cin >> student[i].grad.month >> student[i].grad.day >> student[i].grad.year;


		cout << endl << endl;
	}
}

void displayStudentInfo(Student student[COUNT])
{
	cout << "ID     Name      Address    City   State   Zip  Birthdate  Enter Date  Graduation Date" << endl;
	for (int i = 0; i < COUNT; i++)
	{
		cout << setw(5) << left << student[i].ID;
		cout << setw(12) << student[i].name;
		cout << setw(10) << student[i].address;
		cout << setw(10) << student[i].city;
		cout << setw(5) << student[i].state;
		cout << setw(7) << student[i].zip;

		cout << student[i].birth.month << "/" << student[i].birth.day << "/" << student[i].birth.year;
		cout << "  " << student[i].enter.month << "/" << student[i].enter.day << "/" << student[i].enter.year;
		cout << "  " << student[i].grad.month << "/" << student[i].grad.day << "/" << student[i].grad.year;
		 
		cout << endl << endl;
	}
}


/*
cout << "Enter Student "<< i + 1 << " Birth date (ex. 12 25 2016)";
cin >> ???? >> ????? >> ?????;
cout << "Enter Student " << i + 1 << " Entrance date (ex. 12 25 2016)";
cin >> ????? >> ????? >> ?????;
cout << "Enter Student " << i + 1 << " Graduation date (ex. 12 25 2016)";
cin >> ????? >> ????? >> ?????;

*/

/*
cout << ????? << "/" << ????? << "/" << ?????;
cout << "  " <<  ????? << "/" << ????? << "/" << ?????;
cout << "  " << ????? << "/" << ????? << "/" << ?????;
*/