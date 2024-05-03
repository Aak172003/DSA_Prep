/*
Stiver Article - https://takeuforward.org/data-structure/combination-sum-1/

Link - https://leetcode.com/problems/combination-sum/




Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
*/


class Solution {
public:
    void getans(vector<vector<int>> &res,vector<int>& cand,vector<int> &output,int ind,int sum,int target)
    {

        // Input: candidates = [2], target = 1
        // Output: []
        if(sum>target)   
            return;

        if(sum==target)
        {
            res.push_back(output);
            return;
        }
        
        int n= cand.size();

        for(int i=ind;i<n;i++) 
        {
            // Pick - phle pick pick pick in left call if kahi sum ke barabar milta hai to ,
            // push into result
            output.push_back(cand[i]);
            sum+=cand[i];
            
            getans(res,cand,output,i,sum,target);
            
            // After reaching in last index , then call to Not pick right side
            // Not pick
            sum-=cand[i];
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> res;
        vector<int> output;
        getans(res,cand,output,0,0,target);
        return res;
    }
};



