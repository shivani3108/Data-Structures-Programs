// Name: Shivani Arya
// Roll No: 19585
// Program to create Circular Double linked list
#include<iostream>
#include<stdio.h>
#include<process.h>
using namespace std;
template <class T>
class CDLLNode
{
	 public:
	 T info;
	 CDLLNode *next;
	 CDLLNode *previous;
	
	
	CDLLNode(T element)
	{
		info=element;
		next=this;
		previous=this;
	}
};

template <class T>
class CDLL_List
{
     CDLLNode <T>*tail;
		 public:
		 CDLL_List()
		 {
		 	tail=0;
		 }	
void addatHead(T element)
{
	
  CDLLNode <T>*N=new CDLLNode<T>(element);
  if(tail==0)
  {

  	tail=N;
  	tail->next=N;
  	tail->previous = N;
  }
  else
  {
  
     tail->next->previous =N;
     N->next = tail->next;
     tail->next=N;
	    
  }
  
}
void addatTail(T element)
{
	
  CDLLNode <T>*N=new CDLLNode<T>(element);
  if(tail==0)
  {
  	tail=N;
  	tail->previous=N;
  	tail->next=N;
  }
  else
  {
  	 N->next=tail->next;
  	 N->previous=tail;
  	 tail-> next=N;
     tail=N;
  }  
}
void traverse_forward()
{
	CDLLNode<T>*temp;
	temp=tail->next;
	if(tail==0)
	{ 
	  cout<<"/nList is empty";
	}
	else
	{
	while(temp!=tail)
	  {
		cout<<temp->info;
		temp=temp->next;		
	  }
	  cout<<tail->info;
    }
}


bool search (T element)
{
	CDLLNode <T>*temp=tail->next;
	while(temp!=tail)
	{
		if(temp->info == element)
		{
		 return true;
		 break;
	    }	    
		 temp=temp->next;
	}
}

CDLLNode <T>*search_pointer(T element)
{
	CDLLNode <T>*temp = tail->next;
	while( temp!=tail)
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

void delete_from_head()
{   
    CDLLNode <T>*temp=tail->next;
	if(tail==0)
	return ;
	else if(tail==tail->next)
	{
		delete(tail);
		tail=NULL;
		
	}
	else
	{
	CDLLNode <T>*temp=tail->next;
	tail->next=tail->next->next;
	delete (temp);
    }
}

void delete_from_tail()
{
    CDLLNode <T>*temp=tail->previous;
	if(tail==0)
	return ;
	else if(tail==tail->next)
	{
		delete(tail);
		tail=NULL;
		
	}
	else if(tail->next!=tail)
	{ 
	  temp->next=tail->next;
	  delete (tail); 
	  tail=temp;
	  tail->next->previous=tail;
	}		
}

void delete_after_pos(int pos)
{
	if(tail==0)
	cout<<"List is empty!"<<endl;
	else if(tail->next==tail)
	{
		delete(tail);
		tail=0;
	}
	else
	{
		CDLLNode<T>*prev=tail->next;
		CDLLNode<T>*current=tail->next;
		int index=0;
		while(1)
		{
			index++;
			if(index=pos+1)
			break;
			prev=current;
			current=current->next;
			
		}
		current->next->previous=prev;
		prev->next=current->next;
		delete(current);
	}
}

void delete_before_pos(int pos)
{
	if(tail==0)
	cout<<"List is empty!"<<endl;
	else if(tail->next==tail)
	{
		delete(tail);
		tail=0;
	}
	else
	{
		CDLLNode<T>*prev=tail->next;
		CDLLNode<T>*current=tail->next;
		int index=0;
		while(1)
		{
			index++;
			if(index=pos-1)
			break;
			prev=current;
			current=current->next;
			
		}
		current->next->previous=prev;
		prev->next=current->next;
		delete(current);
	}
}

void  menu(T element)
{
     int choice;
     cout<<"Circular Double Linked List Program"<<endl;
    do{
	cout<<"MENU"<<endl;
	cout<<"1.Insert at Head"<<endl;
	cout<<"2.Insert at Tail"<<endl;
    cout<<"3.Traverse forward"<<endl;
    cout<<"4.Search"<<endl;
    cout<<"5.Delete from head"<<endl;
    cout<<"6.Delete from tail"<<endl;
	cout<<"7.Exit"<<endl;
	cout<<"\nEnter your choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:  cout<<"Enter the element:";
	             cin>>element;
		         addatHead(element);
		         break;
		case 2:  cout<<"Enter the element:";
	             cin>>element;
		         addatTail(element);
		         break;
		case 3:  traverse_forward();
		         break;
	    case 4:  CDLLNode<T>*s;
		         cout<<"Enter the element to be searched:";
	             cin>>element;
	             s=search_pointer(element);
				 cout<<"Element found at: "<<s;
		         break;	
		case 5:  delete_from_head();
		         break;	    
		case 6:  delete_from_tail();
		         break;	      	
		case 7:  exit(0);
		         break;
		default:  cout<<"Wrong input!"<<endl;
    }
	 }   while (choice!=7);	
} 
};

int main()
{
	char type;
	cout<<"CIRCULAR DOUBLE LINKED LIST PROGRAM"<<endl;
	cout<<"\nEnter 'i' for integer and 'c' for char type: ";
	cin>>type;
	if(type=='i')
	{
		int element;
		CDLL_List<int>L;
		L.menu(element);		
	}
	else if(type=='c')
	{
		char element;
		CDLL_List<char>L;
		L.menu(element);
	}
	return 0;
}

