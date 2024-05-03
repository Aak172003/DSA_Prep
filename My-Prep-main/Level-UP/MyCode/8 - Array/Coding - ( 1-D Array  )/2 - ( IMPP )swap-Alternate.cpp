
/*
Codestudio Link  -   https://www.codingninjas.com/codestudio/problems/swap-alternate_624941?leftPanelTab=1
*/

// #include <bits/stdc++.h>
// void swapAlternate(int *arr, int n);

void swapAlternate(int arr[], int size)
// function ko Initialse krte time hum ,
// parameter pass krte time usme data type jaroor denge

{
    // 1st Approach , To Swap Alternate
    for (int i = 0; i < size; i++)
    {
        // if i+1 size ke ander tk hota to hi hum swap kr paenge
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
            i++;
        }
    }

    // 2ND Approach , To swap Alternate
    for (int i = 1; i < size; i = i + 2)
    {
        if (i < size)
        {
            swap(arr[i - 1], arr[i]);
        }
    }

    // 3rd Approach , To swap Alternate
    for (int i = 0; i < n - 1; i++)
    {
        swap(arr[i], arr[i + 1]);
        i++;
    }
}
