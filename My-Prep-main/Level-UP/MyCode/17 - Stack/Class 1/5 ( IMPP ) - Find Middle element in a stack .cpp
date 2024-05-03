#include <iostream>
#include <stack>
using namespace std;

// Iterative way
int getMiddle(stack<int> &s)
{
        int size = s.size();

        while (!s.empty())
        {
                if (s.size() == size / 2 + 1)
                {
                        return s.top();
                }
                else
                {
                        s.pop();
                }
        }
        return 0;
}

// Reccursive way
void printMiddle(stack<int> &s, int &totalSize)
{
        if (s.size() == 0)
        {
                cout << "There is no element in stack" << endl;
                return;
        }
        // base case
        if (s.size() == totalSize / 2 + 1)
        {
                cout << "Middle element is: " << s.top() << endl;
                return;
        }

        int temp = s.top();
        s.pop();

        // recursive call
        printMiddle(s, totalSize);

        // backtrack; krte time jisko pop kia tha usko humne temp me store kia hai ,
        // so usko hum dubara se push kr skte hai

        s.push(temp);
}

int main()
{
        stack<int> s;

        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
        s.push(70);

        int totalSize = s.size();
        printMiddle(s, totalSize);

        // int getMid = getMiddle(s);

        // cout << "the mid Data is : " << getMid << endl;
        // return 0;
}
