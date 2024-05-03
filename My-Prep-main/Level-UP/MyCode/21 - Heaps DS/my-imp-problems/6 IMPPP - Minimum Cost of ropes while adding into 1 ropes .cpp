// LeetCode - https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
// Ytube -  https://youtu.be/mRtq1ucnjJg

// There are given N ropes of different lengths,
// we need to connect these ropes into one rope.
// The cost to connect two ropes is equal to sum of their lengths.
// The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes.

class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {

        priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);

        long cost = 0;
        while (pq.size() != 1)
        {

            // phle saare array elements ko Min heap priority queue me daal do
            // uske bd ek brr me do do krke elements nikalo or unko 2 alag alag variable me daal lo
            // then uske bdd add krlo

            long long value1 = pq.top();
            pq.pop();
            long long value2 = pq.top();
            pq.pop();

            // phr jo add aaya hai dono variable se unko cost ke sth or add krdo
            // or waha priority queue me dono variale ka sum daal dena hai

            cost = cost + (value1 + value2);
            pq.push(value1 + value2);
        }
        return cost;
    }
};
