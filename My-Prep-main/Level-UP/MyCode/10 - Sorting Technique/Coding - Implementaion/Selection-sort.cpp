Examples of stable sorting algorithm : Bubble sort, Insertion sort, Merge sort, Counting sort, Tim sort

                                                                                                   Examples of unstable sorting algorithm : Selection sort,
                                                                                                                                            Heap sort,
                                                                                                                                            Shell sort,
                                                                                                                                            Quicksort.

                                                                                                                                                Image->> From Below Link

/*

Coding Ninja link - https://www.codingninjas.com/codestudio/problems/selection-sort_981162?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1
*/

// Stable Sorting Algorithms -  Link ( https://medium.com/@souravganguly_32007/stable-and-unstable-sorting-c9f114a50dae#:~:text=Hence%2C%20the%20former%20is%20a%20Stable%20sorting%20algorithm,algorithm%3A%20Selection%20sort%2C%20Heap%20sort%2C%20Shell%20sort%2C%20Quicksort. )

#include <bits/stdc++.h>
                                                                                                                                                void
                                                                                                                                                selectionSort(vector<int> &arr, int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        // Take 1st As minimum Value index
        int min_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            // Compare if any value is lesser than our assumption value so update minimum index
            // ye process br br chalega jisse agr first me minimum mila or last me sbse minimum mila to wo min_idx me store hojaega
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        // Swap uing Scratch Method
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        // Use inbuilt Function
        // swap(arr[i],arr[min_idx]);
    }
}
