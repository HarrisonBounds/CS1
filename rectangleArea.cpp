//NAME:

//This program calculates the area of a rectangle.
/*******************************************************
Input: Length and width of rectangle
Process: Calculate the area: length X width
Output: Length, width, and calculated area of a rectangle

*******************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
double getLength();
double getWidth();
double calculateArea(double length, double width);
void displayRectangleInfo(double length, double width, double area);

int main()
{
	//Variables needed 
	double length = 0, width = 0, area = 0;


	//Function Call Statements
	length = getLength();
	width = getWidth();
	area = calculateArea(length, width);
	displayRectangleInfo( length,  width,  area);
		
	return 0;

}

//Function Definitions 

//Prompts and gets the length of the rectangle 
double getLength() //function header
{
	//function body
	double length;
	cout << "Enter the length of the rectangle: ";
	cin >> length;
	return length;
}

//Prompts and gets the width of the rectangle 
double getWidth() //function header
{
	//function body
	double width;
	cout << "Enter the width of the rectangle: ";
	cin >> width;
	return width;
}

//Calculates the area of the rectangle 
double calculateArea(double length, double width) //function header
{
	//function body
	double area;
	area = length * width;
	return area;
}

//Displays the dimensions and area of the rectangle  
void displayRectangleInfo(double length, double width, double area) //function header
{
	//function body
	cout << "Length: " << length << endl;
	cout << "Width " << width << endl;
	cout << "Area: " << area << endl;
}
