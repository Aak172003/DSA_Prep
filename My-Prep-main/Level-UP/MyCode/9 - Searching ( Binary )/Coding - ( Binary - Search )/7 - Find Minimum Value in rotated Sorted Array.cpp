// Most Important *****
// PDF

/*
Leetcode Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
Video Link - https://www.youtube.com/watch?v=j3187M1P2Xg
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right = n-1;

        while(left<right) 
        {
            int mid = left + (right-left)/2;
            
            if(nums[mid]>nums[right])
            left = mid+1;
            else
            right = mid;
        }
        return nums[left];
    }
};