// Name: Shivani Arya
// Roll No: 19585
// Program to create Single linked list
#include<bits/stdc++.h>
using namespace std;

template <class t>
class IntSLLNode
{
public:
t info;
IntSLLNode*next;

IntSLLNode()
{
info = 0;
next = NULL;
}

IntSLLNode(t element)
{
info = element;
next = NULL;
}

};

template <class t>
class IntSLLList
{
public:
IntSLLNode<t> *head;
IntSLLNode<t> *tail;


IntSLLList()
{
head = NULL; // 0
tail = NULL; // 0
}

void insertatHead(t element)
{
IntSLLNode<t> * N = new IntSLLNode<t>(element);

if(head==NULL)
{
head = N;
tail = N;
}

else
{
N->next = head;
head = N;
}

}

void insertatTail(t element)
{
IntSLLNode<t>* N = new IntSLLNode<t>(element);

if(head==NULL)
{
head = N;
tail = N;
}

else
{

tail->next=N;
tail=N;

}
}

void traverse()
{

IntSLLNode<t> *temp;
temp =  head;
while(temp != NULL)
{
cout<<temp -> info <<"--> ";
temp = temp->next;
}
}


bool search(t element)
{
IntSLLNode<t> *temp;
temp = head;

while(temp!=NULL)
{
if(temp->info == element)
return true;
temp = temp->next;
}
return false;

}

void del()
{


if(head==NULL) //list is empty
{
return;
}

else if(head == tail) //list has one element
{
delete(head);
head=NULL;
tail=NULL;
}

else
{
IntSLLNode<t> *temp= head;
head = head->next;
delete(temp);
}
}

int total()
{
IntSLLNode<t> *temp = head;
int count =0;

while(temp!=NULL)
{
count = count+1;
temp = temp->next;

}

return count;
}

int avg()
{
IntSLLNode<t> *temp =  head;
float count=0;
float sum=0;
float average=0.0;

while(temp!=NULL)
{
sum += temp->info;
count = count+1;
temp=temp->next;
}

average = sum/count;

return average;

}

void delend()
{
if(head==NULL) //list is empty
{
return;
}
else if(head == tail) //list has one element
{
delete(head);
head=NULL;
tail=NULL;

}

else if(head!=tail)
{
IntSLLNode<t> *temp= head;

while(temp->next != tail)
{
temp=temp->next;

delete(tail);
tail=temp;
tail->next=NULL;
//return ;
}
}

}

void reverse()
{
IntSLLNode <t>*temp1 = head;
IntSLLNode <t>*temp2 = NULL;
IntSLLNode <t>*next = NULL;

while(temp1!=NULL)
{
next = temp1->next;
temp1->next = temp2;
temp2 = temp1;
temp1 = next;
}

head = temp2;
traverse();

}

void insert_after_pos(t element, int pos)
{
IntSLLNode<t>*N=new IntSLLNode<t>(element);
if (head==NULL)
cout<<"List is empty";
else if (head==tail)
{
	tail->next=N;
	tail=N;
}
else
{
	IntSLLNode<t>*temp=head;
	int index=0;
	while(1)
	{
		index++;
		if(index==pos)
		break;
		temp=temp->next;
		if(temp->next==NULL)
		{
			cout<<"Entered position is not valid\nElement is entered at the end of list"<<endl;
			break;
		}
	}
	if(temp->next==NULL)
	{
		tail->next=N;
		tail=N;
	}
	else
	{
		N->next=temp->next;
		temp->next=N;
	}
}
}

void insert_before_pos(t element, int pos)
{
IntSLLNode<t>*N=new IntSLLNode<t>(element);
if (head==NULL)
cout<<"List is empty";
else if (head==tail)
{
	tail->next=N;
	tail=N;
}
else
{
	IntSLLNode<t>*temp=head;
	int index=0;
	while(1)
	{
		index++;
		if(index==pos-1)
		break;
		temp=temp->next;
		if(temp->next==NULL)
		{
			cout<<"Entered position is not valid\nElement is entered at the end of list"<<endl;
			break;
		}
	}
	if(temp->next==NULL)
	{
		tail->next=N;
		tail=N;
	}
	else
	{
		N->next=temp->next;
		temp->next=N;
	}
}
}

void delete_before_pos(int pos)
{
if (head==NULL)
cout<<"List is empty";
else if (head==tail)
{
	 delete(head);
	 head=NULL;
	 tail=NULL;
}
else
{
	IntSLLNode<t>*previous=head;
	IntSLLNode<t>*current=head;
	int index=0;
	while(1)
	{
		index++;
		if(index==pos-1)
		break;
		previous=current;
		current=current->next;
		if(current->next==NULL)
		{
			cout<<"Index out of bound"<<endl;
			break;
		}
	}
	previous->next=current->next;
	delete(current);
}
}

void delete_after_pos(int pos)
{
if (head==NULL)
cout<<"List is empty";
else if (head==tail)
{
	 delete(head);
	 head=NULL;
	 tail=NULL;
}
else
{
	IntSLLNode<t>*previous=head;
	IntSLLNode<t>*current=head;
	int index=0;
	while(1)
	{
		index++;
		if(index==pos+1)
		break;
		previous=current;
		current=current->next;
		if(current->next==NULL)
		{
			cout<<"Index out of bound"<<endl;
			break;
		}
	}
	previous->next=current->next;
	delete(current);
}
}

void menu2(t element)
{
int option;
do
{

cout<<"\n\n****MENU****\n";
cout<<"Press 1. Inserting an element At Beginning\n";
cout<<"Press 2. Inserting an element At End\n";
cout<<"Press 3. For Traversing/Display of elements\n";
cout<<"Press 4. For Search\n";
cout<<"Press 5. For Delete at Head\n";
cout<<"Press 6. For Delete at Tail\n";
cout<<"Press 7. For Counting of Elements\n";
cout<<"Press 8. For Average\n";
cout<<"Press 9. For Reverse\n";
cout<<"Press 10. Insert after given position\n";
cout<<"Press 11. Insert before given position\n";
cout<<"Press 12. Delete after given position\n";
cout<<"Press 13. Delete before given position\n";
cout<<"Press 14. For Exit\n";

cout<<"Enter choice: ";
cin>>option;

switch(option)
{
case 1: cout<<"Enter an Element: ";
cin>>element;
insertatHead(element);
break;

case 2: cout<<"Enter an Element: ";
cin>>element;
insertatTail(element);
break;

case 3: traverse();
break;

case 4: cout<<"Element you want to find: ";
cin>>element;
if(search(element)==1)
{
cout<<"Element is Present in List\n";
}
else
cout<<"Element is not present in the List\n";
break;

case 5: del();
break;

case 6: delend();
break;

case 7: cout<<"Total number of elements in list is: "<<total()<<endl;;
break;

case 8: cout<<"Average of elements in List is: "<<avg()<<endl;
break;

case 9: cout<<"\nBefore Reverse: ";
traverse();
cout<<"\nAfter Reverse: ";
reverse();
break;

case 10: cout<<"Adding element after a position\n";
         cout<<"Enter element: ";
         cin>>element;
         int position;
         cout<<"Enter position: ";
         cin>>position;
         insert_after_pos(element, position);
         break;
         
case 11: cout<<"Adding element before a position\n";
         cout<<"Enter element: ";
         cin>>element;
         cout<<"Enter position: ";
         cin>>position;
         insert_before_pos(element, position);
         break;
         
case 12: cout<<"Deleting element after a position\n";
         cout<<"Enter position: ";
         cin>>position;
         delete_after_pos(position);
         break;
         
case 13: cout<<"Deleting element before a position\n";
         cout<<"Enter position: ";
         cin>>position;
         delete_before_pos(position);
         break;
         
case 14: cout<<"\n\nExiting\n";
exit(0);

default:cout<<"\nInvalid input";
      break;

}

}while(option!=14);

}

};

void menu1()
{
cout<<"\n\n\tTYPES\n";
cout<<"1. Int \n";
cout<<"2. Char \n";
cout<<"3. Float\n";
cout<<"4. Long \n";
cout<<"Enter Choice: ";

}


int main()
{
int opt,me1;
char choice;

menu1();
cin>>me1;
cout<<endl;

if(me1 == 1)
{
int element;
IntSLLList < int > SL;
SL.menu2(element);
}

else if( me1 == 2)
{
char element;
IntSLLList <char> SL;
SL.menu2(element);
}

else if( me1 == 3)
{
float element;
IntSLLList < float > SL;
SL.menu2(element);
}

else if(me1 == 4)
{
long element;
IntSLLList <long> SL;
SL.menu2(element);
}

else
{
cout<<"\nInvalid input";
}


return 0;
}
