
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getLargest(int arr[], int n, int k)
{

    // Create Min Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    while (i < k)
    {
        pq.push(arr[i]);
        i++;
    }

    cout << "pq size is -> " << pq.size() << endl;

    // Bche hue elements ke lie
    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            // Pop
            // First pop , then
            pq.pop();
            // Push
            // Add value in priorty queue , priority_queue do heapify by itself
            pq.push(arr[i]);
        }
    }

    int largest = pq.top();
    return largest;
}

int getSmallestElement(int arr[], int n, int k)
{

    // Create Max Heap
    priority_queue<int> pq;
    int i = 0;
    while (i < k)
    {
        pq.push(arr[i]);
        i++;
    }

    cout << "pq size is -> " << pq.size() << endl;

    // Bche hue elements ke lie
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            // Pop
            // First pop , then
            pq.pop();
            // Push
            // Add value in priorty queue , priority_queue do heapify by itself
            pq.push(arr[i]);
        }
    }

    int smallest = pq.top();
    return smallest;
}

int main()
{

    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 3;

    // Get kth Smallest Element
    int ans = getSmallestElement(arr, n, k);

    cout << "The smallest Element is -> " << ans << endl;

    // Get kth Largest Element
    int res = getLargest(arr, n, k);

    cout << "The Largest Element is -> " << res << endl;

    return 0;
}
