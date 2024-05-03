/*
Coding Ninja Link - https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0
*/
// Using For Loop

#include <bits/stdc++.h>
void insertionSort(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++)
    {
        // temp me wo i ki value daal dia
        int temp = arr[i];
        //  initialise j with i-1,
        // value se jisse ki hum uske piche ki saari values me comoarison kr ske
        int j = i - 1;

        // hum ek ek krke piche jaate rhte hai i-1 se jb tk 0 pr nhi pauch jaate
        for (; j >= 0; j--)
        {

            // agr jo temp me hai , uski value choti hai aane waali hr value se to j ko swap kr denge
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            // or jaha aane wali value choti pdti hai temp ki value se , to hum sidha keh skte hai usko value ke just bdd apni value aaegi
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
