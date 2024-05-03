/*

Link - https://takeuforward.org/data-structure/set-matrix-zero/

*/

//  ***********************************       Brute Force Approach

// Mark Row
void markRow(vector<vector<int>> &matrix, int n, int m, int i)
{
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

// Mark column
void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // Function for mark row as -1
                markRow(matrix, n, m, i);
                // Function for mark col as -1
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    return 0;
}

//  *********************************   Better  Approach

int row[n] = {0}; // row array
int col[m] = {0}; // col array

// Traverse the matrix:
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] == 0)
        {
            // mark ith index of row wih 1:
            row[i] = 1;

            // mark jth index of col wih 1:
            col[j] = 1;
        }
    }
}

// Finally, mark all (i, j) as 0
// if row[i] or col[j] is marked with 1.
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (row[i] || col[j])
        {
            matrix[i][j] = 0;
        }
    }
}

return matrix;

//  *********************************   Optimise Approach

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = true;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // iterate from forward
        /* For Row */
        for (int i = 0; i < rows; i++)
        {
            if ()
                col0 = false;

            /* For Column */
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    // where we find 0 , then make 0 at corresponds dummy to 0
                    matrix[i][0] = matrix[0][j] = 0;
        }

        // After set all Dummy elements is 0
        // then again traverse from back

        // iterate from backward
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)

                /* Check in dummy row and column , if any of 0 */
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    // if any of 0 , thrn put corresponds to 0
                    matrix[i][j] = 0;
                }
            // if row goes to 0th row , so check ki col0 is true or false ,
            // if false so put matrix[0][0] = 0;

            // Bcoz kyuki, 1st column me hi kahi mujhe 0 mil chuka tha ,
            // so its compusory ki 0th column ke saare elemenet bcomes 0

            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};