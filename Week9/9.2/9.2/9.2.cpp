#include <iostream>
#include<string>

using namespace std;

struct Emp getdata(); //gets emp dataand reads into the array
void printdata(struct Emp emp[], int size); //prints out the data in the struct onto terminal
double get_average(struct Emp* emp, int size , string cmp_name); //average salary of a company
double get_salary(struct Emp emp[], int size, string emp_name); //serach the salary of an employee


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

int main()
{
	const int size = 5;
	int i;
	struct Emp emp[size];
	double average;
	double salary;
	string cmp_name;
	string emp_name;
	
	for (i = 0; i<size;i++) 
	{
		emp[i] = getdata();
	}

	printdata(emp, size);

	cout << "Enter a company name to get average for company: ";
	cin >> cmp_name;
	average = get_average(emp, size, cmp_name);

	cout << "Enter Employee name to get Employee Salary ";
	cin >> emp_name;
	salary = get_salary(emp, size, emp_name);

	cout << "Average For " << cmp_name << " is " << average << endl;
	cout << "Salary For " << emp_name << " is " << salary << endl;


	return 0;
}

struct Emp getdata()
{
	struct Emp emp;

	cout << "Enter Employees id: ";
	cin >> emp.emp_id;

	cout << "Enter Employee Name: ";
	cin >> emp.emp_name;

	cout << "Enter Employee Salary: ";
	cin >> emp.salary;

	cout << "Enter Company ID: ";
	cin >> emp.cmp_detail.company_id;

	cout << "Enter Company Name: ";
	cin >> emp.cmp_detail.company_name;

	cout << endl;

	return emp;
}

void printdata(struct Emp emp[], int size)
{
	int i = 0;

	for (i = 0;i < size;i++)
	{
		cout << "Enter Employees id: "<<emp[i].emp_id<<endl;
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
	for (i = 0; i < size;i++)
	{
		if (emp[i].cmp_detail.company_name == cmp_name)
		{
			average += emp[i].salary;
			count++;
		}
	}

	return average / count;
}

double get_salary(struct Emp emp[],int size,  string emp_name)
{
	int i;
	for (i = 0; i < size;i++)
	{
		if (emp[i].emp_name == emp_name)
		{
			return emp[i].salary;
		}
	}
}