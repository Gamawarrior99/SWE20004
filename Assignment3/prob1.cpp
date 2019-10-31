/*
Name: Gamaliel D'mello
Student Number: 102117407
Description: reads and updates file of students
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

struct student
{
	string name;
	int id;
	float grade;
	student* next;
};
typedef struct student stu;
typedef stu* stuptr;

void readFile(stuptr students);
void updateFile();
void print_details(stuptr students);
void search_s(stuptr students, string search);
void find_max(stuptr students);
void average(stuptr students);
void menu();

int main()
{
	int choice;
	string search;
	stuptr start = new student;

	readFile(start);

	do {
		menu();
		cout << "What is your choice?  ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			print_details(start);
			break;
		case 2:
			average(start);
			break;
		case 3:

			cout << "Enter student's grade you want to look for: ";
			cin >> search;
			cout << endl;
			search_s(start, search);
			break;
		case 4:
			find_max(start);
			break;
		case 5:
			updateFile();
			readFile(start);
			break;
		case 6:
			cout << "Program ended Succesfull" << endl;
			break;
		}
	} while (choice != 7);
	return 0;
}

void readFile(stuptr start)
{
	int i = 0;
	stuptr students = new student;
	stuptr previous = NULL;


	string line;
	ifstream inFile("student_details.txt");

	if (inFile.fail())
	{
		cout << endl;
		cout << "File Not Found" << endl;
	}

	inFile >> start->name >> start->id >> start->grade;
	start->next = students;


	while (!inFile.eof())
	{
		inFile >> students->name >> students->id >> students->grade;
		students->next = NULL;
		previous = students;
		students = new student;
		previous->next = students;
	}

	inFile.close();
}

void updateFile()
{
	string in_name;
	int in_id;
	float in_grade;

	ofstream outFile;
	outFile.open("student_details.txt", ios_base::app);

	cout << "Enter Details" << endl;
	cout << "Name: ";
	cin >> in_name;

	cout << "ID: ";
	cin >> in_id;

	cout << "Grade: ";
	cin >> in_grade;

	outFile << endl << in_name << " " << in_id << " " << in_grade;
	cout << "Succesfull Updated File" << endl;
	outFile.close();
}

void print_details(stuptr students)
{
 while (students->next != NULL)
	{
		cout << "Name: " << students->name << endl;
		cout << "ID: " << students->id << endl;
		cout << "Grade: " << students->grade << endl;
		cout << endl;
		students = students->next;
}
}

void search_s(stuptr students, string search)
{
  while (students -> next != NULL)
  {
		if(students->name == search) 
    {
		 cout << "Name: " << students->name << endl;
		 cout << "ID: " << students->id << endl;
		 cout << "Grade: " << students->grade << endl;
		 cout << endl;   
		} 
    students = students->next;	
	}
  if (students -> next == NULL)
  {
    cout<<"No Student Found"<<endl;
  }

}

void find_max(stuptr students)
{
	int max = 0;
  while (students->next != NULL)
	{
		if(students->grade > max)
    {
      		max = students->grade;
    }
	students = students->next;  
  }
	cout << "Highest Grade is: " << max << endl << endl;
}

void average(stuptr students)
{
	float avg = 0;
  int i = 0;
  while (students->next != NULL)
	{
		
		avg +=students->grade;
    i++;
		students = students->next;
	}
  avg = avg/i;
	cout << "Average Grade is: " << avg << endl << endl;
}

void menu()
{
	cout << "(1) Display students	" << endl;
	cout << "(2) Calculate average " << endl;
	cout << "(3) Search for particular student's grade " << endl;
	cout << "(4) Find maximum " << endl;
	cout << "(5) Add new student to the Record" << endl;
	cout << "(6) Quit Program" << endl;
}
