

// LeetCode - https://leetcode.com/problems/assign-cookies/description/

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end()); // Sort children's greed factors in ascending order
        sort(s.begin(), s.end()); // Sort cookie sizes in ascending order

        /*

        // [ 1, 2, 3 ] -> children
        // [ 1, 1 ] -> cookies

        So here both index having 1 cookies ,
        but according to children
        at 0th index 1children so it accept 1 cookies from cookies

        but if at children in next index are 2 childrens , but only 1 cookie have ,
        so here nhi de skte cookies

        */

        /*
        [ 1, 8, 9, 10 ]
        [ 1, 5, 9 ]

        1 map with 1 and 8 map with 9 bcoz 8 children and 9 cookies so , easily distribute
        */
        int ans = 0;
        int i = 0; // Index for children
        int j = 0; // Index for cookies

        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                ans++;
                i++; // Move to the next child
            }
            j++; // Move to the next cookie regardless of whether it satisfies the child's greed factor or not
        }

        return ans;
    }
};