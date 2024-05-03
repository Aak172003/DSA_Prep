// GFG Link -https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        // to store ans
        vector<int> ans;

        if (root == NULL)
            return ans;

        // this is used to store Node Data and Horizontal Distance
        map<int, int> mp;

        // Queue for the Level Order Traverse

        // Traversing each node with its current Horizontal Distance by the Queue.

        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())

        {
            // temp me node data hai
            Node *temp = q.front().first;

            // hd me line store kr rha hai
            int hd = q.front().second;

            // above dono kaam ke bdd pop that node with line
            q.pop();

            // check kr rhe hai , ki jo line hume mila hai hd se ,
            // so kya map me us hd line pr phle se koi value hai ya nhi
            // if not mila so map me us hd line index pr temp node ka data daal dena hai
            if (!mp[hd])
            {
                // Horizontal distance ke according store the data
                mp[hd] = temp->data;
            }
            // agr mil gya , so now move to next node
            // if temp node ka left hai to queue me wo daal dega , with its line index
            if (temp->left)
            {
                // first push temp->left node  , and hd-1 , left me jaaenge to -krna hai current hr value se

                q.push({temp->left, hd - 1});
            }

            // after going to left , queue me push temp->next and current horizontal me +1 krna hai
            if (temp->right)
            {
                q.push({temp->right, hd + 1});
            }
        }

        // iterate over map and push it.second kyuki seconda data actual Node hai
        for (auto it : mp)

        {

            ans.push_back(it.second);
        }

        return ans;
    }
};
