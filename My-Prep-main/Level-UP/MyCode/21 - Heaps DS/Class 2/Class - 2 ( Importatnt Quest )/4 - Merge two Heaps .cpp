
// Gfg - https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution
{
public:
    void heapify(vector<int> &ans, int size, int i)
    {

        //                                      O based Index Consider , Here
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < size && ans[largest] <= ans[left])
        {
            largest = left;
        }
        if (right < size && ans[largest] <= ans[right])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(ans[largest], ans[i]);
            i = largest;

            // again call heapify , but here i pass index jo swap hua hai largest ke sth ,
            //                           index
            //                           12
            //                          /  \
            //                        50    60 largest
            //                      /   \   /
            //                    30   40  52

            // In first call , i is like index 12 -> 1 , 50 -> 2 , 60 -> 3 , 30 -> 4 , 40 -> 5 , 52 -> 6
            // i = 1
            // do heapify on 12 value

            //                           60
            //                          /  \
            //                        50    12  index
            //                      /   \   /
            //                    30   40  52

            // Now , i goes to 3 , i = 3 , me 12 is the value
            // so this 12 ko bhi to heapify krna pdega

            //                           60
            //                          /  \
            //                        50    52
            //                      /   \   /
            //                    30   40  12 index

            heapify(ans, size, i);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {

        // Approach -1
        /*
        Like first ek vector me bot array ko store kr lenge ,
        us vector ke ek ek elements ko , priority_queue me daal denge
        then priorty_queue se top nikal kr ek ans vector me daal denge

        vector<int> ans;

        for (auto i : a)
        {
            ans.push_back(i);
        }
        for (auto i : b)
        {
            ans.push_back(i);
        }

        vector<int> res;
        priority_queue<int> pq;

        for (auto it : ans)
        {
            pq.push(it);
        }
        // pq.top() -> extract from queue
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return ans;



        */

        /*


        // Approach -> 2 (Using STL Max - Heap)

        vector<int> ans;

        for (auto i : a)
            ans.push_back(i);
        for (auto i : b)
            ans.push_back(i);

        priority_queue<int> pq;

        for (auto it : ans)
        {
            pq.push(it);
        }

        int size = ans.size();

        // Apply heapify Concept ,
        // Starting from below , non - leaf node
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(ans, size, i);
        }
        // for(auto i : ans){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return ans;


        */
    }
};