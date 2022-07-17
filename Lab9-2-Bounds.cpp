//Harrison Bounds
//This program inputs 10 integers and places them into even, odd, or negative categories

#include<iostream>
#include<iomanip>

using namespace std;

const int INTEGERS = 10;

void getNum(int[]);
void determineEvenOrOdd(int[], int[], int[], int&, int&);
void determineNegative(int[], int[], int&);
void displayArrays(int[], int[], int[], int, int, int);

int main()
{
	char repeat;
	cout << "This program inputs 10 integers and places them into even, odd, or negative categories\n\n";
	do
	{
		int nums[INTEGERS] = { 0 };
		int even[INTEGERS] = { 0 }, odd[INTEGERS] = { 0 }, negative[INTEGERS] = { 0 };
		int e_count, o_count, n_count;

		getNum(nums);
		determineEvenOrOdd(nums, even, odd, e_count, o_count);
		determineNegative(nums, negative, n_count);
		displayArrays(even, odd, negative, e_count, o_count, n_count);

		cout << "\n\nWould you like to process another 10 integers? Please enter y for yes or n for no:   ";
		cin >> repeat;

	} while (repeat == 'Y' || repeat == 'y');
}
//This function get the list of 10 integers from the user
void getNum(int nums[])
{
	for (int i = 0; i < INTEGERS; i++)
	{
		cout << "Integer = ";
		cin >> nums[i];
	}
}
//This function determines whether the integers are even or odd and then stores then in a specific array
void determineEvenOrOdd(int nums[], int even[], int odd[], int& e_count, int& o_count)
{
	e_count = 0;
	o_count = 0;
	for (int i = 0; i < INTEGERS; i++)
	{
		if (nums[i] % 2 == 0)
		{
			even[e_count] = nums[i];
			e_count++;
		}
		else if(nums[i] % 2 != 0)
		{
			odd[o_count] = nums[i];
			o_count++;
		}
	}
}
//This function determines whether the number is negative or not and stores it in a specific array
void determineNegative(int nums[], int negative[], int& n_count)
{
	n_count = 0;
	for (int i = 0; i < INTEGERS; i++)
	{
		if (nums[i] < 0)
		{
			negative[n_count] = nums[i];
			n_count++;
		}
	}
}
//This function displays the negative integers, the even integers, and the odd integers
void displayArrays(int even[], int odd[], int negative[], int e_count, int o_count, int n_count)
{
	cout << "The negative integers are: \n";
	for (int i = 0; i < n_count; i++)
		cout << negative[i] << setw(5);

	cout << "\n\n\nThe even integers are: \n";
	for (int i = 0; i < e_count; i++)
		cout << even[i] << setw(5);

	cout << "\n\n\nThe odd integers are: \n";
	for (int i = 0; i < o_count; i++)
		cout << odd[i] << setw(5);
}


