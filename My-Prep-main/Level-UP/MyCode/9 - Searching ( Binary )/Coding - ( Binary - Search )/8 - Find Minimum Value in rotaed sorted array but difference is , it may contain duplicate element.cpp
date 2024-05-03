/*
This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates
LeetCode Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

Video Link - Video Link - https://www.youtube.com/watch?v=j3187M1P2Xg
*/


class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n=nums.size();
        int left=0;
        int right = n-1;

        while(left<right) 
        {
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right])
            left = mid+1;
            else if (nums[mid]<nums[right])
            right = mid;
            else
            right--;
        }
        return nums[left];
        
    }
};