/*
Important Case
1 - Integers in each row are sorted in ascending from left to right.
2 - Integers in each column are sorted in ascending from top to bottom.


Leetcode Link - https://leetcode.com/problems/search-a-2d-matrix-ii/description/


matrix = [
          [1,4,7,11,15]
target 19 , suppose element = 15 , here 19>15 so go in next row Basically row++
because 15 hi last value hai

and if target = 7 , 7<15 , means find upto column--

          [2,5,8,12,19]
          [3,6,9,16,22]
          [10,13,14,17,24]
          [18,21,23,26,30]
          ]

*/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int row = matrix.size();

        int col = matrix[0].size();

        int rowIndex = 0;

        int colIndex = col - 1;

        while (rowIndex < row && colIndex >= 0)
        {
            // Starting From 1st row ke last column ki value se ,
            // this is only way to solve this problem , in this case
            int element = matrix[rowIndex][colIndex];

            // Found that
            if (target == element)
                return true;
            //  target 19 , suppose element = 15 ,
            //  here 19>15 so go in next row because 15 hi last value hai
            if (element < target)
                rowIndex++;
            // and if target = 7 , 7<15 , means find upto column--
            else
                colIndex--;
        }
        return false;
    }
};