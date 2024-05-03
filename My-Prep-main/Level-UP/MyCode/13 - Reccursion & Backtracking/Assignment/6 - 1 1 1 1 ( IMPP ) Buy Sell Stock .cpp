

// LeetCode - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

//                                                             MyPdf

class Solution
{
public:
    //                              Approach - 1  ( Using Iterative Approach  )

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;
        int minm = prices[0];
        int profit = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            minm = min(prices[i], minm);
            cout << "the mini " << i << " is : " << minm << endl;

            profit = max(prices[i] - minm, profit);
            cout << "the profit " << i << "is : " << profit << endl;
        }
        return profit;
    }

    //                              Approach - 2  ( Using Reccursive Approach  )

    void giveProfit(vector<int> &prices, int &miniDay, int &profit, int startInd)
    {

        if (startInd >= prices.size())
        {
            return;
        }
        miniDay = min(prices[startInd], miniDay);
        profit = max(prices[startInd] - miniDay, profit);

        giveProfit(prices, miniDay, profit, startInd + 1);
    }
    int maxProfit(vector<int> &prices)
    {

        if (prices.size() == 1)
            return 0;

        int miniDay = prices[0];
        int profit = INT_MIN;
        int startInd = 1;
        giveProfit(prices, miniDay, profit, startInd);

        return profit;
    }
};