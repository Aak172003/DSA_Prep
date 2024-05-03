
// Interview Questio , Definately Considered

// This Approach Take an Extra Space - O(N)
// But If we want solve in Using Without Extra space

// Leetcode Link - https://leetcode.com/problems/merge-sorted-array/description/

// We will keep checking for the greater element of the two arrays(i=m-1,j=n-1) and insert the values.

// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// nums1 = [1,2,3,0,0,0]
//              |     |
//              i     k

// nums2 = [2,5,6]
//              |
//              j

// nums2[j] > nums1[i] thus nums1[k]=6
// k and j are decremented.

// ********************************* 1ST Complete ******************************************************************

// nums1 = [1,2,3,0,0,6]
//              |   |
//              i   k

// nums2 = [2,5,6]
//            |
//            j
// nums2[j]>nums1[i] thus nums1[k]=5
// k and j are decremented.

// ********************************* 2ND Complete********************************************************************

// nums1 = [1,2,3,0,5,6]
//              | |
//              i k

// nums2 = [2,5,6]
//          |
//          j
// nums2[j]<nums1[i] thus nums1[k]=3

// ********************************* 3RD Complete********************************************************************

// nums1 = [1,2,3,3,5,6]
//            | |
//            i k

// nums2 = [2,5,6]
//          |
//          j
// k and i are decremented.
// nums2[j]=nums1[i] thus nums1[k]=2

// ********************************* 4RTH Complete********************************************************************

// nums1 = [1,2,2,3,5,6]
//          | |
//          i k

// nums2 = [2,5,6]
//          |
//          j
// k and i are decremented.
// nums2[j]>nums1[i] thus nums1[k]=2

// / ********************************* 5TH Complete********************************************************************

// nums1 = [1,2,2,3,5,6]
//          |
//          i,k    i and k both point first index

// nums2 = [2,5,6]
//          |
//          j
// nums2[j] = nums1[i] thus nums1[k]=2
// k and j are decremented. J over here  , then pit remaining value in arr1

* /

    class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Kyuki jb m size ki array me jaha jaha 0 hai waha n jaega to islea
        // k ka size m+n-1 hi lenge

        while (i > = 0 &&j > = 0)
        {
            if (nums1[i] > nums2[j])
            {
                // then 2nd execute , according above example
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else
            {
                // 1st execute  , according above example
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        // jb j ya i me se koi bhi 0 pr pauch jaega to hum dono i , j
        // me se jo 0 tk nhi pauce honge to hum usko value daalte jaega normally

        while (i >= 0) // for i ke lie
        {
            nums1[k] = nums1[i];
            k--;
            i--;
        }

        while (j >= 0) // for j ke lie
        {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};

// *************************************************************************************************************

//                                    Merge Two Sorted with Extra Space m+n size
//                                    where m and n is length of give both two array

void mergeSortedArray(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0; // for both given two sorted array
    int k = 0;        // for new Array of size m+n
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
            // or we can also write in below way
            // k++,i++
        }
        else
        {
            arr3[k++] = arr2[j++];
            // or we can also write in below way
            // k++,j++
        }
    }
    // Copy First K element from array 1
    while (i < n)
    {
        arr3[k++] = arr1[i++];
        // or we can also write in below way
        // k++,i++
    }
    while (j < m)
    {
        arr3[k++] = arr2[j++];
        // or we can also write in below way
        // k++,j++
    }
}

int main()
{
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 6};

    int arr3[8] = {0};

    mergeSortedArray(arr1, 5, arr2, 3, arr3);

    return 0;
}
