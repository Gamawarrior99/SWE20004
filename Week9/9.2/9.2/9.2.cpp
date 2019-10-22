#include <iostream>
#include<string>

using namespace std;

void getdata(); //gets emp dataand reads into the array
void printdata(struct Emp emp[], int size); //prints out the data in the struct onto terminal
double get_average(struct emp* emp, int size , string average); //average salary of a company
double get_salary(struct Emp emp[], string emp_name); //serach the salary of an employee


struct company_detail
{
	string company_id;
	string companuy_name;
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


}