/*
GFG Link - https://practice.geeksforgeeks.org/problems/queue-reversal/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
*/

class Solution
{

public:
    //                                           Approach - 1(Using Stack)

    // phle  queue me aage se sb nikalte chalo, or usko stack me daalte chalo,
    // then jb stack me sb aajae,
    // phr  stack ke top se nikal kr sb wapas q me piche se daalte chalenge

    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        int n = q.size();

        // Phle queue se stack me daaala
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            s.push(num);
        }
        // Phr stack ke last me jo dalega wo queue me phle dalega
        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
        return q;
    }

    // **************************************************************

    //                                              Approach - 2 ( Using Reccursion )

    void reverse(queue<int> &q)
    {

        // aage se phla element nikalte rhenge ,
        // jaise hi aakri element milega ,
        // tb usko hum wapas piche se daalna start kr deneg

        if (q.empty())
            return;

        int temp = q.front();
        q.pop();
        // Call reccursion
        reverse(q);
        // Push when backtrack
        q.push(temp);
    }

    queue<int> rev(queue<int> q)
    {
        reverse(q);
        return q;
    }

    //                                              Approach - 3 ( Using Deque )
};