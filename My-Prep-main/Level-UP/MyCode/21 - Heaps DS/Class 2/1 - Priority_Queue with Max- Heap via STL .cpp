
#include <iostream>
#include <bits/stdc++.h>
// OR
// #include <queue>
using namespace std;

int main()
{

    // By Default priority-queue : folow Max-Heap Property
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(90);
    pq.push(80);
    pq.push(60);
    pq.push(30);

    cout << "Elements Inserted" << endl;

    cout << "Top Element -> " << pq.top() << endl;
    pq.pop();
    cout << "Top Element -> " << pq.top() << endl;

    //  Size
    cout << "Size of PQ -> " << pq.size() << endl;

    // Check if Empty or not
    if (pq.empty())
    {
        cout << "pq is Empty " << endl;
    }
    else
    {
        cout << "pq have some Element " << endl;
    }

    // Print elements in the priority queue
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}