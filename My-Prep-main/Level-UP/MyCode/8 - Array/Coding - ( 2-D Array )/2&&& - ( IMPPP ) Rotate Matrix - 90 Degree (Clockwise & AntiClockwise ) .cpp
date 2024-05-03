// Leetcode - https://leetcode.com/problems/rotate-image/description/

// Brute Force Approach - 1  -  TC-O(N^2) , SC - O(N*M)

// consider one more matrix and put the values in new considered matrix

// *******************************************************************************************************************

// ( Inplace Swapping )  Optimise Approach  (Clock Wise )

// TC-O(N^2)+O(N^2) ,
// SC - O(1)

#include <iostream>

using namespace std;

void printArray(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void callTranspose(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            int temp = arr[j][i];
            arr[j][i] = arr[i][j];
            arr[i][j] = temp;
        }
    }
}

void ClockWise(int arr[][3], int row, int col)
{
    callTranspose(arr, 3, 3);
    cout << "Transpose in Clockwise Function : " << endl;
    printArray(arr, 3, 3);

    // After Rotate 90 Degree to Clockwise
    cout << "After Rotate 90 Degree Clockwise " << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < (int)row / 2; j++)
        {
            swap(arr[i][j], arr[i][row - j - 1]);
        }
    }

    printArray(arr, 3, 3);
}

void AntiClockWise(int arr[][3], int row, int col)
{
    callTranspose(arr, 3, 3);
    cout << "Transpose in AntiClockWise Function : " << endl;
    printArray(arr, 3, 3);

    // After Rotate 90 Degree to AntiClockWise
    cout << "After Rotate 90 Degree AntiClockWise " << endl;

    for (int i = 0; i < (int)row / 2; i++)
    {
        for (int j = 0; j < row; j++)
        {
            swap(arr[row - i - 1][j], arr[i][j]);
        }
    }
    printArray(arr, 3, 3);
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printArray(arr, 3, 3);

    ClockWise(arr, 3, 3);

    // AntiClockWise(arr , 3 , 3);

    return 0;
}