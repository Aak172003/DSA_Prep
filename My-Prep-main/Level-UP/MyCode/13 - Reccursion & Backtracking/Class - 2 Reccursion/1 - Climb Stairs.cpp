/*
LeetCode link - https://leetcode.com/problems/climbing-stairs/description/
*/

#include <iostream>
using namespace std;

//                 Using Iterative Way
int climbStairs(int n)
{
    // Lets say 0 point pr also we have 1 possible way ,
    // to reach that 0th stair ( Just onself )
    if (n <= 2)
        return n;

    int prev1 = 2, prev2 = 1, res;
    //  Same as Fibonacci Series

    for (int i = 3; i <= n; i++)
    {
        //     1     2     3     5
        //     |     |
        //   prev2  prev1
        //   res = 1  +2 = 3 ,
        //   prev2 = prev1
        //   prev1 = res
        res = prev1 + prev2;
        prev2 = prev1;
        prev1 = res;
    }

    return res;
}

// ********************************************************************************************************

//                 This Give TLE because -> Multiple Reccursion Call

int climbStairs(int n)
{
    if (n == 1 || n == 2)
        // for n=1, come from 0th stair for n=2, come from either 1st or 0th stair
        return n;

    // come either from (n-1)th stair or from (n-2)th stair
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{

    // climb stairs
    int n;
    cin >> n;
    int ans = climbStairs(n);
    cout << ans << '\n';

    return 0;
}
