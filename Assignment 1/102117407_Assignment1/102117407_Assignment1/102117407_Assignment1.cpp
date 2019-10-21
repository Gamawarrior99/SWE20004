/*Name: Gamaliel D'mello
Student id: 102117407
File name: 102117407_Assignment1
Purpose: A console Application that takes in a number that has digits between 2 and 8 and encodes and decodes it
*/

#include <iostream>
#include <string>
#include <cmath>

//Function decleration
int menu();
int getNum();
int numSeperator(int number);
int encoder(int number, int digit, bool ExtraProtect);
int decoder(int encoded, int digit, bool ExtraProtect);
int numFind(int Num);

using namespace std;

/*Main gets users Choice and 
does validation and calls functions to encode
and/pr decode the value*/
int main()
{
	const int ENDCODE = -1;
	int choice, userNum, digit, i = 0, encoded, decoded;
	char ans;
	bool extraProtect, isAns = false;
	
	do 
	{
		extraProtect = false;
		choice = menu();

		if (choice == 1)
		{
			userNum = getNum();
			digit = numSeperator(userNum);
			
			if (digit == 8)
			{
				cout << "Do you want Extra protection (y or n): ";
				cin >> ans;

				do
				{
					if (tolower(ans) == 'y')
					{
						extraProtect = true;
						encoded = encoder(userNum, digit, extraProtect);
						isAns = true;
					}
					else if (tolower(ans) == 'n')
					{
						encoded = encoder(userNum, digit, extraProtect);
						isAns = true;
					}
					else
					{
						cout << "Please make a choice based on the following(y or n): ";
						cin >> ans;
					}
				} while (isAns == false);
			}
			else
			{
				encoded = encoder(userNum, digit, extraProtect);
			}
			
			cout << "Do you want to Decode (y or n): ";
			cin >> ans;

			do
			{
				if (tolower(ans) == 'y')
				{
					decoded = decoder(encoded, digit, extraProtect);
					cout << "Digits Contained " << digit << endl;
					cout << "Encoced value is: " << encoded << endl;
					cout << "decoded value is: " << decoded << endl;
					isAns = true;
				}
				else if (tolower(ans) == 'n')
				{
					cout << "Digits Contained " << digit << endl;
					cout << "Encoced value is: " << encoded << endl;
					isAns = true;
				}
				else
				{
					cout << "Please make a choice based on the following(y or n): ";
					cin >> ans;
				}
			} while (isAns == false);
		}
		else if (choice == ENDCODE)
		{
			cout << "Program has ended Sucessfully";
		}
		else
		{
			cout << "This is an invalid Choice Please input a different Choice" << endl << endl;
		}
	} while (!(choice == ENDCODE));

	return 0;
}

/*Menu to give user the options*/
int menu()
{
	unsigned int choice;
	cout << "Enter 1 to Input your Number" << endl;
	cout << "Enter -1 to exit program" << endl;

	cin >> choice;

	return choice;
}

/*gets the User Number and checks if it is
valid (Between 2 and 8 digits)*/
int getNum()
{
	unsigned int number;
	bool isError = true;

	cout << "Enter Your value (range 2 - 8 digits): ";
	cin >> number;

	do
	{
		if ((number >= 0) && (number <= 9))
		{
			cout << "Please Enter a double Digit Number: ";
			cin >> number;
		}
		else if (number > 99999999)
		{
			cout << "Number has to be less than 8 digits: ";
			cin >> number;
		}
		else
		{
			isError = false;
		}
	} while (isError);

	return number;
}

int numSeperator(int number)
{
	int digit = 0;

	while (!(number == 0))
	{
		number /= 10;
		digit += 1;
	}

	return digit;
}

