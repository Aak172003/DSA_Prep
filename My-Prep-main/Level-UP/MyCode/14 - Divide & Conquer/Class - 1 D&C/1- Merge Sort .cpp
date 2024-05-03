/*

Merge sort is a sorting algorithm that works by dividing an array
into smaller subarrays ,
sorting each subarray , and then merging the sorted subarrays
back together to form the final sorted array.

Is Merge sort In Place ?
No, In merge sort the merging step requires extra space to store the elements.


Is Merge sort Stable?
Yes, merge sort is stable.

One of the main advantages of merge sort is that it has a time complexity of O(n log n),
which means it can sort large arrays relatively quickly.
It is also a stable sort,
which means that the order of elements with equal values is preserved during the sort


Merge is faster than other Sorting Algorithm
Merge sort is a popular choice for sorting large datasets ,
because it is relatively efficient and easy to implement

Tc - for Merge Sort - O(N logN)
SC - for Merge sort - O(N)


*/

// ******************     Implementation

#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{

    // humne ek big array ko hi  really me 2 part me break ni kia
    // just visualise kia hai

    int mid = (start + end) / 2;

    // create two new size of array
    int len1 = mid - start + 1; // Left half
    int len2 = end - mid;       // Right half

    // create dynammic array which take dynammically memory

    int *first = new int[len1];
    // Left half size ka Dynamically array bnana hai
    int *second = new int[len2];
    // Right half size ka Dynamically array bnana hai
    // .
    // .
    // .

    // copy values left wali into left array
    // copy values

    int mainArrayIndex = start;
    // indicates starting kaha se krna hai , phle case ke array me starting 0 se hoga

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    // copy values Right wali into Right array

    mainArrayIndex = mid + 1;
    // indicates starting kaha se krna hai , second case ke array me starting mid se hoga

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // *********************************************************************************************************

    // merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = start; // variable for iterating on third array

    // starting for merging

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // yaha humne 2 new dynamically array ko create krte hai ,
    // kyuki upr wale array ko via mergesort

    // 2 different parts me divide krne ke lie
    // Jb hum Dynammocally memory allocate krte hai so usko delete krna important hota hai

    // Optional

    // delete[] first;
    // delete[] second;
}

void mergeSort(int *arr, int start, int end)
{

    // base case
    // if s == e -> single element
    // if s > e -> means invalid array

    // agr ek hi element hai ,
    // to s and e both point on same value , so it is sorted
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;

    // left part sort karna h
    mergeSort(arr, start, mid);

    // right part sort karna h
    mergeSort(arr, mid + 1, end);

    // Phle left wala part divide hota jaega until only single elmenet left
    // Then right wala part divide hota jaega until only single elmenet left

    // Then Merge hoga aakri me

    // merge krne ke lie
    merge(arr, start, end);
}

int main()
{

    int arr[15] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    int n = 15;
    // Mergesirt krne ke lie hum array , first index , or last index denge
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}