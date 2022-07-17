//Harrison Bounds
//Calculate the average score earned by a Computer Science student for lab and leccure sessions

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

const int STUDENTS = 50;

struct StudentRecord
{
	string name;
	double exam_total_points;
	double lab_total_points;
	double average_grade;
	char letter_grade;
};

//Function Prototypes

void howManyStudentsAndTotalPointsPossible(StudentRecord[], int&, double&, double&);
void getNamesAndTotalPoints(StudentRecord [], int);
void calculateAverageAndLetterGrade(StudentRecord[], int, double, double);
void determineHighestAndLowest(StudentRecord[], int, double&, double&);
void displayRecord(StudentRecord student[], int, double, double);

int main()
{
	StudentRecord students[STUDENTS];
	int number_of_students;
	double exam_points_possible;
	double lab_points_possible;
	double highest, lowest;

	//Function Calls

	howManyStudentsAndTotalPointsPossible(students, number_of_students, exam_points_possible, lab_points_possible);
	getNamesAndTotalPoints(students, number_of_students);
	calculateAverageAndLetterGrade(students, number_of_students, exam_points_possible, lab_points_possible);
	determineHighestAndLowest(students, number_of_students, highest, lowest);
	displayRecord(students, number_of_students, highest, lowest);
}

//Function Headers

//This function gets the number of students taking the course and the total possible points for the exams and the labs
void howManyStudentsAndTotalPointsPossible(StudentRecord[], int& number_of_students, double& exam_points_possible, double& lab_points_possible)
{
	cout << "Enter the number of students in the course: ";
	cin >> number_of_students;

	cout << "Enter the total EXAM points that are possible for the course: ";
	cin >> exam_points_possible;

	cout << "Enter the total LAB points that are possible for the course: ";
	cin >> lab_points_possible;

	cin.ignore();
}

//This function gets the student's name, their total exam scores, and their total lab scores
void getNamesAndTotalPoints(StudentRecord students[], int number_of_students)
{
	for (int i = 0; i < number_of_students; i++)
	{
		cout << "Enter the information for Student " << i + 1 << ": \n";

		cout << "Name: ";
		getline(cin, students[i].name);

		cout << "Exam Points Earned: ";
		cin >> students[i].exam_total_points;

		cout << "Lab Points Earned: ";
		cin >> students[i].lab_total_points;

		cin.ignore();

		cout << endl;
	}
}

//This function calculates the average grade of each student and then determines what letter grade they have
void calculateAverageAndLetterGrade(StudentRecord students[], int number_of_students, double exam_points_possible, double lab_points_possible)
{
	for (int i = 0; i < number_of_students; i++)
	{
		students[i].average_grade = (0.60 * (students[i].exam_total_points / exam_points_possible)) + (0.40 * (students[i].lab_total_points / lab_points_possible));


		if (students[i].average_grade <= 1.00 && students[i].average_grade >= .90)
			students[i].letter_grade = 'A';

		else if (students[i].average_grade < .90 && students[i].average_grade >= .80)
			students[i].letter_grade = 'B';

		else if (students[i].average_grade < .80 && students[i].average_grade >= .70)
			students[i].letter_grade = 'C';

		else if (students[i].average_grade < .70 && students[i].average_grade >= .60)
			students[i].letter_grade = 'D';

		else if(students[i].average_grade < .60)
			students[i].letter_grade = 'F';
	}

}

//This function determines the highest overall average and the lowest overall average
void determineHighestAndLowest(StudentRecord students[], int number_of_students, double& highest, double& lowest)
{
	highest = students[0].average_grade;
	for (int i = 1; i < number_of_students; i++)
	{
		if (students[i].average_grade > highest)
			highest = students[i].average_grade;
	}

	lowest = students[0].average_grade;
	for (int i = 0; i < number_of_students; i++)
	{
		if (students[i].average_grade < lowest)
			lowest = students[i].average_grade;
	}
}

//This function displays the Student Record for each student's name, exam and lab points, their average, letter grade, and the highest and lowest scores
void displayRecord(StudentRecord students[], int number_of_students, double highest, double lowest)
{
	cout << setprecision(1) << fixed << showpoint;

	cout << "\n\nStudent Name          Exam Pts          Lab Pts          Average          Letter Grade\n";
	cout << "----------------      ---------         --------         --------         --------------\n";

	for (int i = 0; i < number_of_students; i++)
	{
		cout << setw(23) << left << students[i].name;
		cout << setw(20) << students[i].exam_total_points;
		cout << setw(20) << students[i].lab_total_points;
		cout << setw(18) << (students[i].average_grade * 100);
		cout << setw(20) << students[i].letter_grade;
		cout << endl << endl;
	}

	cout << "Highest Average: " << highest * 100 << endl;
	cout << "Lowest Average: " << lowest * 100 << endl;
}