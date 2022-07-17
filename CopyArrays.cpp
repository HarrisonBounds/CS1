/******************************************************************************
  Description   : Copy a 1D array using functions
********************************C**********************************************/
//Harrison Bounds
#include <iostream>
using namespace std; //introduces namespace std

const int NUMEL = 10;

void copyArray(int[], int, int[]);
void displayLists(int[], int, int[]);

int main(void)
{
    int nums[NUMEL] = { 22, 5, 67, 98, 45, 32, 101, 99, 73, 10 };
    int duplicate[NUMEL] = { 0 };

    copyArray(nums, NUMEL, duplicate);
    displayLists(nums, NUMEL, duplicate);

    cout << endl << endl;
    return 0;
}

void copyArray(int original[], int NUMELS, int duplicate[])
{
    cout << "Original array is " << original << endl;
    cout << "Duplicate array is " << duplicate << endl;

    for(int i = 0; i < NUMELS; i++)   //must copy element by element
       duplicate[i] = original[i];
    //duplicate = original;            //this does not work

    cout << "Original array is " << original << endl;
    cout << "Duplicate array is " << duplicate << endl;
}

void displayLists(int original[], int NUMELS, int duplicate[])
{

    cout << "\n\nThe list of items in original array is:  " << endl;
    for (int i = 0; i < NUMELS; i++)
        cout << original[i] << " ";

    cout << "\n\nThe list of items in the duplicate array is:  " << endl;
    for (int i = 0; i < NUMELS; i++)
        cout << duplicate[i] << " ";
}
