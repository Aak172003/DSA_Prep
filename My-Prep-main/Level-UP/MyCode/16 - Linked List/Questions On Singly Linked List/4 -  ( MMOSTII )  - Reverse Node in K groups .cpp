/*
Leetcode Link - https://leetcode.com/problems/reverse-nodes-in-k-group/description/
*/
// hum ek case ko solve krte hai baaki ,
// Reccursion Complete krdega

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

/**************************************************************/

void printList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " the data is : " << temp->data << " " << endl;
        temp = temp->next;
    }
    cout << endl;
}

/**************************************************************/

int getLength(Node *&head)
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

/**************************************************************/

// 1 case ke lie solve krna hai baaki reccursion samhal lega
Node *reverseKNodes(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return NULL;
    }
    int len = getLength(head);
    if (k > len)
    {
        cout << "Enter a valid value for k " << endl;
        return head;
    }

    // it means number of nodes in LL is >= k

    // code for reverse
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;

    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step B: recursive call
    if (forward != NULL)
    {
        // we still have nodes left to reverse
        // forward stor current ka next

        Node *recursionKaAns = reverseKNodes(forward, k);

        // head store 2 ka address jo ki 1 ke next me hai
        // 1 -> 2 -> 3 -> 4 -> 5 -> 6

        // head->next  , bcoz head me 2 ka address pda hai but hum forward ka address bheje hai ,
        // kyuki remaing pr same kaam forward wale address se krna hai
        head->next = recursionKaAns;
    }

    // step C: return head of the modified LL ,
    // kyuki initial me humne prev me daala , wo return krdenge
    return prev;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);

    // Connection Between Nodes

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;

    printList(head);
    cout << endl;

    // Print len
    int length = getLength(head);
    cout << "the length is :" << length << endl;

    // Reverse k Nodes
    head = reverseKNodes(head, 3); // store head means node type
    printList(head);
}
