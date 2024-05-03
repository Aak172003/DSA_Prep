class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        // Approach -1 Sorting
        // TC - O(nlogn)
        // SC - O(N)

        vector<pair<int, int>> vpp;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            vpp.push_back({abs(x - arr[i]), arr[i]});
        }
        // Difference , value
        sort(vpp.begin(), vpp.end());

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(vpp[i].second);
        }
        sort(ans.begin(), ans.end());
        return ans;

        // // MaxHeap
        // priority_queue<pair<int,int>>pq;
        // for(auto ele : arr)
        // {
        //     cout<<ele<<" "<<endl;

        //     pq.push(make_pair(abs(x-ele),ele));

        //     if(pq.size()>k)
        //     {
        //         // Reove pair from max heap
        //         pq.pop();
        //     }
        // }
        // while(!pq.empty())
        // {
        //     // cout<<"data at map"<<pq.top().second<<endl;
        //     pq.pop();
        // }

        // vector<int>ans;
        // while(!pq.empty())
        // {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }

        // sort(ans.begin(), ans.end());
        // return ans ;
    }
};