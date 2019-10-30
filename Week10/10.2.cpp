#include <iostream>
#include <string>

using namespace std;

struct student
{
	char letter;
	struct student* next;
};

typedef struct student Student;
typedef Student* Studentptr;

int main()
{
	Studentptr NewPtr, StartPtr, CurrentPtr, PreviousPtr;
	StartPtr = NULL;

	NewPtr = new student;
	if (NewPtr != NULL)
	{
		cin >> NewPtr->letter;
		NewPtr->next = NULL;
		PreviousPtr = NULL;
		CurrentPtr = StartPtr;
		while (CurrentPtr != NULL && NewPtr->letter > CurrentPtr->letter)
		{
			PreviousPtr = CurrentPtr;
			CurrentPtr = CurrentPtr->next;
		}

		if (PreviousPtr == NULL)
		{
			NewPtr->next = StartPtr;
			StartPtr = NewPtr;
		}
		else
		{
			PreviousPtr->next = NewPtr;
			NewPtr->next = CurrentPtr;
		} 
	}
	else
	{
		cout << NewPtr->letter << " not inserted. No memory available.\n";
	} 

  NewPtr = new student;
	if (NewPtr != NULL)
	{
		cin >> NewPtr->letter;
		NewPtr->next = NULL;
		PreviousPtr = NULL;
		CurrentPtr = StartPtr;
		while (CurrentPtr != NULL && NewPtr->letter > CurrentPtr->letter)
		{
			PreviousPtr = CurrentPtr;
			CurrentPtr = CurrentPtr->next;
		}

		if (PreviousPtr == NULL)
		{
			NewPtr->next = StartPtr;
			StartPtr = NewPtr;
		}
		else
		{
			PreviousPtr->next = NewPtr;
			NewPtr->next = CurrentPtr;
		} 
	}
	else
	{
		cout << NewPtr->letter << " not inserted. No memory available.\n";
	} 

NewPtr = new student;
	if (NewPtr != NULL)
	{
		cin >> NewPtr->letter;
		NewPtr->next = NULL;
		PreviousPtr = NULL;
		CurrentPtr = StartPtr;
		while (CurrentPtr != NULL && NewPtr->letter > CurrentPtr->letter)
		{
			PreviousPtr = CurrentPtr;
			CurrentPtr = CurrentPtr->next;
		}

		if (PreviousPtr == NULL)
		{
			NewPtr->next = StartPtr;
			StartPtr = NewPtr;
		}
		else
		{
			PreviousPtr->next = NewPtr;
			NewPtr->next = CurrentPtr;
		} 
	}
	else
	{
		cout << NewPtr->letter << " not inserted. No memory available.\n";
	} 

  NewPtr = new student;
	if (NewPtr != NULL)
	{
		cin >> NewPtr->letter;
		NewPtr->next = NULL;
		PreviousPtr = NULL;
		CurrentPtr = StartPtr;
		while (CurrentPtr != NULL && NewPtr->letter > CurrentPtr->letter)
		{
			PreviousPtr = CurrentPtr;
			CurrentPtr = CurrentPtr->next;
		}

		if (PreviousPtr == NULL)
		{
			NewPtr->next = StartPtr;
			StartPtr = NewPtr;
		}
		else
		{
			PreviousPtr->next = NewPtr;
			NewPtr->next = CurrentPtr;
		} 
	}
	else
	{
		cout << NewPtr->letter << " not inserted. No memory available.\n";
	} 

  NewPtr = new student;
	if (NewPtr != NULL)
	{
		cin >> NewPtr->letter;
		NewPtr->next = NULL;
		PreviousPtr = NULL;
		CurrentPtr = StartPtr;
		while (CurrentPtr != NULL && NewPtr->letter > CurrentPtr->letter)
		{
			PreviousPtr = CurrentPtr;
			CurrentPtr = CurrentPtr->next;
		}

		if (PreviousPtr == NULL)
		{
			NewPtr->next = StartPtr;
			StartPtr = NewPtr;
		}
		else
		{
			PreviousPtr->next = NewPtr;
			NewPtr->next = CurrentPtr;
		} 
	}
	else
	{
		cout << NewPtr->letter << " not inserted. No memory available.\n";
	} 

	cout << StartPtr->letter;

	CurrentPtr = StartPtr->next;
	cout << CurrentPtr->letter;

	CurrentPtr = CurrentPtr->next;
	cout << CurrentPtr->letter;

  CurrentPtr = CurrentPtr->next;
	cout << CurrentPtr->letter;

  CurrentPtr = CurrentPtr->next;
	cout << CurrentPtr->letter;

  

	return 0;
}

