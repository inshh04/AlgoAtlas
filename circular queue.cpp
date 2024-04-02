#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

// Node Creation
void read_Node(Node *n)
{
    cout << "Enter the data for new node :";
    cin >> n->data;
}

Node *createNode(int data)
{
    Node *anyNode = new Node();
    anyNode->data = data;
    return anyNode;
}

Node *createWithInput()
{
    Node *anyNode = new Node();
    read_Node(anyNode);
    return anyNode;
}

bool isEmpty()
{
    return (front == NULL && rear == NULL);
}

Node *Front()
{
    if (isEmpty())
    {
        cout << "Queue is Empty :(" << endl;
        return NULL;
    }
    return front;
}

void enQueue(Node *newNode)
{
    if (newNode == NULL)
    {
        cout << "Node to insert is NULL." << endl;
        return;
    }

    if (isEmpty())
    {
        front = rear = newNode;
        rear->next = front; // For a circular queue, connect rear to front
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Update rear's next to point back to front
    }
}

void deQueue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty :(" << endl;
        return;
    }
    Node *temp = front;
    front = front->next;
    delete temp;

    if (front == rear)
    {
        rear = front = NULL; // If front becomes NULL, update rear to NULL as well
    }
    else
    {
        rear->next = front; // Update rear's next to point back to front
    }
}


void printNode(Node *nodeToDisplay)
{
    if (nodeToDisplay == NULL)
    {
        cout << "Node is NULL." << endl;
        return;
    }
    cout << nodeToDisplay->data << endl;
}

void printQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    Node *current = front;
    do
    {
        printNode(current);
        current = current->next;
    } while (current != front); // Traverse the circular queue
    cout << endl;
}

int main()
{
    int ch;
    do
    {
        cout << "\n\n\t\t\t*--------WELCOME TO MAIN MENU--------*" << endl;
        cout << "1) Enqueue" << endl;
        cout << "2) Dequeue" << endl;
        cout << "3) To Print Queue" << endl;
        cout << "4) To Exit" << endl;
        cout << "Enter Choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "\t\t---------Enqueue---------" << endl;
            Node *node = createWithInput();
            enQueue(node);
            cout << "YOUR Queue:" << endl
                 << endl;
            printQueue();
            break;
        }

        case 2:
        {
            cout << "\t---------- Dequeue ------------" << endl;
            deQueue();
            cout << "Your New Queue:" << endl
                 << endl;
            printQueue();
            break;
        }

        case 3:
        {
            cout << "\t----------PRINT Queue------------" << endl;
            printQueue();
            break;
        }

        case 4:
        {
            cout << "YOU HAVE ENDED THE PROGRAM SUCCESSFULLY ^_^ " << endl;
            exit(-1);
            break;
        }

        default:
        {
            cout << "INVALID" << endl;
        }
        }
    } while (1);
}



