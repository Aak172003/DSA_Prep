
// LeetCode - https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// TC - O(logn) -> Binary Search

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1;
        int high = n;

        int mid;

        while (low < high)
        {
            mid = low + (high - low) / 2;
            // if true hota hai means , bad version mil gya ,
            // so which means iske aage or dekhne ka koi mtlb nhi hai , so high ko mid krdo
            if (isBadVersion(mid))
            {
                high = mid;
            }
            // if false means hume bad version nhi mila , so ika mtlb low = mid + 1 ,
            // krdo abhi bug nhi mila , aage or search kro
            else
            {
                low = mid + 1;
            }
            mid = low + (high - low) / 2;
        }
        return high;
    }
};