#include <iostream>
#include <deque>
using namespace std;

int main()
{
        // creation
        deque<int> dq;

        dq.push_front(5);
        dq.push_front(10);

        dq.push_back(20);
        dq.push_back(30);

        // This is how calculate size in deque

        cout << "Size: " << dq.size() << endl;

        //  Pop from front
        dq.pop_front();

        // Pop from back
        dq.pop_back();

        cout << "Front:  " << dq.front() << endl;
        cout << "back: " << dq.back() << endl;

        if (dq.empty())
        {
                cout << "DQ is empty" << endl;
        }
        else
        {
                cout << "DQ is not empty" << endl;
        }

        return 0;
}