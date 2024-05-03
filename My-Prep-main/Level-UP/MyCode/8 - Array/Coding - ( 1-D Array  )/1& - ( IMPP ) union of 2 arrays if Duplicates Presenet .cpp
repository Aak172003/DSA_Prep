// Logic :

// Traverse from 1st array , and check in vector if current value at array is present in vector or not ,
// if not present add that particular element into vector

// Do same For second array as well
// Traverse from 2nd array , and check in vector if current value at array is present in vector or not ,
// if not present add that particular element into vector

#include <iostream>
#include <vector>
using namespace std;

// simply traverse krega ans pr jo final ans hoga hamara ,
// agr traverse ke time milta hai so return true otherwise false

bool isAlreadyPresent(int element, vector<int> arr)
{
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] == element)
            return true;
    }
    return false;
}

void findUnion(vector<int> arr1, vector<int> arr2)
{
    // ans vector me apna saara store krenge union value , or duplicay pta lgane ke lie ,

    // hum isAlreadyPresent function ko call kr denge ki jo bhi value mai array se traverse krke extract kr rha hu
    // wo ans array me present hai ki nhi wo

    vector<int> ans;
    for (auto element : arr1)
    {

        bool flag = isAlreadyPresent(element, ans);
        // if false -> means not present  so simply push into the ans array
        if (flag == false)
        {
            ans.push_back(element);
        }
    }

    // same with arr2
    // if false -> means not present  so simply push into the ans array
    for (auto element : arr2)
    {
        bool flag = isAlreadyPresent(element, ans);
        if (flag == false)
        {
            ans.push_back(element);
        }
    }

    // Traverse All over the vector ans
    for (auto val : ans)
    {
        cout << val << ' ';
    }
}

int main()
{

    int m, n;

    cin >> m;
    vector<int> arr1(m);

    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }

    cin >> n;
    vector<int> arr2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    findUnion(arr1, arr2);
    return 0;
}
