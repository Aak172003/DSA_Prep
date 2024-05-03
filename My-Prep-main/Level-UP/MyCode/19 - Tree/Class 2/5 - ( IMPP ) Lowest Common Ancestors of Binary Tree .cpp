
// My Notes

// LeetCode - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// Optional Video - https://youtu.be/ViOY_QSBp1s

/*
Naive Solution

Always occur Case


1. if left and right se null milta hai , which means element present hi nhi hai
2. if left se null and right se value milta hai , so return that right value

3. if right se null and left se value , so return that left value
4. if dono !NULL hote hai , means uska root hi ans hai and , return that root

*/

class Solution
{
public:
    bool findPath(TreeNode *root, vector<TreeNode *> &path, TreeNode *p)
    {
        if (root == NULL)
            return false;

        path.push_back(root);

        if (root == p)
            return true;

        // if current root p or q ke barabar nhi hai to goes for left and right Check
        if (findPath(root->left, path, p) || findPath(root->right, path, p))
        {
            return true;
        }

        // Let's say maan lo ki left or right traversal ke dauraan bhi Apne ko vakue nhi mila
        // then jisko hum vetor me daale the pop krdenge , because wo hamara ans nhi hai
        path.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)

    {
        vector<TreeNode *> path1, path2;

        // agr dono function me se kisi ka bhi phi nhi mila so return null
        if (!findPath(root, path1, p) || !findPath(root, path2, q))
            return NULL;

        TreeNode *ans = NULL;

        for (int i = 0; i < path1.size() && i < path2.size(); i++)
        {
            if (path1[i] == path2[i])
                ans = path2[i];
        }
        return ans;
    }
};

// But Originally from babbar
// From Babbar

// Optimise Solution

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // Base Case
        if (root == NULL)
            return 0;
        // if root hi p and q hai , so return p , q
        if (root->val == p->val)
            return p;

        if (root->val == q->val)
            return q;

        // OR

        // If p and q pas as a value (int) , then return its root

        /*

        // Node* lca(Node* root ,int n1 ,int n2 )

        if (root == NULL)
            return root;
        // if root hi p and q hai , so return p , q
        if (root->data == n1)
            return root;
        if (root->data == n2)
            return root;

        */

        // if not found at root node , then goes to left and right

        // left and right find krega ja ja kr .

        // if left me jaate jaate value mil jaati hai , so return that value

        // if right me jaate jaate value mil jaati hai , so return that particular value

        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        // if left NUll and right NULL return krte hai , means value not present in tree
        if (leftAns == NULL && rightAns == NULL)
            return NULL;

        else if (leftAns == NULL && rightAns != NULL)
            return rightAns;

        else if (leftAns != NULL && rightAns == NULL)
            return leftAns;

        else
            return root;
    }
};