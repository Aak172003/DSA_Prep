// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

// https://leetcode.com/problems/sort-colors/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        // Approcah - 1
        // TC - O(nlogn)
        // SC - O(1)

        sort(a, a + n);

        // Approach - 2  ( Use Counting Sort )   Take three Variable
        // TC - O(n)
        // SC - O(1)

        int c0 = 0;
        int c1 = 0;
        int c2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                c0++;
            }
            else if (a[i] == 1)
                c1++;
            else
                c2++;
        }

        int i = 0;
        while (c0 >= 1)
        {
            a[i] = 0;

            c0--;
            i++;
        }

        while (c1 >= 1)
        {
            a[i] = 1;

            c1--;
            i++;
        }

        while (c2 >= 1)
        {
            a[i] = 2;

            c2--;
            i++;
        }

        // Approach - 3 ( Ducth National Flag )
        // TC - O(n)
        // SC - O(1)

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
                mid++;
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
