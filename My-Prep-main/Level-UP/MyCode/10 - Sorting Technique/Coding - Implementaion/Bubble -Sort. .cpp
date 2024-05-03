

#include <bits/stdc++.h>
void bubbleSort(vector<int> &arr, int n)
/*
Function Calling me jo n means size dia hai wo orginal size dia uski starting from 1 hai
But if we want to start index at 0 so we go N-1 size array
*/
{
    // Write your code here.

    // first loop iterate form , no of passes
    for (int round = 0; round < n - 1; round++)
    {
        // second loop iterate for comparisons , or swapping , ye br br last elemts tk jaega
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

{
    bool swapped = false;

    for (int round = 0; round < n - 1; round++)
    {
        // if sorted hoga to , phle hi pss me pta lg jaega , agr no swapping means , elemets alredy in sorted order
        // i krne se , hr ek ek loop me sort hoga last element , to hum dubara loop usse ek phle tk hi chalenge ,
        // jaha tk sort hogy hai
        for (int j = 0; j < n - round; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // if no swapping occur means , array is alreaady sorted, in ascending order
        if (swapped == false)
        {
            break;
        }
    }
}
