#include <iostream>

using namespace std;

void reorder(int* a, int* b, int* c);

int main()
{
	int a;
	int b;
	int c;

	cout << "Enter First Number: ";
	cin >> a;

	cout << "Enter Second Number: ";
	cin >> b;

	cout << "Enter Last Number: ";
	cin >> c;

	reorder(&a, &b, &c);

	cout << "Values Re-ordered are: " << a << " " << b << " " << c << endl;
}

void reorder(int* a, int* b, int* c)
{
	if (*a > *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	if (*a > *c)
	{
		int tmp = *a;
		*a = *c;
		*c = tmp;
	}

	if (*b > * c)
	{
		int tmp = *b;
		*b = *c;
		*c = tmp;
	}
}
