#include <iostream>
#include <queue>
using namespace std;

class CirQueue
{
public:
        int size;
        int *arr;
        int front;
        int rear;

        CirQueue(int size)
        {
                this->size = size;
                arr = new int[size];
                front = -1;
                rear = -1;
        }

        void push(int data)
        {

                // Queue Full
                if ((front == 0 && rear == size - 1))
                {
                        cout << "Q is fulll, cannot insert" << endl;
                }
                // single element case - > first element
                //  Means pushing first only single element

                else if (front == -1)
                {
                        // then front and rear ko aage bdha denge at 0th index pr
                        // Initially wo dono front and rear == -1 pr tha ,
                        // Which means , both are at -ve index queue is empty
                        front = rear = 0;
                        arr[rear] = data;
                }
                // circular nature
                else if (rear == size - 1 && front != 0)
                {
                        // means  agr front -1 pr nhi haii , or rear = size-1 hai
                        // Ab mujhe piche se element push krna start kr dena chaiye
                        //  So that's why mai rear = 0 , krdunga jisse mai aage value daal skuu
                        rear = 0;
                        arr[rear] = data;
                }
                // normal flow
                else
                {
                        //  normal case me jaise hi mai first element daalunga tbhi mai front ko -1 se 0 krdunga
                        //  phr simple rear me value daal kr rear++ krte rhunga
                        rear++;
                        arr[rear] = data;
                }
        }

        void pop()
        {

                // empty check
                if (front == -1)
                {
                        cout << "Q is empty , cannot pop" << endl;
                }
                // single element
                else if (front == rear)
                {
                        arr[front] = -1;
                        front = -1;
                        rear = -1;
                }
                // circular nature
                else if (front == size - 1)
                {
                        front = 0;
                }
                // normal flow
                else
                {
                        //  kuch delete nhi krunga ,
                        // bs front++ krte rhunga
                        front++;
                }
        }

        int getSize()
        {
                return rear - front;
        }

        // This is how i print data

        void printQueue()
        {
                int i = front;
                cout << "i is : " << i << endl;

                if (front == -1)
                {
                        cout << "Q is empty" << endl;
                        return;
                }

                do
                {
                        cout << arr[i] << " ";
                        i = (i + 1) % size;
                } while (i != (rear + 1) % size);

                cout << endl;
        }
};

int main()
{

        CirQueue cq(5);

        cout << "the size is : " << cq.size << endl;

        cq.push(10);
        cq.push(20);
        cq.push(30);
        cq.push(40);
        cq.push(50);
        cq.push(60);

        cout << "Elements in the queue: " << endl;
        cq.printQueue();

        return 0;
}
