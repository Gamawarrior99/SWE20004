#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <cmath>

using namespace std;

char menu();
int int_number_generator();
double double_price_generator(int min, int max);
double TV_price(int amount, double price);
double Refrigerator_price(int amount, double price);
double Laptop_price(int amount, double price);
double Mobile_price(int amount, double price);


int main()
{
	const char E = 'E';
	char choice;
	int amount;
	double Total_Price, tv_price = 0, fridge_price = 0, laptop_price = 0, mobile_price = 0, price = 0;
	do {
		choice = menu();
		amount = int_number_generator();
		if (toupper(choice) == 'T')
		{
			price = double_price_generator(300, 1000);
			tv_price = TV_price(amount, price);

			cout << "Rate for TV is: " << price << endl;
			cout << "Number of TV's in Purchase: " << amount << endl;
			cout << "Total price is after payback (if any): " << tv_price << endl;
		}
		if (toupper(choice) == 'R')
		{
			price = double_price_generator(100, 500);
			fridge_price = (Refrigerator_price(amount, price)* 0.055);

			cout << "Rate for TV is: " << price << endl;
			cout << "Number of TV's in Purchase: " << amount << endl;
			cout << "Total price is after tax: " << fridge_price << endl;
		}
		if (toupper(choice) == 'L')
		{
			price = 1000;
			laptop_price = Laptop_price(amount, price);

			cout << "Rate for TV is: " << price << endl;
			cout << "Number of TV's in Purchase: " << amount << endl;
			cout << "Total price is: " << laptop_price<< endl;
		}
		if (toupper(choice) == 'M')
		{
			
			price = 500;
			mobile_price = Mobile_price(amount, price);

			cout << "Rate for TV is: " << price << endl;
			cout << "Number of TV's in Purchase: " << amount << endl;
			cout << "Total price is: " << mobile_price << endl;
		}

		Total_Price = tv_price + fridge_price + laptop_price + mobile_price;
		cout << "final recipt" << endl;
		cout << "TV: " << tv_price<<endl;
		cout << "Refrigerator: " << fridge_price << endl;
		cout << "Laptop price is: " << laptop_price << endl;
		cout << "Mobile price is: " << mobile_price << endl;
		cout << "total bill is: " << Total_Price << endl;

		cout << "rounded Bill is: " <<round(Total_Price)<< endl;
		
		
	} while (toupper(choice) != E);
	return 0;
}

char menu()
{
	char choice;
	bool valid = false;
	cout << "Enter T For TV" << endl;
	cout << "Enter R For Refrigerator" << endl;
	cout << "Enter L For Laptop" << endl;
	cout << "Enter M For Mobile" << endl;
	cout << "Enter E For Exit" << endl;

	do {
		if (valid == true)
		{
			cout << "Invalid Choice: ";
		}
		cin >> choice;
		valid = true;
		if (toupper(choice) == 'T')
		{
			valid = false;
		}
		if (toupper(choice) == 'R')
		{
			valid = false;
		}
		if (toupper(choice) == 'L')
		{
			valid = false;
		}
		if (toupper(choice) == 'M')
		{
			valid = false;
		}
		if (toupper(choice) == 'E')
		{
			valid = false;
		}
	} while (valid);
	cout << endl;
	return choice;
}

int int_number_generator()
{
	srand((unsigned)time(0));
	return (rand() % 50) + 1;
}

double double_price_generator(int min, int max)
{
	srand((unsigned)time(0));
	double random = ((double)rand()) / (double)RAND_MAX;
	double diff = max - min;
	double r = random * diff;
	return min + r;
}

double TV_price(int amount, double price)
{
	double total = amount * price;
	if (price >= 500)
	{
		total -= (50*amount);
	}
	return total;
}

double Refrigerator_price(int amount, double price)
{
	return  amount * price;
}

double Laptop_price(int amount, double price)
{
	return  amount * price;
}

double Mobile_price(int amount, double price)
{
	double total;
	int tenless = 0;
	if (amount >= 10)
	{
		tenless = amount - 10;

	}
	total = (10 * price) + (tenless * (price / 2));
	return total;
}