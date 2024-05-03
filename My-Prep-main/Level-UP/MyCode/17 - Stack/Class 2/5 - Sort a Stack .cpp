#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int target)
{
        // base case
        // wapas jaate time hum first value dal die
        if (s.empty())
        {
                s.push(target);
                return;
        }

        // here check condition ki top pr jo value hai agr bdi
        // This help sort in Descending Order
        // s.top < target

        //  ******************************************************************************************

        // This for Ascenfing order
        if (s.top() >= target)
        {
                // agr targetchota hota hai s.top se to directly insert krdnge or return kr denge
                s.push(target);
                return;
        }

        int topElement = s.top();
        s.pop();
        insertSorted(s, target);

        // BT
        s.push(topElement);
}

void sortStack(stack<int> &s)
{
        // base case
        if (s.empty())
                return;

        // top element nikala or pop krdia from stack
        int topElement = s.top();
        s.pop();

        // br br nikalte gye
        sortStack(s);

        // stack empty hone ke bdd insert sort call hogya
        insertSorted(s, topElement);
}

int main()
{
        stack<int> s;
        s.push(7);
        s.push(11);
        s.push(3);
        s.push(5);
        s.push(9);

        sortStack(s);

        cout << "Printing" << endl;
        while (!s.empty())
        {
                cout << s.top() << " ";
                s.pop();
        }
        cout << endl;
        return 0;
}
