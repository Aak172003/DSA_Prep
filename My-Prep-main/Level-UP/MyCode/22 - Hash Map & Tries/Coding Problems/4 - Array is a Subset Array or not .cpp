
// Gfg - https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Approach - 1 ( Linear Search )
// Tc - O(mn)

string isSubset(int a1[], int a2[], int n, int m)
{

    for (int i = 0; i < m; i++)
    {
        int val = a2[i];
        int flag = 0; // Move flag inside the loop

        for (int j = 0; j < n; j++)
        {
            if (val == a1[j])
            {
                flag = 1;
                a1[j] = -1; // Mark element as used
                break;
            }
        }

        if (flag == 0)
            return "No"; // Use '==' instead of '='
    }

    return "Yes";
}

// Approach - 2 ( use Binary Search ) -> means jaha Linear Serach lg pae , so waha Binary Serach uska Optimal hoga
// Tc - O(m log n)

void binarysearch(int a1[], int value, int &flag, int size)
{
    sort(a1, a1 + size);
    int start = 0, end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (value == a1[mid])
        {
            flag = 1;
            a1[mid] = -1; // Mark element as used
            break;
        }
        else if (value > a1[mid])
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
}
string isSubset(int a1[], int a2[], int n, int m)
{

    for (int i = 0; i < m; i++)
    {
        int val = a2[i];
        int flag = 0;

        binarysearch(a1, val, flag, n);

        if (flag == 0)
            return "No"; // Use '==' instead of '='
    }

    return "Yes";
}

// Use Hash Map  Tc - O(m + n)

string isSubset(int a1[], int a2[], int n, int m)
{

    string ans = "Yes";

    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++)
        mpp[a1[i]]++;

    for (int i = 0; i < m; i++)
    {
        int val = a2[i];
        if (mpp.find(val) != mpp.end())
        {
            if (mpp[val] > 0)
                mpp[val]--;
            else
            {
                ans = "No";
                break;
            }
        }
        else
        {
            ans = "No";
            break;
        }
    }

    return ans;
}