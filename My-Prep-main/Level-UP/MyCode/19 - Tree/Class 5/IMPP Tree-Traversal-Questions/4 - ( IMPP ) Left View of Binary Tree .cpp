// GFG - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

//                      Approach - 1 ( Reccursion )

void leftTraversal(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    level = level + 1;
    if (root->left)
    {
        leftTraversal(root->left, level, ans);
    }

    if (root->right)
    {
        leftTraversal(root->right, level, ans);
    }
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    int level = 0;

    leftTraversal(root, level, ans);

    return ans;
}

//                              Approach - 2 ( Level Order Traversal )

// Here i use Level Order Traversal , For Left View of Binary Tree

queue<Node *> q;
vector<int> ans;

if (root == NULL)
    return ans;
q.push(root);

while (!q.empty())
{
    // Calculate size of q but initially q=1 for root node
    int n = q.size();
    // Then we push_back the front value

    ans.push_back(q.front()->data);

    /* for second level se size becomes 2 , loop start from 0 */
    for (int i = 0; i < n; i++)
    {
        /*
          0 wale iteration me us first value ko
          q se front me daal kr usko pop krlenge , ans usko ans
          wale vector  me to hum size nikalte hii
           uski front value ko ans me daal denge */
        Node *temp = q.front();
        q.pop();
        // Suppose temp me front value daala , the if uska left exist so
        // , we push the left value into q
        if (temp->left)
            q.push(temp->left);
        // Suppose temp me front value daala , the if uska right exist
        // so, we push the right value into q
        if (temp->right)
            q.push(temp->right);
    }
}
return ans;
