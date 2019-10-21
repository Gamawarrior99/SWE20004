#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int x,y,z,ans;
    cout << "Enter First value"<<endl;
    cin>> x;
    cout << "Enter Second value"<<endl;
    cin>> y;
    cout << "Enter Third value"<<endl;
    cin>> z;
    ans = x+y+z;
    cout<< "The sum of "<< x <<"+" <<y <<"+" <<z << " is "<<ans<<endl;

    return 0;
}