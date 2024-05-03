
// LeetCode - https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

class Solution
{
public:
    int minSwaps(string s)
    {

        //                                       Approach -1

        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty() && s[i] == ']')
                {
                    st.pop();
                }
                else
                {
                    count++;
                }
            }
        }
        return (count + 1) / 2;

        //                                       Approach - 2 ( Best Approach )

        if (s.size() == 0)
            return 0;

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            // empty
            if (st.empty())
            {
                if (s[i] == ']' || s[i] == '[')
                {
                    st.push(s[i]);
                }
            }
            // for both cases
            else
            {
                if (s[i] == ']')
                {
                    if (st.top() == '[')
                    {
                        st.pop();
                    }
                }
                // '['
                else
                {
                    st.push(s[i]);
                }
            }
        }

        int n = st.size() / 2;
        return n;
    }
};
