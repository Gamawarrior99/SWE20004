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
};
typedef struct student stu;

int readFile(stu students[]);
void updateFile();
void sort_student_grades(stu students[], int student_total);
void sort_student_names(stu students[], int student_total);
void print_details(stu students[], int student_total);
int search_s(stu students[], int student_total, string search);
void find_max(stu students[],int student_total);
void average(stu students[], int student_total);
void menu();

int main()
{
  const int size = 100;
  stu students[size];
  int student_total = 0;
  int choice;
	float index;
  string search;

  student_total = readFile(students);
  do{
    menu();
		cout << "What is your choice?  ";
        cin >> choice;  
        cout << endl;
		switch(choice){
			case 1:
				print_details(students, student_total);
				break;
			case 2:
      average(students,student_total);
      break;
      case 3:
      cout<<"sort by (1)grade or (2)name"<<endl;
      cin>>choice;
      switch(choice)
      {
        case 1:
        sort_student_grades(students, student_total);
        break;
        case 2:
        sort_student_names(students, student_total);
        break;
      }
      case 4:
      
      cout << "Enter student's grade you want to look for: ";
      cin >> search; 
      cout << endl;
				index = search_s(students, student_total, search);
					if(index == -1)
                    {
						cout << "No student found ";
                        cout << endl;
					} 
				break;
        case 5: 
			find_max(students,student_total);
				break;
			case 6: 
			updateFile();
    }
  } while (choice != 7);
return 0;
}

int readFile(stu students[])
{
	int i = 0;

	string line;
	ifstream inFile("student_details.txt");

	while (!inFile.eof())
  {
  inFile >> students[i].name >> students[i].id >>students[i].grade; 
  i++;
  }

inFile.close();
return i;
}

void updateFile()
{
  string in_name;
  int in_id;
  float in_grade;

  ofstream outFile;
	outFile.open("student_details.txt",ios_base::app);

  cout<<"Enter Details"<<endl;
  cout<<"Name: ";
  cin>>in_name;

  cout<<"ID: ";
  cin>>in_id;

  cout<<"Grade: ";
  cin>>in_grade;

  outFile<<endl<<in_name<<" "<<in_id<<" "<<in_grade;
  cout<<"Succesfull Updated File"<<endl;
outFile.close();
}

void sort_student_grades(stu students[], int student_total)
{
  int i = 0;
  int j= i+1;
  for(i=0;i<student_total-1;i++) 
  {
		for(j = i+1;j<student_total;j++)
    {			
			if(students[i].grade > students[j].grade)
      { 
				swap(students[i].name , students[j].name);
				swap(students[i].id , students[j].id);
        swap(students[i].grade , students[j].grade);
			}
		}
  }
 print_details(students, student_total);
}

void sort_student_names(stu students[], int student_total)
{
  int i = 0;
  int j= i+1;
  for(i=0;i<student_total-1;i++) 
  {
		for(j = i+1;j<student_total;j++)
    {			
			if(students[i].name > students[j].name)
      { 
				swap(students[i].name , students[j].name);
				swap(students[i].id , students[j].id);
        swap(students[i].grade , students[j].grade);
			}
		}
  }
 print_details(students, student_total);
}

void print_details(stu students[], int student_total)
{
  int i = 0;
   for(i=0;i<student_total;i++)
    {
        cout <<"Name: " << students[i].name << endl;
        cout <<"ID: " << students[i].id << endl;
 
        cout <<"Grade: " <<students[i].grade << endl;
        cout << endl;		
	  }
}

int search_s(stu students[], int student_total, string search)
{
  int i;
		for(i=0;i<student_total;i++) 
    {
        if (students[i].name == search)
        {	
            cout<<"Name: " << students[i].name << endl;
            cout <<"ID: " << students[i].id << endl;
            cout <<"Grade: " <<students[i].grade << endl;
            cout << endl;
            break;
        } 	
	}
    return 1;
}

void find_max(stu students[],int student_total)
{
  float max=0;
  int i = 0;
	for(i =0;i<student_total;i++)
    {
		if(students[i].grade > max)
		max = students[i].grade;
	}
	cout << "Highest Grade is: " << max << endl << endl;
}

void average(stu students[], int student_total)        
{
	float avg;
  float sum=0;
  int i;
	for(int i=0;i<student_total;i++)
    {
		sum += students[i].grade;
	}
	avg = sum /student_total;
	cout << "Average Grade is: " << avg << endl << endl;
}

void menu()
{
  	cout << "(1) Display students	" << endl;
		cout << "(2) Calculate average " << endl;
		cout << "(3) Sort the students' details " << endl;
		cout << "(4) Search for particular student's grade " << endl;
		cout << "(5) Find maximum " << endl;
		cout << "(6) Add new student to the Record" << endl;
		cout << "(7) Quit Program" << endl;
}
