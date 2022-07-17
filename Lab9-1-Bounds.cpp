//Harrison Bounds
//Calculate average score made on exams

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

const int NUMBER_OF_STUDENTS = 12;

void getNameAndScores(string&, int[]);
void determineHighAndLowScores(int[], int&, int&);
void calculateAverage(int[], double&);
void passAndFail(int[], int&, int&);
void scoresByLetterGrade(int[], int&, int&, int&, int&, int&);
void displayInfo(string, int[], double, int, int, int, int, int, int, int, int, int);

int main()
{
	char repeat;
	do
	{
		string name;
		int score[NUMBER_OF_STUDENTS] = { 0 };
		int highest = 0, lowest = 0;
		int pass = 0, fail = 0;
		double average = 0;
		int A = 0, B = 0, C = 0, D = 0, F = 0;
		

		getNameAndScores(name, score);
		determineHighAndLowScores(score, highest, lowest);
		calculateAverage(score, average);
		passAndFail(score, pass, fail);
		scoresByLetterGrade(score, A, B, C, D, F);
		displayInfo(name, score, average, highest, lowest, pass, fail, A, B, C, D, F);

		cout << "Would you like to calculate the average for another exam? <Y or N>";
		cin >> repeat;

	} while (repeat == 'Y' || repeat == 'y');
}

//Get the Exam Name and the student's scores
void getNameAndScores(string& name, int score[])
{
	cout << "Please enter the name of the exam: ";
	getline(cin, name);
	for (int counter = 0; counter < NUMBER_OF_STUDENTS; counter++)
	do
	{	
		cout << "Enter exam " << counter + 1 << "  ";
		cin >> score[counter];
		
		if (score[counter] < 0 || score[counter] > 100)
			cout << "ERROR - You must enter a number in the range of 1 - 100 !!!" << endl;

	} while (score[counter] < 0 || score[counter] > 100);
}

//See which was the highest score and the lowest score
void determineHighAndLowScores(int score[], int& highest, int& lowest)
{
	int counter;
	highest = score[0];
	for (counter = 1; counter < NUMBER_OF_STUDENTS; counter++)
	{
		if (score[counter] > highest)
			highest = score[counter];
	}

	lowest = score[0];
	for (counter = 1; counter < NUMBER_OF_STUDENTS; counter++)
	{
		if (score[counter] < lowest)
			lowest = score[counter];
	}
}

//Get the average of all the student's exam scores
void calculateAverage(int score[], double& average)
{
	double total = 0;
	for (int counter = 0; counter < NUMBER_OF_STUDENTS; counter++)
		total += score[counter];
	average = total / NUMBER_OF_STUDENTS;
}

//See how many students passed or failed
void passAndFail(int score[], int& pass, int& fail)
{
	for (int counter = 0; counter < NUMBER_OF_STUDENTS; counter++)
	{
		if (score[counter] > 60)
			++pass;

		else if (score[counter] < 60)
			++fail;
	}
}

//See how many students got which letter grade
void scoresByLetterGrade(int score[], int& A, int& B, int& C, int& D, int& F)
{
	for (int counter = 0; counter < NUMBER_OF_STUDENTS; counter++)
	{
		if (score[counter] >= 90 && score[counter] <= 100)
			++A;
		else if (score[counter] >= 80 && score[counter] < 90)
			++B;
		else if (score[counter] >= 70 && score[counter] < 80)
			++C;
		else if (score[counter] >= 60 && score[counter] < 70)
			++D;
		else
			++F;

	}
}

//Display name, scores, average, highest and lowest scores, who passes and failed, and the letter grades
void displayInfo(string name, int score[], double average, int highest, int lowest, int pass, int fail, int A, int B, int C, int D, int F)
{
	cout << "\n\n\nThe scores for " << name << " are: " << endl;

	for (int counter = 0; counter < NUMBER_OF_STUDENTS; counter++)
	{
		cout << " " << score[counter];
	}

	cout << setprecision(2) << fixed << showpoint;
	cout << "\n\nThe average score is " << average << "\n\n";
	cout << setprecision(0) << fixed << showpoint;
	cout << "The highest score is " << highest << endl;
	cout << "The lowest score is " << lowest << endl << endl;
	cout << "Number of Students who passed: " << pass << endl;
	cout << "Number of Students who failed: " << fail << endl << endl;

	cout << "The number of exams represented by each letter grade is as follows: " << endl;
	cout << "A's:  " << A << endl;
	cout << "B's:  " << B << endl;
	cout << "C's:  " << C << endl;
	cout << "D's:  " << D << endl;
	cout << "Fs:  " << F << endl;

}