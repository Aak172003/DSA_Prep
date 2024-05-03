#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    //                                                                    array
    // int arr[] = {1,5,6,9,8,5,3,4} ;

    // Max - Heap
    // priority_queue<int>pq(arr , arr + 8) ;

    // Min - Heap
    // priority_queue<int , vector<int> , greater<int>>pq(arr , arr + 8) ;

    //                                                                    vector
    vector<int> arr{10, 2, 3, 6, 4, 8, 9, 5};

    // Max - Heap
    priority_queue<int> pq(arr.begin(), arr.end());

    // Min - Heap
    // priority_queue<int , vector<int> , greater<int>>pq(arr.begin() , arr.end()) ;

    cout << "Elements Inserted" << endl;

    cout << "Top Element -> " << pq.top() << endl;
    pq.pop();
    cout << "Top Element -> " << pq.top() << endl;

    //  Size
    cout << "Size of PQ -> " << pq.size() << endl;

    return 0;
}
