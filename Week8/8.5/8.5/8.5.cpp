#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void readfile(float* prices, int size);
void printfile(float* prices, int size);
void writefile(float* prices, int size);

int main()
{
	const int size = 20;
	float price[size] = {0};

	readfile(price, size);
	printfile(price, size);
	writefile(price, size);
}

void readfile(float* prices, int size)
{
	int x;
	int i;
	float p;
	int j = 1;
	ifstream inFile;

	inFile.open("price.dat");
	if (!inFile)
	{
		cout << "Unable to open file";
	}

	inFile >> x;
	prices[0] = x;
	x *= 2;

	for (i = 1;i <= x;i++)
	{
		inFile >> p;
		if (i % 2 == 0)
		{
			prices[j] = p;
			j++;
		}
	}
	
	inFile.close();
}

void printfile(float* prices, int size)
{
	int i = 0;

	for (i = 1;i <= prices[0];i++)
	{
		cout << fixed<<setprecision(2) <<prices[i] << " " << endl;
	}
}

void writefile(float* prices, int size)
{
	int i;
	float min = prices[1];
	float max = 0;
	float average = 0;

	for (i = 1;i <= prices[0];i ++)
	{
		average += prices[i];

		if (prices[i] < min)
		{
			min = prices[i];
		}

		if (prices[i] > max)
		{
			max = prices[i];
		}
	}

	average /= prices[0];

	cout << "Number of Price Readings: " << prices[0]<<endl;
	cout << "Maximum Price: " <<fixed<<setprecision(2)<< setprecision(2)<<max << endl;
	cout << "Minimum Price: " <<fixed<< setprecision(2)<<min << endl;
	cout << "Average Price: " <<fixed<< setprecision(2) <<average << endl;

	ofstream inFile;

	inFile.open("output.dat");
	if (!inFile)
	{
		cout << "Unable to open file";
	}

	inFile << "Number of Price Readings: " << prices[0] << endl<< "Maximum Price: " << fixed << setprecision(2)<<
		setprecision(2) << max << endl<<"Minimum Price: " << fixed << setprecision(2) << min << endl<< "Average Price: " <<
		fixed << setprecision(2) << average << endl;
	cout << "\nSuccesfully written to file"<<endl;
	inFile.close();
}