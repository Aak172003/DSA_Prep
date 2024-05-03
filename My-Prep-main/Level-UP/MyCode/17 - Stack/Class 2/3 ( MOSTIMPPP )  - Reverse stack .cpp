/*
GFG Link - https://practice.geeksforgeeks.org/problems/reverse-a-stack/1

stack me pop krte krte hr ek stage me ek element sambhal kr rkhna hai ,
so usko insert at bottom lga kr put kr dena hai stack ke last element me

*/

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target)
{

    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    // recursion cal
    insertAtBottom(s, target);
    // BackTrack
    s.push(topElement);
}

void reverseStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    // reverse stack
    reverseStack(s);
    // insert at bottom target ko
    insertAtBottom(s, target);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);

    cout << "Printing" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}