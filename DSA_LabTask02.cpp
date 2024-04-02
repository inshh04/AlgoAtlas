#include <iostream>
using namespace std;

struct Node
{
int data;
Node * next;
};


/*Globally Declared Head*/
Node * head = NULL;


void read_Node(Node* n)
{
    cout << "Enter Data of Node: ";
    cin >> n->data;
    
}

Node * createNodeWithInput()
{
	Node* newNode = new Node;
    read_Node(newNode);
    return newNode;
}

Node * createNode(int data) 
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL; // Initialize the 'next' pointer to nullptr
    return newNode;
}



// Function to get the last Node in the linked list
Node* getLast() 
{
    if (head == NULL) 
	{
        return NULL;  // List is empty
    }

    Node* current = head;
    while (current->next != NULL) 
	{
        current = current->next;
    }
    return current;
}

// Function to get a Node with a specific data value
Node* getNode(int data) 
{
    Node* current = head;
    while (current != NULL) 
	{
        if (current->data == data) 
		{
            return current;
        }
        current = current->next;
    }
    return NULL;  // Node with data not found
}

// Function to get the Node preceding a Node with specific data value
Node* getPrev(int data) 
{
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) 
	{
        if (current->data == data) 
		{
            return prev;
        }
        prev = current;
        current = current->next;
    }
    return NULL;  // Node with data not found
}


/*---------------------- Helper Functions ----------------------*/
void insertAtEnd(Node *newNode) 
{
    if (head == NULL) 
	{
        head = newNode;
        newNode->next = NULL;
    } 
	else 
	{
        Node* temp = head;
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}


void insertAfter(int data, Node* node) {
    if (node == NULL) {
        cout << "Invalid node provided." << endl;
        return;
    }
    // Rest of the code
}

//Function to Insert an element at the beginning of list
void InsertAtHead(Node* newNode)
{
	Node* firstNode;   //first Node is a temporary Node used to store the address of first original node before insertion
	if (head == NULL)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		firstNode = head;
		head = newNode;
		newNode->next = firstNode;
	}

}


void InsertBefore(Node* newNode, int data)
{
	Node* Sn;
	Node* Sp = getPrev(data);
	Sn = Sp->next;
	Sp->next = newNode;
	newNode->next = Sn;
}

void printNode(Node* node) 
{
    if (node == NULL) 
	{
        cout << "Invalid node provided." << endl;
        return;
    }
    cout << "Node Data: " << node->data << endl;
}


