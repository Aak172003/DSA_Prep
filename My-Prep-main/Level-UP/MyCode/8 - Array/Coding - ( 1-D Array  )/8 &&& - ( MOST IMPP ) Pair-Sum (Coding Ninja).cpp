/*
Coding Ninja Link - https://www.codingninjas.com/codestudio/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTab=1
*/

/*
Leetcode Link - https://leetcode.com/problems/two-sum/description/

Same Question in Leetcode name as - 2 Sum
But it can be solved using Hash table , Below solution is not accacpted in leetcode
*/

// Brute Force Approach - 1

vector<vector<int>> pairSum(vector<int> &arr, int s)
{

   vector<vector<int>> ans;
   for (int i = 0; i < arr.size(); i++)
   {
      for (int j = i + 1; j < arr.size(); j++)
      {
         if (arr[i] + arr[j] == s)
         {
            vector<int> temp;

            // According to Question , minimum value phle push hoga , then maximum value
            temp.push_back(min(arr[i], arr[j]));
            temp.push_back(max(arr[i], arr[j]));
            // hume Question me and ek vector ke ander dena hai vector ke form me

            ans.push_back(temp);
         }
      }
   }
   // sort krdenge sabhi vector ko jo pair me hume Mile hai
   sort(ans.begin(), ans.end());
   return ans;
}

// ***************************************************************************************************************************************************

// Optimise Approach 2  - Using Hash Table

// My Notes ( Page )

// SC - O(N) For using Hash Map

class Solution
{
public:
   vector<int> twoSum(vector<int> &nums, int target)
   {
      vector<int> ans;
      unordered_map<int, int> mpp;
      for (int i = 0; i < nums.size(); i++)
      {
         /*
         mpp.find target-nums[i] ko find krta hai mpp me agr wo find kr leta hai to return an
         iterator of target-nums[i] value ka  if end tk jaane se phle ,
         he able to find answer
         */

         if (mpp.find(target - nums[i]) != mpp.end()) // Found
         {
            // Agr hume map me nhi milta to hum usko simply map me store kraa denge , vith uske index ke sth

            // here map me target - nums[i] nhi milta hai to hum
            // map me uski value and index ko add kr rhe hai

            //  Insert index of that two Element

            ans.push_back(i);                     // store currnet index jiski value hum substract kr rhe hai target se to find remaining value
            ans.push_back(mpp[target - nums[i]]); // this store index of that remaing element whose index is stored in hash Tabbe

            return ans;
         }
         // mpp[value] = i means mpp me wo value ke sth uski index or daal dega

         mpp[nums[i]] = i;

         // mpp[first] = second

         // Like in first iteration hash table was empty

         // target - 2 = 7 but 7 is not in hast Table
         // mpp[2] = 0;
         // |           |
         // |           |
         // | ( 2 , 0 ) |

         // Like in second iteration hash table has ( 2 , 0 )

         // target - 7 = 2 so 2 is prenet in hast Table
         // mpp[2] = 0;
         // |           |
         // |           |
         // | ( 2 , 0 ) |

         // push in vector of index 2 , 7
         // 2 - i
         // 7 - mpp[target-nums[i]]
      }
      return ans; // Retur index jb element milgya us data ka jo array me hai

      // ***************************************************************************************************************************************************

      // Optimise Approach 3  - Using Sort and Two Pointer Approach

      // TC - O(NlogN) in Best Case

      // SC - O(N) For using pair in vector

      int n = nums.size();
      int i = 0;
      int j = n - 1;

      // pair inside vector
      vector<pair<int, int>> ans;

      // Pushing value and its index on pair
      for (int i = 0; i < n; i++)
      {
         ans.push_back({nums[i], i});
      }

      // Sort the vector
      sort(ans.begin(), ans.end());

      while (i < j)
      {
         int sum = ans[i].first + ans[j].first;

         if (sum == target)
         {
            // Return Index
            return {ans[i].second, ans[j].second};
         }
         // if sum krne se bda hojaega ans , so j ko piche le aao
         else if (sum > target)
            j--;
         // if sum chota rh jaega target se, to i ko aage le jaenge else i++;
      }
      return {-1, -1};
   }
};