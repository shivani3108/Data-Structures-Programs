// Name: Shivani Arya
// Roll No: 19585
// Program to create Stack using Linked List
#include<bits/stdc++.h>
using namespace std;
template <class t>
class SLLNode
{
public:
t info;
SLLNode*next;

SLLNode()
{
info = 0;
next = NULL;
}

SLLNode(t element)
{
info = element;
next = NULL;
}

};

template <class t>
class SLLList
{
public:
SLLNode<t> *head;
SLLNode<t> *tail;


SLLList()
{
head = NULL; // 0
tail = NULL; // 0
}

void insertatHead(t element)
{
SLLNode<t> * N = new SLLNode<t>(element);

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
SLLNode<t> *temp= head;
head = head->next;
delete(temp);
}
}

void traverse()
{

SLLNode<t> *temp;
temp =  head;
while(temp != NULL)
{
cout<<temp -> info <<"--> ";
temp = temp->next;
}
}


};

template<class t>
class Stack
{
   public:
   SLLList<t> SL;

Stack()
{
SL.head = NULL;
}

void push(t element)
{
SL.insertatHead(element);
}

void pop()
{
SL.del();
}

t top_element()
{
return SL.head->info;
}

bool is_empty()
{
if(SL.head == NULL)
return true;
else
return false;
}

void display()
{
    SL.traverse();
}

void stack_menu(t element)
{
int option;

do
{
cout<<"\n\n ** MENU **\n";
cout<<" 1. PUSH\n";
cout<<" 2. POP\n";
cout<<" 3. DISPLAY\n";
cout<<" 4. TOP_ELEMENT\n";
cout<<" 5. IS_EMPTY\n";
cout<<" 6. EXIT\n";
cout<<"Enter Option: ";
cin>>option;

switch(option)
{
case 1: t element;
cout<<"Enter Element: ";
cin>>element;
push(element);
break;

case 2: pop();
break;

case 3: display();
break;

case 4: cout<<"Top Element is: ";
cout<<top_element();
break;

case 5: cout<<"Stack ";
if(is_empty() == 1)
{
cout<<"is empty";
}
else
cout<<"is not empty";
break;

case 6: cout<<"\nExiting";
exit(0);

default: cout<<"\nInvalid input";
      break;
}
}while(option!=6);
}
};

void type_menu()
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
int choice;

type_menu();
cin>>choice;
cout<<endl;

if(choice==1)
{
int element;
Stack<int> sk;
sk.stack_menu(element);
}

else if(choice == 2)
{
char element;
Stack<char> sk;
sk.stack_menu(element);
}

else if(choice==3)
{
float element;
Stack<float> sk;
sk.stack_menu(element);
}

else if(choice==4)
{
long element;
Stack<long> sk;
sk.stack_menu(element);
}

else
{
cout<<"Invalid Input";
}
return 0;
}
