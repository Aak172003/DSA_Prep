
// LeetCode - https://leetcode.com/problems/transpose-matrix/description/

// Retun 2d vector ( Use Extra space )

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{

    // Make 2d Vector
    int r = matrix.size();
    int c = matrix[0].size();

    // Make 2D vector of col x row size (Beacuse after transpose ,
    // row becomes col , and col becomes row )

    vector<vector<int>> ans(c, vector<int>(r, 0));

    // Iterate in column wise
    for (int i = 0; i < c; i++)
    {
        // and insert in  sequence wise ( or Row Wise )
        for (int j = 0; j < r; j++)
        {
            ans[i][j] = matrix[j][i];
        }
    }
    return ans;
}

// Void DataType : Inplace Transpose

// Approach 1(Brute Force) : The first approach come to our mind is to
//                           initialize an another array,
//                           and store the value
//                           arr2[i][j] = arr1[i][j] like this and again restore
//                           the value to the original array.

void transpose(vector<vector<int>> &matrix, int n)
{
    // code here
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = matrix[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = arr[i][j];
        }
    }
}

// Time complexity: O(n^2), Because we are running nested loop.
// Auxiliary space: O(n^2), Because we have used an array of size (N*N).

// Approach2: Now we are doing this using in-palce swaaping in the existing array it will reduce our space from O(n) to O(1).

// follow the below steps to solve this problem:

// Run a nested loop from i=0 to n.
// and swap the arr[i][j] value to arr[j][i] .

void transpose(vector<vector<int>> &matrix, int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}