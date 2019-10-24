#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#define END -1

using namespace std;

struct model_details
{
	string brand;
	string type;
	int id;
};

struct Vehicle
{
	int year;
	double price;
	struct model_details model;
};

int ReadFile(struct Vehicle* Car);
void menu();
void display(struct Vehicle* Car, int size);
int find_Min_price(struct Vehicle* Car, int size);
double find_average_price(struct Vehicle* Car, int size, string Brand);

int main()
{
	const int size = 100;
	struct Vehicle Car[size];
	int choice;
	int Num_Lines;
	int Min = 0;
	double average;
	string brand;

	Num_Lines = ReadFile(Car);

	do {
		menu();
		cin >> choice;
			switch (choice)
			{
				case 1:
					display(Car, Num_Lines);
					break;
				case 2:
					Min = find_Min_price(Car, Num_Lines);
					cout << "Details OF car With lowest Prices are" << endl;
					cout << "Brand: " << Car[Min].model.brand << endl;
					cout << "Type: " << Car[Min].model.type << endl;
					cout << "Vehicle ID: " << Car[Min].model.id << endl;
					cout << "Year: " << Car[Min].year << endl;
					cout << "Price: " << fixed << setprecision(2) << Car[Min].price << endl;
					cout << endl;
					break;
				case 3:
					cout << "Enter Vehicle Brand to get Average Price: ";
					cin >> brand;
					average = find_average_price(Car, Num_Lines, brand);
					if (average != 0)
					{
						cout << "Average Price of: " << brand << " is " << fixed << setprecision(2) << average << endl << endl;
					}
					break;
				default:
					if (choice != END)
					{
						cout << "This is not a valid option" << endl;
					}
			}
		} while (choice != END);
	return 0;
}

void menu()
{
	cout << "Enter your choice" << endl;
	cout << "Enter 1 to Display all" << endl;
	cout << "Enter 2 to Find Minimum Price" << endl;
	cout << "Enter 3 to Find Average Price" << endl;
	cout << "Enter -1 to exit the program" << endl;
}

int ReadFile(struct Vehicle* Car)
{
	int i = 0;

	string line;
	ifstream inFile("vehicle.txt");

	while (!inFile.eof())
	{
		inFile >> Car[i].model.brand;
		inFile >> Car[i].model.type;
		inFile >> Car[i].model.id;
		inFile >> Car[i].year;
		inFile >> Car[i].price;
		i++;
	}

	return i;
}

void display(struct Vehicle* Car, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		cout << "Brand: " << Car[i].model.brand << endl;
		cout << "Type: " << Car[i].model.type << endl;
		cout << "Vehicle ID: " << Car[i].model.id << endl;
		cout << "Year: " << Car[i].year << endl;
		cout << "Price: " << fixed << setprecision(2) << Car[i].price << endl;
		cout << endl;
	}
}

int find_Min_price(struct Vehicle* Car, int size)
{
	int i;
	int Min = Car[0].price;
	int value = 0;
	for (i = 0; i < size; i++)
	{
		if (Car[i].price < Min)
		{
			Min = Car[i].price;
			value = i;
		}
	}
	return value;
}

double find_average_price(struct Vehicle* Car, int size, string Brand)
{
	double average = 0;
	int i;
	int count = 0;
	bool found = false;

	for (i = 0; i < size; i++)
	{
		if (Car[i].model.brand == Brand)
		{
			average += Car[i].price;
			found = true;
			count++;
		}
	}

	if (found == false)
	{
		cout << "No Such Brand" << endl << endl;
		return 0;
	}

	return average / count;
}