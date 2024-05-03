
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

int main()
{
    string name = "Aakash";
    deque<char> q;

    for (int i = 0; i < 6; i++)
    {
        cout << "the curr ele is : " << name[i] << endl;
        q.push_front(name[i]);
    }

    string reverse = "";
    while (!q.empty())
    {
        cout << "the front ele is : " << q.front() << endl;
        reverse = reverse + q.front();
        q.pop_front();
    }

    for (auto it : reverse)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "the reversed string is : " << reverse << endl;
    return 0;
}
