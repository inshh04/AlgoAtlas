#include <iostream>
using namespace std;

#define SIZE 5
int myStack[SIZE];
int top = -1;

bool isfull()
{
	if(top>=SIZE -1)
	  return true;
	else
	  return false;
}

bool isEmpty()
{
	if(top==-1)
	  return true;
	else
	  return false;
}

int push(int val)
{
	if(!isfull())
	{
		myStack[++top]=val;
	}
	else
	{
		cout<<"STACK OVERFLOW"<<endl;
	}
	
}

void pop()
{
	if(!isEmpty())
	{
		top--;
	}
	else
	{
		cout<<"STACK UNDERFLOW"<<endl;
	}
}

void displayStack()
{
	if(!isEmpty())
	{
		cout<<"YOUR STACK IS: \n"<<endl;
		for(int i=top ; i>=0;--i)
		{
			cout<<myStack[i]<<endl;
		}
	}
	else
	{
		cout<<"Stack is Empty!\n"<<endl;
	}
	
}

int main()
{
	int myStack[10], n=10 , top=-1;
	
	int ch, val;
	cout<<"1) Push in Stack"<<endl;
	cout<<"2) Pop from Stack"<<endl;
	cout<<"3) Display Stack"<<endl;
	cout<<"4) Exit"<<endl;
	do
	{
		cout<<"Enter Choice: "<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				{
					cout<<"Enter value to be pushed: "<<endl;
					cin>>val;
					push(val);
					break;
				}
				
			case 2:
				{
					pop();
					break;
				}
				
			case 3:
				{
					displayStack();
					break;
				}
				
			case 4:
				{
					cout<<"YOU HAVE ENDED THE PROGRAM SUCCESSFULLY ^_^ "<<endl;
					exit(-1);
					break;
				}
				
			default:
				{
					cout<<"INVALID"<<endl;
				}
		}
   }while(ch!=4);
}

