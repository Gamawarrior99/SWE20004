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
    ans = x*y*z;
    cout<< "The product of "<< x <<"x" <<y <<"x" <<z << " is "<<ans<<endl;

    return 0;
}