/*
Leetcode Link -  https://leetcode.com/problems/search-in-rotated-sorted-array/description/
Youtube  -  https://youtu.be/r3pMQ8-Ad5s
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        //                                     Brute Force Approach

        /*
          Use Linear Search Method , Which Takes
          TC - O( N )
          SC - O(1)
        */

        //                                     Optimise  Approach
        /*
               Use Binary Search Method , Which Takes
               TC - O( LogN )
               SC - O(1)
        */

        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;

            // Left side is sorted
            // If low element is < or = mid , Means it is a sorted Array

            /*
            3 1
            1 - target
            //  is case ke lie hamara ye solution best hai
            */
            if (nums[low] <= nums[mid])
            {
                if (target <= nums[mid] && nums[low] <= target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // Right  side is sorted
            else
            {

                if (target <= nums[high] && target >= nums[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};