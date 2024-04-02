#include <iostream>
using namespace std;

struct BST
{
int data;
BST * left;
BST * right;
};

BST * root = NULL;

void read_Node(BST * n)
{
	cout << "Enter the data for new node :";
	cin >> n->data;
	n -> left = NULL;
	n -> right = NULL;
}

BST * createNodeWithInput()
{
	BST* anyNode = new BST();
	read_Node(anyNode);
	return anyNode;
}

BST * createNode(int data)
{
	BST* anyNode = new BST();
	anyNode->data = data;
	anyNode -> left = NULL;
	anyNode -> right = NULL;
	return anyNode;
}

BST * searchParentNew(int value) // helper function for Insert
{
	BST* temp = root;
	BST*  prev = NULL;
	while(temp!=NULL)
	{
		prev = temp;
		if(value < temp -> data)
		{
			temp = temp -> left;
		}
		else if ( value > temp -> data)
		{
			temp = temp -> right;
		}
	}
	return prev;
}

void insert(BST * newNode)
{
	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
    	BST* parentNew = searchParentNew(newNode -> data);
    	if (newNode -> data < parentNew -> data)
	         {
	         	parentNew -> left = newNode;
	         } 
	
	    else if (newNode -> data > parentNew -> data)
        	{
		       parentNew -> right = newNode ;
	        }
    }
}

BST * searchNode(int val)
{
	BST* temp = root;
	while(temp != NULL)
	{
		if(val == temp -> data)
		{
			return temp;
		}
		
		if (val < temp -> data)
		{
			temp = temp -> left;
		}
		
		if (val > temp -> data)
		{
			temp = temp -> right;
		}
	}
	return NULL;
}

BST * searchParentNode(int value)
{
	BST* temp = root;
	BST*  prev = NULL;
	while(temp!=NULL)
	{
		prev = temp;
		if (temp->data < value)
        {
            temp = temp->left;
        }
        else if (temp->data > value)
        { 
           temp = temp->right;
        }
	}
	return prev;
}

BST * searchMinimum()
{
	BST* temp = root;
	
	while(temp -> left != NULL)
	{
		temp = temp -> left;
	}
	return temp;
}

BST * searchMaximum()
{
	BST* temp = root;
	
	while(temp -> right != NULL)
	{
		temp = temp -> right;
	}
	return temp;
}

void printNode(BST * nodeToPrint)
{
   cout<<""<<nodeToPrint->data<<endl;
}

BST* replacement(BST* node)
{
	BST* replacementParent = node;
	BST* replacement = node->right;
	while (replacement->left != NULL)
	{
		replacementParent = replacement;
		replacement = replacement->left;
	}
	return replacement;
}

void deleteNode(int val)
{
	BST* Snode = searchNode(val);
	BST* Sparent = searchParentNode(val);
	int is_left;

	if (Sparent->left == Snode)
	{
		is_left = 1;
	}
	else
	{
		is_left = 0;
	}

	// CASE 1: Deleting a node with no children (a leaf node)
	if (Snode->left == NULL && Snode->right == NULL)
	{
		if (is_left)
		{
			Sparent->left = NULL;
		}
		else
		{
			Sparent->right = NULL;
		}
		delete Snode;  // Free the memory of the deleted node
	}

	// CASE 2: Deleting a node with a single child
	else if (Snode->left == NULL || Snode->right == NULL)
	{
		BST* child = (Snode->left != NULL) ? Snode->left : Snode->right;

		if (is_left)
		{
			Sparent->left = child;
		}
		else
		{
			Sparent->right = child;
		}
		delete Snode;  // Free the memory of the deleted node
	}

	// CASE 3: Deleting a node with two children
	else if (Snode->left != NULL && Snode->right != NULL)
	{
		BST* replacementNode = replacement(Snode);
		Snode->data = replacementNode->data;
		deleteNode(replacementNode->data);
	}
}

void displayInorder(BST* root) 
{
    if (root == NULL)
        return;
    displayInorder(root->left);
    printNode(root);
    displayInorder(root->right);
}

