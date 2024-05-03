/*
LeetCode Link - https://leetcode.com/problems/valid-parentheses/description/
*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // opening bracket
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }

            //  if opposite bracket occur
            else
            {
                // closing bracket - ch
                if (!st.empty())
                {
                    // Extrat top element
                    char topCh = st.top();

                    // Condition Checking
                    if (ch == ')' && topCh == '(')
                    {
                        // matching brackets
                        st.pop();
                    }
                    else if (ch == '}' && topCh == '{')
                    {
                        // matching brackets
                        st.pop();
                    }
                    else if (ch == ']' && topCh == '[')
                    {
                        // matching brackets
                        st.pop();
                    }
                    else
                    {
                        // brackets not matching
                        return false;
                    }
                }

                // if stack is empty
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            // valid
            return true;
        }
        else
            return false;
    }
};