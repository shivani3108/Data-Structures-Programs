#include<iostream>
#include<stdio.h>
#include<process.h>
using namespace std;
// Name: Shivani Arya
// Roll No: 19585
// Program to create Double linked list

class IntDLLNode
{
	 public:
	 int info;
	 IntDLLNode *next;
	 IntDLLNode *previous;
	 IntDLLNode()
	 {
		info=0;
		next=NULL;
		previous=NULL;
	 }
	
	IntDLLNode(int element)
	{
		info=element;
		next=NULL;
		previous=NULL;
	}
};

class IntDLL_List
{
     IntDLLNode*head;
     IntDLLNode*tail;
		 public:	
         IntDLL_List()
    	 {
	    	head=NULL;
	    	tail=NULL;
	     }
	
void addatHead(int element)
{
	
  IntDLLNode *N=new IntDLLNode(element);
  if(head==NULL)
  {
  	head=N;
  	tail=N;
  }
  else
  {
  	 head->previous=N;
  	 N->next=head;
     head=N;
  }
  
}
void addatTail(int element)
{
	
  IntDLLNode *N=new IntDLLNode(element);
  if(head==NULL)
  {
  	head=N;
  	tail=N;
  }
  else
  {
  	 N->previous=tail;
  	 tail-> next=N;
     tail=N;
  }  
}
void traverse_forward()
{
	IntDLLNode*temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->info;
		temp=temp->next;		
	}
}

void traverse_backward()
{
	IntDLLNode*temp;
	temp=tail;
	while(temp!=NULL)
	{
		cout<<temp->info;
		temp=temp->previous;		
	}
}


bool search (int element)
{
	IntDLLNode *temp=head;
	while(temp!=NULL)
	{
		if(temp->info == element)
		{
		 return true;
		 break;
	    }	    
		 temp=temp->next;
	}
}

IntDLLNode *search_pointer(int element)
{
	IntDLLNode *temp = head;
	while( temp!=NULL)
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

void insert_before_pos(int element, int pos)
{
IntDLLNode *N=new IntDLLNode(element);
if (head==NULL)
cout<<"List is empty";
else if (head==tail)
{
	head->previous=N;
	N->next=head;
	head=N;
}
else
{
	IntDLLNode *temp=head;
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
		N->previous=tail;
		tail=N;
	}
	else
	{
		temp->next->previous=N;
		N->next=temp->next;
		N->previous=temp;
		temp->next=N;
	}
}
}
void insert_after_pos(int element, int pos)
{
IntDLLNode *N=new IntDLLNode(element);
if (head==NULL)
cout<<"List is empty";
else if (head==tail)
{
	tail->next=N;
	N->previous=tail;
	tail=N;
}
else
{
	IntDLLNode *temp=head;
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
		N->previous=tail;
		tail=N;
	}
	else
	{
		temp->next->previous=N;
		N->next=temp->next;
		N->previous=temp;
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
	IntDLLNode *prev=head;
	IntDLLNode *current=head;
	int index=0;
	while(1)
	{
		index++;
		if(index==pos-1)
		break;
		prev=current;
		current=current->next;
		if(current->next==NULL)
		{
			cout<<"Index out of bound"<<endl;
			break;
		}
	}
	current->next->previous=prev;
	prev->next=current->next;
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
	IntDLLNode *prev=head;
	IntDLLNode *current=head;
	int index=0;
	while(1)
	{
		index++;
		if(index==pos+1)
		break;
		prev=current;
		current=current->next;
		if(current->next==NULL)
		{
			cout<<"Index out of bound"<<endl;
			break;
		}
	}
	current->next->previous=prev;
	prev->next=current->next;
	delete(current);
}
}

};

int main()
{
	int ele,choice;
	char ch;
   	IntDLL_List I = IntDLL_List();
    cout<<"Linked List Program"<<endl;
    do{
	cout<<"MENU"<<endl;
	cout<<"1.Insert at Head"<<endl;
	cout<<"2.Insert at Tail"<<endl;
    cout<<"3.Traverse forward"<<endl;
    cout<<"4.Traverse backward"<<endl;
    cout<<"5.Insert before a position"<<endl;
    cout<<"6.Insert after a position"<<endl;
    cout<<"7.Delete before a position"<<endl;
    cout<<"8.Delete after a position"<<endl;
    cout<<"9.Search"<<endl;
	cout<<"10.Exit"<<endl;
	cout<<"Enter your choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:  cout<<"Enter the element:";
	             cin>>ele;
		         I.addatHead(ele);
		         break;
		case 2:  cout<<"Enter the element:";
	             cin>>ele;
		         I.addatTail(ele);
		         break;
		case 3:  I.traverse_forward();
		         break;
		case 4:  I.traverse_backward();
		         break;
		case 5:  cout<<"Adding element before a position\n";
                 cout<<"Enter element: ";
                 cin>>ele;
                 int position;
                 cout<<"Enter position: ";
                 cin>>position;
                 I.insert_before_pos(ele,position);
                 break;	
		case 6:  cout<<"Adding element after a position\n";
                 cout<<"Enter element: ";
                 cin>>ele;
                 cout<<"Enter position: ";
                 cin>>position;
                 I.insert_after_pos(ele,position);
				 break;	
		case 7:  cout<<"Deleting element before a position\n";
                 cout<<"Enter position: ";
                 cin>>position;
                 I.delete_before_pos(position);
                 break;	
		case 8:  cout<<"Deleting element after a position\n";
                 cout<<"Enter position: ";
                 cin>>position;
                 I.delete_after_pos(position);
                 break;	 		 		         
		case 9:  cout<<"Enter the element:";
	             cin>>ele;
				 cout<<"Element found at:"<<I.search_pointer(ele);
		         break;
		case 10: cout<<"Exiting";
		         exit(0);
    }
		 cout<<"\nDo you wish to continue?";
		 cin>>ch;
	 }   while (ch=='Y'||ch=='y');	
	     return 0;
}  

