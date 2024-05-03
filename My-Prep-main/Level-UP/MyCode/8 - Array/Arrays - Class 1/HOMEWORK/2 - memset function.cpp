
/*
memeset(arr,value,sizeof(arr));

// Memset is same as fill_n(arr, size , value)
// Memset me hum -1 or 0 ke alava or kuch nhi daal skte poore array me

//                    And

fill_n(arr,size,value);

but this is not same as Memset but if work for different value
int num[100] = {24};    give an error , in memset .
so to remove this error use fill_n(num,100,24); to fill 24 at all array index

*/

#include <iostream>
using namespace std;

int main()
{
    // This will print 0 0 0 0 0 0 0 upto 99 index
    // But hum 0 ke alava or koi is tarah se daalna chae to ye kaam nhi krta
    int num[100] = {0};
    for (int i = 0; i < 100; i++)
    {
        cout << num[i] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // memset function to initialize an array with 0 or -1 (not work on other value)s
    int arr[10];
    memset(arr, -1, sizeof(arr));
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int num[100];
    fill_n(num, 100, 24);

    for (int i = 0; i < 100; i++)
    {
        cout << num[i] << endl;
    }
    return 0;
}
