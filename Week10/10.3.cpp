using namespace std;



struct numbstr 

{

    int number;

    struct numbstr *next;

};



typedef struct numbstr NUMBstr;

typedef NUMBstr *NUMBstrptr;



int random_number()

{ 

    int num;

    num = rand() %50; //genarates a random number between 0 and 50

    return num;

}



void insert(NUMBstrptr * sPtr, int value) {

  NUMBstrptr newPtr; 

  NUMBstrptr previousPtr; 

  NUMBstrptr currentPtr;

  newPtr = new NUMBstr; 

  if (newPtr != NULL)

  {

    newPtr-> number = value;

    newPtr-> next = NULL; 

    previousPtr = NULL;

    currentPtr = * sPtr;

    while (currentPtr != NULL && value > currentPtr-> number) 

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



int isEmpty( NUMBstrptr sPtr )

{

    return sPtr == NULL;

}





void printList(NUMBstrptr currentPtr) {

  if (isEmpty(currentPtr)) {

    cout << "List is empty.\n";

  } 

  else {

    cout << "The list is: ";

    while (currentPtr != NULL) {

      cout << currentPtr-> number << "--> ";

      currentPtr = currentPtr-> next;

    }

    cout << "NULL\n";

  } 

}





main()

{

    srand(time(NULL));// set time to null so the random number function uses doesnt use time to generate a number

    int i;

    int item;

    NUMBstrptr startPtr = NULL;

    for(i=0;1<10;i++)

    {

        item = random_number();

        insert( &startPtr, item);

    }



    printList( startPtr );

}