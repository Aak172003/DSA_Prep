/*
Leetcode Link - https://leetcode.com/problems/spiral-matrix/

*/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // here i store all emenets
        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        // Count points to 1st Element
        int count = 0;
        // total represent total no of Elemenets
        int total = row * col;

        // Index Initialization
        int startingRow = 0;
        int startingCol = 0;
        int EndingRow = row - 1;
        int EndingCol = col - 1;

        // jb tk count == na hojae total ement ke ,
        //  tb tk hum ye nhi maan skte hi humne poora 2d array traverse krlia hai
        while (count < total)
        {
            // print Starting row
            for (int index = startingCol; count < total && index <= EndingCol; index++) // During Incresing check Also count<total condition
            {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            // Print Ending Column
            for (int index = startingRow; count < total && index <= EndingRow; index++)
            {
                ans.push_back(matrix[index][EndingCol]);
                count++;
            }
            EndingCol--;

            // Print last Row Elements
            for (int index = EndingCol; count < total && index >= startingCol; index--)
            {
                ans.push_back(matrix[EndingRow][index]);
                count++;
            }
            EndingRow--;

            // Print First Column
            for (int index = EndingRow; count < total && index >= startingRow; index--)
            {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};