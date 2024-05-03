/*
LeetCode Link - https://leetcode.com/problems/generate-parentheses/description/


Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]


*/
class Solution {
public:
     
    void helperfun(vector<string> &result ,int n, int openingcount, int closingcount , string str)
    {
        // Base Case 
        // To generate balanced parnthesis openingcount and closingcount both should be 

        if(openingcount == n && closingcount == n)
        {
            result.push_back(str);
            return;
        }
     
        // Case - 1
        if(openingcount < n)
        {
            helperfun(result,n,openingcount + 1,closingcount , str + "(");
        }

        // Case - 2
        if(closingcount < openingcount)
        {
            helperfun(result,n,openingcount,closingcount + 1 , str + ")");
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string>result;
        string str = "";
        int openingcount = 0;
        int closingcount = 0;
        helperfun(result, n,openingcount, closingcount,str);
        return result;
    
    }
};