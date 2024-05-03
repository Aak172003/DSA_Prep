
#include <iostream>
#include <bits/stdc++.h>
// OR
// #include <queue>
using namespace std;

int main()
{

    // Priority queue -> with min heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(10);
    pq2.push(20);
    pq2.push(90);
    pq2.push(80);
    pq2.push(60);
    pq2.push(30);

    cout << "Elements Inserted" << endl;

    cout << "Top Element -> " << pq2.top() << endl;

    pq2.pop();

    cout << "Top Element -> " << pq2.top() << endl;

    // Print elements in the priority queue
    while (!pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }
}