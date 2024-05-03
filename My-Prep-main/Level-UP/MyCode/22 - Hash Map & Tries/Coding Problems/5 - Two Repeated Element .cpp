
// Gfg - https://practice.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int N)
    {
        // Your code here

        // vector<int> ans;
        // unordered_map<int, int> mpp;

        // for (int i = 0; i < N + 2; i++)
        // {
        //     mpp[arr[i]]++;
        //     if (mpp[arr[i]] == 2)
        //     {
        //         ans.push_back(arr[i]);
        //     }
        // }

        // return ans;

        vector<int> res;
        vector<int> ans(N + 1, 0);

        for (int i = 0; i < (N + 2); i++)
        {
            if (ans[arr[i]] > 0)
            {
                res.push_back(arr[i]);
            }
            else
            {
                ans[arr[i]]++;
            }
        }

        return res;
    }
};