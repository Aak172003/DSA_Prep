

// Gfg - https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

class Solution
{
public:
    void leftTraversal(Node *root, int level, vector<int> &ans)
    {
        if (root == NULL)
            return;

        // if(ans.size == level ) -> then push value into ans , if not then i can not push node value into ans vector
        if (level == ans.size())
        {
            ans.push_back(root->data);
        }

        level = level + 1;

        if (root->right)
        {
            leftTraversal(root->right, level, ans);
        }

        if (root->left)
        {
            leftTraversal(root->left, level, ans);
        }
    }
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> ans;
        int level = 0;

        leftTraversal(root, level, ans);

        return ans;
    }
};
