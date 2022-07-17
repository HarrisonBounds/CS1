//Harrison Bounds
//Program that stores the home address and current college address for their students and displays the information in a report

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

const int STUDENT_RECORDS = 50;

struct Address
{
	string street_address;
	string city_state;
	string zipcode;
};

struct StudentAddress
{
	string name;
	Address home_address;
	Address college_address;
};

void getNumberOfStudents(int&);
void getNamesandAddress(StudentAddress student[], int);
void displayNameAndAddresses(StudentAddress student[], int);

int main()
{
	StudentAddress student[STUDENT_RECORDS];
	int num_of_students;

	getNumberOfStudents(num_of_students);
	getNamesandAddress(student, num_of_students);
	displayNameAndAddresses(student, num_of_students);
}

//This function gets the number of students in the school

void getNumberOfStudents(int& num_of_students)
{
	do
	{
		cout << "Number of Student (Must be a positive number less than or equal to 50)  =  ";
		cin >> num_of_students;

		cin.ignore();

		if (num_of_students < 0 || num_of_students >= 50)
			cout << "Please enter a valid number of students\n\n";

	} while (num_of_students < 0 || num_of_students >= 50);
}

//This function gets the name and address from each student

void getNamesandAddress(StudentAddress student[STUDENT_RECORDS], int num_of_students)
{
	for (int i = 0; i < num_of_students; i++)
	{
		cout << "Please enter the information for Student " << i + 1 << ".\n";

		cout << "Name: ";
		getline(cin, student[i].name);
		cout << endl << endl;

		cout << "     Home Address: \n";

		cout << "          Street Address: ";
		getline(cin, student[i].home_address.street_address);

		cout << "          City, State: ";
		getline(cin, student[i].home_address.city_state);

		cout << "          Zip Code:";
		getline(cin, student[i].home_address.zipcode);

		cout << "     College Address:\n";

		cout << "          Street Address: ";
		getline(cin, student[i].college_address.street_address);

		cout << "          City, State: ";
		getline(cin, student[i].college_address.city_state);

		cout << "          Zip Code: ";
		getline(cin, student[i].college_address.zipcode);
	}
}

//This function displays each student's name and both of their addresses

void displayNameAndAddresses(StudentAddress student[STUDENT_RECORDS], int num_of_students)
{
	cout << "The student Address report is:\n\n";

	for (int i = 0; i < num_of_students; i++)
	{
		cout << student[i].name << endl;
		cout << "     Home:   " << student[i].home_address.street_address << endl 
			 << "             " << student[i].home_address.city_state << "   " << student[i].home_address.zipcode << "\n\n";

		cout << "     College:   " << student[i].college_address.street_address << endl
			 << "             " << student[i].college_address.city_state << "   " << student[i].college_address.zipcode << "\n\n";

	}
}