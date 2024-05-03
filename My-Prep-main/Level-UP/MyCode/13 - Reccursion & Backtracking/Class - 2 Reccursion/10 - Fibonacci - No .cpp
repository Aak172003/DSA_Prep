/*
LeetCode Link - https://leetcode.com/problems/fibonacci-number/description/
*/

class Solution
{
public:
    int fib(int n)
    {
        /*
        Both Way
        TC - O(N)
        SC - Auxillary Space
        */

        //  Using Reccursion Solution
        if (n <= 1)
            return n;

        // Or

        // if(n==0)return 0;
        // if(n==1)return 1;

        int last = fib(n - 1);
        int secondLast = fib(n - 2);

        int result = last + secondLast;
        return result;

        //  Using Iterative way

        if (n <= 1)
            return n;

        // Or

        // if(n==0)return 0;
        // if(n==1)return 1;

        int prev1 = 0;
        int prev2 = 1, nextelement;

        for (int i = 2; i <= n; i++)
        {
            nextelement = prev1 + prev2;
            prev1 = prev2;
            prev2 = nextelement;
        }
        return nextelement;
    }
};
