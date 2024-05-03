class Solution
{
public:
    void solve(stack<int> &s, int count, int size)
    {
        // base case
        if (count == size / 2) // size ki value fix hoti hai
        {
            s.pop();
            return;
        }

        // hr upr se ek ek element ko store krega ,
        // then pop krlenge phr function call mrr dega
        int ans = s.top();
        s.pop();

        // Recursion
        // Hum count bdhate jenge ki jb tk wo size/2 ke = na aajae ,
        // if aajata hai to return krenge or us stage me jo temp tha usko add krdenge
        solve(s, count + 1, size);

        s.push(ans);
    }

    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        int count = 0;
        solve(s, count, sizeOfStack);
    }
};