void printpostOrder(BST* node){
    if(node){
        printpostOrder(node->left);
        printpostOrder(node->right);
        cout << node->data<<" ";
    }
}

int main()
{
    int ch;
	do
	{
		cout<<"\n\n\t\t\t*--------WELCOME TO MAIN MENU--------*"<<endl;
		cout<<"1) To Insert"<<endl;
	    cout<<"2) To Search"<<endl;
	    cout<<"3) To Delete"<<endl;
		cout<<"4) To Traverse"<<endl;
		cout<<"5) To Exit"<<endl;
		cout<<"Enter Choice: "<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				{
					cout<<"\t\t---------Insertion---------"<<endl;
				    
				    BST* newNode = createNodeWithInput();
                    insert(newNode);
                    
					break;
				}
				
			case 2:
				{
					cout<<"\t---------- Searching ------------"<<endl<<endl;
				    int a=0;
				    while(a!=6)
					{
							cout<<"\t1) To Search Node"<<endl;
	                        cout<<"\t2) To Search Parent"<<endl;
	                        cout<<"\t3) To Search Parent New"<<endl;
		                    cout<<"\t4) To Search Minimum"<<endl;
		                    cout<<"\t5) To Search Maximum"<<endl;
		                    cout<<"\t6) exit to main menu"<<endl;
		                    cout<<"Enter Choice: "<<endl;
		                    cin>>a;
		                    
		                    switch(a)
		                    {
		                    	case 1:
				                   {
					                  cout<<"\t----------To Search Node------------"<<endl;
					                  int val = 0;
					                  cout << "Enter the key value for the node to be searched:"<<endl;
				                      cin >> val;
					                  cout << "The Searched key is:" << endl;
					                  BST* Searched = searchNode(val);
					                  cout << Searched->data;
	
					                  break;
				                   }
				                   
				            	case 2:
				                   {
					                  cout<<"\t----------To Search Parent------------"<<endl;
					                  int val = 0;
					                  cout << "Enter the a value of Node to search its Parent:"<<endl;
					                  cin >> val;
					                  cout << "The Searched key Parent is:" << endl;
					                  BST* SearchedParent = searchParentNode(val);
					                  cout << SearchedParent->data;
					                  cout << endl;
	
					                  break;
				                   }
				                   
				            	case 3:
				                   {
					                  cout<<"\t----------To Search Parent New------------"<<endl;
					                  cout<<"Enter a new node to search its parent"<<endl;
					                  BST* node = createNodeWithInput();
					                  cout << "The Key value of New Node's Parent is: " << endl;
					                  BST* SearchedParentNew = searchParentNew(node->data);
					                  cout << SearchedParentNew->data;
					                  cout << endl;
	
					                  break;
				                   }
				                   
				            	case 4:
				                   {
					                  cout<<"\t----------To Search Minimum------------"<<endl;
					                  BST* Minimum = searchMinimum();
					                  cout << "The Minimum key Value in BST is :" << endl;
					                  cout << Minimum->data;
					                  cout << endl;
	
					                  break;
				                   }
				                   
				            	case 5:
				                   {
					                  cout<<"\t----------To Search Maximum------------"<<endl;
					                  BST* max = searchMaximum();
					                  cout<<"The Maximum Key IN BST Is: "<<endl;
					                  cout<<max->data;
					                  cout<<endl;
	
					                  break;
				                   }
				                   
				                default:
				                   {
				                       cout<<"INVALID"<<endl;
				 		}
				}
			} 
			break;
		}
			case 3:
				{
					cout<<"\t----------To Delete------------"<<endl;
					int val = 0;
			        cout << "Enter the value of key to Delete :"<<endl;
			        cin >> val;
			        deleteNode(val);
					break;
				}
				
			case 4:
				{
					cout<<"\t----------To Traverse In Inorder------------"<<endl;
					displayInorder(root);
					cout<<endl<<endl;
					printpostOrder(root);
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
