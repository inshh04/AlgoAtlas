#include <iostream>
using namespace std;

struct Node
{
int data;
Node * next;
Node * prev;
};

/*Globally Declared first and last pointers*/
Node * head = NULL;
Node * tail = NULL;

// Node Creation
void readNode(Node * newNode) //helper function
{
	 cout << "Enter Data of Node: ";
    cin >> newNode->data;
}

Node* createWithInput()
{
	Node* anyNode = new Node();
	readNode(anyNode);
	return anyNode;

}


Node * createNode(int data) 
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL; // Initialize the 'next' pointer to null
    return newNode;
}

// Search/Find/Get Node
//Function to get the node having the data value as input data
Node* getNode(int data)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}


// Node Insertion  //yahan pe tail null hi rahe ga
void insertAtHead(Node * newNode)
{
	if(head == NULL && tail == NULL)
	{
	   head = newNode;
	   newNode->prev = newNode;
	   newNode->next = newNode;
	   tail = newNode;	
	}
	
	else
	{
		Node* firstNode = head;
		Node* lastNode = tail;
		head = newNode;
		newNode->prev = lastNode;
		newNode->next = firstNode;
		firstNode->prev = newNode;
		lastNode->next = newNode;
	}
}

void insertAtEnd(Node * newNode)
{
	if (head == NULL && tail == NULL)
	{
		head = newNode;
		newNode -> prev = newNode;
		newNode -> next = newNode;
		tail = newNode;
	}
	else
	{
		Node* firstNode = head;
		Node* lastNode = tail;
		firstNode -> prev = newNode;
		lastNode -> next = newNode;
		newNode -> prev = lastNode;
		newNode -> next = firstNode;
		tail = newNode;
	}
}

void insertAfter(int data, Node * newNode)
{
	Node *S;
	Node *Sn;
	S = getNode(data);
	Sn = S -> next;
    S -> next = newNode;
    newNode -> prev = S;
    newNode -> next = Sn;
    Sn -> prev = newNode;
	
	
	  
}

void insertBefore(int data, Node * newNode)
{
	Node *S;
	Node* Sp;
	S = getNode(data);
	Sp = S ->prev;
	Sp -> next = newNode;
	newNode -> prev = Sp;
	newNode -> next = S;
	S -> prev = newNode;
}

// Display
void printNode(Node * n) // helper function
{
	cout<< n -> data <<endl; //prints each element of list
}

//TRAVERSING
void printList()
{
	Node* temp = head;
	do
	{
		cout<<"\n\t";
		printNode(temp);
		temp = temp ->next;
	}
	while (temp != head);
}

// REVERSE TRAVERSING
void reversePrintList()
{
	Node* temp = tail;
	do
	{
		cout<<"\n\t";
		printNode(temp);
		temp = temp -> prev;
	}
	while (temp != tail);
	
}

// Node deletion
void deleteFromStart()
{
	Node* firstNode = head;
	Node* lastNode = tail;
	Node* Sn = firstNode -> next;
	Sn -> prev = lastNode;
	lastNode -> next = Sn;
	head = Sn;
	delete firstNode; 
}


void deleteFromEnd()
{
	//Node* temp = tail;
	Node* firstNode = head;
	Node* lastNode = tail;
	Node* Sp = lastNode -> prev;
	firstNode -> prev =Sp;
	Sp -> next = firstNode;
	tail = Sp;
	delete lastNode;
	
}

void deleteNode(int data)
{
	Node *S = getNode(data);
	Node* Sp = S -> prev;
	Node *Sn = S -> next;
	Sp -> next = Sn;
	delete S;
	
}




