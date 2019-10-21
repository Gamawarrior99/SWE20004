#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    float Voltage_Gain = 0, f, n;
    cout<<"Enter the frequency"<<endl;
    cin>>f;
    cout<<"Enter the Number of stages in the amplifier"<<endl;
    cin>>n;
    Voltage_Gain = pow(275/sqrt(pow(23,2)+(0.5*pow(f,2))), n);

    cout<<"At Frequency of "<<f<<" hertz, the Voltage gain is "<<Voltage_Gain<<endl;
     return 0;
}
