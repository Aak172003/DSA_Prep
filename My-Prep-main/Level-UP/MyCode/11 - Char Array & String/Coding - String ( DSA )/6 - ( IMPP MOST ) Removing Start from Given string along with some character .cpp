
// LeetCode -> https://leetcode.com/problems/removing-stars-from-a-string/

class Solution
{
public:
    string removeStars(string s)
    {
        // Approavh 1 - ( TC - O(N) SC - O(N))

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
                st.pop();
            else
                st.push(s[i]);
        }

        string ans;
        while (!st.empty())
            ans += st.top(), st.pop();

        // Reverse because of LIFO Principle
        reverse(ans.begin(), ans.end());

        return ans;

        // Approach - 2 - (TC - O(N) SC - O(1))

        // string ans = "";

        // for (int i = 0; i < s.size(); i++)
        // {
        //     if (s[i] != '*')
        //     {
        //         ans.push_back(s[i]);
        //     }
        //     else
        //     {
        //         ans.pop_back();
        //     }
        // }
        // return ans;
    }
};