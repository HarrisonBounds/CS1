//NAME: Enter your name here!

//This program calculates the average of 3 exams and 
//determines the Letter Grade earned

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Variables to store exam scores, total of scores, 
	//calculated average, loop counter, and student name 
	double exam = 0;
	double total = 0;
	double average = 0;
	string student_name;
	int num_exams = 0;
	char again;
	
	do
	{ 
		total = 0;
		//Prompt and read the student's name
		cout << "Enter the student's name: ";
		getline(cin, student_name);
		
		cout << "\nEnter number of exams: ";
		cin >> num_exams;
		
		//Prompt and read exam scores from user
		for (int counter = 1; counter <= num_exams; counter++)
		{
			cout << "Enter Exam " << counter << " score ";
			cin >> exam;
			total += exam; //total = total + exam;
			 //counter = counter + 1;  counter += 1;
		}

		//Calculate Average of exams
		average = total / num_exams;

		//Display Student Name, Average and letter grade earned
		cout << "\n\nStudent Name: " << student_name << endl;
		cout << "Average: " << average << endl << endl << endl;

		cout << "Run program again (Y for Yes, N for N)";
		cin >> again;
		cin.get();
	} while (again == 'Y' || again == 'y');

	return 0;
}
