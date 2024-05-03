

// LeetCode - https://leetcode.com/problems/find-the-duplicate-number/submissions/840864044/

// 1st AppRoach -> sort the Array , so while traversing nums[i]==nums[i+1]
// so this nums[i] is a duplicate No

/*

// 2nd Approach - > Using Hash Map le lo


Here simple method is that we create a hash table in which we store elements one by one
If any value have frequency > 1 so return this value , Because this is a Duplicate Element

*/

// Tortoise Method -> 3rd Approach

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int slow = nums[0];
        int fast = nums[0];

        // Do while Loop
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        /*
        jb tk both meet nhi hojaate same point prr ,Tb tk fast ko do move and slow ko ek move
        If both pointer meet at single elements ,
        then we initialise fast pointer on First element  */

        fast = nums[0];
        // Then again jb tk both not meet at single elemenet , we need to shift fast s well as slow
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};