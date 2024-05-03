/*
LeetCode Link -  https://leetcode.com/problems/backspace-string-compare/
*/

class Solution
{
public:
    string afterremove(string str)
    {
        stack<char> ans;
        for (int i = 0; i < str.size(); i++)
        {
            if (!ans.empty() && str[i] == '#')
            {
                ans.pop();
            }
            // Means Ignore # if we have an empty stack
            // Suppose if y#f#o##f

            // 1. y remove with #
            // 2. f remove with #
            // 3. o remove with #

            // 4. Bcha #f ( or here st is empty )  so agr mai simply push krunga ,
            // res me #f both push but we have to push only char  ,
            // that's why i ignore # only consider f

            else if (str[i] != '#')
            {
                ans.push(str[i]);
            }
        }

        // Simple pushing into string
        string res = "";
        while (!ans.empty())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        return res;
    }

    bool backspaceCompare(string s, string t)
    {

        string s1 = afterremove(s);
        string s2 = afterremove(t);

        if (s1.size() != s2.size())
            return false;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
};