
// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Gfg : https://practice.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1



*/

class Solution
{
public:
    int checkRedundancy(string s)
    {
        // code here
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {

            bool flag = 0;
            if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                st.push(s[i]);
            }

            else if (s[i] >= 'a' && s[i] <= 'z')
                continue;
            else
            {

                while (!st.empty() && st.top() != '(')
                {
                    if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                    {
                        flag = 1;
                    }
                    // cout<<"flag for"<<st.top()<<"flag "<<flag<<endl;
                    st.pop();
                }

                if (flag == 0)
                {
                    // break ;
                    return 1;
                }

                st.pop();
            }
        }

        // while(!st.empty()) {
        //     cout<<st.top()<< " " ;
        //     st.pop();
        // }

        // cout<<endl;

        return 0;
    }
};
