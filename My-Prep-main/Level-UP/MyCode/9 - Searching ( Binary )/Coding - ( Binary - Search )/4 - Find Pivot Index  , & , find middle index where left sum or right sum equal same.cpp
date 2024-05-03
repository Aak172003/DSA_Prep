/*
Leetcode Link - https://leetcode.com/problems/find-pivot-index/
*/

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        // Brute Force Approach
        /*
        TC- O(N^2)
        SC - o(1)
        */

        // 1 7 13 6 5 6
        // i = 0 so j = 0 to j<i for LeftSum and k = nums.size()-1 to k > i for right sum

        // 1st Iteration

        // 1 7 13 6 5 6
        // if i = 0
        // j = 0 , k = last index sirf
        // leftsum = 1  ,  rightsum = 6
        // if (leftsum == rightsum)
        //     return i;

        // 2nd Iteration

        // 1 7 13 6 5 6
        // if i = 1
        // j = [ 0 , 1 ] , k = [ last index sirf , and second last index ] k start from piche se
        // leftsum = 1 + 7 ,  rightsum = 6 + 5
        // if (leftsum == rightsum)
        //     return i;

        // 3rd Iteration

        // 1 7 13 6 5 6
        // if i = 2
        // j = [ 0 , 1 , 2] , k = [ last index sirf , and second last index , third last index] k start from piche se
        // leftsum = 1 + 7 + 13,  rightsum = 6 + 5 + 6
        // if (leftsum == rightsum)
        //     return i;
        // yes here return index

        for (int i = 0; i < nums.size(); i++)
        {
            // create leftSum and rigthSum variable
            int leftsum = 0, rightsum = 0;

            // i jaha pr bhi hoga j hamesha piche se hi starty hoga
            for (int j = 0; j < i; j++)
            {
                leftsum = leftsum + nums[j];
            }
            for (int k = nums.size() - 1; k > i; k--)
            {
                rightsum = rightsum + nums[k];
            }
            if (leftsum == rightsum)
                return i;
        }
        return -1;

        // ******************************************************************************************************************

        // Prefix sum
        /*
        TC- O(N)
        SC - o(1)
        */

        int sum = 0;
        // Phle saara sum nikal lia
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }

        int lsum = 0;
        // rsum me actual jo sum kra wo daal dia
        int rsum = sum;

        for (int i = 0; i < nums.size(); i++)
        {
            // rsum se -ve krte jaenge , or lsum me + krte jaenge ,
            // jaise hi lsum or rsum barabar hote hai , return index
            rsum = rsum - nums[i];
            if (lsum == rsum)
            {
                return i;
            }
            lsum = lsum + nums[i];
        }
        return -1;
    }
};