#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string name;
    int count, i = 0;

    cout<<"Type in your name"<<endl;
    cin>> name;
    cout<< "Welcome to my world! "<<name<<endl;
    cout<< "How Many Greetings"<<endl;
    cin>> count;
        for(i=0;i<count;i++)
            {
                cout<< "Welcome to my world! "<<name<<endl;
            }


    return 0;

}