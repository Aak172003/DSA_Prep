#include <iostream>
using namespace std;

#include <limits.h>
#include <vector>

int main()
{

    //                     STL me 2D Array

    // 2D vector      declaration, insertion, access

    // declaration of 2d
    vector<vector<int>> arr;

    // Vector 1D array ka , jisme value put via itself
    vector<int> a{1, 2, 3};
    vector<int> b{4, 5, 6};
    vector<int> c{7, 8, 9};

    // insetion in 2D vector
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    // ************************************************************************************************************************

    // How can i find size
    int row = arr.size();
    int col = arr[0].size();

    // ************************************************************************************************************************

    // row-wise access in 2D vector
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    //                                   STL

    // initialization
    int rows = 3;
    int col = 5;

    // vector<vector<int>> arr(row, vector<int>(col, value));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        // if no of column same hoga to 0 , 1 , 2 sbhi se kaam chl jaega
        // but if no of column is different , so use i , because i indicates krega us vector
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    // ************************************************************************************************************************

    // yaha 2d array me byDefault -8 chala jaega sb me

    vector<vector<int>> arr2(5, vector<int>(5, -8));
    for (int i = 0; i < arr2.size(); i++)
    {
        for (int j = 0; j < arr2[0].size(); j++)
        {
            cout << arr2[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    // ************************************************************************************************************************

    return 0;
}