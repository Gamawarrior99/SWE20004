#include<iomanip>
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

bool validateString(string s);
bool validateSize(string s);

int main()
{
    string SerialNumber, username, EmpName, MAC;
    char PcType;
    unsigned int cores;
    float CPUspeed;
    int IPV4_address[4] = {0};
    bool ValidString = true, validsize = true, validnum = true ;

//PC Serial Number
    cout<<"Please enter your PC Serial Number (AlphaNumeric no spaces): ";
    getline(cin, SerialNumber);
    ValidString = validateString(SerialNumber);
    validsize = validateSize(SerialNumber);

    while(ValidString == false||validsize == false)
    {
        if (ValidString == false)
        {
            cout<<"This is an invalid statement, Please follow the given format (AlphaNumeric no spaces): ";
            getline(cin, SerialNumber);
            ValidString = validateString(SerialNumber);
        }

        if (validsize == false)
            {
                cout<<"This is an invalid statement, Please follow the given format (AlphaNumeric no spaces): ";
                getline(cin, SerialNumber);
                validsize = validateSize(SerialNumber);
            }

    } 
//Username
cout<<"Please enter your UserName (AlphaNumeric no spaces): ";
    getline(cin, username);
    ValidString = validateString(username);
    validsize = validateSize(username);

    while(ValidString == false||validsize == false)
    {
        if (ValidString == false)
        {
            cout<<"This is an invalid statement, Please follow the given format (AlphaNumeric no spaces): ";
            getline(cin, username);
            ValidString = validateString(username);
        }

        if (validsize == false)
            {
                cout<<"This is an invalid statement, Please follow the given format (AlphaNumeric no spaces): ";
                getline(cin, username);
                validsize = validateSize(username);
            }

    }

    //Emp Name
    cout<<"Please Enter your name: ";
    getline(cin, EmpName);
    
    //PC type
    cout<<"Please Enter your PC type(S=server, D=desktop, L=laptop, T=tablet, P=phone): ";
    cin>>PcType;

    //Number of Cores
    cout<<"Please Enter the number of cores: ";
    cin>>cores;

    //CPU frequency
    cout<<"Please enter the CPU speed: ";
    cin>>CPUspeed;

    //MAC address
    cout<<"Please Enter your mac address: ";
    cin>>MAC;
    if (MAC.length() != 16)
        {
                cout<<"This is an invalid statement, Please follow the given format (16 Digit Hex MAC Address): ";
                cin>>MAC;
                validsize = true;
        }
    while(validsize == false)
    {
         cout<<"This is an invalid statement, Please follow the given format (16 Digit Hex MAC Address): ";
         cin>>MAC;
  
    } 

    //IP Address
	cout << "Please enter the IPV4 address without the dots (e.g. 111 222 333 444):" << endl;
	for(int i = 0;i<4;i++)
    {
        cin>>IPV4_address[i];
    }

    cout<< setw(50) << setfill('-') << "+" << endl;
	cout<< "| User: " << username << " | Employee: " << EmpName << " | Serial: " << SerialNumber <<" |"<< endl;
	cout<< setw(50) << setfill('-') << "+" << endl;
	cout<< "| PC Type: " << PcType << " | Cores: " << cores << " | CPU Speed: " << CPUspeed << " | MAC:" << MAC << " | IP: ";
	for (int i = 0; i < 4; i++)
	{
		cout << IPV4_address[i];
            if (i != 3)
            {
                cout << ".";
            }
	}
    cout<<" |"<<endl;
	cout<< setw(50) << setfill('-') << "+" << endl;
	
    //IP to INT
	unsigned long int	ip_interger = (IPV4_address[0]*(pow(256., 3))) + (IPV4_address[1] * (pow(256., 2))) + (IPV4_address[2] * 256) + IPV4_address[3];
	cout << "iP address as interger: " << ip_interger << endl;

	return 0;
}


bool validateString(string s)
{
    for (auto c : s) //auto decides the data type depending on what data is stored part of cpp v11 could have used an if statement before to decide the data type but extra work
    {                  // might not be compatible with all compilers (older compliers)
        if (!isalnum(c))
        {
            return false;
        }

        if(isspace(c))
        {
            return false;
        }
    }

    return true;
}

bool validateSize(string s)
{
     if (s.length() != 10)
        {
         return false;
        }
 return true;
}