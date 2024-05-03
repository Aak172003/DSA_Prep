
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {

        vector<int> ans;
        if (root == NULL)
            return {};

        // Map is used to store
        // <horizontal Distance , Node value>
        map<int, int> mpp;

        // Queue for the Level Order Traverse
        // Traversing each node with its current Horizontal Distance by the Queue.

        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {

            Node *temp = q.front().first;

            // Horizontal Distance
            int hd = q.front().second;

            q.pop();

            // Update
            mpp[hd] = temp->data;

            // If left exist , go for Left
            if (temp->left)
            {
                q.push({temp->left, hd - 1});
            }
            // If Right exist , go for Right
            if (temp->right)
            {
                q.push({temp->right, hd + 1});
            }
        }

        // iterate over map and push it.second kyuki seconda data actual Node hai
        for (auto it : mpp)

        {

            ans.push_back(it.second);
        }

        return ans;
    }
};