

// Gfg - https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1

class Solution
{
public:
    vector<int> leftSmaller(int n, int a[])
    {

        //  ***************************  Approach - 1 (using Two Loops)  ***************************
        vector<int> ans;
        // int minele  = INT_MAX;
        ans.push_back(-1);

        for (int i = 1; i <= n; i++)
        {
            bool found = false;
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j] < a[i])
                {
                    ans.push_back(a[j]);
                    found = true;
                    break;
                }
            }

            if (!found)
                ans.push_back(-1);
        }

        return ans;

        //  ***************************  Approach - 2 ( using Stack ) ***************************

        vector<int> ans;

        stack<int> st;

        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && st.top() >= a[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }

            st.push(a[i]);
        }
        return ans;
    }
};