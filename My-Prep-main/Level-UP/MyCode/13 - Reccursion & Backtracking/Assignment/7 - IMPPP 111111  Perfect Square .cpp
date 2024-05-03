
// LeetCode - https://leetcode.com/problems/perfect-squares/description/

//                                                             MyPdf

//                                          Approach - 1 ( Using Reccursion -> Give TLE)
class Solution
{
public:
    int getCountSquare(int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);

        while (i <= end)
        {
            int perfectsquare = i * i;

            int numSquare = 1 + getCountSquare(n - perfectsquare);

            if (numSquare < ans)
                ans = numSquare;

            ++i;
        }
        return ans;
    }
    int numSquares(int n)
    {
        return getCountSquare(n) - 1;
    }
};
