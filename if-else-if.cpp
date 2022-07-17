

//NAME: Harrison Bounds

//This program calculates the average of 2 exams and determines whether the student passed the course

#include <iostream>
using namespace std;

int main()
{
	//Variables to store exam scores and calculated average
	int exam1 = 0, exam2 = 0;
	double average = 0;


	//Prompt and read exam scores from user
	cout << "Enter Exam 1 Score: ";
	cin >> exam1;
	cout << "Enter Exam 2 Score: ";
	cin >> exam2;

	//Calculate Average of exams
	average = (exam1 + exam2) / 2.0;

	//Display Exam scores and average
	cout << "\n\nExam 1 Score: " << exam1 << endl;
	cout << "Exam 2 Score: " << exam2 << endl << endl;
	cout << "Average: " << average << endl;

	if (average <= 100 && average >= 89.5)
		cout << "\n\nLetter Grade Earned = A" << endl;
	else if (average < 89.5 && average >= 79.5)
		cout << "\n\nLetter Grade Earned = B" << endl;
	else if (average < 79.5 && average >= 69.5)
		cout << "\n\nLetter Grade Earned = C" << endl;
	else if (average < 69.5 && average >= 59.5)
		cout << "\n\nLetter Grade Earned = D" << endl;
	else 
		cout << "\n\nLetter Grade Earned = F" << endl;


	

}