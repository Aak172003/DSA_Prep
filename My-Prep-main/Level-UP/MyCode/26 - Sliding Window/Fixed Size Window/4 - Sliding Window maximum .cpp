class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        // Two For Loop Approach --> TLE
        // TC - O(N^2)
        // SC - O(N)

        // int n = nums.size();
        // vector<int>result;

        // for(int i=0;i<n-k+1;i++)
        // {
        //     int maxvalue = INT_MIN;
        //     for(int j=i;j<i+k;j++)
        //     {
        //         maxvalue = max(maxvalue,nums[j]);
        //     }
        //     result.push_back(maxvalue);
        // }
        // return result;

        // *****************************************************************************

        // Using Deque
        // TC - O(N)
        // SC - O(N)

        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        /*phle to jbtk i > i-k se bdaa nhi hota ,
        tb tk mai ans em store kuch nhi krunga

        */

        for (int i = 0; i < n; i++)
        {

            // Step -1  make space for nums
            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // then hr ek i ke lie ,
            // mai check krung ki kya us index ki value se choti value to nhi hai,
            // dq ke front index ki value pr

            while (!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }

            // Then push Index
            dq.push_back(i);

            // window bannana start
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};