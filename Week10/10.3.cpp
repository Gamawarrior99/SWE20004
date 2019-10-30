#include <iostream>
#include <cstdlib>

using namespace std;

struct Number
{
    int num;
    struct Number *next;
};
typedef struct Number number;
typedef number* numberptr;



int random_number()
{ 
    int num;
    return num = rand() %50+1;;

}



void insert(numberptr * sPtr, int value) {

  numberptr newPtr; 
  numberptr previousPtr; 
  numberptr currentPtr;
  newPtr = new number; 

  if (newPtr != NULL)
  {
    newPtr-> num = value;
    newPtr-> next = NULL; 
    previousPtr = NULL;
    currentPtr = * sPtr;

    while (currentPtr != NULL && value > currentPtr-> num) 
    {
      previousPtr = currentPtr;
      currentPtr = currentPtr-> next;
    } 

    if (previousPtr == NULL)
    {
      newPtr-> next = * sPtr;* sPtr = newPtr;
    }
    else 
    {
      previousPtr-> next = newPtr;
      newPtr-> next = currentPtr;
    } 
  }
  else 
  {
    cout << value << " not inserted. No memory available.\n";
  }
}

int isEmpty( numberptr sPtr )
{
    return sPtr == NULL;
}





void printList(numberptr currentPtr)
 {
  if (isEmpty(currentPtr)) 
  {
    cout << "List is empty.\n";
  } 
  else 
  {
    cout << "The list is: ";
    while (currentPtr != NULL) 
    {
      cout << currentPtr-> num << "--> ";
      currentPtr = currentPtr-> next;
    }
    cout << "NULL\n";
  } 
}

void calculate_average(numberptr currentPtr)
{
  int average = 0;
  while (currentPtr != NULL) 
    {
       average+=currentPtr-> num;
       currentPtr = currentPtr-> next;
    }
    cout<<"average is: "<<average/10<<endl;
}



int main()
{
    srand(time(NULL));
    int i;
    int item;
    numberptr startPtr = NULL;
    for(i=0;i<10;i++)
    {
        item = random_number();
        insert( &startPtr, item);
    }
    printList(startPtr);
    calculate_average(startPtr);
}
