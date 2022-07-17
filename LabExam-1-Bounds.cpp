//Harrison Bounds
/*Calculate handling fee and shipping charge based on the volume of
the shape and the total processing charges to create an invoice for her customers*/

#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>


using namespace std;

const double PI = 3.1416;

int main()
{
	//Variables
	double volume = 0, cube_side = 0, major_radius = 0, minor_radius = 0;
	double handling_fee = 0, shipping_charge = 0, total = 0;
	double a_radius = 0, b_radius = 0, c_radius = 0;
	int choice;
	string name, shape;

	
	do
	{
		cout << "Please enter your choice of shape from the following menu: " << endl;
		cout << "1. Cube\n";
		cout << "2. Torus\n";
		cout << "3. Ellipsoid\n";
		cout << "4. Quit\n\n";

		cout << "Enter menu choice: ";
		cin >> choice;
		cin.ignore();

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
			cout << "\n\n*****ERROR. An invalid choice was made. Please re-select.*****\n\n";
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);


	
		switch (choice)
		{
		case 1:
			shape = "Cube";
			cout << "\nEnter the name of the Customer: ";
			getline(cin, name);
			cout << "\n\nEnter the Side meaursement of the cube: ";
			cin >> cube_side;

			volume = pow(cube_side, 3);

			cout << "\nShipping Invoice for " << name << endl << endl << endl;
			cout << "Dimensions of the " << shape << ": " << endl;
			cout << "Side: " << cube_side << endl << endl;
			break;
		case 2:
			shape = "Torus";
			cout << "\nEnter the name of the Customer: ";
			getline(cin, name);
			cout << "Enter the Major Radius (R) measurement of the Torus: ";
			cin >> major_radius;
			cout << "Enter the Minor Radius (r) measurement of the Torus: ";
			cin >> minor_radius;

			volume = 0.25 * pow(PI, 2) * (minor_radius + major_radius) * pow((major_radius - minor_radius), 2);

			cout << "\nShipping Invoice for " << name << endl << endl << endl;
			cout << "Dimensions of the " << shape << ": " << endl;
			cout << "Major Radius(R): " << major_radius << endl;
			cout << "Minor Radius(r): " << minor_radius << endl;
			break;
		case 3:
			shape = "Ellipsoid";
			cout << "\nEnter the name of the Customer: ";
			getline(cin, name);
			cout << "\nEnter the a-axis radius: ";
			cin >> a_radius;
			cout << "\nEnter the b-axis radius: ";
			cin >> b_radius;
			cout << "\nEnter the c-axis radius: ";
			cin >> c_radius;

			volume = 1.333333 * PI * a_radius * b_radius * c_radius;

			cout << "\nShipping Invoice for " << name << endl << endl << endl;
			cout << "Dimensions of the " << shape << ": " << endl;
			cout << "A-Axis Radius: " << a_radius << endl;
			cout << "B-Axis Radius: " << b_radius << endl;
			cout << "C-Axis Radius: " << c_radius << endl;
			break;
		case 4:
			cout << "\nThanks for usind this program!!!!!\n";
			exit(1);
			break;
		}
	


	if (volume > 0 && volume <= 50)
	{
		handling_fee = 5.55;
		shipping_charge = 0.10 * volume;
		total = handling_fee + shipping_charge;
	}
	else if(volume > 50 && volume <= 100)
	{
		handling_fee = 7.75;
		shipping_charge = (volume - 50) * 0.23;
		total = handling_fee + shipping_charge;
	}
	else if(volume > 100 && volume <= 150)
	{
		handling_fee = 9.50;
		shipping_charge = (volume - 100) * 0.28;
		total = handling_fee + shipping_charge;
	}
	else if (volume > 150)
	{
		handling_fee = 11.25;
		shipping_charge = (volume - 150) * 0.32;
		total = handling_fee + shipping_charge;
	}

	

	cout << setprecision(1) << fixed << showpoint;
	cout << "\nVolume: " << volume << " cubic feet" << endl << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << "Handling Fee.............................$" << handling_fee << endl;
	cout << "Shipping Charge..........................$" << shipping_charge << endl;
	cout << "Total Processing Charges.................$" << total << endl;



}