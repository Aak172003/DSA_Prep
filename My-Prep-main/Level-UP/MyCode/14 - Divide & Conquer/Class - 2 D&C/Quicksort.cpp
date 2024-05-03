#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << ' ';
    cout << '\n';
}

int partition(vector<int> &arr, int s, int e)
{
    int pivotIndex = s; // take 1 element
    int pivot = arr[s]; // take pivot element

    // Count krkenge left se jb tk pivot se chota hoga , when jaise hi condition
    // fail , then we put pivot value at count + 1 index pr
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
            cnt++;
    }
    // When Fail
    // then we put pivot value at count + 1 index pr
    int correctIndex = s + cnt;

    swap(arr[pivotIndex], arr[correctIndex]);
    pivotIndex = correctIndex;

    // make left me chote elements , or right me bde elemnts
    // Use 2 pointer Approch ,
    // agr left me bd value or right me chota so turant swap krdenge or i++ , j-- krdenge

    int i = s, j = e;

    while (i < correctIndex && j > correctIndex)
    {
        // if left me pivot se bd then swap with right me pivot se chota
        while (arr[i] < pivot)
            i++;
        while (arr[j] >= pivot)
            j--;
        if (i < correctIndex && j > correctIndex)
            swap(arr[i++], arr[j--]);
    }

    // bcoz issi se left or right part me divide hoga
    return correctIndex;
}

void quickSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        // s==e single element is sorted already    s>e invalid array
        return;

    // partition
    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1); // left half
    quickSort(arr, p + 1, e); // right half
}

// **********************************************************************************************

int main()
{

    vector<int> arr{5, 2, 5, 8, 2, 1, 5, 6, 34, 3};
    int s = 0;
    int e = arr.size() - 1;
    printVector(arr);
    quickSort(arr, s, e);
    printVector(arr);

    return 0;
}