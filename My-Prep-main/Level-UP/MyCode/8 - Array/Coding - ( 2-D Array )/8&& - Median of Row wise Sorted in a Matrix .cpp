
// Extra Space
class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {

        //         This Take
        //         Tc : o(R * C) +  R * C log(R * C)
        //         Sc : O(R * C)
        vector<int> ans;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }

        int start = 0;
        int end = ans.size() - 1;
        sort(ans.begin(), ans.end());
        // for(auto it : ans)
        // {
        //     cout<<it<<" ";
        // }
        int mid = start + (end - start) / 2;

        // cout<<endl;

        return ans[mid];
    }
};

// Without Extra Space
class Solution
{
public:
    int totalElementLessThanEqualToMid(vector<int> &row, int val)
    {
        int low = 0;
        int high = row.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (row[mid] <= val)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

    int median(vector<vector<int>> &matrix, int r, int c)
    {

        int low = 1;
        int high = 1e9;
        int median = ((r * c) + 1) / 2;

        while (low <= high)
        {

            // Find mid

            int mid = low + (high - low) / 2;

            int count = 0;

            for (int i = 0; i < r; i++)
                //   Row wise check krega
                count = count + totalElementLessThanEqualToMid(matrix[i], mid);

            if (count < median)
                low = mid + 1;
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
