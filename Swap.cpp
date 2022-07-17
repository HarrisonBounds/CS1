//This program illustrates pass by reference
//It reads two real numbers from the user and swaps the values in memory

#include<iostream>
using namespace std;

// Function declarations (Prototypes)
void getNumbers(double&, double&);
void swap(double&, double&);

int main(void)
{
    //Declaration/Initialization statements
    double first_number = 0.0, second_number = 0.0;//stores numbers entered by user

    //Function call statement to get numbers from user
    getNumbers(first_number, second_number);

    //Verify what is stored in the variables before the swap function is called
    cout << "\nFirst number entered by user and stored in first_number: "
        << first_number;
    cout << "\nSecond number entered by user and stored in second_number: "
        << second_number;

    //Function call statement to swap() the values in memory
    swap(first_number, second_number);       // call swap

    //Display what is stored in the variables after the swap( ) is performed 
    cout << "\n\nThe value stored in first_number is:  " << first_number << endl;
    cout << "The value stored in second_number is: " << second_number << endl;

    return 0;
}

//This function prompts the user to enter two real numbers to be swapped
void getNumbers(double& num1, double& num2)
{
    cout << "Please enter the first real number to be swapped: ";
    cin >> num1;
    cout << "Please enter the second real number to be swapped: ";
    cin >> num2;
}

//This function swaps the values stored in first_number and second_number  
void swap(double& n1, double& n2)
{
    double temp;  //temporary holding location for value

    temp = n1;   // save first value in temporary storage
    n1 = n2;     // move second value in first value's memory location
    n2 = temp;   // store value saved in temp to second number's original memory location
}
