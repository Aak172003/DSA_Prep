/*
LeetCode Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// means same element milega to j++,
// otherwise i++ krke ith position pr jth value daal kr then j++
*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            // if ith element and jth element is equal so j++
            if (nums[i] != nums[j])
            {
                // but if ith and jth is not equal so i++ ,

                i++;
                // First Increase i and then Swap the value present at index

                nums[i] = nums[j];

                // means same element milega to j++,
                // otherwise i++ krke ith position pr jth value daal kr then j++
            }
        }
        // because i ke hisab se hi mai value daal rha huu, jb jb value daal rha huu to i++ kr rha huu
        return i + 1;
    }
};