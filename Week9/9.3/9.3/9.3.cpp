#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum genre
{
	Pop, Jazz, Classic, Rock
};

struct album
{
	string album_name;
	genre kind;
	int track_number;
	string tracks[5];
	string tracklocation;
};
typedef struct album albums;

int menu();
void add_album(vector<albums>* album);
void print_album(vector<albums> album);

int main()
{
	int choice;
	vector<albums> album;
	bool exit = false;

	do
	{
		choice = menu();
		switch (choice)
		{
			case 1: 
				add_album(&album);
				break;
			case 2: 
				print_album(album);
				break;
			case 4: 
				exit = true;
				break;
			default: 
				cout << "Error exit code 1: Invalid input";
		}
	} while (exit == false);
	return 0;
}

int menu()
{
	int choice = 0;
	cout << "Enter 1 to Add an album" << endl;
	cout << "Enter 2 to Display all albums" << endl;
	cout << "Enter 3 to Select a track to be played" << endl;
	cout << "Enter 4 to exit the program" << endl;
	cout << "what do you want to do: ";
	do
	{
		cin >> choice;
		if (choice < 0 && choice >=4)
		{
			choice = 0;
		}
	} while (choice == 0);

	return choice;
}

void add_album(vector<albums>* album)
{
	int num = 0;
	int i = 0;
	int x = 0;
	int kind = 0;
	genre genre_kind;
	albums data;

	cout << "Enter The Amount of albums you want to add: ";
	cin >> num;
	for (i = 0; i < num; i++)
	{
		cout << "Enter Album Name: ";
		cin >> data.album_name;

		cout << "Enter genre (0 -> pop, 1-> Jazz, 2 -> classic, 3 -> Rock): ";
		cin >> kind;
		switch(kind)
		{
			case 1:
				data.kind = Jazz;
				break;
			case 2:
				data.kind = Classic;
				break;
			case 3:
				data.kind = Rock;
				break;
			default: 
				data.kind = Pop;
				break;
		}
		
		cout << "Enter Number of tracks in the album: ";
		do {
			cin >> data.track_number;
		} while (!(data.track_number >= 1 || data.track_number <= 5));

		cout << "Enter Tracks" << endl;
		for (x = 0; x < data.track_number; x++)
		{
			cin >> data.tracks[x];
		}
		
		cout << "Enter Album File Location: ";
		cin >> data.tracklocation;

		album->push_back(data);
	}
}

void print_album(vector<albums> album)
{
	int i = 0;
	int x = 0;
	for (i = 0; i < album.size(); i++)
	{
		cout << "Name of the Album is : " << album[i].album_name << endl;
		switch (album[i].kind)
		{
			case 1: cout << "Genre of Album is: " << album[i].kind << endl;
		}
		
		cout << "NO. of tracks : " << album[i].track_number << endl;
		for (x = 0; x < album[i].track_number; x++)
		{
			cout << album[i].tracks[x]<<endl;
		}
		cout << "Track are loacted at: " << album[i].tracklocation << endl;
	}
}