int main()
{
	//---------------------------FIRST------------------------
	Node* first = createNode(27);
	//linking head with first node
	head = first;
	
	//--------------------------SECOND------------------------
	Node* second = createNode(29);
	//placing second node as next in first node
	first -> next = second;
	//placing first node as previous node in second node
	second -> prev = first;
	
	//--------------------------THIRD-------------------------
	Node* third = createNode(25);
	//placing third node as next in second node
	second -> next = third;
	//placing second node as previous node in third node
	third -> prev = second;
	
	//--------------------------FOURTH-----------------------
	Node* fourth = createNode(20);
	//placing fourth node as next in third node
	third -> next = fourth;
	//placing third node as previous node in fourth node
	fourth -> prev = third;
	//linking fourth node and first by setting first node as next in fourth node
	fourth -> next = head;
	//linking first and fourth by placing fourth node as previous node in first node
	head -> prev = fourth;
	
	//terminating at  fourth node
	tail = fourth;
	
	//printing list
	cout<<"\t----------List----------"<<endl<<endl;
	printList();
	
int c;
do
  {
      cout<<"\n\n\t\t\t*--------WELCOME TO MAIN MENU--------*"<<endl;
      cout<<"\t1. INSERT NODE"<<endl;
      cout<<"\t2. SEARCH NODE"<<endl;
      cout<<"\t3. PRINT LIST "<<endl;
      cout<<"\t4  PRINTING LIST IN REVERSE"<<endl;
      cout<<"\t5. DELETE"<<endl;
      cout<<"\t6. To Exit"<<endl;
      cout<<"\nENTER YOUR CHOICE: "<<endl<<endl;
      cin>>c;
    switch (c)
       {
          case 1:
               {
                  int a;
                  cout<<"\n---INSERT NODE---"<<endl;
                  cout<<"\t1. Insert At The Beginning:"<<endl;
                  cout<<"\t2. Insert At The End:"<<endl;
                  cout<<"\t3. Insert After Node:"<<endl;
                  cout<<"\t4. Insert Before Node:"<<endl;
                  cout<<"ENTER YOUR CHOICE: "<<endl<<endl;
                  cin>>a;
                  switch(a)
                      {
                        case 1:
                            {
                                cout<<"----Insert At The Beginning----"<<endl<<endl;
                                Node* fifth = createWithInput();
                                insertAtHead(fifth);
                                 cout<<"----------AFTER INSERTION AT HEAD----------"<<endl;
                                printList();
	                            break;
                            }

                        case 2:
                            {
                                cout<<"----Insert At The End----"<<endl;
                                Node* fifth = createWithInput();
	                            insertAtEnd(fifth);
		                        cout << "------------After Insertion-------------";
		                        printList();
	                            break;
                            }

                        case 3:
                            {
                                cout<<"----Insert After Node----"<<endl;
                                int x;
                                Node* fifth = createWithInput();
                                cout<<"Enter the data after which you want to insert node: "<<endl;
                                cin>>x;
                                insertAfter(x,fifth);
                                cout<<"------------After Insertion:------------"<<endl;
                                printList();
                                break;
                            }

                       case 4:
                           {
                              cout<<"----Insert Before Node----"<<endl;
                              int x;
                              Node* fifth = createWithInput();
                              cout<<"Enter the data before which you want to insert node: "<<endl;
                              cin>>x;
                              insertBefore(x,fifth);
                              cout<<"----------AFTER INSERTION:-------------"<<endl;
                              printList();
                              break;
                           }

                       default:
                          {
                             cout<<"invalid input"<<endl<<endl; }
                          }


                        break;
                } 

           //SEARCH NODE
            case 2:
               {
                 int b;
                 cout<<"\n-------SEARCH NODE-------"<<endl;
                 int x;
                 cout<<"Enter the value of Node you want to search in the list:"<<endl;
                 cin>>x;
                 Node* val = getNode(x);
                 cout<<"Searched Node is: "<<val -> data <<endl;
                 
                 break;
               }

           //PRINT LIST
            case 3:
               {
                  cout<<"\n-----------PRINTING LIST--------------"<<endl;
                  printList();

                  break; 
               }

           //PRINTING LIST IN REVERSE
           case 4:
               {
                  cout<<"\n-------------PRINTING LIST IN REVERSE--------------"<<endl;
                  reversePrintList();

                  break;
               }

            //DELETING NODE
            case 5:
               {
                   int b;
                   cout<<"\n\t--------------DELETE NODE----------------"<<endl<<endl;
                   cout<<"\t1. Delete From Start "<<endl;
                   cout<<"\t2. Delete From End "<<endl;
                   cout<<"\t3. Delete Any Node  "<<endl;
                   cout<<"Enter Your Choice: "<<endl;
                   cin>>b;
                   
                   switch(b)
                   {
                   	    case 1:
                   	  	{
                   	  	    cout<<"----------------DELETE FROM START----------------"<<endl<<endl;
                   	  	    cout<<"BEFORE DELETION:"<<endl<<endl;
                   	  		printList(); 
                   	  		deleteFromStart();
                   	  		cout<<"\t After Deleting First Node:"<<endl<<endl;
                   	  		printList();
                   	  		
                   	  		break;
						}
						
						case 2:
                   	  	{
                   	  		cout<<"------------------DELETE FROM END------------------"<<endl<<endl;
                   	  		cout<<"BEFORE DELETION:"<<endl<<endl;
                   	  		printList(); 
							deleteFromEnd();
                   	  		cout<<"\t After Deleting Last Node:"<<endl<<endl;
                   	  		printList();
                   	  		
                   	  		break;
						}
						
						case 3:
                   	  	{
                   	  		cout<<"------------------DELETE ANY NODE-----------------"<<endl<<endl;
                   	  		cout<<"BEFORE DELETION:"<<endl<<endl;
                   	  		printList(); 
                   	  		int x;
                   	  		cout<<"Enter value of node you want to delete: "<<endl;
                   	  		cin>>x;
                   	  		deleteNode(x);
                   	  		cout<<"After Deletion of Node:"<<endl<<endl;;
                   	  		printList();
                   	  		
                   	  		break;
						}
						
						default:
                          {
                             cout<<"invalid input"<<endl<<endl; 
						  }
                          
				   }

                   break;
               }

            case 6:
               {
                  cout<<"your program has ended successfully!!"<<endl<<endl;
                  exit(-1);
               }

           default:
               {
                  cout<<"INVALID INPUT-_-"<<endl<<endl;
               }
       }
   }
while(1);

}
