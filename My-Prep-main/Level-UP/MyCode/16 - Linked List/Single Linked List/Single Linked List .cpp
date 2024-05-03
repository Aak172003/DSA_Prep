#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default Constructor

    // For first node when cretaed
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    // Parameterise Constructor

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // TODO: Write a destrcutor to delete a node
    ~Node()
    {

        // value me store islea kia kyuki mai bdd me bta skuu ki maine kon si value free kraya huu
        int value = this->data;

        // Memory Free Krane ka Code ,
        //  agr jisko delete kr rhe hai agr wo kisi or ,
        // ko bhi point kr rha hai to waha se bhi usko disconnect krna pdega

        //                         Optional

        // if (this->next != NULL)
        // {
        //     delete next;
        //     this->next = NULL;
        // }

        cout << "Memory is Free : " << value << endl;
    }
};

// Here we count find the Length
int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// I want to insert a node at the head of Linked List

// Insert At  Head Function
// Here we take reference kyuki mai nhi chahta ki copy bne usme operation ho ,
// balki mai chahta hu ki meri original
// Linked list me change ho jae

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // check for Empty LL, if there is no any Node
    if (head == NULL || tail == NULL)
    {
        Node *newNode = new Node(data);
        // jb we have no node , to jo new node bnaega ussi ko mai sbse phle
        // head or tail bna dunga

        head = newNode;
        tail = newNode;
    }

    // tail update islea nhi krenge kyuki , insert at head krne se phle tail previous node pr tha ,
    // insert krenge to head pointer aage jaega tail , to wohi rhega

    else
    {
        // step1:
        Node *newNode = new Node(data);
        // step2:
        newNode->next = head;
        // step3:
        head = newNode;
    }
}

// I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // check for Empty LL, if there is no any Node
    if (head == NULL)
    {
        // Create new node
        Node *newNode = new Node(data);
        /* Agr head null hai to hum first node ko hi head and tail keh denge */
        head = newNode;
        tail = newNode;
        /*

        return;
        // Chahe return krlo if me otherwise if-else ke sth khel lo
        */
    }
    else
    {
        // step1: creatae a node
        Node *newNode = new Node(data);
        // step2: connect woth tail ndoe
        tail->next = newNode;
        // step3: update tail;
        tail = newNode;
    }
}

// Insert at Middle / or any Particular POSITION

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{

    //   Maan lo head null hota hai
    if (head == NULL)
    {
        // so ek node bnega , jo ki wohi head & tail dono kehlaega  ,
        // or return kr jaega
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // step1: find the position: prev & curr;
    //  lets suppose usne position = 0 dia means insert at Head call
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // FIND Length -> jisse hum ll me traverse kr ske ,
    // us target value ko find krne ke lie
    int len = findLength(head);

    // IF position agr jyada deta hai Current Linked list ki length se
    // to hum insertAtTail ko call krdenge
    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // ste1:find prev and curr

    int i = 1;
    Node *prev = head;
    // i ek variable lia hai jo ki jaise hi position ko reach
    // reach kr jaati hai to ,
    // hum us prev pr pauch jaate hai

    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    // to hum curr me prev ka next daal denge . ,
    // kyuki hume element un dono ke beech me insert krna hai
    // jisse hum in dono ka use kke inke beech me value put krdenge

    Node *curr = prev->next;

    // Link tut na jae uska dhyan jaroor rkhna hai
    // step2;
    //  create new node
    Node *newNode = new Node(data);

    // step3:
    newNode->next = curr;

    // step4:
    prev->next = newNode;
}

//                              DELETE

void deleteNode(int position, Node *&head, Node *&tail)
{

    // if list is empty , so ll is empty
    if (head == NULL)
    {
        cout << "Cannot delete, LL is empty";
        return;
    }

    // deleting first node
    if (position == 1)
    {
        // Phle temp me us first node ka access le lenge ,
        // jisse usko delete kr pae or delete krne ke time pr ,
        // uska datanikal kr dikha pae ,
        // ki kon sa data delete hua
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);

    // deleting last node
    if (position == len)
    {
        // find prev
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        // step2:
        prev->next = NULL;
        // step3: -> temp me tail daal dia ,
        // jisse ki prev jo hai usko , tail bna ske
        Node *temp = tail;
        // step4: -> update tail
        tail = prev;
        // step5: -> delete
        delete temp;
        return;
    }

    // deleting middle node

    // step  : find prev and curr
    int i = 1;
    Node *prev = head;
    // i ek variable lia hai jo ki jaise hi position ko reach
    // reach kr jaati hai to , hum us prev pr pauch jaate hai
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    // to hum curr me prev ka next daal denge .
    // jisse hum in dono ka use kke inke beech ki value delete krdenge
    Node *curr = prev->next;

    // step2:
    prev->next = curr->next;
    // step3:
    curr->next = NULL;
    // step4:
    delete curr;
}

// How to Traverse in Linked List
// send head reference to traverse from head upto final Linked List

// For printing the data
void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    // Initial me

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);
    insertAtTail(head, tail, 77);

    print(head);
    cout << endl;
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAtPosition(101, 5, head, tail);
    cout << "Printing after insert at position call" << endl;
    print(head);
    cout << endl;
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    deleteNode(50, head, tail);
    cout << endl;
    print(head);
    cout << endl;

    return 0;
}