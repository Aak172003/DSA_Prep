#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default Constructor
    // For first Node Created
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// For Printing the data
void print(Node *head)
{
    // initially temp first node ke address ko pint krega , via storing first node ka address
    Node *temp = head;
    // actually here temp store address

    int i = 0;

    while (temp != NULL)
    {
        cout << "i is : " << i << endl;
        cout << "the data is " << temp->data << endl;
        temp = temp->next;
        i++;
        // When if temp == null means aage or koi element nhi hai jiska address ye stoere krega
    }
}

int main()
{
    Node *node1 = new Node(20);
    Node *node2 = new Node(30);
    Node *node3 = new Node(40);
    Node *node4 = new Node(50);
    Node *node5 = new Node(60);

    // Way to connect all linked List
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    //     // Store Address

    // cout<<"n1 Address is : "<<n1<<endl;
    // cout<<"n1 Address is : "<<n2<<endl;
    // cout<<"n1 Address is : "<<n3<<endl;
    // cout<<"n1 Address is : "<<n4<<endl;

    // // Store Data

    // cout<<"n1 data is : "<<n1->data<<endl;
    // cout<<"n1 data is : "<<n2->data<<endl;
    // cout<<"n1 data is : "<<n3->data<<endl;
    // cout<<"n1 data is : "<<n4->data<<endl;

    // Taking head pointer bcoz ,
    //  printing ke lie first node ka address chaiye hota hai
    Node *head = node1;
    // Call Print function
    print(head);

    return 0;
}
