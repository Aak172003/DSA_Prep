#include <iostream>
using namespace std;

class Deque
{
public:
        int *arr;
        int size;
        int front;
        int rear;

        Deque(int size)
        {
                this->size = size;
                arr = new int[size];

                // Initially
                front = -1;
                rear = -1;
        }

        void pushRear(int data)
        {
                // check queue is full (front == 0 && rear == size - 1) means queue is full
                if ((front == 0 && rear == size - 1))
                {
                        cout << "Q is fulll, cannot insert" << endl;
                        return;
                }
                // if queue is empty so push an element and front = rear = 0 initialise
                else if (front == -1)
                {
                        front = rear = 0;
                }
                // Circular push , front not 0th index but rear at last index
                else if (rear == size - 1 && front != 0)
                {
                        rear = 0;
                }
                // normal flow
                else
                {
                        rear++;
                }
                arr[rear] = data;
        }

        void pushFront(int data)
        {
                // TODO: add one more condition in the QUEUE FULL if block
                if ((front == 0 && rear == size - 1))
                {
                        cout << "Q is fulll, cannot insert" << endl;
                        return;
                }
                else if (front == -1)
                {
                        front = rear = 0;
                }
                // if front 0th index pr baitha hai ,
                // means agr or value push krna hai to front ko last index pr point krwa denge
                else if (front == 0 && rear != size - 1)
                {
                        front = size - 1;
                }
                // if front 0 pr nhi hai 0th index se kahi aage hai ,
                // means insert krne ke lie front-- krte jaenge
                else
                {
                        front--;
                }
                arr[front] = data;
        }

        void popFront()
        {
                //  if front has no element , means front = -1
                if (front == -1)
                {
                        cout << "Q is empty , cannot pop" << endl;
                        return;
                }
                // if front == rear , means single element present
                // After deleting front or rear == -1 initialsie krdena hai
                else if (front == rear)
                {
                        arr[front] = -1;
                        front = -1;
                        rear = -1;
                }
                // if front == size-1 ,
                // means hume front =0 initialsie krdena hai
                else if (front == size - 1)
                {
                        arr[front] = -1;
                        front = 0;
                }
                // normal case
                else
                {
                        arr[front] = -1;
                        front++;
                }
        }

        void popRear()
        {
                // means no element present
                if (front == -1)
                {
                        cout << "Q is empty , cannot pop" << endl;
                        return;
                }
                // means single element present
                else if (front == rear)
                {
                        arr[front] = -1;
                        front = -1;
                        rear = -1;
                }
                // if rear = 0 hai , means at 0th index ,
                // rear initialise with size-1
                else if (rear == 0)
                {
                        arr[rear] = -1;
                        rear = size - 1;
                }
                // normal case
                else
                {
                        arr[rear] = -1;
                        rear--;
                }
        }

        void print()
        {
                for (int i = 0; i < size; i++)
                {
                        cout << arr[i] << " ";
                }
                cout << endl;
        }
};

int main()
{
        Deque dq(10);
        dq.print();

        dq.pushRear(10);
        dq.pushRear(20);
        dq.pushRear(30);
        dq.pushRear(40);
        dq.pushRear(50);
        dq.pushRear(60);
        dq.pushRear(70);
        dq.pushRear(80);

        dq.print();

        dq.popRear();
        dq.print();

        dq.popRear();
        dq.print();

        dq.popFront();
        dq.print();

        dq.popFront();
        dq.print();

        dq.popFront();
        dq.print();

        dq.pushFront(101);
        dq.print();

        dq.pushFront(102);
        dq.print();

        dq.pushFront(103);
        dq.print();

        dq.pushFront(104);
        dq.print();

        dq.popFront();
        dq.print();

        dq.popFront();
        dq.print();

        dq.pushRear(201);
        dq.print();

        dq.pushRear(202);
        dq.print();

        dq.pushRear(203);
        dq.print();
        dq.pushRear(204);
        dq.print();

        dq.pushRear(205);
        dq.print();

        return 0;
}