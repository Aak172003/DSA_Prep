
// Leet Code - https://leetcode.com/problems/path-sum/

class Solution
{
public:
    bool checkIsEqual(TreeNode *root, int targetSum, int currSum)
    {

        // Left node ka left and right null node ke lie
        if (root == NULL)
            return false;

        // Base Case
        if (root->left == NULL && root->right == NULL)
        {
            currSum = currSum + root->val;
            if (currSum == targetSum)
                return true;
            else
            {
                return false;
            }
        }

        // Left Call
        bool leftAns = checkIsEqual(root->left, targetSum, currSum + root->val);

        // Right Call
        bool rightAns = checkIsEqual(root->right, targetSum, currSum + root->val);

        cout << "left for " << root->val << " left -> " << leftAns << " Right for " << root->val << " right -> " << rightAns << endl;
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {

        if (root == NULL)
            return false;
        int currSum = 0;

        bool ans = checkIsEqual(root, targetSum, currSum);

        return ans;
    }
};