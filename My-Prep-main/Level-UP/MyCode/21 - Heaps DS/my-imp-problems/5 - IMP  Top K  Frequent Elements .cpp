// LeetCode - https://leetcode.com/problems/top-k-frequent-elements/
// Ytube - https://youtu.be/3YFFqwzxosU

// typedef pair<int,int> pi;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        for (auto it : nums)
            umap[it]++;

        /*
     value count
        1 - 3
        2 - 2
        3 - 1
        */

        // Create Min Heap

        // priority_queue<pair<pi,vector<pi>,greater<pi>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it : umap)
        {
            // phle count then uski value , is order me islea dia kyuki count is a
            // deciding factor for maximum  and minimum
            pq.push(make_pair(it.second, it.first));

            /*
         count value
            3 - 1
            2 - 2
            1 - 3
            */

            /* MinHeap
         count value
            1 - 3
            2 - 2
            3 - 1
            */
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty())
        {
            pair<int, int> result = pq.top();
            // pq ek pair form me hai so usko store krne ke lie , always use pair
            pq.pop();

            ans.push_back(result.second);
        }
        return ans;
    }
};