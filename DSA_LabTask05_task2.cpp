#include<iostream>
using namespace std;

struct Stock
{
    int numberOfShares;
    int sharePrice;
};

struct Node
{
    Stock *data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

bool isEmpty() 
{
    return (front == NULL && rear == NULL);
}

Stock *readStockInfo()
{
    Stock *stock = new Stock();
    cout << "Enter the number of shares: ";
    cin >> stock->numberOfShares;
    cout << "Enter the share price: ";
    cin >> stock->sharePrice;
    return stock;
}

void readNode(Node *newNode)
{
    newNode->data = readStockInfo();
}

Node *createNodeWithInput()
{
    Node *anyNode = new Node();
    readNode(anyNode);
    anyNode->next = NULL;
    return anyNode;
}

Node *createNode(Stock *data)
{
    Node *anyNode = new Node();
    anyNode->data = data;
    anyNode->next = NULL;
    return anyNode;
}

void enQueue(Node *nodeToEnqueue)
{
    if (nodeToEnqueue == NULL)
    {
        cout << "Node to insert is NULL." << endl;
        return;
    }

    if (isEmpty())
    {
        front = rear = nodeToEnqueue;
    }
    else
    {
        rear->next = nodeToEnqueue;
        rear = nodeToEnqueue;
    }
}

void deQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
}

Node *Qfront()
{
    return front;
}

void printNode(Node *nodeToDisplay)
{
    if (nodeToDisplay == NULL)
    {
        cout << "Node is NULL." << endl;
        return;
    }
    cout << "Number of Shares: " << nodeToDisplay->data->numberOfShares <<endl;
	cout<< " Share Price: " << nodeToDisplay->data->sharePrice << endl;
}

void printQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    Node *current = front;
    while (current != NULL)
    {
        printNode(current);
        current = current->next;
    }
}


void sellShares() 
{
	 if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
	
	int sell, gain = 0;
	cout << "Enter the price per share to sell all shares : " <<endl; 
	cin >> sell;
	Node* temp = front;
	while (temp != 0) {
		gain = gain + (temp->data->numberOfShares * sell);
		Node* del = temp;
		temp = temp->next;
		delete del;
	}
	cout << "The total gain by selling all the shares is : " << gain << " PKR." <<endl;
}

int main()
{
    int ch;
    do
    {
        cout << "\n\n\t\t\t*--------WELCOME TO MAIN MENU--------*" << endl;
        cout << "1) Buy Shares" << endl;
        cout << "2) Sell Shares" << endl;
        cout << "-1) To Exit" << endl;
        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "\t\t---------Buy Shares---------" << endl <<endl;
            Node *node = createNodeWithInput();
            enQueue(node);
            cout<<endl<<endl;
            printQueue();
            break;
        }

        case 2:
        {
            cout << "\t---------- Sell Shares ------------" << endl <<endl;
            printQueue();
            cout<<endl<<endl;
			sellShares();
            break;
        }

        case -1:
        {
            cout << "YOU HAVE ENDED THE PROGRAM SUCCESSFULLY ^_^ " << endl;
            return 0;
        }

        default:
        {
            cout << "INVALID" << endl;
        }
        }
    } 
	while (1);
}

