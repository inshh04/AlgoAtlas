#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct HashTable
{
    int Capacity;
    list<int>* table;

    HashTable(int key)
    {
        this->Capacity = key;
        table = new list<int>[Capacity];
    }

    void insert(int data)
    {
        int index = data % Capacity;
        table[index].push_back(data);
    }

    void remove(int key)
    {
        int index = key % Capacity;
        list<int>::iterator it;

        for (it = table[index].begin(); it != table[index].end(); it++)
        {
            if (*it == key)
                break;
        }

        if (it != table[index].end())
        {
            table[index].erase(it);
        }
    }

    bool search(int key)
    {
        int index = key % Capacity;
        auto it = find(table[index].begin(), table[index].end(), key);

        return it != table[index].end();

    }

    void display()
    {
        for (int i = 0; i < Capacity; i++)
        {
            cout << i;
            for (auto element : table[i])
            {
                cout << " --> " << element;
            }
            cout << endl;
        }
    }
};

int main()
{
    int data[] = { 5, 12, 67, 9, 16 };

    int size = 5;

    HashTable hashing(7); // the indexes are from 0 till 6

    for (int i = 0; i < size; i++)
        hashing.insert(data[i]);

    cout << "Initially The Chaining for hashtable is : " << endl;
    hashing.display();

    int choice, key;

    do
    {
        cout << "MAIN MENU:" << endl;
        cout << "1. INSERT:" << endl;
        cout << "2. REMOVE" << endl;
        cout << "3. DISPLAY" << endl;
        cout << "4. SEARCH:" << endl;
        cout << "5. EXIT:" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            hashing.insert(key);
            break;
        case 2:
            cout << "Enter key to remove: ";
            cin >> key;
            hashing.remove(key);
            break;
        case 3:
            cout << "The Chaining for hashtable is : " << endl;
            hashing.display();
            break;
        case 4:
            cout << "Enter key to search: ";
            cin >> key;
            if (hashing.search(key))
                cout << "Key found in the hashtable." << endl;
            else
                cout << "Key not found in the hashtable." << endl;
            
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}



