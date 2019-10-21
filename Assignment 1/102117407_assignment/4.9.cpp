#include <iostream>
#include <string>

using namespace std;

int main()
 {
   char ans;
   int DayOfWeek, i = 0;
   bool validDay = true, ValidAns = true;
   do {
      do {
         cout << "What day is it (Sunday = 1): ";
         cin >> DayOfWeek;
         if (DayOfWeek <= 0 || DayOfWeek >= 8) 
         {
            cout << "This is not a valid day" << endl;
            validDay = false;
         } 
         else 
         {
            do {
               cout << "Is it Raining (y or n): "; 
               cin >> ans;
               if (tolower(ans) == 'y') 
               {
                  if (DayOfWeek != 1 && DayOfWeek != 7) 
                  {
                     cout << "Go out and Take an Umbrella" << endl << endl;
                  }
                  else 
                  {
                     cout << "Read in bed" << endl << endl;
                  }
                  i++;
               } 
               else if (tolower(ans) == 'n') 
               {
                  if (DayOfWeek != 1 && DayOfWeek != 7) 
                  {
                     cout << "Go Out" << endl << endl;
                  } 
                  else 
                  {
                     cout << "Go out" << endl << endl;
                  }
                  i++;
               } 
               else 
               {
                  cout << "Please make a choice based on the following(y or n): ";
                  ValidAns = false;
               }
            } while (ValidAns != true);
         }
      } while (validDay != true);
   } while (i != 7);

   return 0;
}