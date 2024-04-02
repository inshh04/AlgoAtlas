#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

Node* create_Node()
{
    Node* anyVal = new Node();
    return anyVal;
}

void read_Node(Node* n)
{
    cout << "Enter Data of Node: ";
    cin >> n->data;
    
}

void display_Node(Node* n)
{
    cout << "Element :" ;
    cout << n->data << endl;
}


//to insert a new Node at the head
void insert_at_head(Node* newNode)
{
    Node* firstNode ;   
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

//Linked List Traversal
void display_list()
{
    cout << "Traversal of Linked list is :" << endl;
    Node* temp;
    if (head == NULL)
    {
        cout << "Linked List is empty";
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            display_Node(temp);
            temp = temp->next;
        }
    }
}


// Searching the last Node of linked list
void search_last()
{
    Node* temp = head;
    if (temp == NULL)
    {
        cout << "Linked List is empty" << endl;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "Last Element: " << temp->data << endl;
    }
}

int main()
{
    Node* first = create_Node();
    //linking head and first Node
    head = first;
    read_Node(first);
    

    Node* second = create_Node();
    //Linking first and second Node
    first->next = second;
    read_Node(second);
    

    Node* third = create_Node();
    //Linking second and third Node
    second->next = third;
    //terminatin g the linked list at third Node
    third->next = NULL;
    read_Node(third);
    
    //Traversal
    display_list();
    cout << endl;


    //inserting at head
    Node* newNode = create_Node();
    cout << "INSERTION AT HEAD: "<<endl;
    read_Node(newNode);
    insert_at_head(newNode);
    cout << "After Insertion "<<endl;
    display_list();
    cout << endl;

    //last Element
    search_last();
    cout << endl;

    //free dynamic memory allocation
    delete first;
    delete second;
    delete third;

    return 0;
}

