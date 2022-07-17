
//NAME: 
//This program calculates the average of 3 exams for 4 students

#include <iostream>
#include <string>
using namespace std;

const int NUMBER_OF_EXAMS = 3;
const int NUMBER_OF_STUDENTS = 3;

int main()
{
	//Variables to store exam scores, total of scores, calculated average, loop counter, and student name 
	double exam = 0;
	double total = 0;
	double average = 0;
	string student_name;

	for (int student = 1; student <= NUMBER_OF_STUDENTS; student++)
	{
		//Prompt and read the student's name
		cout << "Enter the student's name: ";
		getline(cin, student_name);
		total = 0;
		//Prompt and read exam scores from user
		for (int counter = 1; counter <= NUMBER_OF_EXAMS; counter++)
		{
			cout << "Enter exam " << counter << " score: ";
			cin >> exam;
			total = total + exam;
		}
		cin.get();
		//cin.ignore();
		//Calculate Average of exams
		average = total / NUMBER_OF_EXAMS;

		//Display Student Name, Exams total, and Average
		cout << "\n\nStudent Name: " << student_name << endl;
		cout << "Total of Exams: " << total << endl << endl << endl;
		cout << "Average: " << average << endl << endl << endl;
	}
}