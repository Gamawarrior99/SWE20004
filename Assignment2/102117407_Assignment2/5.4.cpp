#include<iostream>
#include<string>
#include <cstdlib>
#include<ctime>

int RandomNumberGenerator();
int roll();
int again(int firstRoll, int bet, int Balance);
int Bank(bool win, int value, int Balance);
bool check(int Balance);
void message(int value, int type);

using namespace std;

int main()
{
    int bet, total, Balance = 1000, count = 0;
    bool playAgain = true, invalid;
    srand (time(NULL));

    while (playAgain)
    {
        bet = 0;
        cout<<"Your Bank Balance is: "<<Bank(true,bet, Balance )<<endl;
        cout<<"What is your bet?: "<<endl;

        if (Balance > 3000)
        {
            message(20, 119);
        }

        invalid = true;
        while (invalid)
        {
            invalid = false;
            cin>>bet;

            if (bet>Balance)
            {
                cout<<"Invalid bet"<<endl<<"You Do not have the required Funds"<<endl;
                invalid = true;
            }
            if (cin.fail())
            {
                cout<<"Invalid bet"<<endl<<"Invalid Value used for Funds"<<endl;
                invalid = true;
                cin.clear();
                cin.ignore(256, '/n');
                break;
            }
        }

        if (bet < 100)
        {
            count +=1;
            message(count, 76);
        }
        if (bet == Balance)
        {
            message(20, 65);
        }

        total = roll();

        if (total == 7 || total == 11)
        {   
            cout<<"Player Win" << endl;
            Balance = Bank(true, bet, Balance);
            cout<<"Your Bank Balance is: "<<Balance<<endl;
        }
        else if (total == 2 || total == 8 || total == 12)
        {
            cout << " Player Lose" << endl;
            Balance = Bank(false, bet, Balance);
            cout<<"Your Bank Balance is: "<<Balance<<endl;
        }
        else
        {
            cout<<endl;
            Balance = again(total, bet, Balance);
        }
        playAgain = check(Balance);
    }
    return 0;
}

int RandomNumberGenerator()
{
  return rand() %6  + 1;  
}

int roll()
{
    int dice1, dice2,total;
    dice1 = RandomNumberGenerator();
    dice2 = RandomNumberGenerator(); 
    total = dice1 + dice2;
    cout<<"Dice 1:"<<dice1<<endl;
    cout<<"Dice 2:"<<dice2<<endl;
    cout << "Player's throw = " << total<<endl;
    return total;
}
int again(int firstRoll, int bet, int Balance)
{
    int total;
    bool win = true; 
    while (win)
    {          
        total = roll();
        if (total == firstRoll)
        {
            cout << "Player Win" << endl;
            win = false;
            Balance = Bank(true, bet, Balance);
            cout<<"Your Bank Balance is: "<<Balance<<endl;
        }
        else if (total == 7)
        {
           cout << "Player Lose" << endl;
           win = false;
           Balance = Bank(false, bet,Balance);
           cout<<"Your Bank Balance is: "<<Balance<<endl;
        }
        else
        {
            cout<<endl;
        }
    }
    return Balance;
}

int Bank(bool win, int value, int Balance)
{
    if(win)
    {
        Balance += value;
    }
    else
    {
       Balance -= value;
    }
    return Balance;   
}

bool check(int Balance)
{
    bool playAgain, invalid = true;
    char choice;
    
    if (Balance==0)
    {
        cout<<"You've Busted"<<endl;
        playAgain = false;
    }
    else if (Balance > 0)
    {
        cout<<"Play Again?: ";
        while (invalid){
            cin>>choice;
            if(choice == 'y')
            {
                playAgain = true;
                invalid = false;
            }
            else if(choice == 'n')
            {
                playAgain = false;
                invalid = false;
            }
            else
            {
                invalid = true;
            } 
        }
    }
    return playAgain;
}

void message(int value, int type)
{
    if(value >10)
    {
        if (type == 65)
        {
            cout<<"Oh, You're Going for broke, huh"<<endl;
        }
        else if (type == 199 )
        {
            cout<<"You're up big. Now's the time to cash out"<<endl;
        }
        else if (type == 76)
        {
            cout<<"Aw cmon, take a chance!"<<endl;
        }  
    }
}
