
// My Notes

// Tc - for Merge Sort - O(N logN)
// SC - for Merge sort - O(1)

#include <iostream>
#include <vector>
using namespace std;

// For Printing The array
void printVector(vector<int> arr)
{
    for (auto i : arr)
        cout << i << ' ';
    cout << '\n';
}

void inplaceMerge(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int i = s;
    int j = mid + 1;
    int ans = 0;

    // Here check wheteher ki elements phle se hi sorted order me to nhi hai ,
    // agr hota hai to mai merge sort kyu lgau
    if (arr[j] >= arr[mid])
        return;

    while (i <= e && j <= e && i != j)
    {
        // if arr[i] <= arr[j] ke to waha swapping nhi hoga element ka ,
        // i++ krdenge
        if (arr[i] <= arr[j])
        {
            i++;
        }

        else
        {
            int temp = arr[j];
            // yaha j ki position pr wo k maan kr jbtk k reach nhi krjata or jb tk k > i se,
            // tb tk wo arr[k] me arr[k - 1] krdeta hai means,
            // piche ke elements ko aage daal deta hai,
            // phr us i ki jgah pr j wali value daal deta hai int k = j;

            while (k > i)
            {
                arr[k] = arr[k - 1];
                k--;
            }
            arr[i] = temp;
            i++;
            j++;
        }
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    inplaceMerge(arr, s, e);
}

int main()
{

    vector<int> arr{2, 4, 1, 3, 5};
    int s = 0, e = arr.size() - 1;
    mergeSort(arr, s, e);
    printVector(arr);

    return 0;
}