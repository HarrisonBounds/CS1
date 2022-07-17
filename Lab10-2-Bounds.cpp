//Harrison Bounds
//Program that answers to a true and false quiz given to students in a course

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

const int NUM_OF_QUESTIONS = 5;
const int STUDENTS = 100;

void numberOfStudentsAndNames(int&, string[], char[]);
void studentsAndAnswers(char[][NUM_OF_QUESTIONS], string[], int);
void calculateGrades(char[], char[][NUM_OF_QUESTIONS], double[], int);
void display(string[], char[], char[][NUM_OF_QUESTIONS], double[], int);

int main()
{
	int number_of_students = 0;
	string student_names[STUDENTS];
	char answer_key[STUDENTS] = { 0 };
	char answers[STUDENTS][NUM_OF_QUESTIONS] = { 0 };
	double grade[STUDENTS];
	bool repeat;

	cout << "This program calculates the grade for studets taking a true-false quiz.\n\n\n";
	do
	{
		numberOfStudentsAndNames(number_of_students, student_names, answer_key);
		studentsAndAnswers(answers, student_names, number_of_students);
		calculateGrades(answer_key, answers, grade, number_of_students);
		display(student_names, answer_key, answers, grade, number_of_students);

		cout << "Would you like to process another quiz? Enter 1 for yes or 0 for no:  ";
		cin >> repeat;
	} while (repeat);
}

//This function gets the number of students that took th quiz, the name of those students, and the answer key
void numberOfStudentsAndNames(int& number_of_students, string student_names[], char answer_key[])
{
	cout << "How many students took the quiz?   ";
	cin >> number_of_students;

	cout << "\n\nPlease enter the answer key.\n\n";

	for (int i = 0; i < NUM_OF_QUESTIONS; i++)
	{
		cout << "Answer #" << i + 1 << ":   ";
		cin >> answer_key[i];
		cin.ignore();
	}

	cout << "\n\n\nPlease enter the student's names.\n\n";

	for (int j = 0; j < number_of_students; j++)
	{
		cout << "Student #" << j + 1 << " Name:  ";
		getline(cin, student_names[j]);
		
	}
}

//This function gets the students answers for the quiz
void studentsAndAnswers(char answers[][NUM_OF_QUESTIONS], string student_names[], int number_of_students)
{
	for (int i = 0; i < number_of_students; i++)
	{
		cout << "\nPlease enter the answers for " << student_names[i] << ". \n";
		for (int j = 0; j < NUM_OF_QUESTIONS; j++)
		{
			
			cout << "Answer #" << j + 1 << ": ";
			cin >> answers[i][j];
			cin.ignore();
		}
	}
}

//This function calculates the grades of the students by comparing their answers to the answer key
void calculateGrades(char answer_key[], char answers[][NUM_OF_QUESTIONS], double grade[], int number_of_students)
{
	int grades = 0;
	for (int i = 0; i < number_of_students; i++)
	{
		grades = 0;
		for (int j = 0; j < NUM_OF_QUESTIONS; j++)
		{
			if (answers[i][j] == answer_key[j])
				grades += 2;
		}
		grade[i] = grades;
	}
	
}

//This function displays the student's names, the answer key, their answers, and their grade
void display(string student_names[], char answer_key[], char answers[][NUM_OF_QUESTIONS], double grade[], int number_of_students)
{
	cout << "\n\n\nStudent Name" << setw(15) << "           Quiz Answers" << setw(15) << "           Grade\n";
	cout << "---------------" << setw(15) << "       ---------------" << setw(15) << "  -------\n";

	cout << "Key" << setw(22);
	for (int a = 0; a < NUM_OF_QUESTIONS; a++)
	{
		cout << answer_key[a];
		cout << " ";
	}
	cout << setw(13) << "10";
	cout << endl;

	for (int i = 0; i < number_of_students; i++)
	{
		cout << setw(25) << left << student_names[i];
		for (int j = 0; j < NUM_OF_QUESTIONS; j++)
		{
			cout << answers[i][j];
			cout << " ";
		}
		cout << "           " << grade[i] << endl << endl;
	}
}

