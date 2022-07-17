#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	double length = 0, width = 0, area = 0;
	ifstream inFile;  //Input file stream to open file and read 

	inFile.open("rectangle.txt"); //open file to read from 

	if (!inFile) //check to see if file is open
		cout << "\n\n**** ERROR OPENING FILE. ******\n" << endl;
	else
	{
		while (!inFile.eof()) //while not at end of file(eof)
		{
			inFile >> length;
			inFile >> width;
			area = length * width;
			cout << "\n\n The area of a rectangle with a length of " << length << " and a width of " << width << " is " << area;
			cout << endl << endl;
			if (inFile.eof()) //if end—of-file, break out of loop
				break;
		}
	}
	inFile.close();


	return 0;
}