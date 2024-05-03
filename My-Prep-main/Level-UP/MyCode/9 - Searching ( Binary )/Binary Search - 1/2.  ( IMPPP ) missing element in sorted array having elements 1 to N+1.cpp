// find the missing element in sorted array having elements 1 to N+1

#include <iostream>
#include <vector>
using namespace std;

/*

Approach 1 -> Makintain a unorderd_mao , key and its frequenct ,
if any value has 0 frequency , so that value are missing

Time Complexity: O(n), where n is the length of given array
Auxiliary Space: O(n)

*/

/*
Approach 2->Binary Search Method

Time Complexity : O(log(N)), where N is the length of given array
Auxiliary Space : O(1)

*/

int missingElement(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = n + 1;

    while (s <= e)
    {
        // mid pr jo value hai agr uski value ,
        // mid + 2 index ke barabar hai means wo missing value left me hai ,
        // so search on left

        if (arr[mid] == mid + 2)
        {
            ans = mid + 1; // store in ans , jo missing value hai wo mid value ke just aage wali value hai
            e = mid - 1;
        }

        // Agr mid pr jo value hai , vo mid + 2 ke barabar nhi hai
        // means start ko mid + 1 , shift krke krna pdega

        // here if mid ki value mid + 2 ke barabar nhi hai , means elements increasing order me nhi hai ,
        // so which means apne ko search right me krna hai
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
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

    int ans = missingElement(arr);
    cout << ans << '\n';

    return 0;
}

index->0 1 2 3 | 4 | 5 6 7 8 1 2 3 4 | 5 | 6 8 9 10 | |
    s e

        mid = 4 check if (arr[mid] == mid + 2) agr hai means return krdo mid + 1 value kyuki wo missing hai
                                                                                   otherwise
                                                                                       s = mid + 1

                                                                                                 index->0 1 2 3 |
                                                                                           4 | 5 6 7 8 1 2 3 4 | 5 | 6 8 9 10 | |
                                                                                           s e
                                                                                               mid =