#include <iostream>
#include <string>
#include <fstream>

#define END -1

using namespace std;

struct company_detail
{
	string company_id;
	string company_name;
};

struct Emp
{
	string emp_name;
	string emp_id;
	double salary;
	struct company_detail cmp_detail;
};

void getdata(struct Emp* emp)
{
	int x; //value of the first line
	int i = 0;

	ifstream inFile;

	inFile.open("input.dat"); //name of file here
	if (!inFile)
	{
		cout << "Unable to open file";
	}

	inFile >> x; //reads first line of file and adds it to x
	for (i = 0; i <= x; i++) //while i is less than the total values
	{
		inFile >> emp[i].emp_id;
		inFile >> emp[i].emp_name;
		inFile >> emp[i].salary;
		inFile >> emp[i].cmp_detail.company_id;
		inFile >> emp[i].cmp_detail.company_name;
	}
}

void printdata(struct Emp emp[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		cout << "Enter Employees id: " << emp[i].emp_id << endl;
		cout << "Enter Employee Name: " << emp[i].emp_name << endl;
		cout << "Enter Employee Salary: " << emp[i].salary << endl;
		cout << "Enter Company ID: " << emp[i].cmp_detail.company_id << endl;
		cout << "Enter Company Name: " << emp[i].cmp_detail.company_name << endl;
		cout << endl;
	}
}

double get_average(struct Emp* emp, int size, string cmp_name)
{
	double average = 0;
	int i;
	int count = 0;
	for (i = 0; i < size; i++)
	{
		if (emp[i].cmp_detail.company_name == cmp_name)
		{
			average += emp[i].salary;
			count++;
		}
	}

	return average / count;
}

int get_salary(struct Emp emp[], int size)
{
	int i;
	int High_Salary = emp[0].salary;
	int value;
	for (i = 0; i < size; i++)
	{
		if (emp[i].salary > High_Salary)
		{
			value = i;
		}
		return value;
	}
}

void menu()
{
	cout << "Enter 1 to Display all" << endl;
	cout << "Enter 2 to Get Average of a Company" << endl;
	cout << "Enter 3 to Get Employee With Highest salary" << endl;
}

int main()
{
		const int size = 5;
		struct Emp emp[size];
		int choice;
		double average;
		string cmp_name;
		int value;

		getdata(emp); //sends the array to filed up with the values from file

		do {
			menu();
			cin >> choice;
			switch (choice)
			{
				case 1://prints all data
					printdata(emp, size);
				case 2://gets the name with highest salary
					value = get_salary(emp, size);
					//cout statenments saying average sal for cmp is
				case 3://gets the average salary of a cmp
					cout << "Enter a company name to get average for company: ";
					cin >> cmp_name;
					average = get_average(emp, size, cmp_name);
					//cout here higest sal for emp is
			}
		} while (choice != END);
	return 0;
}
