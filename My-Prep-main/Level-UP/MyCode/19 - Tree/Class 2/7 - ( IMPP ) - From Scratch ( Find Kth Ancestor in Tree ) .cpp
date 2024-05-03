
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        this->data = value;
        left = NULL;
        right = NULL;
    }
};

TreeNode *buildTree()
{
    int data;
    cout << "Enter data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    else
    {

        TreeNode *rootNode = new TreeNode(data);

        cout << "Enter left data for " << data << endl;

        rootNode->left = buildTree();

        cout << "Enter Right data for " << data << endl;

        rootNode->right = buildTree();

        return rootNode;
    }
}

// void levelOrderTraversal(TreeNode* root) {

//     cout<<"Come into Level Order levelOrderTraversal "<<endl ;
//     queue<TreeNode*>q ;
//     q.push(root) ;

//     while(!q.empty()){

//         TreeNode* temp = q.front() ;
//         q.pop() ;

//         cout<<temp->data<<" " ;

//         if(temp->left){
//             q.push(temp->left) ;
//         }
//         if(temp->right){
//             q.push(temp->right) ;
//         }
//     }
// }

// Wanted to Print in level eise
void levelOrderTraversal(TreeNode *root)
{

    cout << "Come into Level Order levelOrderTraversal " << endl;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        TreeNode *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

bool kthAncester(TreeNode *root, int &k, int p)
{
    // Base Case
    if (root == NULL)
    {
        return false;
    }

    if (root->data == p)
    {
        return true;
    }

    bool leftAns = kthAncester(root->left, k, p);
    bool rightAns = kthAncester(root->right, k, p);

    // Cjeck if left or right me ans mila ki nhi
    if (leftAns || rightAns)
    {
        k--;
    }

    if (k == 0)
    {
        cout << "Answer -> " << root->data << endl;
        k = -1;
    }

    return leftAns || rightAns;
}

int main()
{
    TreeNode *root = NULL;

    root = buildTree();
    cout << "Insertion Stop " << endl;

    cout << "RootNode is : " << root << endl;

    levelOrderTraversal(root);

    cout << endl;
    cout << "Now Finding Kth Ancestore :: " << endl;
    int k = 1;
    int p = 4;

    bool found = kthAncester(root, k, p);

    return 0;
}
