/*
LeetCode Link - https://leetcode.com/problems/first-unique-character-in-a-string/description/
*/

class Solution {
public:
    int firstUniqChar(string s) 
    {
        // Approach - 1 -> Without using extra space 
        for(int i=0;i<s.length();i++)
        {
            bool flag = true;
            for(int j=0;j<s.length();j++)
            {
                if(i!=j && s[i] == s[j])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                return i;
        }
        return -1;

        // Approach - 2 -> Using Extra space 

        // map<char,int> mpp;
        // for(int i=0;i<s.size();i++)
        // {
        //     mpp[s[i]]++;
        // }

        // for(int i=0;i<s.size();i++)
        // {
        //     if(mpp[s[i]]==1)return i;
        // }
        // return -1;
    }
};