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
    // Parameterised Constructor
    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    // Destruvtor
    ~Node()
    {
        cout<<"Node with value :"<<this->data<<"deleted";
    }

};

void printlist(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getlen(Node *head)
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

// send head and tail by Address ,
// because hum saare changes apne origibak head or tail variable me chahte hai
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // if Linked-List is empty, so insert an data and say head and tail
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

// send head and tail by Address ,
// because hum saare changes apne origibak head or tail variable me chahte hai
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        // if position == 1 , insert at head
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }

        int len = getlen(head);

        if (position > len)
        {
            insertAtTail(head, tail, data);
            return;
        }

        int i = 1;
        Node *prevnode = head;
        while (i < position - 1)
        {
            prevnode = prevnode->next;
            i++;
        }

        Node *currnode = prevnode->next;
        // step-1 find previous node and current node
        Node *newnode = new Node(data);
        // step -2
        prevnode->next = newnode;
        // step -3
        newnode->prev = prevnode;
        // step -4
        currnode->prev = newnode;
        // step -5
        newnode->next = currnode;
    }
}

// DELETE
void deleteFromPos(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << " Linked List is empty ." << endl;
        return;
    }

    // LETS SUPPOSE HAMARE PSS Single Node hai
    if (head->next == NULL)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    int len = getlen(head);
    if (position > len)
    {
        cout << "Please enter a valid position" << endl;
    }

    if (position == 1)
    {
        // head ko delete krna hai islea temp me daal dia
        Node *temp = head;
        // head ko point krwa dia head ke next se
        head = head->next;
        // head ke prev me null daal dia
        head->prev = NULL;

        temp->next = NULL;
        delete temp;
        return;
    }

    if (position == len)
    {
        // delete last node
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    // delete from middle of linked list

    // step1: find left, curr, right
    int i = 1;
    Node *left = head;
    
    while (i < position - 1)
    {
        left = left->next;
        i++;
    }
    Node *curr = left->next;
    Node *right = curr->next;

    // step2:
    left->next = right;
    // step3:
    right->prev = left;

    // step4:
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

int main()
{
    //                               1st Method

    // Node* first = new Node(50);
    // Node* second = new Node(60);
    // Node* third = new Node(70);

    // Node *head = first;
    // Node *tail = third;

    // // Linking Between Nodes
    // first->next = second;
    // second->prev = first;

    // second->next = third;
    // third->prev = second;

    // printlist(first);
    // cout<<endl;

    // insertAtHead(head, tail, 40);
    // insertAtHead(head, tail, 30);
    // printlist(head);

    // // Insertion at Tail
    // cout << endl;

    // insertAtTail(head, tail, 80);
    // insertAtTail(head, tail, 100);

    // printlist(head);

    //                                 2nd Method

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    printlist(head);

    // Insertion at Tail

    cout << endl;

    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    printlist(head);

    cout << endl;

    // Insert At Position

    insertAtPosition(head, tail, 1, 100);
    insertAtPosition(head, tail, 4, 430);
    printlist(head);

    // Delete
    cout << "after deleting :" << endl;
    deleteFromPos(head, tail, 2);

    cout << endl;
    printlist(head);
    cout << endl;

    return 0;
}
