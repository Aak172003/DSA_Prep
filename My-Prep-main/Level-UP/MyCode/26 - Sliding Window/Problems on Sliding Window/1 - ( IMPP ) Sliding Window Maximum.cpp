class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // Two For Loop Approach --> TLE
        // TC - O(N^2)
        // SC - O(N)

        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n - k + 1; i++)
        {
            int maxvalue = INT_MIN;
            for (int j = i; j < i + k; j++)
            {
                maxvalue = max(maxvalue, nums[j]);
            }
            result.push_back(maxvalue);
        }
        return result;

        // ***********************************************************************

        // Using Deque
        // TC - O(N)
        // SC - O(N)

        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            /*
            While adding the elements from back ,
            we check again and again ,
            if dq empty na ho or dq.back()<nums[i] ho ,
            to hum dq.pop_back krke usse greater wale element ko daal denge
            */
            while (!dq.empty() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }

        // then dq.front() element hum ans vector me daal denge
        ans.push_back(dq.front());

        // Iterate over remaing element

        // via iterating ek ek elemenet add hota jaega
        for (int i = k; i < nums.size(); i++)
        {
            // dq.front == nums[i-k]
            // If same Element , so remove from dequeu
            // us block se nikalne ke lie front se dq me pop krna pdega

            if (dq.front() == nums[i - k])
                dq.pop_front();

            while (!dq.empty() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            // then dq.front() element hum ans vector me daal denge
            ans.push_back(dq.front());
        }
        return ans;
    }
};