#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    const float PI = 3.14159;
    float I = 0, E, R, F, L, C, Fr, max = 1;
    bool ans = true;
    cout<<"This program is used to calculate the current flowing through an AC circut"<<endl;

    cout<<"Please input the Electromotive Force(Volts)"<<endl;
    cin>>E;

    cout<<"The resistance (OHMS)"<<endl;
    cin>>R;

    cout<<"Frequency of Current (Hertz)"<<endl;
    cin>>F;

    cout<<"Inducatance (Henrys)"<<endl;
    cin>>L;

    cout<<"The Capacitance (Farads)"<<endl;
    cin>>C;

    I = E/sqrt(pow(R, 2)+pow((2*PI*F*L)-(1/(2*PI*F*C)), 2));

    cout<<"The Current is "<<I<<" Amps"<<endl;

    cout<<"Finding when the current is at max depending on frequencies"<<endl;
   while(ans) 
    {
        Fr = 1/(2*PI*sqrt((L*C)));
        I = E/sqrt(pow(R, 2)+pow((2*PI*Fr*L)-(1/(2*PI*Fr*C)), 2));
        if (I == max)
        {
            ans = false;
        }
    }
    cout<<"Max Current is 1.0 Amps when the frequency is "<<Fr<<endl;
    return 0;
}