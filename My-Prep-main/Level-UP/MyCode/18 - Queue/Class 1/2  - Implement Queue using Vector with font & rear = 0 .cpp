#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    // Constructor me size dia , then us size ke hisab se ek array create kia ,
    //  Then us array me value insert kr rha huu
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];

        // initialise front at extreme left and rear at extreme right
        front = 0;
        rear = 0;
    }

    // Initial me ek point hoga , jiko front and rear point kr rhe honge ,
    // then hum jb jb value daalenge , tb tb rear ko ++ krte rhenge
    //  Or if rear == size so means array is full

    void push(int data)
    {
        if (rear == size)
        {
            cout << "Q is full " << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        //  if front == rear means kuch nhui hai
        if (front == rear)
        {
            cout << "Q is empty" << endl;
        }
        else
        {
            // hum value delete nhi krenge balki waha pr -1 value assign kr denge
            arr[front] = -1;
            front++;

            // front aage badhate badhate rear ke barabar aagya ,
            // it means queue is empty
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Q is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        // means front or rear me koi value nhi hai
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //  If mujhe size nikalna hai , to hume rear - front krdenge
    int getSize()
    {
        // because data present in between rear and front
        return rear - front;
    }
};

int main()
{
    Queue q(10);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout << "Size of queue is: " << q.getSize() << endl;

    q.pop();

    cout << "Size of queue is: " << q.getSize() << endl;

    cout << "Front element is: " << q.getFront() << endl;

    if (q.isEmpty())
    {
        cout << "Q is empty" << endl;
    }
    else
    {
        cout << "Q is not empty" << endl;
    }

    return 0;
}