void printList()
 {
    Node* current = head; // Assuming 'head' is the pointer to the first node

    cout << "Linked List: ";
    while (current != NULL) 
	{
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}



/*---------------------- Helper Functions ----------------------*/
void deleteFromStart() 
{
    if (head != NULL) 
	{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteFromEnd() 
{
    if (head == NULL) 
	{
        return; // If the list is empty, nothing to delete
    }
    if (head->next == NULL) 
	{
        delete head;
        head = NULL;
        return;
    }
    
    Node* current = head;
    while (current->next->next != NULL) 
	{
        current = current->next;
    }
    
    delete current->next;
    current->next = NULL;
}



/*---------------------- Helper Functions ----------------------*/
void deleteNode(int data)
 {
    if (head == NULL) 
	{
        return; // If the list is empty, nothing to delete
    }
    if (head->data == data) 
	{
        deleteFromStart();
        return;
    }
    
    Node* prev = getPrev(data);
    if (prev != NULL) 
	{
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
    }
}

void deleteList() 
{
    Node* current = head;  // Assuming 'head' is the pointer to the first node of the linked list

    while (current != NULL) 
	{
        Node* next = current->next;  // Save the next node before deleting the current one
        delete current;  // Delete the current node
        current = next;  // Move to the next node
    }

    // After deleting all nodes, make sure to set the 'head' to nullptr to indicate an empty list
    head = NULL;
}


int main()
{
	
	Node* first = createNode(29);
	//linking head and first Node
	head = first;


	Node* second = createNode(27);
	//Linking first and second Node
	first->next = second;


	Node* third = createNode(24);
	//Linking second and third Node
	second->next = third;
	//terminating the linked list at third Node
	third->next = NULL;

	Node* fourth = createNode(22);
	//Linking third and fourth Node
	third->next = fourth;
	//terminating the linked list at fourth Node
	fourth->next = NULL;

	printList();
	
int c;
do
{
cout<<"\n\n\t\t\t*--------WELCOME TO MAIN MENU--------*"<<endl;
cout<<"\t1. INSERT NODE"<<endl;
cout<<"\t2. SEARCH NODE"<<endl;
cout<<"\t3. DISPLAY NODE"<<endl;
cout<<"\t4. DELETE"<<endl;
cout<<"\t5. To Exit"<<endl;
cout<<"\nENTER YOUR CHOICE: "<<endl<<endl;
cin>>c;
switch (c)
	{
		case 1:
		{
			int a;
			cout << "\n---INSERT NODE---" << endl;
			cout << "\t1. Insert At The Beginning:" << endl;
			cout << "\t2. Insert At The End:" << endl;
			cout << "\t3. Insert After Node:" << endl;
			cout << "\t4. Insert Before Node:" << endl;
			cout << "ENTER YOUR CHOICE: " << endl << endl;
			cin >> a;
			switch (a)
			{
			case 1:
			{
				cout << "----Insert At The Beginning----" << endl << endl;
				Node* fifth = createNodeWithInput();
				InsertAtHead(fifth);
				cout << "After Insertion ";
				printList();

				break;
			}

			case 2:
			{
				cout << "----Insert At The End----" << endl;
				Node* fifth = createNodeWithInput();
				insertAtEnd(fifth);
				cout << "After Insertion ";
				printList();
				break;
			}

			case 3:
			{
				cout << "----Insert After Node----" << endl;

				int x;
				Node* fifth = createNodeWithInput();
				cout << "Enter the data of Node AFTER which you want to insert new Node: ";
				cin >> x;
				insertAfter(x, fifth);
				cout << "After Insertion ";
				printList();
				break;
			}

			case 4:
			{
				cout << "----Insert Before Node----" << endl;

				int x;
				Node* fifth = createNodeWithInput();
				cout << "Enter the data of Node BEFORE which you want to insert new Node: ";
				cin >> x;
				InsertBefore(fifth, x);
				cout << "After Insertion ";
				printList();
				break;
			}

			default:
			{
				cout << "invalid input" << endl << endl;						}
			}


			break;
		}

		case 2:
		{
			int b;
			cout << "\n---SEARCH NODE---" << endl;
			cout << "\t1. GET NODE:" << endl;
			cout << "\t2. GET PREVIOUS NODE:" << endl;
			cout << "\t3. GET LAST Node:" << endl;
			cout << "ENTER YOUR CHOICE: " << endl << endl;
			cin >> b;

			switch (b)
			{
			case 1:
			{
				int x;
				cout << "----GET NODE----" << endl << endl;
				cout << "Enter the data value of Node" << endl;
				cin >> x;
				Node* a = getNode(x);
				cout << "Searched Node: " << a->data << endl;
				break;
			}

			case 2:
			{
				cout << "----GET PREVIOUS NODE----" << endl;

				int x;
				cout << "Enter the data value of Node to search its previous node :" << endl;
				cin >> x;
				Node* a = getPrev(x);
				cout << "Searched Node: " << a->data << endl;
				break;
			}

			case 3:
			{
				cout << "----GET LAST Node----" << endl;
				Node* a = getLast();
				cout << a->data << endl;
				break;
			}

			default:
			{
				cout << "invalid input" << endl << endl;						}
			}


			break;
		}

		case 3:
		{

			cout << "\n---DISPLAY LINKED LIST---" << endl;
			printList();
			break;
		}

		case 4:
		{
			int d;
			cout << "\n---DELETE NODE---" << endl;
			cout << "\t1. DELETE NODE:" << endl;
			cout << "\t2. DELETE FIRST NODE:" << endl;
			cout << "\t3. DELETE LAST NODE:" << endl;
			cout << "\t4. DELETE LIST:" << endl;
			cout << "ENTER YOUR CHOICE: " << endl << endl;
			cin >> d;

			switch (d)
			{
			case 1:
			{
				cout << "----DELETE NODE----" << endl << endl;
				int x;
				cout << "Enter the data value of Node to be deleted: ";
				cin >> x;
				deleteNode(x);
				cout << "After Deletion ";
				printList();
				break;
			}

			case 2:
			{
				cout << "----DELETE FIRST NODE----" << endl;
				deleteFromStart();
				cout << "After deletion of FIRST Node ";
				printList();
				break;
			}

			case 3:
			{
				cout << "----DELETE LAST NODE----" << endl;
				deleteFromEnd();
				cout << "After deletion of LAST Node ";
				printList();
				break;
			}

			case 4:
			{
				cout << "----DELETE LIST----" << endl;
				deleteList();
				printList();
				break;
			}

			default:
			{
				cout << "invalid input" << endl << endl;						}
			}


			break;
		}

		case 5:
		{
			cout << "your program has ended successfully!!" << endl << endl;
			exit(-1);
		}

		default:
		{
			cout << "INVALID INPUT" << endl << endl;
		}
		}
	} while (1);

	//free the dynamic memory allocation
	delete first;
	delete second;
	delete third;

	return 0;
}
