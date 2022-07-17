//Harrison Bounds
/*This program will get 7 different numbers from the user
 and compare them to the student's chosen numbers in the file.
 If the students match a certain amount of the numbers, they
 will when a cash prize that will be displayed*/

//Header Files
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;


//Declare constants
const int STUDENTS = 50;
const int NUMBERS = 7;

//Structure for the student information
struct Students
{
	int id_num = 0;
	string name;
	int choices[NUMBERS] = { 0 };
	int match = 0;
	double winnings = 0;
};

//Function Prototypes
void studentRegistration(Students[], int&);
void determineWinner(Students[], int[]);
void resultsReport(Students[], int);
void winningsReport(Students[], int);

int main()
{
	//number of students, structure array, and random number array declared as variables
	int number_of_students;
	Students student_info[STUDENTS] = { 0 };
	int rand_num[NUMBERS] = { 0 };

	//Function calls
	studentRegistration(student_info, number_of_students);
	determineWinner(student_info, rand_num);
	resultsReport(student_info, number_of_students);
	winningsReport(student_info, number_of_students);
}

//The function retrieves the information from each student in the file
void studentRegistration(Students student_info[], int& number_of_students)
{
	ifstream inFile;
	int i = 0;
	inFile.open("guesses2.txt");

	if (!inFile)
		cout << "\n\n*****ERROR OPENING FILE*****\n";
	else
	{
		while (!inFile.eof())
		{
			inFile >> student_info[i].id_num;
			getline(inFile, student_info[i].name);
			for (int j = 0; j < NUMBERS; j++)
			{
				inFile >> student_info[i].choices[j];
			}
			i++;
		}
		number_of_students = i;
	}
}

/*The function gets the 7 numbers entered and then compares the numbers to the student's choices in the file.
If they get 7 right, they win 20 dollars, 6 right gets them 10 dollars, and 5 right gets them 5 dollars*/

void determineWinner(Students student_info[], int rand_num[])
{
	cout << "Enter the 7 different, random numbers between 1 and 50 that were selected.\n\n";
		for (int i = 0; i < NUMBERS; i++)
		{
			do
			{
				cout << "Number " << i + 1 << ": ";
				cin >> rand_num[i];
				if (rand_num[i] > 50 || rand_num[i] < 1)
				{
					cout << "Please enter a number inside the range of 1 - 50";
				}
				cout << endl;
			} while (rand_num[i] > 50 || rand_num[i] < 1);
		}

		for (int i = 0; i < STUDENTS; i++)
		{
			for (int j = 0; j < NUMBERS; j++)
			{
				for (int k = 0; k < NUMBERS; k++)
				{
					if (rand_num[j] == student_info[i].choices[k])
					{
						student_info[i].match += 1;
					}

				}
			}
		}

		for (int i = 0; i < STUDENTS; i++)
		{
			if (student_info[i].match == 7)
			{
				student_info[i].winnings = 20;
			}

			else if (student_info[i].match == 6)
			{
				student_info[i].winnings = 10;
			}

			else if (student_info[i].match == 5)
			{
				student_info[i].winnings = 5;
			}
			
		}
}

//This functiom sorts the student's name from the file into alphabetical order by last name
void resultsReport(Students student_info[], int number_of_students)
{
	int i, j;
	Students temp;

	for (i = 0; i < (number_of_students - 1); i++)
	{
		for (j = 1; j < number_of_students; j++)
		{
			if (student_info[j].name < student_info[j - 1].name)
			{
				temp = student_info[j];
				student_info[j] = student_info[j - 1];
				student_info[j - 1] = temp;
			}

		}
	}
}

/*This functioon displays the results of the student's id number, name, chosen numbers, matches, and their prize winnings.
There are also three seperate reports that include the students matches 7, 6, and 5 numbers*/
void winningsReport(Students student_info[], int number_of_students)
{
	cout << "* * * * * * * * * * * * * * * * Results Report * * * * * * * * * * * * * * * *\n\n";
	cout << "Student ID     Student Name             Chosen Numbers         Matches      Prize $\n";
	cout << "____________________________________________________________________________________\n";

	for (int i = 1; i < number_of_students; i++)
	{
		cout << left << setw(15) << student_info[i].id_num << setw(23) << student_info[i].name;
		for (int j = 0; j < NUMBERS; j++)
		{
			cout << setw(3) << student_info[i].choices[j];
		}
		cout << "       " << setw(13) << student_info[i].match;
		cout << setprecision(2) << fixed << showpoint;
		cout << student_info[i].winnings;
		cout << endl;
	}

	cout << "\n\n\n* * * * * * * * * Winnings Report * * * * * * * * *\n\n";
	cout << "*********Students Who Matched All 7 Numbers*********\n\n";
	cout << "Student ID     Student Name       Matches      Prize $\n";
	cout << "_______________________________________________________\n";

	for (int i = 1; i < STUDENTS; i++)
	{
		if (student_info[i].match == 7)
		{
			cout << left << setw(13) << student_info[i].id_num << setw(25) << student_info[i].name
				<< setw(10) << student_info[i].match << setw(10) << student_info[i].winnings
				<< endl << endl;
		}
	}

	cout << "***********Students Who Matched 6 Numbers***********\n\n";
	cout << "Student ID     Student Name       Matches      Prize $\n";
	cout << "_______________________________________________________\n";


	for (int i = 1; i < STUDENTS; i++)
	{
		if (student_info[i].match == 6)
		{
			cout << left << setw(13) << student_info[i].id_num << setw(25) << student_info[i].name
				<< setw(10) << student_info[i].match << setw(10) << student_info[i].winnings
				<< endl << endl;
		}
	}

	cout << "***********Students Who Matched 5 Numbers***********\n\n";
	cout << "Student ID     Student Name       Matches      Prize $\n";
	cout << "_______________________________________________________\n";

	for (int i = 1; i < STUDENTS; i++)
	{
		if (student_info[i].match == 5)
		{
			cout << left << setw(13) << student_info[i].id_num << setw(25) << student_info[i].name
				<< setw(10) << student_info[i].match << setw(10) << student_info[i].winnings
				<< endl << endl;
		}
	}

}