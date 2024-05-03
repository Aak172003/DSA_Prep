class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

    int kthSmallest(int arr[], int l, int r, int k)
    {

        //   1st Approach

        vector<int> v;
        for (int i = l; i <= r; i++)
        {
            v.push_back(arr[i]); // push_back ka means V vector me array li value daala
        }

        // Sorting krdenge Array me
        sort(v.begin(), v.end()); // v.begin point to first element
                                  // v.end point to last element
                                  // Above sort technique use Quick Sort

        return v[k - 1]; // k hume user dega

        /*

         |7 |->5                             |20|->5
         |10|->4                             |15|->4
         |4 |->3 => After sorting in vector  |10|->3
         |3 |->2                             |7 |->2
         |20|->1                             |4 |->1
         |15|->0                             |3 |->0
                        v[k-1] Return

         */

        //   2nd Approach

        priority_queue<int> pq; // Use MaxHeap Prperty jiska parent value always greater than its child value

        for (int i = 0; i <= r; i++)
        {
            pq.push(arr[i]); // Heap me push kia

            if (pq.size() > k) // maxHeap ka size never greater than k
            {
                pq.pop();
                /* Max heap me sbse bdii value top root pr hoga
                Deleting always from root , then root se gayab hone ke bdd heapify hoga jo sbse bdi value hai wo phr remove hoga
                is tarah se jo kth largest value hai wo top pr rhegi */
            }
        }
        return pq.top();
    }
};