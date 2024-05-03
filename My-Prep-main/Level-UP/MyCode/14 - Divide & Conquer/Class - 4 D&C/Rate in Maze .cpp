#include <iostream>
#include <vector>

using namespace std;

// Printing the Matrix
void printSolution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
    int i = row;
    int j = col;

    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }

    // Check Upper Half Diagonal

    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i--, j--;
    }

    // Check Bottom Up Diagonal

    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i++, j--;
    }

    return true;
}

void solve(vector<vector<char>> &board, int col, int n)
{
    // Base Case
    if (col >= n)
    {
        printSolution(board, n);
        return;
    }

    // solve case 1 , And all Case will handle by Reccursion

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {

            // rakh do
            board[row][col] = 'Q';
            solve(board, col + 1, n);

            board[row][col] = '-';
        }
    }
}

int main()
{
    int n = 4;

    // Means here Create 4 * 4 ka chess board bn gya
    vector<vector<char>> board(n, vector<char>(n, '-'));

    int col = 0;

    // 0 -> empty cell
    // 1 -> Queen at Cell

    solve(board, col, n);
    return 0;
}
