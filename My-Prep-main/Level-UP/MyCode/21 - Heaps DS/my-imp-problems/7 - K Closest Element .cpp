
// LeetCode Link - https://leetcode.com/problems/find-k-closest-elements/description/
// Ytube Link - https://youtu.be/Of4bdCDwcdY
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {

        // MaxHeap

        priority_queue<pair<int, int>> pq;
        for (auto ele : arr)
        {
            // pair bnaya key me substract or value me original key
            /*
            If Example :  1 2 3 4 5   where x = 3
                          2 1 0 1 2

            //MAX Heap

               | (2,5) |
               | (2,1) |
               | (1,4) |
               | (1,2) |
               | (3,0) |
               _________
            */
            pq.push(make_pair(abs(x - ele), ele));
            if (pq.size() > k)
            {
                // Reove pair from max heap
                pq.pop();
            }
        }

        // used to store the elements
        vector<int> ans;

        while (!pq.empty())
        {
            pq.top ke second
                ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};