#include<iostream>
#include<string>
#include <cstdlib>
#include<ctime>

int ActualNum();
bool Check(unsigned int Count, unsigned int Actual);
void Msg(unsigned int Count);

using namespace std;

int main()
{
	bool Eventloop = true;
	while (Eventloop)
	{
		bool Ans = true, error = true;
		unsigned int guess;
		int Count = 0, Actual = 0;

		Actual = ActualNum();

		cout << "I have a number between 1 and 1000." << endl;
		cout << "Can you guess my number?" << endl;
		cout << "Please type your first guess" << endl;

		cin >> guess;

		while (Ans)
		{
			bool Checker;
			Checker = Check(guess, Actual);
			Count = Count + 1;

			if (Checker == false)
			{
				cin >> guess;
			}

			if (Checker == true)
			{
				Msg(Count);

				char choice;

				cout << "Excellent! You guessed the number!" << endl;
				cout << "Would you like to play again? (y or n)" << endl;
				cin >> choice;

				if (choice == 'y')
				{
					Ans = false;
				}
				if (choice == 'n')
				{
					Ans = false;
					Eventloop = false;
				}

			}
		}
	}
	return 0;
}

int ActualNum()
{
	srand(time(NULL));
	return rand() % 1000 + 1;
}

bool Check(unsigned int guess, unsigned int Actual)
{
	string message;

	if (guess < Actual)
	{
		cout << "Too Low" << endl;
	}
	if (guess > Actual)
	{
		cout << "Too High" << endl;
	}
	if (guess == Actual)
	{
		return true;
	}
	return false;
}

void Msg(unsigned int Count)
{
	if (Count < 10)
	{
		cout << "Either you know the secret or you got lucky!" << endl;
	}
	else if (Count == 10)
	{
		cout << "Ahah! You know the secret!" << endl;
	}
	else if (Count > 10)
	{
		cout << "You should be able to do better!" << endl;
	}

}