#include<iostream>
#include<stdio.h>
#include<process.h>
using namespace std;
// Name: Shivani Arya
// Roll No: 19585
// Program to create Sorted linked list


class SortedNode
{
public:
int info;
SortedNode*next;

SortedNode()
{
info = 0;
next = NULL;
}

SortedNode(int element)
{
info = element;
next = NULL;
}
};


class SortedList
{
public:
SortedNode *head;
SortedNode *tail;


SortedList()
{
head = NULL; // 0
tail = NULL; // 0
}

void insert(int element)
{
SortedNode *N = new SortedNode(element);

if(head==NULL) //List has Zero element
{
head = N;
tail = N;
}

else if(head==tail) //List has 2 elements
{
  if(head->info < N->info)
  {
     tail->next = N;
     tail = N;
  }
  else
  {
     N->next= head;
     head=N;
  }
}

else //List has more than 2 elements
{
SortedNode *temp = head;

while(temp->info < tail->info)
{

  if(N->info<head ->info)
  {
	 N->next=head;
	 head=N;
  }
  else if (N->info > temp->info && N->info < temp->next->info)
  {
  	N->next=temp->next;
  	temp->next=N;
  }
  else
    temp = temp->next;     
}
if (N->info>tail->info)
{
	tail->next=N;
	tail=N;
}
}
}

void delete_element(int element)
{
	SortedNode *current = head;
	if(current->info==element)
	{
		 head=head->next;
		 delete(current);
	} 
	else
	{
		 SortedNode *current = head;
	     SortedNode *previous = head;
	while( current!=NULL)
	{
		 previous=current;
		 current=current->next;
		 if(current->info == element)
		{
		 previous->next=current->next;
		 delete(current);
		 break;
	    }   
	}
    }
}

void traverse()
{
SortedNode *temp;
temp =  head;
while(temp != NULL)
{
cout<<temp -> info <<"--> ";
temp = temp->next;
}
}

bool search(int element)
{
SortedNode *temp = head;
while(temp!=NULL)
{
if(temp->info==element)
{
return true;
temp = temp->next;
}

return false;
}
}

SortedNode *search_pointer(int element)
{
	SortedNode *temp = head;
	while( temp->info<=element)
	{
		if(temp->info == element)
		{
		 return temp;
		 break;
	    }
	     temp = temp->next;   
	}
	   return temp;
}


void main_menu()
{
int option,element;
do
{
cout<<"\n\t**MENU**\n";
cout<<"Press 1: For Insertion of Elements\n";
cout<<"Press 2: For Searching the Element\n";
cout<<"Press 3: For Display\n";
cout<<"Press 4: For Delete\n";
cout<<"Press 5: For Exit\n";
cout<<"Enter Choice: ";
cin>>option;

switch(option)
{
case 1: cout<<"Enter Element: ";
cin>>element;
insert(element);
break;

case 2: cout<<"Enter Element: ";
cin>>element;
cout<<"Element found at:"<<search_pointer(element)<<endl;
break;

case 3: cout<<"\nList is: ";
traverse();
break;

case 4: cout<<"\nEnter element to be deleted: ";
cin>>element;
delete_element(element);
break;


case 5: cout<<"\nExitiing\n";
exit(0);

default: cout<<"\nInvalid Input\n";
break;
}

}while(option!=5);
}

};

int main()
{
SortedList SL;
SL.main_menu();

return 0;
}
