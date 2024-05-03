/*
LeetCode Link - https://leetcode.com/problems/minimize-maximum-of-array/description/

Youtube Link - https://www.youtube.com/watch?v=xDN7LSSmvDU

*/

class Solution {
public:

    int minimizeArrayValue(vector<int>& nums) 
    {
        // minimum possibel answer
        long mini = nums[0];
        // initial sum
        long sum = nums[0];
        
        // loop starts from 1st index beacause 0th index value never decrease ,
        //  beause if we decrease so always need to increase left index value , 
        // but from 0th index no left value
        for(int i=1;i<nums.size();i++)
        {

            sum = sum + nums[i];

            if(nums[i]>mini) 
            {
                int average = sum / (i+1);  // calculationg Average 

                if(average >= mini)
                {
                    // if not a whole no , so we take ceil value 
                    if(sum%(i+1))
                    
                    mini = average +1;
                    // if after finding average ,  take simple average 
                    else mini = average;
                }
            }
        }
        return mini;
    }
};