#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ***********************************************************************************

// TC- O(logn)
int binarySearch(int arr[], int n, int target)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int element = arr[mid];

        if (target == element)
            return mid;
        else if (target < element)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        // Again need to find Mid
        mid = s + (e - s) / 2;
    }

    // if element not found
    return -1;
}

// ***********************************************************************************

// TC- O(logn)
int firstOccurence(vector<int> arr, int target)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1; // if not found, return -1

    while (s <= e)
    {
        int element = arr[mid];

        if (target == element)
        {
            ans = mid;   // store in ans
            e = mid - 1; // check in left
        }
        else if (target < mid)
            e = mid - 1;
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }

    return ans;
}

// ***********************************************************************************

int main()
{

    // binary search

    int arr[] = {2, 4, 6, 8, 10, 12, 16};
    int size = 7;
    int target = 2;

    int ans = binarySearch(arr, size, target);

    if (ans == -1)
    {
        cout << "target not found\n";
    }
    else
    {
        cout << "target found at index " << ans << '\n';
    }

    // ******************************************************************************************

    // binary search using STL

    vector<int> arr{1, 2, 3, 4, 5, 6};
    int target = 10;

    // Always return in boolean form , wheteher true or false
    // If not able to found return false otherwise true
    bool ans = binary_search(arr.begin(), arr.end(), target);
    cout << ans << '\n';
    if (ans)
        cout << "target found\n";
    else
        cout << "target not found\n";

    // ******************************************************************************************

    // find first occurence of an element in sorted array
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int ans = firstOccurence(arr, target);
    cout << ans << '\n';

    // ******************************************************************************************

    // first and last occurence of an element in sorted array using STL

    vector<int> arr{1, 2, 3, 4, 4, 5, 6};
    int n = 6;

    int target = 5;

    // For First Occurance
    // Always return index value start index from 0th index
    auto lowerBound = lower_bound(arr.begin(), arr.end(), target);
    int ans = lowerBound - arr.begin();
    cout << ans << '\n';

    //  For Last Occurance
    // Always return index value start index from 0th index
    auto upperBound = upper_bound(arr.begin(), arr.end(), target);
    int ans2 = upperBound - arr.begin() - 1;
    cout << ans2 << '\n';

    // total number of occurences of an element in sorted array using STL

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    // Total Occurance = ( Last Occurance - First Occurance ) + 1

    int upperBound = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    int lowerBound = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int ans = upperBound - lowerBound;
    // (0 index value )

    //  if we want 1 index value
    // use Total Occurance = ( Last Occurance - First Occurance ) + 1

    cout << ans << '\n';

    // ******************************************************************************************

    return 0;
}
