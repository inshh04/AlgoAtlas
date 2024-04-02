#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *stackTop = NULL;

//Node Creation
void read_Node(Node* n)
{
	cout << "Enter the data for new node :";
	cin >> n->data;
}


Node* createNode(int data)
{
	Node* anyNode = new Node();
	anyNode->data = data;
	return anyNode;

}

Node* createWithInput()
{
	Node* anyNode = new Node();
	read_Node(anyNode);
	return anyNode;

}

void push(Node* nodeToInsert) 
{
    if (nodeToInsert == NULL) 
	{
        cout << "Node to insert is NULL." << endl;
        return;
    }
    nodeToInsert->next = stackTop;
    stackTop = nodeToInsert;
}

bool isEmpty() 
{
    return (stackTop == NULL);
}

void pop() 
{
    if (isEmpty()) 
	{
        cout << " STACK UNDERFLOW :(" << endl;
        return;
    }
    Node* temp = stackTop;
    stackTop = stackTop->next;
    delete temp;
}

Node* top() 
{
    if (isEmpty()) 
	{
        cout << "Stack is empty. No top element." << endl;
        return NULL;
    }
    return stackTop;
}

void printNode(Node* nodeToDisplay) 
{
    if (nodeToDisplay == NULL) 
	{
        cout << "Node is NULL." << endl;
        return;
    }
    cout << nodeToDisplay->data << endl;
}

void printStack() 
{
    if (isEmpty()) 
	{
        cout << "Stack is empty." << endl;
        return;
    }
    Node* current = stackTop;
    while (current != NULL) 
	{
        printNode(current);
        current = current->next;
    }
}

// Clear Stack function using a helper function
void clearStack() 
{
    while (!isEmpty()) 
	{
        pop();
    }
}

int main()
{

	int ch;
	do
	{
		cout<<"\n\n\t\t\t*--------WELCOME TO MAIN MENU--------*"<<endl;
		cout<<"1) Push in Stack"<<endl;
	    cout<<"2) Pop from Stack"<<endl;
	    cout<<"3) Print Stack"<<endl;
	    cout<<"4) Clear Stack"<<endl;
		cout<<"5) Exit"<<endl;
		cout<<"Enter Choice: "<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				{
					int c;
					cout<<"\t\t---------PUSH---------"<<endl;
					cout<<"\t1. Push with Data:"<<endl;
					cout<<"\t2. Push without Data:"<<endl;
					cout<<"\nENTER CHOICE"<<endl;
					cin>>c;
					switch(c)
					{
						case 1:
							{
								cout<<"--------Push with Data:----------"<<endl<<endl;
								Node *node = createWithInput();
								push(node);
								cout<<"YOUR STACK:"<<endl<<endl;
								printStack();
								break;
							}
							
						case 2:
							{
								cout<<"--------Push without Data:----------"<<endl<<endl;
								Node* newNode = createNode(100);
								push(newNode);
								cout<<"Your Stack:"<<endl;
								printStack();
								break;
							}
					}
					break;
				}
				
			case 2:
				{
					cout<<"\t---------- POP ------------"<<endl;
					pop();
					cout<<"Your New Stack:"<<endl<<endl;
					printStack();
					break;
				}
				
			case 3:
				{
					cout<<"\t----------PRINT STACK------------"<<endl;
					cout<<"Yout Stack:"<<endl<<endl;
					printStack();
					
					break;
				}
				
			case 4:
				{
					cout<<"\t----------CLEARING STACK------------"<<endl;
					clearStack();
					
					break;
				}
				
			case 5:
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
   }while(1);
}
