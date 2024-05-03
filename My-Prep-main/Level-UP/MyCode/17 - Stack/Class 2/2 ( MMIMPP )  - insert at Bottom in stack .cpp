

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int value)
{
    // cout<<st.size();
    if (st.empty())
    {
        st.push(value);
        return;
    }

    int data = st.top();
    st.pop();

    insertAtBottom(st, value);

    st.push(data);
}
int main()
{
    stack<int> st;
    st.push(5);
    st.push(15);
    st.push(27);
    st.push(32);
    st.push(11);

    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    int valWant = st.top();
    cout << "the top  value is : " << valWant << endl;
    st.pop();

    insertAtBottom(st, valWant);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
