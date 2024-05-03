// TC - O(N^2)
// SC - O(N + 2);

// Becuase last wala printSubarrayforStart Beacuse ,
// ye function me rhega always kyuki ye function khatam nhi hoga

#include <iostream>
#include <vector>
using namespace std;

// Iterate hoga phle start = 0 , end = 0 ke lie

// Then end + 1 kr kre 1 ke sth saara print kraa dena
// 1               start = 0 , end = 0
// 1 2             start = 0 , end = 1
// 1 2 3           start = 0 , end = 2
// 1 2 3 4         start = 0 , end = 3
// 1 2 3 4 5       start = 0 , end = 5

// if n > nums.size() then , go out of this fun
// then in printSubarrayforStart me jaakr start = 1 krwa lega , so ab start = 2 hai , automatically end = 2 ,

// 2               start = 1 , end = 1
// 2 3             start = 1 , end = 2
// 2 3 4           start = 1 , end = 3
// 2 3 4 5         start = 1 , end = 4

void printSubarrayfixEnd(vector<int> &nums, int start, int end)
{
    if (end == nums.size())
    {
        return;
    }

    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    printSubarrayfixEnd(nums, start, end + 1);
}

void printSubarrayfixStart(vector<int> &nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        int end = start;
        printSubarrayfixEnd(nums, start, end);
    }
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};

    printSubarrayfixStart(v);

    return 0;
}
