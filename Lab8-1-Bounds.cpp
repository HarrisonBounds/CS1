//Harrison Bounds
//Compute and Display Customer's bill for an All You Can Eat Buffet

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std; 

//Function Prototypes
void getInformation(string&, string&, int&, int&, int&);
void calculateCharges(int, int, int, double&, double&, double&, double&, double&, double&, double&);
void displayBill(string, string, int, int, int, double, double, double, double, double, double, double);

const double ADULT_MEAL = 6.00, CHILD_MEAL = 3.00, DESSERT = 1.00;
const double TAX_RATE = 0.065, GRATUITY_RATE = .15;

int main(void)
{
	bool choice;
	do
	{
		//Variables
		string date, name;
		int num_adult_meals, num_child_meals, num_desserts;
		double adult_charge, child_charge, dessert_charge;
		double taxes, subtotal, gratuity_charge, grand_total;

		//Function Call
		getInformation(date, name, num_adult_meals, num_child_meals, num_desserts);
		calculateCharges(num_adult_meals, num_child_meals, num_desserts, adult_charge, child_charge, dessert_charge, taxes, subtotal, gratuity_charge, grand_total);
		displayBill(date, name, num_adult_meals, num_child_meals, num_desserts, adult_charge, child_charge, dessert_charge, taxes, subtotal, gratuity_charge, grand_total);

		cout << "Would you like to process another customer's bill? <1 for Yes> <0 for N0>  ";
		cin >> choice;
		cin.ignore();
	} while (choice);
}

//This function gets the customer's information
void getInformation(string& date, string& name, int& num_adult_meals, int& num_child_meals, int& num_desserts)
{

	cout << "Please enter the following Customer's Information." << endl;
	cout << "Date: ";
	getline(cin, date);

	cout << "\n\nCustomer's Name: ";
	getline(cin, name);
	do
	{
		cout << "\n\nNumber of Adult Meals: ";
		cin >> num_adult_meals;

		if (num_adult_meals < 0)
			cout << "ERROR - Please enter a valid number" << endl;

	} while (num_adult_meals < 0);

	do
	{
		cout << "\n\nNumber of Child Meals: ";
		cin >> num_child_meals;

		if(num_child_meals < 0)
			cout << "ERROR - Please enter a valid number" << endl;

	} while (num_child_meals < 0);

	do
	{
		cout << "\n\nNumber of Desserts: ";
		cin >> num_desserts;

		if(num_desserts < 0)
			cout << "ERROR - Please enter a valid number" << endl;

	} while (num_desserts < 0);
}

/*This function calculate's the Meal Charges, the Subtotal,
the Taxes, the Gratuity, and the Grand Total*/
void calculateCharges(int num_adult_meals, int num_child_meals, int num_desserts, double& adult_charge, double& child_charge, double& dessert_charge, double& taxes, double& subtotal, double& gratuity_charge, double& grand_total)
{

	adult_charge = ADULT_MEAL * num_adult_meals;
	child_charge = CHILD_MEAL * num_child_meals;
	dessert_charge = DESSERT * num_desserts;
	taxes = (adult_charge + child_charge + dessert_charge) * TAX_RATE;
	subtotal = taxes + (adult_charge + child_charge + dessert_charge);
	gratuity_charge = subtotal * GRATUITY_RATE;
	grand_total = subtotal + gratuity_charge;
}

//This function displays the Customer's Bill
void displayBill(string date, string name, int num_adult_meals, int num_child_meals, int num_desserts, double adult_charge, double child_charge, double dessert_charge, double taxes, double subtotal, double gratuity_charge, double grand_total)
{
	cout << "\n\nThe All-You-Can-Eat Buffet Restaurant\n\n";
	cout << date << endl;
	cout << name << endl << endl;

	cout << setprecision(2) << fixed << showpoint;
	cout << "Adult Meal Charge: " << num_adult_meals << " @ " << ADULT_MEAL << " each                 $  " << adult_charge << endl;
	cout << "Child Meal Charge: " << num_child_meals << " @ " << CHILD_MEAL << " each                 $  " << child_charge << endl;
	cout << "Dessert Charge: " << num_desserts << " @ " << DESSERT << " each                    $  " << dessert_charge << endl;
	cout << "Taxes:                                           $  " << taxes << endl;
	cout << "           Subtotal:                             $  " << subtotal << endl << endl;
	cout << "Gratuity Charge: (15.00%)                        $  " << gratuity_charge << endl << endl;
	cout << "TOTAL DUE:                                       $  " << grand_total << "\n\n\n\n";

	cout << "Thank you for eating at the All-You-Can-Eat Buffet Restaurant." << endl;
	cout << "Please come again.\n\n";

}