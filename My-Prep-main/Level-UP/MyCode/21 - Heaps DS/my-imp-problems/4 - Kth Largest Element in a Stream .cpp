// Input
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// Output
// [null, 4, 5, 5, 8, 8]

// Explanation
// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3);   // return 4
// kthLargest.add(5);   // return 5
// kthLargest.add(10);  // return 5
// kthLargest.add(9);   // return 8
// kthLargest.add(4);   // return 8

// LeetCode - https://leetcode.com/problems/kth-largest-element-in-a-stream/
//  Ytube Soln - https://www.youtube.com/watch?v=8HR8Ak5zuus&list=PLzjZaW71kMwTF8ZcUwm9md_3MvtOfwGow&index=14

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int gk;
    KthLargest(int k, vector<int> &nums)
    {
        gk = k;
        //     [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
        //       |     |
        //   K value Array Given

        // Given Array ko push into priority queue
        for (auto it : nums)
        {

            pq.push(it);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    //   | 4 |
    //   | 5 |
    //   | 8 |

    // Add Function
    int add(int val)
    {
        pq.push(val);
        if (pq.size() > gk)
        {
            pq.pop();
        }

        return pq.top();
    }
};
