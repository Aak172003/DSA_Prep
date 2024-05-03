/*
Leetcode Link -  https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
*/

// TC-O(n)    SC-O(n)

class Solution
{
public:
    string removeDuplicates(string s)
    {

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            // if ans naam ki string me hum elemnt piche se daalte jaenge
            // or hum ans.back() se back ki value string elements ke barabar hota hai to , hum ans me se usko pop krlenge
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

    // ************************************************************************

    // Using Stack
    // TC-O(n)    SC-O(n)

    string removeDuplicates(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            // stack me value daalne ka jb tk stack empty na ho or st.top not equal to current s[i] character
            if (!st.empty() && st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        // Use String to store ans
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // Reverse the ans because in stack , if we print from stack , it print in reverse order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
