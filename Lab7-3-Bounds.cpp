//Harrison Bounds
//Calculate average score and letter grade

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//Function Prototypes

string getStudentName();
int getNumberExams();
double getScoresAndCalculateTotal(int);
double calculateAverage(int, double);
char determineLetterGrade(double);
void displayAverageGrade(string, double, char);

int main()
{
	char repeat;
	do
	{
		//Variables
		string name;
		int num_exams;
		double total = 0, score = 0, average = 0;
		char letter_grade;
		int counter = 0;
	

	
	
			//Function Calls
			name = getStudentName();
			num_exams = getNumberExams();
			total = getScoresAndCalculateTotal(num_exams);
			average = calculateAverage(num_exams, total);
			letter_grade = determineLetterGrade(average);
			displayAverageGrade(name, average, letter_grade);

			cout << "Would you like to calculate another student's grade? <Y or N> ";
			cin >> repeat;
			cin.ignore();

	} while (repeat == 'Y' || repeat == 'y');
} 

//Function Defintions

string getStudentName()
{
	string name;
	cout << "Please enter the student's name: ";
	getline(cin, name);

	return name;
}

int getNumberExams()
{
	int num_exams;
	do
	{		
		cout << "Please enter the number of exams taken by the student in the course: ";
		cin >> num_exams;
		cin.ignore();
		if (num_exams < 0)
			cout << "ERROR. Enter a number greater than 0";
	} while (num_exams < 0);

	return num_exams;
}

double getScoresAndCalculateTotal(int num_exams)
{
	double total = 0, score;
	cout << "Enter the exam scores: " << endl;
	for (int counter = 1; counter <= num_exams; counter++)
	{		
		cout << "Exam " << counter << ": ";
		cin >> score;
		cin.ignore();
		total = total + score;
	}
	return total;
}

double calculateAverage(int num_exams, double total)
{
	return total / num_exams;
}

char determineLetterGrade(double average)
{
	char letter_grade;

	if (average >= 90 && average <= 100)
		letter_grade = 'A';
	else if (average >= 80 && average < 90)
		letter_grade = 'B';
	else if (average >= 70 && average < 80)
		letter_grade = 'C';
	else if (average >= 60 && average < 70)
		letter_grade = 'D';
	else if (average >= 0 && average < 60)
		letter_grade = 'F';

	return letter_grade;
}

void displayAverageGrade(string name, double average, char letter_grade)
{
	cout << setprecision(1) << fixed << showpoint;
	cout << "\n\nStudent Name: " << name << endl;
	cout << "Average: " << average << endl;
	cout << "Letter Grade Earned: " << letter_grade << endl << endl;
}