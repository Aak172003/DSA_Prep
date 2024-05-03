#include <vector>

void multiply(int A[][100], int B[][100], int C[][100], int N)
{
    //   Row
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
}

//                                   OR

// Link - https://www.youtube.com/watch?v=DvG9SF2VXL4&t=17s

//                      row , col  :   row , col
//                       n1 x m1   :    n2 x m2

// // row
// int n1 = A.size();
// int n2 = B.size();

// // col
// int m1 = A[0].size();
// int m2 = B[0].size();

// vector<vector<int>> ans;

// if (m1 == n2)
// {
//     // Fix a row
//     for (int i = 0; i < n1; i++)
//     {
//         vector<int> temp;

//         // 2nd matrix ke column ka access
//         for (int j = 0; j < m2; j++)
//         {
//             int sum = 0;
//             // write n1 or m2 ( new array me jaha after operation daalna hai)
//             for (int k = 0; k < n1; k++)
//             {
//                 // k move according to row or column no of any of two matrix
//                 sum = sum + A[i][k] * B[k][j];
//             }
//             temp.push_back(sum);
//         }
//         ans.push_back(sum);
//     }
// }
// else
// {
//     return ans;
// }