#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
    Node *next;
    int data;
};

Node *InsertionSort(Node *front, Node *current, int data);

int main()
{

    ifstream inputstream("numbers.txt");
    string line;
    Node *head = nullptr;
    Node *current;

    if (inputstream.is_open())
    {

        while (inputstream >> line)
        {
            if (head == nullptr)
            {
                head = new Node();
                current = head;
                current->data = stoi(line);
                current->next = nullptr;
            }
            else
            {
                current = InsertionSort(head, current, stoi(line));
            }
            //current -> data = stoi(line);
        }
        cout << "debug statemnt" << endl;
        current = head;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    return 0;
}

Node *InsertionSort(Node *front, Node *current, int number)
{
    Node *traversal = front;
    Node *new_node = new Node();
    new_node->next = nullptr;
    Node *previous = traversal;
    new_node->data = number;
    cout << number << endl;
    if (current->data <= number)
    {

        current->next = new_node;
        current = current->next;
        current->next = nullptr;
        return current;
    }

    while (traversal != nullptr)
    {
        if (number > traversal -> data)
        {
            previous = traversal;
            traversal = traversal->next;
        }
        
    }
    return traversal;
}
