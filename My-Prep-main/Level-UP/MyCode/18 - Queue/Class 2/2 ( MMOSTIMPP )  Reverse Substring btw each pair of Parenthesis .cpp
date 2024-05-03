
// Leetcode - https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/submissions/1090749772/

// My Page from Diary

class Solution
{
public:
    string reverseParentheses(string s)
    {

        stack<string> st;
        string curr = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (curr.size() > 0)
                {
                    st.push(curr);
                    curr = "";
                }
                st.push("(");
            }
            else if (s[i] == ')')
            {
                st.push(curr);
                curr = "";
                string temp = "";

                while (!st.empty() && st.top() != "(")
                {
                    string t = st.top();
                    st.pop();

                    reverse(t.begin(), t.end());
                    temp = temp + t;
                }

                // for '( '
                st.pop();
                st.push(temp);
            }
            else
            {
                curr = curr + s[i];
            }
        }

        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }

        // cout<<"the ans is : "<<ans<<" "<< "and the curr is : "<< curr<<endl ;

        return ans + curr;
    }
};