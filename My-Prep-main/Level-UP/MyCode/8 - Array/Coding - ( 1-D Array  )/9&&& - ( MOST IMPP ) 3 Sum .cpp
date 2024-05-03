// LeetCode - https://leetcode.com/problems/3sum/solutions/

// Gfg - https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Ytube - https://youtu.be/WdaeixEeAVs

// Make sum = 0
// a + b + c = 0
// b + c = - a
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int a = nums[i];
            int t = -a;
            int s = i + 1, e = n - 1;
            while (s < e)
            {
                if (nums[s] + nums[e] == t)
                {
                    ans.push_back({nums[i], nums[s], nums[e]});

                    //  *****************************************************************************************************

                    // nums[s] == nums[s + 1] this will help to avoid repeated task ,
                    // ki agr aage se do same element so s++

                    while (s < e && nums[s] == nums[s + 1])
                    {
                        s++;
                    }
                    // nums[e] == nums[e - 1] this will help to avoid repeated task ,
                    //  ki agr piche se do same element so e--
                    while (s < e && nums[e] == nums[e - 1])
                    {
                        e--;
                    }

                    // If not use above condition , this will give error
                    // Input nums = [ -2, 0, 0, 2, 2 ] ,
                    // Output = [ [ -2, 0, 2 ], [ -2, 0, 2 ] ] ,
                    // Expected = [[ -2, 0, 2 ]]

                    // ****************************************************************************************************

                    s++;
                    e--;
                }
                else if (nums[s] + nums[e] > t)
                {
                    e--;
                }
                else
                {
                    s++;
                }
            }

            // here lets suppose [-4 -1 -1 0 1 2]
            // in first iteration me -4 ke lie poora check , then
            // in Second iteration me -1 ke lie check , then aage next iteration me gye
            // means -1 is our i so repeated task again krne pdega , jo ki hum Phle -1 ke lie kr chuke hai

            while (i + 1 < n && nums[i + 1] == nums[i])
            {
                i++;
            }

            // Agr hum above condition check nhi krte to , same i ke lie 2 brr same result aa skta hai
            // ex  i = -1
            // Input: nums = [-1,0,1,2,-1,-4]
            // [[-1,-1,2],[-1,0,1],[-1,0,1]]
        }
        return ans;
    }
};