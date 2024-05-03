

// Leetcode - https : // leetcode.com/problems/k-diff-pairs-in-an-array/description/
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        // ***************************  Approach -1 Brute Force Approach -> Two for Loop
        // TC - O(N^2)
        // SC - O(1)

        // But This case was not , handle duplicate data

        // int n = nums.size();
        // for(int i=0;i<n;i++)
        // {
        //     for(int j = i+1;j<n;j++)
        //     {
        //         if(abs(nums[i] - nums[j]) == k)
        //         {
        //             count++;
        //         }
        //     }
        // }
        // return count;

        // ***************************  Approach - 2 Two Pointer Approach
        // TC - O(N)
        // SC - O(1)

        // sort(nums.begin(), nums.end());
        // int i = 0, j = 1, ans = 0;

        // while (i < nums.size() && j < nums.size())
        // {
        //     if (nums[j] - nums[i] == k)
        //     {
        //         ans++;
        //         i++, j++;
        //         // This is used for handle duplicate data
        //         // 1 1 1 1 3 4 5
        //         // i j
        //         // kyuko agr hum 1 - 1 = 0 mil gya to agr j ko ek brr bdhaenge , tb bhi same cheez ke lie ans++ hojaega
        //         // i      j
        //         while (j < nums.size() && nums[j] == nums[j - 1])
        //         {
        //             j++;
        //         }
        //     }
        //     else if (nums[j] - nums[i] > k)
        //     {
        //         i++;
        //         // For this Case
        //         // Let's say 1 3 4 5 6 , where k = 0
        //         //           i j
        //         // here 3 - 1 > k so i++;

        //         // Let's say 1 3 4 5 6 , where k = 0
        //         //             |
        //         //             i,j
        //         if (j - i == 0)
        //         {
        //             j++;
        //         }
        //     }
        //     else
        //         j++;
        // }
        // return ans;

        // ***************************  Approach - 3 Two Pointer Approach + Set
        // TC - O(N)
        // SC - O(N)

        int count = 0;

        sort(nums.begin(), nums.end());
        // Pairs ko ander daal dega jb unka diff == k hoga jisse ki aage aane wala same pair ka count na hopae
        // Bhale unka diff == k ho jae
        set<pair<int, int>> ans;

        int i = 0, j = 1;
        // Let's say 1 3 4 5 6 , where k = 0
        //           i j
        while (j < nums.size())
        {
            int diff = nums[i] - nums[j];

            if (abs(diff) == k)
            {
                ans.insert(make_pair(nums[i], nums[j]));
                i++, j++;
                // count++;
            }
            else if (abs(nums[i] - nums[j]) < k)
                j++;

            else
                i++;
            if (i == j)
                j++;
        }
        return ans.size();
    }
};

// ***************************  Approach - 4 Binary Search + Set
// TC - O(logn)
// SC - O(N)

class Solution
{
public:
    int rightbs(vector<int> &nums, int start, int x)
    {
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            // agar value milgaya to use return karwao
            if (nums[mid] == x)
                return mid;

            // agar value mid is small hai to end ko peeche kar do
            if (nums[mid] > x)
                end = mid - 1;

            // agar value greater hai mid se to start ko mid +1 kar do
            else
                start = mid + 1;

            // update the mid value
            mid = start + (end - start) / 2;
        }
        return -1;
    }
    int findPairs(vector<int> &nums, int k)
    {
        //
        sort(nums.begin(), nums.end());

        // Pairs ko ander daal dega jb unka diff == k hoga jisse ki aage aane wala same pair ka count na hopae
        // Bhale unka diff == k ho jae
        // set will print unique value
        set<pair<int, int>> s;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            // agar nums[i]+k ka value aage array mai present hai to usko pair bna kr set me daal do

            if (rightbs(nums, i + 1, nums[i] + k) != -1)
            {
                s.insert(make_pair(nums[i], nums[i] + k));
            }
        }
        return s.size();
    }
};