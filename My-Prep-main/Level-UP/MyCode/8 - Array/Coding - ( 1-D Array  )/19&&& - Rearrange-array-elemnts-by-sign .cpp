/*

Leetcode - https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

*/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        // ek new array create kia ,
        // phle sb me 0 value daal dia

        vector<int> ans(nums.size(), 0);

        // One index for +ve value daalne ke lie ,
        // another for -ve value daalne ke lie

        int p = 0; // for +ve
        int k = 1; // for -ve

        // Iterate over elements ,
        // and put elements in vector in form of +ve , -ve , +ve , -ve , +ve , -ve

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                ans[p] = nums[i];
                // index ko do brr bdhaenge ,
                // kyuki alternate krna hai sb
                p = p + 2;
            }
            else
            {
                ans[k] = nums[i];
                k = k + 2;
            }
        }
        return ans;
    }
};