/*
LeetCode Link - https://leetcode.com/problems/rotate-array/
*/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        // Approach - 1 -> By using an Extra Space

        // Time Complexity : O(N)
        // Space Complexity : O(N)

        /*
        yaha agr hum original nums me operation krte to , starting ke 3 index tk ke operation
        aage ki value me overwrite kr jaate , jiski wjh se hum aage ki value lost krjaate

        islea hume ek new vector bnate hai same size ka ,
        ussi me saari value ek ek krke daalte hai
        */

        // Here declare temp vector jo ki store krega
        vector<int> temp(nums.size());
        for (int i = 0; i < temp.size(); i++)
        {
            // arr[(i+k)%n] = arr[i] shift in cyclic Way k position
            temp[(i + k) % nums.size()] = nums[i];
        }
        // copy temp into nums vector
        nums = temp;
    }

    // Approach - 2 -> Without using an extra space
    // Time Complexity : O(N)

    // Space Complexity : O(1)

    void reverse(vector<int> &num, int low, int high)
    {
        while (low < high)
        {
            swap(num[low], num[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {

        int n = (int)nums.size();

        // if give n value size 7 digit and k = 10 ,
        // // According to nums, 0, n - k - 1            n = 7 , k = 10
        // 0 , 7 - 10    -> 0 , -3 is not a valid index , so to achieve Valid index ,

        // k = k % n;  -> 10  % 7 = 3

        // so as if now 0 , 7 - 3   -> 0 , 44 is a valid index

        k = k % n;
        reverse(nums, 0, n - k - 1);

        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};