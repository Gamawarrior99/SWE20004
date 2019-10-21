#include<iostream>
#include<string>
#define SIZE 20

using namespace std;

bool check(char input);
void Swap(char *ch1, char *ch2);
void Sort(char input[]);
void frequency(char input[]);

int main()
{
    int i = 0, k = 0;
    char in, input[SIZE];
    bool sanitized = false;
    cout<<"Enter 20 Alphabets"<<endl;
    for (i = 0;i<SIZE;i++)
    {
        do
        {
            cin>>in;
            sanitized = check(in);
            if (sanitized == false)
            {
                cout<<in<<" is not an Alphabet"<<endl;
            }
        } while (sanitized==false);

        input[i]=in;
        for (k = 0;k<i;k++)
        {
            if (input[i] == input[k])
            {
                cout<<in<<" is a duplicate Letter"<<endl;
            }
        }
    }
    Sort(input);

    for (i = 0;i<SIZE;i++)
    {
        cout<<input[i];
    }
    cout<<endl;

    frequency(input);    
    return 0;
}

bool check(char input)
{
    if(!(isdigit(input)))
    {
        return true;
    }
    return false;
}

void swap(char *ch1, char *ch2) 
{ 
    int temp = *ch1; 
    *ch1 = *ch2; 
    *ch2 = temp; 
} 
   
void Sort(char input[]) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < SIZE-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < SIZE-i-1; j++) 
     { 
        if (input[j] > input[j+1]) 
        { 
           swap(&input[j], &input[j+1]); //sends the address of the two values (Call by reference)
           swapped = true; 
        } 
     } 

     if (swapped == false) 
     {
        break; 
     }
   } 
} 

void frequency(char input[])
{
  int j = 0, k = 0,temp = 0, mode = 0, fre;
  for (j = 0; j<SIZE;j++)  
  {
      for (k = 0;k<SIZE;k++)
      {
          if (input[j] == input[k])
          {
              temp++;
          }
      }

      if(temp>mode)
      {
        mode = temp;
        fre = j;
      }
      temp = 0;
  }
    cout<<"The Most Frequent Letter is "<<input[fre]<<" mode is "<<mode<<endl;
}
     