

// LeetCode - https://leetcode.com/problems/path-sum-ii/description/

class Solution
{
public:
    void CallForPath(TreeNode *root, int tSum, int cSum, vector<int> ans, vector<vector<int>> &result)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            cSum = cSum + root->val;
            if (cSum == tSum)
            {
                ans.push_back(root->val);

                result.push_back(ans);
            }
        }

        ans.push_back(root->val);

        CallForPath(root->left, tSum, cSum + root->val, ans, result);
        CallForPath(root->right, tSum, cSum + root->val, ans, result);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<vector<int>> result;
        vector<int> ans;

        int currSum = 0;
        CallForPath(root, targetSum, currSum, ans, result);

        return result;
    }
};

//                                       Through Backtracking

// void checkAvail(TreeNode *root, int targetSum, int currSum, vector<vector<int>> &result, vector<int> &ans)
// {
//     if (root == NULL)
//         return;

//     if (root->left == NULL && root->right == NULL)
//     {
//         // Last value ke lie
//         ans.push_back(root->val);
//         currSum += root->val;
//         if (currSum == targetSum)
//         {
//             result.push_back(ans);
//         }

//         // Last me pop or subtract krdena
//         ans.pop_back();
//         currSum -= root->val;
//         return;
//     }

//     // Include currNpode
//     ans.push_back(root->val);
//     currSum += root->val;

//     checkAvail(root->left, targetSum, currSum, result, ans);
//     checkAvail(root->right, targetSum, currSum, result, ans);

//     // Backtrack
//     ans.pop_back();
//     currSum = currSum - root->val;
// }
