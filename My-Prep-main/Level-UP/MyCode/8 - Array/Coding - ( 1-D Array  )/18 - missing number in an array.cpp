// https://leetcode.com/problems/missing-number/description/

// https://www.geeksforgeeks.org/find-the-missing-number/

class Solution
{
public:
    //   Approach - https://youtu.be/6KHW7ZQwtCA

    int MissingNumber(vector<int> &array, int n)
    {
        // USING XOR METHOD
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = ans ^ i;
        }
        for (int i = 0; i < array.size(); i++)
        {
            ans = ans ^ array[i];
        }
        return ans;

        // SUM FORMULA

        // int sum=(n*(n+1))/2;
        // for(int i=0;i<n-1;i++)
        // {
        //     sum=sum-array[i];
        // }
        // return sum;
    }
};
