
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int target, int count)
{
    // s ka size always be same
    int size = (s.size() / 2) + 1;
    // Base Case

    if (count == size)
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    // Reccursion
    solve(s, target, count + 1);

    // Backtrack
    s.push(temp);
}

void insertAtBottom(stack<int> &s)
{
    if (!s.empty())
    {
        // this is used to fetch first element
        int target = s.top();
        s.pop();

        int count = 0;
        solve(s, target, count);
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    insertAtBottom(s);

    while (!s.empty())
    {
        cout << "The data is " << s.top() << endl;
        s.pop();
    }

    return 0;
}
