#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void inputMatrix(int arr[][500], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void printMatrix(int arr[][500], int rows, int cols)
{
    cout << '\n';

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// **********************************************************************************************************

void printRowWiseSum(int arr[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        // because yaha pr column change hoga br br , same row pr
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << ' ';
    }
    cout << '\n';
}

// **********************************************************************************************************

void printColWiseSum(int arr[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        // because ander row change hoga br br ek brr same column pr
        for (int j = 0; j < cols; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << ' ';
    }
    cout << '\n';
}

// **********************************************************************************************************

bool linearSearch(int arr[][500], int rows, int cols, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (key == arr[i][j])
                return true;
        }
    }
    return false;
}

// **********************************************************************************************************

void getMinMax(int arr[][3], int rows, int cols)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > maxi)
            {
                maxi = arr[i][j];
            }

            if (arr[i][j] < mini)
            {
                mini = arr[i][j];
            }

            // OR
            // Below work better if matrix me small value also aae , because 1 , goes to if , 2 , 3 , 4 , 5
            // all goes to compare with if not any one goes to else part ,
            // But after 5 any element less than 5, then the else condition will goona rcheck

            // if (arr[i][j] > maxValue)
            // {
            //     maxValue = arr[i][j];
            // }
            // else if (arr[i][j] < minValue)
            // {
            //     minValue = arr[i][j];
            // }
        }
    }
    cout << mini << ' ' << maxi << '\n';
}

// **********************************************************************************************************

// transpose of any rectangular matrix
// This is Applicable for Rectangular Matrix , as well as Square Matrix

void transpose(int arr[][500], int rows, int cols, int ans[][500])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ans[j][i] = arr[i][j];
        }
    }
}

// **********************************************************************************************************

int main()
{

    // declaration of 2D array
    int arr[3][3];

    /// initialization of 2D array
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << arr[2][0] << '\n';

    // ************************************************************************************************************************

    // row-wise access
    // int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int rows = 3;
    // int cols = 3;

    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // ************************************************************************************************************************

    // col-wise access
    // int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int rows = 3;
    // int cols = 3;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << arr[j][i] << ' ';
    //     }
    //     cout << '\n';
    // }

    // ************************************************************************************************************************

    // taking row wise input

    int arr[500][500];
    int rows = 4;
    int cols = 3;
    inputMatrix(arr, rows, cols);
    printMatrix(arr, rows, cols);

    // taking col wise input

    int arr[500][500];
    int rows = 4;
    int cols = 3;

    // ************************************************************************************************************************

    // print row sum
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printRowWiseSum(arr, 3, 3);

    // print col sum
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printColWiseSum(arr, 3, 3);

    // ************************************************************************************************************************

    // linear search in a 2D array
    int arr[500][500] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;
    int key;
    cin >> key;
    int ans = linearSearch(arr, rows, cols, key);
    if (ans)
        cout << "present\n";
    else
        cout << "absent\n";

    // ************************************************************************************************************************

    // maximum and minimum elements in an array
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    getMinMax(arr, 3, 3);

    // ************************************************************************************************************************

    // transpose of any rectangular matrix
    int arr[500][500] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 3, 5}, {2, 4, 8}};
    int rows = 5;
    int cols = 3;
    int ans[500][500];
    cout << "1st method\n";
    printMatrix(arr, rows, cols);
    transpose(arr, rows, cols, ans);
    printMatrix(ans, cols, rows);

    // ************************************************************************************************************************

    return 0;
}