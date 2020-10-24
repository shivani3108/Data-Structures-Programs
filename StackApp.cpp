// Name: Shivani Arya
// Roll No: 19585
// Program to create Stack using Linked List and add 2 large numbers
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
void insertatTail(t element)
{
SLLNode<t>* N = new SLLNode<t>(element);

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
void reverse_push(t element)
{
	SL.insertatTail(element);
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

void add()
{
  Stack <int> s1;
  Stack <int> s2;
  Stack <int> s3;
  int n, m, n2, m2, ele = 0, temp = 0, carry = 0;
  cout<<"Enter the number of digits of 1st number: ";
  cin>>n;
  cout<<"Enter the digits of first number: ";
  for(int i=0;i<n;i++)
  {
    cin>>m;
    s1.push(m);
  }
  cout<<"Enter the number of digits of 2nd number: ";
  cin>>n2;
  cout<<"Enter the digits of second number: ";
  for(int j=0;j<n2;j++)
  {
    cin>>m2;
    s2.push(m2);
  }

  while(s1.is_empty() == 0 && s2.is_empty() == 0)
  {
     temp = s1.top_element() + s2.top_element() + carry;
     ele = temp%10;
     s3.push(ele);
     carry = temp/10;
     s1.pop();
     s2.pop(); 
     if(s1.is_empty()!=0)
     {
     	s3.push(carry);
	 }
  } 
  cout<<"\nSum\n";
  s3.display();
}

void stack_menu(t element)
{
int option;

do
{
cout<<"\n\n ** MENU **\n";
cout<<"Press 1. PUSH\n";
cout<<"Press 2. POP\n";
cout<<"Press 3. DISPLAY\n";
cout<<"Press 4. TOP_ELEMENT\n";
cout<<"Press 5. IS_EMPTY\n";
cout<<"Press 6. ADD TWO LARGE NUMBERS\n";
cout<<"Press 7. EXIT\n";
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

case 6: add();
break;

case 7: cout<<"\nExiting";
exit(0);

default: cout<<"\nInvalid input";
      break;
}
}while(option!=7);
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


else if(choice==2)
{
float element;
Stack<float> sk;
sk.stack_menu(element);
}

else if(choice==3)
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
