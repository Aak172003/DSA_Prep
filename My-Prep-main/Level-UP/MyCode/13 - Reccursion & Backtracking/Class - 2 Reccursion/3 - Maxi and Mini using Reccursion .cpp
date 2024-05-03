#include <iostream>
#include <limits.h>
using namespace std;

// *****************************  GetMaxi ()   ***********************************

void getMax(int arr[], int n, int i, int &maxi)
// yaha hum maxi ko pass by refernce kr rhe hai ,
// kyuki maxi bina call by reference ke
// pass by value hoga , to function ktam hone ke bdd wo khatam ho jaega ,
// because it is like a local variable of function
{
    // if no element, return INT_MIN
    if (i == n)
        return;

    // returns max of curr element and maxi
    maxi = max(maxi, arr[i]);
    // check for remaining array
    getMax(arr, n, i + 1, maxi);
}

// *****************************  GetMini ()   ***********************************

void getMin(int arr[], int n, int i, int &mini)
// yaha hum mini ko pass by refernce kr rhe hai ,
// kyuki mini bina call by reference ke
// pass by value hoga , to function ktam hone ke bdd wo khatam ho jaega ,
// because it is like a local variable of function
{
    if (i == n)
        return;

    mini = min(mini, arr[i]);
    getMin(arr, n, i + 1, mini);
}

int main()
{

    // maximum and minimum number from an array
    int arr[] = {1, 2, 5, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    int i = 0;
    int ans = INT_MIN;
    getMax(arr, n, i, ans);
    cout << ans << '\n';

    int ans3 = INT_MAX;
    getMin(arr, n, i, ans3);
    cout << ans3 << '\n';

    return 0;
}