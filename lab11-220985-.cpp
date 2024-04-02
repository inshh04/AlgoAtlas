#include <iostream>
#include <list>

using namespace std;  // Add this line to use cout and endl without the std:: prefix

int main() {
    
    cout << "----------------------LINKED LIST IMPLEMENTATION THROUGH STL------------------" << endl << endl;
    
    list<int> singlyLinkedList;

    // Insertion
    singlyLinkedList.push_back(1);
    singlyLinkedList.push_back(2);
    singlyLinkedList.push_back(3);

    // Deletion
    singlyLinkedList.pop_back();

    // Printing
    for (auto element : singlyLinkedList) {
        cout << element << " ";
    }
    cout << endl;

    cout << "----------------------DOUBLY LINKED LIST IMPLEMENTATION THROUGH STL------------------" << endl << endl;

    list<int> doublyLinkedList;

    // Insertion
    doublyLinkedList.push_back(1);
    doublyLinkedList.push_back(2);
    doublyLinkedList.push_back(3);

    // Deletion
    doublyLinkedList.pop_back();

    // Printing
    for (auto element : doublyLinkedList) {
        cout << element << " ";
    }
    cout << endl;

    cout << "----------------------CIRCULAR LINKED LIST IMPLEMENTATION THROUGH STL------------------" << endl << endl;

    list<int> circularLinkedList;

    // Insertion
    circularLinkedList.push_back(1);
    circularLinkedList.push_back(2);
    circularLinkedList.push_back(3);

    // Making it circular
    circularLinkedList.push_back(circularLinkedList.front());

    // Deletion
    circularLinkedList.pop_back();

    // Printing
    for (auto element : circularLinkedList) {
        cout << element << " ";
    }
    cout << endl;

}


