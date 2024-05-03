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

TreeNode *insertBST(TreeNode *root, int value)
{
    // if no root , means no one root is present , so just create new treeNode and return that root
    if (root == NULL)
    {
        // this is the first Node , we have to create node
        root = new TreeNode(value);
        return root;
    }

    // if  root , means root is present ,
    // so first check , where should i go as per my cuurent value
    if (root->data > value)
    {
        root->left = insertBST(root->left, value);
    }
    else
    {
        root->right = insertBST(root->right, value);
    }

    return root;
}

void takeInput(TreeNode *&root)
{
    int data;
    cout << "Enter data " << endl;
    cin >> data;

    while (data != -1)
    {
        root = insertBST(root, data);
        cout << "Enter data for this ->  " << data << endl;
        cout << "it should be left and right check according to its value " << endl;
        cin >> data;
    }
}

void levelOrderTraversal(TreeNode *root)
{

    if (root == NULL)
        return;

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

void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left)
    {
        inorderTraversal(root->left);
    }

    cout << root->data << " ";

    if (root->right)
    {
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    if (root->left)
    {
        preorderTraversal(root->left);
    }

    if (root->right)
    {
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left)
    {
        postorderTraversal(root->left);
    }

    if (root->right)
    {
        postorderTraversal(root->right);
    }

    cout << root->data << " ";
}

bool doSeraching(TreeNode *root, int element)
{

    if (root == NULL)
    {
        return false;
    }

    if (root->data == element)
    {
        return true;
    }

    // check for left and right tree
    if (root->data > element)
    {
        doSeraching(root->left, element);
    }
    else
    {
        doSeraching(root->right, element);
    }
}

int main()
{
    TreeNode *root = NULL;

    cout << "Enter the data for node : " << endl;
    takeInput(root);

    cout << "Level Order Traversal " << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal " << endl;
    inorderTraversal(root);

    cout << endl;

    cout << "Preorder Traversal " << endl;
    preorderTraversal(root);

    cout << endl;
    cout << "PostOrder Traversal " << endl;
    postorderTraversal(root);

    cout << " Perform Seraching operation " << endl;
    bool found = doSeraching(root, 25);

    if (found)
    {
        cout << " Element is Found in Tree" << endl;
    }
    else
    {
        cout << " Element is Found in Tree" << endl;
    }

    return 0;
}
