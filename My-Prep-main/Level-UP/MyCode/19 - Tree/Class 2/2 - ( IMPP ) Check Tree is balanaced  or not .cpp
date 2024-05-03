

// LeetCode - https://leetcode.com/problems/balanced-binary-tree/description/

class Solution
{
public:
    int height(TreeNode *root)
    {

        if (root == NULL)
            return 0;
        else
        {
            int leftheight = height(root->left);
            int rightheight = height(root->right);

            int maxheight = max(leftheight, rightheight) + 1;
            return maxheight;
        }
    }

    // void inorderTraversal(TreeNode *root, bool &ans)
    // {
    //     // if root not null
    //     if (root != NULL)
    //     {
    //         // Goes on left
    //         inorderTraversal(root->left, ans);

    //         // Here we get one by one element , that is root ,
    //         // so for particualr element ak hum leftheight , rightheight dono ko nikal kr

    //         // last node pr pauch gye
    //         int lh = height(root->left);
    //         int rh = height(root->right);

    //         // if dono ke sub se > 1 aaya so hum ans me
    //         // if dono me diff > 1 nhi hota means for that particular element ke lie , so go for next element
    //         if (abs(lh - rh) > 1)
    //         {
    //             ans = ans & false;
    //         }

    //         // Goes on Right
    //         inorderTraversal(root->right, ans);
    //     }
    // }

    void preOrderTraversal(TreeNode *root, bool &ans)
    {

        if (root != NULL)
        {
            // Here we get one by one element , that is root ,
            // so for particualr element ak hum leftheight , rightheight dono ko nikal kr

            int lh = height(root->left);
            int rh = height(root->right);

            // if dono ke sub se > 1 aaya so hum ans me
            // if dono me diff > 1 nhi hota means for that particular element ke lie , so go for next element
            if (abs(lh - rh) > 1)
            {
                ans = ans & false;
            }

            // Goes on left
            preOrderTraversal(root->left, ans);

            // Goes on Right
            preOrderTraversal(root->right, ans);
        }
    }

    bool isBalanced(TreeNode *root)
    {

        // if root hi nhi hoga to balanced hi hai tree
        if (root == NULL)
            return true;

        bool ans = true;
        // because hume left height or right height dono nikalna hai ,
        // for each elemenet ka islea inorder traversal ka use kia hai
        preOrderTraversal(root, ans);
        return ans;
    }

    // *********************************       Approach - 2         *********************************

    // From Babbar Video

    int height(TreeNode *root)
    {
        // Brute Force Approcah
        // TC - O(N^2)

        if (root == NULL)
            return 0;
        else
        {
            int leftheight = height(root->left);
            int rightheight = height(root->right);

            int maxheight = max(leftheight, rightheight) + 1;
            return maxheight;
        }
    }

    bool isBalanced(TreeNode *root)
    {

        // if root hi nhi hoga to balanced hi hai tree
        if (root == NULL)
            return true;

        // 1st case

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int diff = abs(leftHeight - rightHeight);

        bool ans1 = (diff <= 1);

        // 1st case solve by me , rest case reccursion solve

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if (ans1 && leftAns && rightAns)
            return true;
        else
        {
            return false;
        }
    }
};