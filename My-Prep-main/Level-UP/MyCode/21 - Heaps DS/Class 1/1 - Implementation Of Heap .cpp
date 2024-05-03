
// Creating heap using Array

#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    // By default , array size in heap is 0
    Heap()
    {
        size = 0;
    }

    void insert(int value)
    {
        // Value insert at end , Phle size bdhana hai
        size = size + 1;
        int index = size;
        arr[index] = value;

        // Placed at Right Position
        // i was store size in index , because index is used to check ,
        // wherther this new element are at current postion or not

        while (index > 1)
        {
            int parentIndex = index / 2;

            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }

        cout << "Succesfull Insert " << endl;
    }

    int deleteData()
    {

        int deletedValue = arr[1];

        // Replace root node value , with last data
        arr[1] = arr[size];
        size--;

        // place root node ka data on its correct position
        int index = 1;
        while (index < size)
        {

            // Extract Left data
            int left = 2 * index;
            // Extract Right Data
            int right = 2 * index + 1;

            // store index of largest value ,
            // between parent ke left and right se
            int larget = index;

            // Left Largest
            if (left < size && arr[larget] < arr[left])
            {
                larget = left;
            }
            // Right Largest
            if (right < size && arr[larget] < arr[right])
            {
                larget = right;
            }

            if (larget == index)
            {
                // value is at correct position

                break;
            }
            else
            {
                swap(arr[index], arr[larget]);
                index = larget;
            }
        }

        return deletedValue;
    }
};

int main()
{
    Heap h;

    // h.arr[0] = -1 ;
    // h.arr[1] = 100 ;
    // h.arr[2] = 50 ;
    // h.arr[3] = 60 ;
    // h.arr[4] = 40 ;
    // h.arr[5] = 45 ;
    // h.size = 5 ;

    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    cout << "Printing the heap " << endl;

    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // h.insert(110) ;

    // cout<<"Printing the heap After Inserting  "<<endl ;

    // for(int i = 0 ;i <= h.size ; i++){
    //     cout<<h.arr[i]<<" " ;
    // }
    // cout<<endl ;

    int deletedValue = h.deleteData();
    cout << "Deleted Value -> " << deletedValue << endl;

    return 0;
}
