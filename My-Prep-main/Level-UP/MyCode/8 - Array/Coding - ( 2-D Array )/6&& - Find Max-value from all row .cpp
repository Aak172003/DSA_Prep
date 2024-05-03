
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void printArray(int arr[][4], int row, int col)
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

void getMaxRowwise(int arr[][4], int row, int col)
{
    cout << "Inside getMaxRowwise fun : " << endl;
    printArray(arr, row, col);

    vector<int> ans;
    int mvalue = INT_MIN;

    cout << "mvalue is  : " << mvalue << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mvalue = max(mvalue, arr[i][j]);
        }
        cout << "mvalue is : " << mvalue << endl;
        ans.push_back(mvalue);
        mvalue = 0;
    }

    for (auto it : ans)
    {
        cout << it << endl;
    }
}

int main()
{
    int arr[3][4] = {{1, 2, 3, 21}, {100, 1, 65, 9}, {5, 6, 34, 2}};
    int row = 3, col = 4;

    printArray(arr, row, col);
    getMaxRowwise(arr, row, col);

    return 0;
}
