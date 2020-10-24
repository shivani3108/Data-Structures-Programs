// Name: Shivani Arya
// Roll No: 19585
// Program to implement Array using Circular Queue

#include<bits/stdc++.h>
#define size 5
using namespace std;

template<class T>
class ArrayQueue 
{
public:
	 int first, last;
	 T storage[size];
ArrayQueue() 
{
     first = last = -1;
}
bool isFull() 
{
return first == 0 && last == size-1 || first == last + 1;
}
bool isEmpty() 
{
return first == -1;
}
void enqueue(T el)
 {
     if (!isFull())
     {
     if (last == size-1 || last == -1) 
	 {
         storage[0] = el;
         last = 0;
         if (first == -1)
         first = 0;
     }
     else storage[++last] = el;
     }
     else cout << "Queue is full!\n";
}

T dequeue()
{
	 T tmp;
     if(!isEmpty())
     {
         tmp = storage[first];
         if (first == last)
         last = first = -1;
         else if (first == size-1)
         first = 0;
         else first++;
         return tmp;
     }
     else tmp=-1;
     return tmp;
     
}

void queue_menu(T element)
{
int option;

do
{
cout<<"\n\n ** MENU **\n";
cout<<"Press 1. Enqueue\n";
cout<<"Press 2. Dequeue\n";
cout<<"Press 3. Is_empty\n";
cout<<"Press 4. Is_Full\n";
cout<<"Press 5. EXIT\n";
cout<<"Enter Option: ";
cin>>option;

switch(option)
{
case 1: T element;
cout<<"Enter Element: ";
cin>>element;
enqueue(element);
break;

case 2: T ele;
ele=dequeue();
if(ele==-1)
cout<<"Queue is empty\n";
else
cout<<"Element deleted is: "<<ele;
break;

case 3: cout<<"Queue ";
if(isEmpty() == 1)
{
cout<<"is empty";
}
else
cout<<"is not empty";
break;

case 4: cout<<"Queue ";
if(isFull() == 1)
{
cout<<"is full";
}
else
cout<<"is not full";
break;

case 5: cout<<"\nExiting";
exit(0);

default: cout<<"\nInvalid input";
      break;
}
}while(option!=5);
}
};
void type_menu()
{
cout<<"\n\n\tTYPES\n";
cout<<"1. Int \n";
cout<<"2. Float\n";
cout<<"3. Long \n";
cout<<"Enter Choice: ";
}

int main()
{
	 cout<<"Circular Queue as an Array\n";
	 int choice;
     type_menu();
     cin>>choice;
     cout<<endl;

     if(choice==1)
     {
         int element;
         ArrayQueue<int> q;
        q.queue_menu(element);
     }

     else if(choice==2)
    {
         float element; 
         ArrayQueue<float> q;
         q.queue_menu(element);
    }

     else if(choice==3)
     {
         long element;
         ArrayQueue<long> q;
         q.queue_menu(element);
     }

     else
     {
         cout<<"Invalid Input";
     }
     return 0;
}
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
