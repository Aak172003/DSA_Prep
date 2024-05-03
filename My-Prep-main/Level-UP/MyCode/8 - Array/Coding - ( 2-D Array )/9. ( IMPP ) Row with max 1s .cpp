
/*
GFG - https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s
*/

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {

        // isme ek ind variable lenge jo last me us current row ka index dega

        // here originalcount lenge jisme matrix me traverse ke time pr ek maxcount lenge

        // jisme maximum aaega maxcount ,
        // us ind ko hum store kr leneg or original count me wo current maxcount daal denge

        // ki bdd me aane wale baaki row me maxcount pta kr ske ki kon se row me max count hai 1s ka

        int origcount = 0;
        int ind = -1;

        for (int i = 0; i < n; i++)
        {
            int maxcount = 0;

            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                    maxcount++;
            }

            if (maxcount > origcount)
            {
                origcount = maxcount;
                ind = i;
            }
        }
        return ind;
    }
};
