

// LeetCode : https://leetcode.com/problems/same-tree/

class Solution
{
public:
    void insertIntoVector(TreeNode *node, vector<int> &ans)
    {
        queue<TreeNode *> q;
        q.push(node);

        while (!q.empty())
        {

            TreeNode *temp = q.front();
            q.pop();

            if (temp)
            {
                ans.push_back(temp->val);
                // Insert Left Node
                q.push(temp->left);
                // Insert Right Node
                q.push(temp->right);
            }
            else
            {
                ans.push_back(INT_MIN);
            }
        }
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> one, two;

        insertIntoVector(p, one);
        insertIntoVector(q, two);

        cout << "First Vector size : " << one.size() << endl;
        cout << "Second Vector size : " << two.size() << endl;

        // if (one.size() != two.size()) {
        //     return false;
        // } else {
        //     for (int i = 0; i < one.size(); i++) {
        //         if (one[i] != two[i]) {
        //             return false;
        //         }
        //     }

        //     return true;

        // Which means this check , size and elemets automatically
        if (one != two)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // Approach -2 ( With Two Inorder and PreOrder Traversal)

    /*
                             1            1
                            / \         /   \
                          1     N      N     1
                        /   \              /   \
                       N      N           N      N

                       TREE 1            TREE 2

        INORDER     N 1 N 1 N        N 1 N 1 N
        PREORDER    1 1 N N N        1 N 1 N N

        WHICH MEANS THROUGH 1 TRAVERSAL ALGO WE CAN NOT DEFOINE THIS TWO TREE ARE Identical or not
        so to solve this we use ( Inorder  + Preorder )

    */
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
        else
            v.push_back(100000);
    }

    void preorder(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            v.push_back(root->val);
            preorder(root->left, v);
            preorder(root->right, v);
        }
        else
            v.push_back(100000);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        vector<int> inp, inq;
        vector<int> prep, preq;

        // Inorder for first and second tree

        inorder(p, inp);
        inorder(q, inq);

        // PreOrder for first and second tree

        preorder(p, prep);
        preorder(q, preq);

        // if our inorder traversal of both tree are equal and if our preorder traversal of both tree are equal ,
        // then result true

        // cout << " Inp : " << endl;
        // for (auto it : inp)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
        // cout << " Inq : " << endl;
        // for (auto it : inq)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;

        // cout << " Prep : " << endl;
        // for (auto it : prep)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
        // cout << " Preq : " << endl;
        // for (auto it : preq)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;

        if (inp == inq && prep == preq)
            return true;
        else
            return false;
    }
};