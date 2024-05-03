/*
LeetCode Link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
*/

class Solution
{
public:
    string removeDuplicates(string s)
    {

        // This is an Brute Force Approach -> with TLE

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (ans.size() == 0)
            {
                ans.push_back(s[i]);
            }
            else
            {
                // if ans naam ki string me hum elemnt piche se daalte jaenge
                // or hum ans.back() se back ki value string elements ke barabar hota hai to ,
                //  hum ans me se usko pop krlenge
                // otherwise , agr match nhi krta to hum piche se value daal denge ans me

                if (s[i] != ans.back())
                {
                    ans.push_back(s[i]);
                }
                else
                {
                    ans.pop_back();
                }
            }
        }
        return ans;

        // ************************************************************************************************************

        // This is Best Approach -> with using an extra space

        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (s[i] == st.top())
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }

        string ans = "";
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

class Solution
{
public:
    string removeDuplicates(string s)
    {

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            // if ans naam ki string me hum elemnt piche se daalte jaenge
            // or hum ans.back() se back ki value string elements ke barabar hota hai to ,
            //  hum ans me se usko pop krlenge
            // otherwise , agr match nhi krta to hum piche se value daal denge ans me

            if (ans.back() != s[i])
            {
                ans.push_back(s[i]);
            }
            // If mil gya to usko bahar nikalne ki jaroorat hai
            else
                ans.pop_back();
        }
        return ans;
    }
};
