/*

LeetCode Link - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

Approach is hum do opposite brackets ko pop krenge jo valid hone , or baaki ko stack me daal denge
jo jo bceh rh gye pop hone se , means hume utne no of brackets add krna hai to make
valid Parenthesis

*/

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        if (s.size() == 0)
            return 0;

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                // if stack is not empty and top element is (
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                    st.push(s[i]);
            }
        }

        return st.size();
    }
};
