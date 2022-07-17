
//NAME: Harrison Bounds

//This program calculates the perimeter and area of a rectangle.
/*******************************************************
Input:
Length and width of rectangle

Process:
1. Calculate the area: length X width
2. Calculate perimeter: (2 X length) + (2 X width)
						OR length + length + width + width

Output:
Length, width, and calculated area and perimeter of a rectangle
*******************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
int getLength();
int getWidth();
int calculateArea(int, int);
int calcPerimeter(int, int);
void displayRectangleInfo(int, int, int, int);

int main()
{
	//Variables needed 
	int length = 0, width = 0, area = 0, perimeter = 0;
	bool repeat;

	do
	{
		//Function Call Statements
		length = getLength();
		width = getWidth();
		area = calculateArea(length, width);
		perimeter = calcPerimeter(length, width);
		displayRectangleInfo(length, width, area, perimeter);

		cout << "Run again (1 for YES, 0 for NO): ";
		cin >> repeat;
	} while (repeat);

	return 0;
}

//Function Definitions 

//Prompts and gets the length of the rectangle 
int getLength() //function header
{
	//function body
	int leng;
	cout << "Enter the Length of the rectangle: ";
	cin >> leng;
	return leng;
}

//Prompts and gets the width of the rectangle 
int getWidth() //function header
{
	//function body
	int wid;
	cout << "Enter the Width of the rectangle: ";
	cin >> wid;
	return wid;
}

//Calculates the area of the rectangle 
int calculateArea(int length, int width) //function header
{
	//function body
	int area = 0;
	area = length * width;
	//cout << endl << area << endl;
	return area;

	//OR  return length * width;
}

//Calculates the perimeter of the rectangle 
int calcPerimeter(int l, int w) //function header
{
	//function body
	int perimeter = 0;
	perimeter = l + l + w + w;
	//cout << endl << perimeter << endl;
	return perimeter;

	//OR  return (2 * l) + (2 * w);
}

//Displays the dimensions and area of the rectangle  
void displayRectangleInfo(int length, int width, int area, int perimeter) //function header
{
	//function body
	cout << "\n\n\nThe dimensions of the rectangle are: " << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Area: " << area << endl;
	cout << "Perimeter: " << perimeter << endl;
	cout << endl << endl;
}

