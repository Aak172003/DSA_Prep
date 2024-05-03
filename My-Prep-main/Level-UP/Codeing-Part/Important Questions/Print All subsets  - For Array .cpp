/*
LeetCode Link - https://leetcode.com/problems/subsets/description/
 */

// Recursive Solution
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))

class Solution {
public:

    void solve(vector<int>& nums ,vector<int>ans,int index, vector<vector<int>> &result)
    {
        // Agr index hamara traverse krte krte array size se bahar so return 
        
        if(index>=nums.size())   // is Question me empty size ka subset bhi output me dena hai
        {
            // but return krne se phle saare , jo bhi ans me daale hai unko print krna pdega   
            result.push_back(ans);
            return ;
        }
        // excluding the element
        solve(nums,ans,index+1,result);

        // including the Element 
        int element = nums[index];
        ans.push_back(element);
        
        solve(nums,ans,index+1,result);

    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>result;
        // string ke case me empty string lena hai , or array ke case me ek vector lena hai 
        vector<int>ans;
        int index = 0;  // indicates elements of nums array
        solve(nums,ans,index,result);
        return result ;
    }
};


    // Using Bit Manipulation 


       vector<vector<int>>result;
       vector<vector<int>> subsets(vector<int>& nums) 
    {

        int n = nums.size();  // ex  - n = 3 -> 2^3  = 8
        
        // here we can also use 1<<n instead Of pow funtion , Because 1<<n it generally means 
        /*
        1 << n = 1 << 3 = ( multiply 3 times two )  2 * 2 * 2
        */
        for(int i=0;i<pow(2,n);i++)
        {
            // i = 0
            // i = 1 
            // i = 2
            /* i = 3    suppose 3 - 011  -  means take elemets at first and second index 
                        011 in this index starting from right to left 
                        But [1,2,3] in this case index starts from left to right 
                        means Take 
                        So For 3 ( 011 -> [1,2] )
            */           
            // ..... till i = 7
            vector<int>ans;
            for(int j = 0;j<n;j++)
            {
                 // j loop iterate over its bits 
            /*
            i = 5 -> 1 0 1
                     2 1 0 - index    

                                 j
            j = 1 0 1 - then 1 0 1 
                        And  1 0 1  - [1,3]
                        First check for j = 0 , so first bit is set so push [1] at vector 
                        then j left shift

                                 j
            j = 1 0 1 - then 0 1 0      <<<
                        And  1 0 1  - [1,3]
                        First check for j = 1 , so 2nd bit is not set so not push [2] at vector 
                        then j left shift

                             j
            j = 1 0 1 - then 1 0 0
                        And  1 0 1  - [1,3]
                        First check for j = 2 , so 3rd is bit is set so push [3] at vector 

            
            */
            // i = 5 -> 101  -> [1,3] -- Her we Goona Find which bit is set or whis is not set , because those bit is set we take it 

                if((1<<j)&i)
                  ans.push_back(nums[j]);  
            }
            result.push_back(ans);
        }
        return result;
    }
