//Harrison Bounds
//This program takes a string from the user and displays it in severala different formats

#include<iostream>
#include<string>

using namespace std;

void getStringAndDisplay(string&);
void calculateLength(string, int&);
void displayNumberOfWords(string);
void displayBackwards(string, int);

int main()
{
	bool repeat;
	do
	{
		string sentence = { 0 };
		int total = 0;

		getStringAndDisplay(sentence);
		calculateLength(sentence, total);
		displayNumberOfWords(sentence);
		displayBackwards(sentence, total);

		cout << "Run program again? Yes = 1 and No = 0:   ";
		cin >> repeat;
	} while (repeat);
}

//This function reads the sentence entered by the user amd displays it

void getStringAndDisplay(string& sentence)
{
	cout << "Enter message: ";
	getline(cin, sentence);
	cout << endl << endl;
	cout << "The message entered was: \n";
	cout << sentence << endl << endl;
}

//This function calculates the length of the string and displays it

void calculateLength(string sentence, int& total)
{

	for (int i = 0; sentence[i] != NULL; i++)
	{
		total = i;
	}
	total += 1;

	cout << "The length of the string entered is: " << total << endl << endl;

}

//This function displays the total number of words in the string

void displayNumberOfWords(string sentence)
{
	int count = 0;
	for (int i = 0; sentence[i] != NULL; i++)
	{
		if (sentence[i] == ' ')
		{
			count++;
		}
	}
	cout << "Number of words in message: " << count + 1 << endl << endl;
}

//This function displays the string backwards

void displayBackwards(string sentence, int total)
{
	for (int i = total; i >= 0; i--)
	{
		cout << sentence[i];
	}
	cout << endl;
}