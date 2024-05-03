
#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    int largest = index;

    // Extract Left data
    if (leftIndex <= n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }
    // Extract Right data
    if (rightIndex <= n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (index != largest)
    {

        // which means left ya right child se koi > hogya currentNode se
        swap(arr[index], arr[largest]);
        index = largest;

        // again call heapify , but here i pass index jo swap hua hai largest ke sth ,
        //                           index
        //                           12
        //                          /  \
        //                        50    60 largest
        //                      /   \   /
        //                    30   40  52

        // In first call , i is like index 12 -> 1 , 50 -> 2 , 60 -> 3 , 30 -> 4 , 40 -> 5 , 52 -> 6
        // i = 1
        // do heapify on 12 value

        //                           60
        //                          /  \
        //                        50    12  index
        //                      /   \   /
        //                    30   40  52

        // Now , i goes to 3 , i = 3 , me 12 is the value
        // so this 12 ko bhi to heapify krna pdega

        //                           60
        //                          /  \
        //                        50    52
        //                      /   \   /
        //                    30   40  12 index

        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n)
{
    // Starting from niche se , then upr jaega ,
    // starting from below non-leaf Node

    // do start from array, where arr ka size n/2 se start hoga

    // because ( n / 2 + 1 to n -> we have leaf Node )
    // but from 1 to n / 2 have a value node
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;
    buildHeap(arr, n);

    cout << "Print Build Heap " << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
