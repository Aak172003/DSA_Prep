

// Gfg Link - https://www.geeksforgeeks.org/problems/ipl-2021-match-day-2--141634/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        //                     Approach - 1 ( Naive Approach )

        vector<int> ans;
        // int maxV = INT_MIN ;

        for (int i = 0; i < n - k + 1; i++)
        {
            int maxvalue = 0;
            for (int j = i; j < i + k; j++)
            {
                // cout<<"max initial : "<<maxvalue <<endl;
                maxvalue = max(maxvalue, arr[j]);
            }
            // cout<<"max value : "<<maxvalue <<endl;
            ans.push_back(maxvalue);
        }

        return ans;
    }

    //                        Approach - 3 ( Optimise Approach - > Set (But TLE FOR Large Case ) )

    int getmaxEle(set<pair<int, int>> &st)
    {
        int maxele = 0;

        for (auto it : st)
        {
            maxele = max(it.first, maxele);
        }
        return maxele;
    }

    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        vector<int> ans;

        set<pair<int, int>> st;

        for (int i = 0; i < k; i++)
        {
            st.insert({arr[i], i});
        }

        int maxele = getmaxEle(st);
        /
            ans.push_back(maxele);

        for (int i = k; i < n; i++)
        {

            if (arr[i] == arr[i - k])
            {
                ans.push_back(getmaxEle(st));
            }
            else
            {
                st.erase({arr[i - k], i - k});

                st.insert({arr[i], i});

                ans.push_back(getmaxEle(st));
            }
        }

        return ans;
    }

    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        // **********************************************************************************

        //                        Approach - 3 ( Optimise Approach -> Max Heap)

        // Time Complexity : O(NlogN), Where N is the size of the array.
        // Auxiliary Space: O(N), where N is the size of the array,
        // this method requires O(N) space in the worst case when the input array is an increasing array

        vector<int> ans;

        // priorty queue me pair
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i], i});
        }

        ans.push_back(pq.top().first);

        for (int i = k; i < n; i++)
        {
            pq.push({arr[i], i});

            // bahar chala gya  ,
            // here find index ki agr i-k ->
            // this is the way to get last index from sliding Window

            // i = 3 , k = 3 get 0th index access
            // i = 4 , k = 3 get 1st index access
            // i = 5 , k = 3 get 2nd index access

            while (pq.top().second <= i - k)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};