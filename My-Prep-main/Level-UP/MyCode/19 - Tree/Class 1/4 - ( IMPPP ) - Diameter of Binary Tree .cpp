

// LeetCode - https://leetcode.com/problems/diameter-of-binary-tree/

// Option 1 is -> left of root may be diameter
// Option 2 is -> right of root may be diameter

// Option 3 is -> leftDiam + rightDiam ( But here no need to + 1 )

class Solution
{
public:
    // For Calculation Height
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftheight = height(root->left);

        int rightheight = height(root->right);

        int maxheight = max(leftheight, rightheight) + 1;
        return maxheight;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        // left ka diameter find , excluding root
        int leftDiamOP1 = diameterOfBinaryTree(root->left);

        // right ka diameter find , excluding root
        int rightDiamOP2 = diameterOfBinaryTree(root->right);

        // if root exist so root-> leftHeight + rightHeight ( Including Root s)
        int maxDiamOP3 = height(root->left) + height(root->right);

        // return maximum of all three Options
        int result = max(max(leftDiamOP1, rightDiamOP2), maxDiamOP3);

        return result;
    }
};