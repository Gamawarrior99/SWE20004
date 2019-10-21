/*Name: Gamaliel D'mello
Student id: 102117407
File name: 102117407_Assignment2
Purpose: Using a version of luhn's algorithm to determine
		 weather a credit card is valid or not
*/

#include<iostream>
#include<string>

#define SIZE 20
#define END -1

using namespace std;

//Function Prototype
int sum1(int card[], int count);
int sum2(int card[], int count);
int getnum();
void print(int card[], int count);
void checksum(int card[], int count, int total);

//Main calls other functions and 
//has a loop to save the digits 
// into the array
int main()
{
	int i = 0;
	int card[SIZE];
	int count = 0;
	int even;
	int odd;

	cout << "enter -1 when finished entering card number" << endl;
	cout << "Enter Card number: " << endl;
	for (i = 0;i < SIZE;i++)
	{
		card[i] = getnum();
		if (card[i] != END)
		{
			count++;
		}
		else
		{
			break;
		}
	}

	print(card, count);

	even = sum1(card, count);
	cout << "Sum 1 is: " << even << endl;

	odd = sum2(card, count);
	cout << "Sum 2 is: " << odd << endl;

	checksum(card, count, even + odd);

	return 0;
}

//Getnum Is a used to Validate if a number is within
//the limits and if it is it will return the value
//to main where its been called
int getnum()
{
	int value = 0;
	bool check;

	do
	{
		cin >> value;
		if ((value >= 0) && (value <= 9)||value == END)
		{
			check = false;
		}
		else
		{
			cout << value << "is Not A valid Number Please re-enter: ";
			check = true;
		}
	} while (check);
	return value;
}

//the print Function gets the array and its length 
//to print the contents of the array to the screen
void print(int card[], int count)
{
	int i = 0;
	cout << "Card Number is: ";

	for (i = 0;i < count;i++)
	{
		cout << card[i];
	}

	cout << endl;
}

//Sum 1 gets the rightmost value after the last digit
//and goes trough the array and adds the values
//to be returned to main
int sum1(int card[], int count)
{
	int i;
	int num;
	int even = 0;

	cout << "The Numbers for Sum 1 are: ";

	if (count % 2 == 0) //if lenght of array is even
	{
		for (i = 0;i < count - 1;i += 2) //starts at 1st digit
		{
			cout << card[i] << " ";
			num = card[i];
			num *= 2;//doubles the number
			if (num > 9)
			{
				num -= 9;//takes away 9 as any single digit number thats
						 // been doubled and the value is greater than 
						 // 9, its values when seperated and added together
						 // is the same as taking away 9
			}

			even += num;
		}
	}
	else
	{
		for (i = 1;i < count - 1;i += 2)//starts at the 2nd digit
		{
			cout << card[i] << " ";
			num = card[i];
			num *= 2;
			if (num > 9)
			{
				num -= 9;
			}

			even += num;
		}
	}
	cout << endl;
	return even;
}

//sum 2 gets every 2nd from the from the rightmost value
//and returns the value to main
int sum2(int card[], int count)
{
	int i = 0;
	int odd = 0;

	cout << "The Numbers for Sum 2 Are: ";

	if (count % 2 == 0)
	{
		for (i = 1;i < count - 1;i += 2)
		{
			cout << card[i] << " ";
			odd += card[i];
		}
	}
	else
	{
		for (i = 0;i < count - 1;i += 2)
		{
			cout << card[i] << " ";
			odd += card[i];
		}
	}

	cout << endl;
	return odd;
}

//Checksum gets the checksum vaue and uses that to test if 
//a card is valid depending on checksum and the last digit 
//it will print an appropriate message
void checksum(int card[], int count, int total)
{
	int check = 0;
	check = (total * 9) % 10;

	cout << "Check Sum is: " << check << endl;
	cout << "Last Digit is: " << card[count - 1] << endl;

	if (check == card[count - 1])
	{
		cout << "Check Sum: " << check << " And Last Digit: " << card[count - 1] << " Are the same: Valid Credit Card Number" << endl;
	}
	else
	{
		cout << "Check Sum: " << check << " And Last Digit: " << card[count - 1] << " Are not the same: Invalid Credit Card Number" << endl;
	}
}