/*Get the user value and the amount of digits
if the digit is 2 or 3 swap the numbers if it is 
4+ get mod of Number *3. extraprotect 
swaps numbers after doing the calculation*/
int encoder(int number, int digit, bool extraProtetion)
{
	int temp = 0, i = digit, num, append = 0;
	int *numArray;
	numArray = new int[digit];

	while (!(number == 0))
	{
		num = number % 10;
		numArray[i-1] = num;
		number /= 10;
		i--;
	}

	if (digit == 2)
	{
		temp = numArray[0];
		numArray[0] = numArray[1];
		numArray[1] = temp;

		for (i = 0; i < digit; i++)
		{
			append = 10 * append + numArray[i];
		}
	}
	else if (digit == 3)
	{
		temp = numArray[0];
		numArray[0] = numArray[2];
		numArray[2] = temp;
		
		for (i = 0; i < digit; i++)
		{
			append = 10 * append + numArray[i];
		}
	}
	else if ((digit >= 4) && (digit <= 8))
	{
		if ((digit == 8) && (extraProtetion == true))
		{
			for (i = 0;i < digit;i++)
			{
				numArray[i] = (numArray[i] * 3) % 10;
			}

			temp = numArray[0];
			numArray[0] = numArray[7];
			numArray[7] = temp;

			temp = numArray[1];
			numArray[1] = numArray[6];
			numArray[6] = temp;

			temp = numArray[2];
			numArray[2] = numArray[5];
			numArray[5] = temp;

			temp = numArray[3];
			numArray[3] = numArray[4];
			numArray[4] = temp;
		}
		else
		{
			for (i = 0; i < digit; i++)
			{
				numArray[i] = (numArray[i] * 3) % 10;
			}
		}

		for (i = 0; i < digit; i++)
		{
			append = 10 * append + numArray[i];
		}
	}
	else
	{
		cout << "This is not a valid Digit Range please try inputting a number between 2 - 8" << endl;
	}

	return append;
}

/*This Fuction Gets the encoded value and seperates it into
induvdual digits and depening on if Extra protect is chosen
it willl first swap the numbers and then call the function
that get the unique number*/

int decoder(int encoded, int digit, bool ExtraProtect)
{
	int temp = 0, i = digit, num, append = 0;
	int* numArray;
	numArray = new int[digit];
	 
	while (!(encoded == 0))
	{
		num = encoded % 10;
		numArray[i-1] = num;
		encoded /= 10;
		i--;
	}

	cout << endl;

	if (digit == 2)
	{
		temp = numArray[1];
		numArray[1] = numArray[0];
		numArray[0] = temp;

		for (i = 0; i < digit; i++)
		{
			append = 10 * append + numArray[i];
		}
	}
	else if (digit == 3)
	{
		temp = numArray[2];
		numArray[2] = numArray[0];
		numArray[0] = temp;

		for (i = 0; i < digit; i++)
		{
			append = 10 * append + numArray[i];
		}
	}
	else if ((digit >= 4) && (digit <= 8))
	{
		if ((digit == 8) && (ExtraProtect == true))
		{
			temp = numArray[7];
			numArray[7] = numArray[0];
			numArray[0] = temp;

			temp = numArray[6];
			numArray[6] = numArray[1];
			numArray[1] = temp;

			temp = numArray[5];
			numArray[5] = numArray[2];
			numArray[2] = temp;

			temp = numArray[4];
			numArray[4] = numArray[3];
			numArray[3] = temp;

			for (i = 0;i < digit;i++)
			{
				numArray[i] = numFind(numArray[i]);
			}
		}
		else
		{
			for (i = 0;i < digit;i++)
			{
				numArray[i] = numFind(numArray[i]);
			} 
		}

		for (i = 0;i < digit;i++)
		{
			append = 10 * append + numArray[i];
		}
	}
	else
	{
		cout << "This is not a valid Digit Range please try inputting a number between 2 - 8" << endl;
	}
	return append;
}

//switch case statement that recieves the value from of the encoded number and decodes it as each number is unique
int numFind(int num) 
{
	switch (num) {
	case 1: 
		return 7;
		break; 
	case 2: 
		return 4;
		break;
	case 3:
		return 1;
		break;
	case 4:
		return 8;
		break;
	case 5:
		return 5;
		break;
	case 6:
		return 2;
		break;
	case 7:
		return 9;
		break;
	case 8:
		return 6;
		break;
	case 9:
		return 3;
		break;
	default:
		return 0;
	}
}