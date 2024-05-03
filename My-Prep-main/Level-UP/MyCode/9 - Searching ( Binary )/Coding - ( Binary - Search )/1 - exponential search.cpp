// https://www.geeksforgeeks.org/exponential-search/

// Exponential search aslso known as
// doubling Search ,
// Galloping Search ,
// Strazile Search

// Exponential search as like Binary Search, always applicable on Sorted Array
// Exponential search is basically used on Very large size of Array

// Search in infinite Array ( Unbounded Array)
// Better than Binary Search

// Unbound Array - >Search element in an Infinite Sorted Array
To solve this Problem, we can use
#include <iostream>
#include <vector>
    using namespace std;

// TC-O(logn)
int binarySearch(vector<int> arr, int target, int s, int e)
{
    int n = arr.size();
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (target == arr[mid])
            return mid;
        else if (target < arr[mid])
            e = mid - 1;
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }

    return -1;
}

// TC-O(logn)
int exponentialSearch(vector<int> arr, int target)
{
    int n = arr.size();
    int i = 1;
    while (i < n && arr[i] <= target)
        i = i << 1;

    int s = i / 2;
    int e = min(i, n - 1);

    int ans = binarySearch(arr, target, s, e);

    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    int ans = exponentialSearch(arr, target);
    cout << ans << '\n';

    return 0;
}
