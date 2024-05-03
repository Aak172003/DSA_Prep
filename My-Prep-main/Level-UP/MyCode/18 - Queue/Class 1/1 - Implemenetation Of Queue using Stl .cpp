#include <iostream>
#include <queue>
using namespace std;

int main()
{
        // creation
        queue<int> q;

        // insertion
        q.push(5);
        q.push(15);
        q.push(25);
        q.push(55);

        // size
        cout << "Size of queue is:  " << q.size() << endl;

        // removal
        // int store = q.pop();

        // cout<<"the Popped element is : "<<q.front()<<endl;

        while (!q.empty())
        {
                cout << "the Popped element is : " << q.front() << endl;
                q.pop();
        }

        cout << "Know queue is empty " << endl;

        cout << "Size of queue After popping is:  " << q.size() << endl;

        if (q.empty())
        {
                cout << "Q is empty" << endl;
        }
        else
        {
                cout << "Q is not empty " << endl;
        }

        return 0;
}