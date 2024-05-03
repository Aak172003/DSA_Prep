
// Gfg - https://practice.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
public:
    int minRow(int N, int M, vector<vector<int>> A)
    {

        int minCount = INT_MAX;
        int index = 0;
        // int count = 0;
        for (int i = 0; i < N; i++)
        {
            int count = 0;

            for (int j = 0; j < M; j++)
            {
                // count 1 in each row
                if (A[i][j] == 1)
                {
                    count++;
                }
            }
            // count < minCount so update minCount , index
            if (count < minCount)
            {
                minCount = count;
                index = i;
            }
        }
        return index + 1;
    }
};