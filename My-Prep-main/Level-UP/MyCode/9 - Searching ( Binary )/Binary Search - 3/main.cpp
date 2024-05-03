#include <iostream>
#include <vector>
using namespace std;

// *********************************************************************************
/*
Approach 1 - Apply Linear search
             TC - o(N)
Approach 2 - First sort the Array , then apply Binary search
             TC - o(nlogn) which is very higher than O(N)

Approach 3 - Binary Search
             TC - o(logn)
*/

int searchInNearlySortedArray(vector<int> arr, int target)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        // Handle three cases after finding mid , because generally
        // our value is present at arr[mid] , arr[mid-1] , arr[mid+1]

        if (target == arr[mid])
            return mid;
        else if (mid + 1 < n && target == arr[mid + 1])
            return mid + 1;
        // else if(mid-1>s && target == arr[mid-1])     // this will also work
        else if (mid - 1 >= 0 && target == arr[mid - 1])
            return mid - 1;

        if (target < arr[mid])
            e = mid - 2;
        // e = mid - 1;     // this will also check , that's why we goona mid + 2
        else
            s = mid + 2;
        // s = mid + 1;     // this will also check , that's why we goona mid - 2

        mid = s + (e - s) / 2;
    }

    return -1;
}

// ********************************************************************************

int oddOcc(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e) // also when mid is end
            return mid;

        if (mid & 1)
        {
            if (arr[mid - 1] == arr[mid]) // arr[even] = arr[odd]     we are at left  goto right
                s = mid + 1;
            else
                e = mid - 1; // mid cant be ans and goto left
        }
        else
        {
            if (arr[mid] == arr[mid + 1]) // arr[even] = arr[odd]     we are at left  goto right
                s = mid + 2;
            else
                e = mid; // mid can be ans and goto left
        }

        mid = s + (e - s) / 2;
    }

    return -1;
}

// ********************************************************************************

int main()
{

    // binary search in nearly sorted array
    // every element in ith position in sorted array will found in i, i+1 or i-1 position in nearly sorted array
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    int ans = searchInNearlySortedArray(arr, target);
    if (ans != -1)
        cout << "target found at index " << ans << '\n';
    else
        cout << "target not found\n";

    /*
    Inputs ->>
    7
    10 3 40 20 50 80 40
    40
    */

    // ********************************************************************************

    // find odd occuring element
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = oddOcc(arr);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
// binary search in nearly sorted array
7
10 3 40 20 50 80 40
40

// find odd occuring element
15
1 1 2 2 1 1 2 2 13 1 1 4 4 6 6
*/