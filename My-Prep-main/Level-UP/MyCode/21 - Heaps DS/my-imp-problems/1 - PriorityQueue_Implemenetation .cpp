#include <iostream>
#include <queue>
using namespace std;

void showpriorityQueue(priority_queue<int> pq)
{
    priority_queue<int> q = pq;
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    // Priority Queue internally work on Max Heap Data Structure
    priority_queue<int> pq;
    pq.push(-10);
    pq.push(15);
    pq.push(5);
    pq.push(-8);
    pq.push(27);
    //                           27
    //                          /  \
    //                        15    5
    //                      /   \
    //                    -8   -10

    showpriorityQueue(pq);
    cout << "size is : " << pq.size();
}
