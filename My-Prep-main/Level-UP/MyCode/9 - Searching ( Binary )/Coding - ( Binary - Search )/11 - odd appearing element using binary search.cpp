/*
******************************          Approach - 1 - Sorting

A Simple Solution is to sort the array and then traverse the array from left to right.
Since the array is sorted, we can easily figure out the required element.

arr[] = {1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40, 13, 13}

After sorted
arr[] = {1, 1,1, 1,1, 1, 2, 2, 2, ,2, 13,13, 13 , 40, 40}

isme ek count = 1 bna lo ;
for() loop chala kr array me traverse krna hai ,

// Constions Check
arr[] = {1, 1, 1, 1,1, 1, 2, 2, 2, ,2, 13,13, 13 , 40, 40}

check if(arr[i-1]==arr[i])
{
    count++;
}

************** 1st Iteration
//       |
arr[] = {1, 1,1, 1, 1, 1, 2, 2, 2, ,2, 13,13, 13 , 40, 40}

count = 1

************** 2nd Iteration
//          |
arr[] = {1, 1, 1, 1, 1, 1, 2, 2, 2, ,2, 13,13, 13 , 40, 40}

check if(arr[i-1]==arr[i])

count = 2

************** 3rd Iteration

//             |
arr[] = {1, 1, 1, 1, 1, 1, 2, 2, 2, ,2, 13,13, 13 , 40, 40}

check if(arr[i-1]==arr[i])

count = 3

************** 4rth Iteration
//                |
arr[] = {1, 1, 1, 1, 1, 1, 2, 2, 2, ,2, 13,13, 13 , 40, 40}

check if(arr[i-1]==arr[i])

count = 4

************** 5th Iteration
//                   |
arr[] = {1, 1, 1, 1, 1, 1, 2, 2, 2, ,2, 13,13, 13 , 40, 40}

check if(arr[i-1]==arr[i])

count = 5

************** 6th Iteration
//                      |
arr[] = {1, 1, 1, 1, 1, 1, 2, 2, 2, ,2, 13,13, 13 , 40, 40}

check if(arr[i-1]==arr[i])

count = 6

************** 7th Iteration

//                         |
arr[] = {1, 1, 1, 1, 1, 1, 2, 2, 2, ,2, 13,13, 13 , 40, 40}

check if(arr[i-1]==arr[i])
so yaha pr above condition fails , so check krlo count%2 ==0
so simple aage bdh jao , aur count wapas initialsie with 1

Then Again above steps

Time complexity of this solution is O(n Log n)

*/

/*


******************************          Approach - 2 - XOR

A Better Solution is to do XOR of all elements, result of XOR would give the odd appearing element.
Time complexity of this solution is O(n).

1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40, 13, 13

1 ^ 1 ^ 2^ 2 ^ 1 ^ 1 ^2 ^ 2 ^ 13 ^ 1 ^ 1 ^ 4 0 ^ 40 ^ 1 3 ^ 13

at last we receive and  = 13 bcoz even no br koi duplicate present hai to wo usko remove krdegi

*/

// ******************************          Approach - 3 - Binary Search

// 1) Find the middle index, say ‘mid’.
// 2) If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are same, then there is an odd occurrence of the element after ‘mid’ else before mid.
// 3) If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are same, then there is an odd occurrence after ‘mid’ else before mid.

#include <iostream>
#include <vector>
using namespace std;

void search(int *arr, int low, int high)
{
    // Base cases
    if (low <= high)
    {
        printf("The required element is %d ", arr[low]);
        return;
    }

    // Find the middle point
    int mid = (low + high) / 2;

    // If mid is even and element next to mid is
    // same as mid, then output element lies on
    // right side, else on left side
    if (mid % 2 == 0)
    {
        if (arr[mid] == arr[mid + 1])
            search(arr, mid + 2, high);
        else
            search(arr, low, mid);
    }
    else // If mid is odd
    {
        if (arr[mid] == arr[mid - 1])
            search(arr, mid + 1, high);
        else
            search(arr, low, mid - 1);
    }
}

// Driver program
int main()
{
    int arr[] = {1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40};
    int len = sizeof(arr) / sizeof(arr[0]);
    search(arr, 0, len - 1);
    return 0;
}