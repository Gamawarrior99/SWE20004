#include<iostream>	//access input output related code
using namespace std;	//use the C++ standard namespace which includes cin and cout

int main() {	//declare the main function
    int n = 5;  //declare an int variable n and set it's value to 5
    for(int i = 1; i <=n; i++) {   //repeat n times
        cout << "Hello world!" << endl;	//display message on the screen
    }
	return 0;	//terminate main thereby the program
}