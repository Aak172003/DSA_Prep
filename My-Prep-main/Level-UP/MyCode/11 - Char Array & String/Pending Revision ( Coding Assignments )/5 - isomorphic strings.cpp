/*
LeetCode Link- https://leetcode.com/problems/isomorphic-strings/description/

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true

*/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        // create two hash map
        int hash[256] = {0};
        bool istMappedornot[256] = {0};

        /*
        1st map is used to store the character of 2nd map
        and 2nd Map is used to mark 2nd char array elements is marked or not

        hash[s[i]]==0 && istMappedornot[t[i]]==0
        we mark the elements , if they satisfy the above condition
        */
        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] == 0 && istMappedornot[t[i]] == 0)
            {
                hash[s[i]] = t[i];
                istMappedornot[t[i]] = true;
            }
        }

        // here we chaeck 1st map me jo value hai is equal to
        // 2nd map elemets
        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] != t[i])
                return false;
        }

        return true;
    }
};