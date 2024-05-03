class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // Approach - 1   (Using Sorting )

        // TC - O(LogN)

        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];

        // Approach - 2 -> Max Heap ( Priority Queue )
        // TC - O(N)

        priority_queue<int> pq(nums.begin(), nums.end());
        int ans = 0;

        while (k--)
        {
            ans = pq.top();
            pq.pop();
        }
        return ans;

        // Approach - 3 -> Min Heap ( Priority Queue )
        // TC - O(Logk)

        priority_queue<int, vector<int>, greater<int>> pq; // Min Heap
        for (auto it : nums)
        {
            pq.push(it);

            // if pq ka size greater than k hoga so hum , pop krdenge
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};