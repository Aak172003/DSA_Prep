

// LeetCode - https://leetcode.com/problems/find-missing-and-repeated-values/

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int limit = n * n;
        vector<int> forCmp(limit, 0), ans;

        // Push values from 1 to 9 in forCmp vector
        for (int i = 0; i < limit; i++)
        {
            forCmp[i] = i + 1;
        }

        // then compare with  gird value to forCmp
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (forCmp[grid[i][j] - 1] > 0)
                    forCmp[grid[i][j] - 1] = -1;
                else
                    ans.push_back(grid[i][j]);
            }
        }

        for (auto it : forCmp)
        {
            if (it > 0)
                ans.push_back(it);
            break;
        }
        return ans;
    }
};