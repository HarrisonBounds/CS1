
//Name: 

//Complete the source code below by replacing the ???? with code to produce the 
//the following output.
/*
While loop output:
1  2  3  4  5  6  7  8  9  10

for loop output:
1  2  3  4  5  6  7  8  9  10

Do_while loop output:
1  2  3  4  5  6  7  8  9  10
*/


#include <iostream>
#include <iomanip>
using namespace std;

const int END_VALUE = 10;

int main(void)
{
	int number = 1;

	cout << "While loop output: " << endl;
	while (number <= END_VALUE)
	{
		cout << setw(4) << number; 
		number++;
	}

	cout << endl << endl;

	int i;
	cout << "for loop output: " << endl;
	for (i = 1; i <= END_VALUE; i++)
		cout << setw(4) << i;

	cout << endl << i << endl;

	cout << endl << endl;
	number = 1;

	cout << "Do_while loop output: " << endl;
	do
	{
		cout << setw(4) << number;
		number++;

	} while (number <= END_VALUE);

	cout << endl << endl;

	//system("pause");
}



