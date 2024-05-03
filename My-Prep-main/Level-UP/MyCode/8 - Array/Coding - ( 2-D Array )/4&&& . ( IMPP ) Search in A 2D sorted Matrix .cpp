/*
LeetCode Link - https://leetcode.com/problems/search-a-2d-matrix/
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        /*                        BRUTE FORCE

       int m = matrix.size();
       int n = matrix[0].size();

       int count =0;

       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(matrix[i][j]==target)
               count=1;

           }
       }

       if(count==1)
       return true;
       else
       return false;

       */

        /*        APPROACH 2 BINARY SEARCH

        The problem statement states that the values of the last col of the ith row is lesser than the first col of (i+1)th row.
        7 < 10 , 20 < 23
        Also, each row is sorted.

        This means that, if we linearly arrange the elements of each row, we will have a sorted array.
        So we can now perform a binary search over it.

        Time Complexity: O(log(m*n)) =O(log(m) + log(n))
        Space Complexity: O(1)

        */

        int row = matrix.size();
        int col = matrix[0].size();

        // if matrix have 0 rows or 0 colums
        if (row == 0 || col == 0)
            return false;

        // treating matrix as array just taking care of end index
        // [0..n*m]
        int start = 0, end = row * col - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            // Now Find mid Position , bY Below Formula

            // a[index] : matrix[index /col][index % col] formulae

            // Here mid  = index

            // Row : index / total-no-of-Col
            // Col : index % total-no-of-Col

            // find value of that particular index where mid is pointing
            int index = matrix[mid / col][mid % col];

            if (target == index)
                return true;
            // left half
            else if (target < index)
                end = mid - 1;
            else
                // right half
                start = mid + 1;
        }
        return false;
    }
};