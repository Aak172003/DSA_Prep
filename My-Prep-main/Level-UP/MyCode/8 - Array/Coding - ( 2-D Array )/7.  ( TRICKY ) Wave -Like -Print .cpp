/*
Code Studio Link - https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_6&leftPanelTab=1


Here Logic is that column wise print krna hai ,
even column pr upr se niche print ans
odd column pr niche se upr print

*/

#include <bits/stdc++.h>
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;

    // cout << "n row is " << nRows << endl;   -> give row
    // cout << "m col is " << mCols << endl;   -> give col

    for (int col = 0; col < mCols; col++)
    {
        if (col & 1) // true means it is odd value
        {
            // odd Index -> Bottom to top
            for (int row = nRows - 1; row >= 0; row--)
            {
                ans.push_back(arr[row][col]);
            }
        }
        else
        {
            // 0 or even iondex -> top to bottom
            for (int row = 0; row < nRows; row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}