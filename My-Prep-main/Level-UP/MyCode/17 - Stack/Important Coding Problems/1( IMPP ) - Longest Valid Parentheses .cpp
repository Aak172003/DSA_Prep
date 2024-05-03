
// LeetCode - https://youtu.be/y165_vMDNW0?si=W1FcOLtNAwRbdFSS

class Solution
{
public:
    int findMaxLen(string S)
    {

        // here store index in stack , thode char which provide hurdle

        stack<int> st;

        for (int i = 0; i < S.length(); i++)
        {
            char ch = S[i];
            if (ch == '(')
            {
                st.push(i);
            }
            else
            {
                if (!st.empty() && S[st.top()] == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
        }
        int maxLen = 0;
        int len = S.length();
        // cout<<"len is "<<len<<endl;

        while (!st.empty())
        {
            int top = st.top();

            // cout<<"top is : "<<top<<endl;
            st.pop();
            maxLen = max(maxLen, len - top - 1);

            // cout<<"max len is : "<<maxLen<<endl;
            len = top;
        }

        int m = max(maxLen, len);

        // cout<<"outside m is  : "<<m<<endl;
        return m;
    }
};
