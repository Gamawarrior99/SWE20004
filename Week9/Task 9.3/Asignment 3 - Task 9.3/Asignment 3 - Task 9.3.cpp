// TSD - Assignent 3 - Task 9.3		 //
// STUDENT NAME: ANTHONY DUMITRU     //
// STUDENT ID  : 100585921           //

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
//Enums
enum genre { pop, Jazz, Classic };
//Structs
typedef struct album
{
	string album_name;
	genre kind;
	int track_number;
	string tracks[5];
	string tracklocation;
}AlbumDetails;

//Functions
bool menu(vector<AlbumDetails> Albums);
void add_album(vector<AlbumDetails> Albums);

//Main
int main()
{
	vector<AlbumDetails> Albums;
	bool loop_menu = true;
	//Loop Through menus whats bool is true
	do
	{
		loop_menu = menu(Albums);
	} while (loop_menu);
}

bool menu(vector<AlbumDetails> Albums)
{
	//Initialiase Menu Selection Variable
	int option;

	//Menu Heading
	cout << "--------------" << endl;
	cout << "     Menu     " << endl;
	cout << "--------------" << endl << endl;
	//Prompt Options
	cout << "Option 1 - Enter Album Detail" << endl;
	cout << "Option 2 - Display Album Details" << endl;
	cout << "Option 3 - Select Track To Play" << endl;
	cout << "Option 4 - Quit" << endl << endl;
	cout << "Response: ";
	//Get Input
	cin >> option;
	//Decorative - Line Spacing
	cout << endl << endl;

	switch (option)
	{
	case 1:
		add_album(Albums);
		break;
	case 2:
		cout << "print_all_album()" << endl << endl;
		break;
	case 3:
		cout << "select_track_to_play()" << endl << endl;
		break;
	case 4:
		return 0;
		break;
	}


}

void add_album(vector<AlbumDetails> Albums)
{
	string AlbName_Input;
	//Var - Number Of Albums To Enter
	int num_albums;
	//Var - Number Of Tracks To Enter
	int no_tracks;
	//Menu Heading
	cout << "-------------------------------" << endl;
	cout << " Option 1 - Enter Album Detail " << endl;
	cout << "-------------------------------" << endl << endl;
	do
	{
		cin.clear();
		cin.ignore();
		//Prompt Num Albums To Enter
		cout << "How Many Albums Would You Like to Enter : ";
		cin >> num_albums;
		if (cin.fail() || (num_albums < 1))
		{
			cout << "Error: Incorrect Input " << endl;
			cout << "Only Accepts Integers Greater Than 1" << endl << endl;
		}
	} while (cin.fail());

	//Prompt Album Details, Per Album
	for (int i = 0; i < num_albums; i++)
	{
		//Prompt Options
		cout << "Album Num. " << setw(2) << (i + 1) << endl;
		cout << "-------------" << endl << endl;
		cout << " - Album Name  : " << endl;
		cin >> AlbName_Input;
		Albums.push_back({ AlbName_Input });
		/*cout << " - Album Genre : " << endl;
		cin >> Albums[i].kind;

		do
		{
			cin.clear();
			cin.ignore();
			cout << "Number Of Tracks : ";
			cin >> no_tracks;

			for (int j = 0; j < no_tracks; j++)
			{
				cout << "Track Num. " << setw(2) << (j + 1) << endl;
				cout << " -  Track Name : " << endl;
				cin >> Albums[i].tracks[j];

			}
			cout << " -  Track Folder Location : " << endl;
			cin >> Albums[i].tracklocation;*/
			/*} while (cin.fail() || (no_tracks < 1));*/
	}
}