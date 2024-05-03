/*
Leetcode Link - https://leetcode.com/problems/zigzag-conversion/description/

Ytube Link - https://youtu.be/JnxAWShm4PU

*/



class Solution
{
public:
    string convert(string s, int nRows)
    {
        // Create vector of size nRows ka
        vector<string> ans(nRows);

        // IF nRows give 1, so return s
        if (nRows == 1)
            return s;

        // Bool flag is used to represent Direction
        bool flag = false;
        int i = 0;

        for (auto ch : s)
        {
            // First Simply add elementsto rows wise
            ans[i] = ans[i] + ch;
            /*

            "PAYPALISHIRING"

            P   A   H   N
            A P L S I I G
            Y   I   R

            */

            //  if i = 0 ,  or nRows -1 means last row pr , so we need to change the direction
            if (i == 0 || i == nRows - 1)
            {
                flag = !flag;
            }

            // If flag = true ,  so goes to down

            if (flag)
            {
                i = i + 1;
            }
            // Otherwise goes to up
            else
            {
                i = i - 1;
            }
        }

        string zigzag = "";
        // iterate firstly on 0th index , 1st index and then 2nd index
        for (auto str : ans)
        {
            // add in zigzag
            zigzag = zigzag + str;
        }
        return zigzag;
    }
};
