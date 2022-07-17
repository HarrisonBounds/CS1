//Harrison Bounds
//Calculate the average of 5 students scores after three rounds of golf

#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

const int STUDENTS = 5;
const int ROUNDS = 3;

void getNamesAndScores(string[], int[][ROUNDS]);
void computeAverage(int[][ROUNDS], double[], double[]);
void findBest(double[], string&, string[], double&);
void displayInformation(string[], int[][ROUNDS], double[], double[], double , string);

int main()
{
		string name[STUDENTS];
		int score[STUDENTS][ROUNDS] = { 0 };
		double student_average[STUDENTS] = { 0 };
		double round_average[ROUNDS] = { 0 };
		double highest = 0;
		string best_name_average;

		getNamesAndScores(name, score);
		computeAverage(score, student_average, round_average);
		findBest(student_average, best_name_average, name, highest);
		displayInformation(name, score, student_average, round_average, highest, best_name_average);
}

//This function gets the names and scores of the golf players
void getNamesAndScores(string name[], int score[][ROUNDS])
{
	cout << "Enter the names and scores of the students participating\n\n\n";
	for (int i = 0; i < STUDENTS; i++)
	{
		cout << "Please enter the student name: ";
		getline(cin, name[i]);
		for (int j = 0; j < ROUNDS; j++)
		{
			cout << "Enter Round " << j + 1 << " score: ";
			cin >> score[i][j];
			cin.ignore();
		}
	}
}

//This function get the average of the individual player's scores and the average for each round
void computeAverage(int score[][ROUNDS], double student_average[], double round_average[])
{
	for (int i = 0; i < STUDENTS; i++)
	{
		int total = 0;

		for (int j = 0; j < ROUNDS; j++)
		{
			total += score[i][j];
		}

		student_average[i] = total / double(ROUNDS);
	}

	for (int j = 0; j < ROUNDS; j++)
	{
		int total = 0;

		for (int i = 0; i < STUDENTS; i++)
		{
			total += score[i][j];
		}
		
		round_average[j] = total / double(STUDENTS);
	}
}

//This function get the best average and the name for who performed the best (Technically the lowest score because of the golf scoring system)
void findBest(double student_average[], string& best_name_average, string name[], double& highest)
{
	highest = student_average[0];
	for (int i = 1; i < STUDENTS; i++)
	{
		if (student_average[i] < highest)
		{
			highest = student_average[i];
			best_name_average = name[i];
		}
	}
}

//This function displays a table of the players, their scores, their averages, the rounds averages, and the name and score of who did the best
void displayInformation(string name[], int score[][ROUNDS], double student_average[], double round_average[], double highest, string best_name_average)
{
	cout << "\n\nPlayer" << setw(15) << "Round 1" << setw(15) << "Round 2" << setw(15) << "Round 3" << setw(15) << "     Ave/Student\n\n";

	for (int i = 0; i < STUDENTS; i++)
	{
		cout << setw(15) << left << name[i];
		for (int j = 0; j < ROUNDS; j++)
		{
			cout << setw(15) << score[i][j];
		}
		cout << setprecision(1) << fixed << showpoint;
		cout << setw(15) << student_average[i] << endl << endl;
	}

	cout << "Ave/Round     ";
	for (int j = 0; j < ROUNDS; j++)
	{
		cout << setw(15) << round_average[j];
	}
	cout << setprecision(1) << fixed << showpoint;
	cout << "\n\n" << best_name_average << " with a " << highest << " had the best student average from the rounds of golf.";
}