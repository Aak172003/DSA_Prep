
// Gfg - https : // practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {

        vector<int> finalamount;
        // Array ko sort aise krte hai
        sort(candies, candies + N);

        // But agr vector hota to hum
        // sort(candies.begin(), candies.end());

        /*
        Minimum amout find krne ke lie hum piche se free ko remove krenge or aage se buy krenge
        */
        int mini = 0;
        int buy = 0;
        int free = N - 1;

        while (buy <= free)
        {
            mini = mini + candies[buy];
            // ek brr mini me buy index ki value add krne ke bdd buy index ko aage bhej dena hai
            // or bs check krte rhna hai ki wo , free index sekm hi rhe
            buy++;

            free = free - K;
        }

        /*
  Maximum amout find krne ke lie hum aage se free ko remove krenge or piche se buy krte chalenge
  */
        int maxi = 0;
        buy = N - 1;
        free = 0;

        while (free <= buy)
        {
            maxi = maxi + candies[buy];
            // ek brr mini me buy index ki value add krne ke bdd buy index ko km krdena  hai
            // or bs check krte rhna hai ki wo , free index sekm jyada hi rhe
            buy--;
            free = free + K;
        }
        finalamount.push_back(mini);
        finalamount.push_back(maxi);

        return finalamount;
    }
};