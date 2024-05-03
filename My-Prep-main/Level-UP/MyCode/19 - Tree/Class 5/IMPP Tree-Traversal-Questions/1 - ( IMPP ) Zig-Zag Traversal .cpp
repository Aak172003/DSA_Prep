

// Gfg - https : // www.geeksforgeeks.org/problems/zigzag-tree-traversal/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        // Initial me level = 1
        int level = 1;

        // This is used to store all elements in level wise
        vector<int> ans;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> vec;

            int sz = q.size();

            while (sz > 0)
            {
                Node *temp = q.front();

                q.pop();

                vec.push_back(temp->data);

                // If Left child exist , then push into queue
                if (temp->left)
                {
                    q.push(temp->left);
                }

                // If Right child exist , then push into queue
                if (temp->right)
                {
                    q.push(temp->right);
                }

                sz--;
            }

            // If found level is Even , then reverse the value in temp vector

            if (level % 2 == 0)
            {
                reverse(vec.begin(), vec.end());
            }

            // After reversing , the values in temp vector , if level is even
            // Store elements one by one into ans
            for (auto it : vec)
            {
                ans.push_back(it);
            }

            level++;
        }

        return ans;
    }
};

// LeetCode -  https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        int level = 1;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> ans;

            int sz = q.size();

            while (sz > 0)
            {
                TreeNode *temp = q.front();
                q.pop();

                ans.push_back(temp->val);

                // If Left child exist , then push into queue
                if (temp->left)
                {
                    q.push(temp->left);
                }

                // If Right child exist , then push into queue
                if (temp->right)
                {
                    q.push(temp->right);
                }

                sz--;
            }

            // If found level is Even , then reverse the value in temp vector

            if (level % 2 == 0)
            {
                reverse(ans.begin(), ans.end());
            }

            // After reversing , the values in temp vector , if level is even
            // Store elements one by one into ans
            res.push_back(ans);

            level++;
        }
        return res;
    }
};
