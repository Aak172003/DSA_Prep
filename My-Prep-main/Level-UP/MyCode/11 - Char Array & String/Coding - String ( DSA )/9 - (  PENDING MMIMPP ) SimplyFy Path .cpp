/*
LeetCode Link - https://leetcode.com/problems/simplify-path/

YTube Link - https://youtu.be/aNONtwL2T60

*/

class Solution
{
public:
    string simplifyPath(string path)
    {

        stack<string> st;
        string res;

        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
                continue;
            string temp;
            // iterate till we doesn't traverse the whole string and doesn't encounter the last /

            // Ex - /../  ,  iterate oveer between / and /
            while (i < path.size() && path[i] != '/')
            {
                // add path to temp string
                temp += path[i];
                ++i;
            }
            // if . ek pdta hia , continue tb tk ki .. na aajae ,
            // single . pr koi dikat nhi but double dot pr hum back jaate hai na

            if (temp == ".")
                continue;
            // pop the top element from stack if occur a..b means pop b and moves to file a
            else if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
                // if encounter , char so oterate over and stor in temp , then push into stack
                // push the directory file name to stack
                st.push(temp);
        }

        // adding all the stack elements to res
        while (!st.empty())
        {
            res = "/" + st.top() + res; // last me res islea kia kyki wo ek same order me aae
            st.pop();
        }

        // if no directory or file is present
        if (res.size() == 0)
            return "/";

        return res;
    }
};