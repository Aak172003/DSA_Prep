#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // Default Constructor
    Node()
    {
        this->prev = NULL;
        this->data = 0;
        this->next = NULL;
    }

    // Parameterise Constructor
    Node(int data)
    {
        this->next = NULL;
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);

    cout << endl;
    int length = getLength(first);
    cout << "the LL length is : " << length << " ";

    return 0;
}