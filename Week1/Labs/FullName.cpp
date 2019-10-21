#include<iostream>	//access input output related code
#include<string>	//access string related code
using namespace std; 	//use the C++ standard namespace which includes cin and cout

int main() {	//declare the main function
	string first, second;	//declare two string variables to store names
	cout << "Welcome to the full name program:"<< endl;	//welocming message
	cout << "Enter you first name:"<< endl;	//prompt user for first name
	cin >> first;	//get first name
	cout << "Enter you second name:"<< endl;	//prompt user for second name
	cin >> second;	//get second name
	cout << "Hello " << first << " " << second << "!"<< endl;	//greet the user
	return 0;	//terminate main thereby the program
}