#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>

#define SIZE 7
#define WIN 8350

using namespace std;

int random_Number_Generator();
void Borders();

int main()
{
	srand(time(NULL));
	int roll[SIZE][SIZE] = {0};
	int i;
	int j;
	int dice1;
	int dice2;
	int total = 0;

	for (i = 0;i <= 50000; i++)
	{
		dice1 = random_Number_Generator();
		dice2 = random_Number_Generator();

		roll[dice1][dice2]+=1;
	}

	Borders();
	for (i = 1;i < SIZE; i++)
	{
		cout << " | ";
		for (j = 1;j < SIZE; j++)
		{
			cout << setw(5) << roll[j][i] << " | ";
		}
		cout << endl;
	}
	Borders();

	cout << "The Sum of The Diagonal Elements are: " << endl << endl;

	for (i = 1;i < SIZE;i++)
	{
		cout << roll[i][i] << " +" << endl;
		total += roll[i][i];
	}
	cout << "___________" << endl;
	cout << total << endl;

	if (total >= WIN)
	{
		cout << total << "is Greater than " << WIN << " The Player Has Won the game :)" << endl;
	}
	else
	{
		cout << total << "is Less than " << WIN << " The Player Has Lost the game :(" << endl;
	}

	return 0;
}

int random_Number_Generator()
{
	return (rand()%6+1);
}

void Borders()
{
	int i = 0;
	
	cout << " |";

	for (i = 0; i < 40;i+=7)
	{
		
		cout << " " << setw(7) << setfill(' ') << setw(7) << setfill('-');
		cout << " |";
	}

	cout << endl;
	cout << setfill(' ');

}

