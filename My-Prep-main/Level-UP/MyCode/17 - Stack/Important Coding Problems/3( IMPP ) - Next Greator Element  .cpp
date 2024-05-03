

// Gfg - https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution
{
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> ans; // Changed from vector<long, long> to vector<long long>

        stack<pair<long long, long long>> st; // Changed from stack<long, long> to stack<pair<long long, long long>>

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top().first <= arr[i]) // Modified the conditions inside while loop
            {
                st.pop();
            }

            if (!st.empty())
            {
                ans.push_back(st.top().first); // Changed from make_pair(arr[i], -1) to st.top().first
            }
            else
            {
                ans.push_back(-1); // Changed from make_pair(arr[i], st.top()) to -1
            }

            st.push({arr[i], i}); // Pushed the element along with its index
        }
        reverse(ans.begin(), ans.end()); // Reversed the answer vector to get the correct order
        return ans;
    }
};
