//Harrison Bounds

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>  //need for File I/0
using namespace std;

const int NUMBER_OF_STUDENTS = 5;

struct Students
{
	int id_num;
	string student_name;
	double gpa;
};

//get student ID, name, and GPA from user
void getInfo(Students[]);
//display all student information
void diplayStudentInfo(Students[]);

int main()
{
	//Array of structures to store information for each student
	Students student_info[NUMBER_OF_STUDENTS];
	bool again;

	do
	{
		getInfo(student_info);
		diplayStudentInfo(student_info);

		cout << "\n Would you like to run again? (1 for Yes  OR  0 for No) ";
		cin >> again;
   } while (again);

return 0;
}

//get student ID, name, and GPA from user
void getInfo(Students student_info[])
{
	ifstream inFile;  //Input file stream to open file and read         

	int i = 0; //index for position in array of structures
	inFile.open("student.txt"); //open file to read from 

	if (!inFile) //check to see if file is open
		cout << "\n\n**** ERROR OPENING FILE. ******\n" << endl;
	else
	{
		while (!inFile.eof()) //while not at end of file(eof)
		{
			inFile >> student_info[i].id_num; //read student id
			getline(inFile, student_info[i].student_name);//get name
			inFile >> student_info[i].gpa;   //read GPA
			i++;
		}
	}
	inFile.close();
}

//display all student information
void diplayStudentInfo(Students student_info[])
{
	cout << setprecision(1) << showpoint << fixed;
	cout << endl << endl << "ID   Student Name      GPA " << endl << endl;
	for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
	{
		cout << left;
		cout << setw(5) << student_info[i].id_num;
		cout << setw(15) << student_info[i].student_name;
		cout << right;
		cout << setw(6) << student_info[i].gpa;
		cout << endl;
	}
	cout << endl << endl << endl;
}


