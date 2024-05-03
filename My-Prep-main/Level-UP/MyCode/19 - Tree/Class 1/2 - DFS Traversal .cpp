// #include <iostream>
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
    cout << "Enter data : " << endl;
    cin >> data;

    if (data != -1)
    {
        // Step A - > Crate RootNode

        TreeNode *root = new TreeNode(data);

        // Step B -> root->left = reccursion()
        cout << "Enter data for left part : " << data << " node " << endl;
        root->left = buildTree();

        // Step C -> root->right = reccursion()
        cout << "Enter data for rigth part : " << data << " node " << endl;
        root->right = buildTree();

        return root;
    }
    else
    {
        return NULL;
    }
}

void inOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    // Step A - > Go to Left Until root != NULL
    inOrderTraversal(root->left);

    // Step B - > Print Data
    cout << root->data << " ";

    // Step C - > Go to Right Until root != NULL
    inOrderTraversal(root->right);
}

void preOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    // Step A - > Print Data
    cout << root->data << " ";

    // Step B - > Go to Left Until root != NULL
    preOrderTraversal(root->left);

    // Step C - > Go to Right Until root != NULL
    preOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    // Step A - > Go to Left Until root != NULL
    postOrderTraversal(root->left);

    // Step B - > Go to Right Until root != NULL
    postOrderTraversal(root->right);

    // Step C - > Print Data
    cout << root->data << " ";
}

int main()
{
    cout << "Hello World" << endl;

    TreeNode *rootNode = NULL;
    rootNode = buildTree();

    cout << "RootNode -> " << rootNode << endl;

    cout << "Insertion stop " << endl;

    cout << "Printing the tree via Inorder Order Traversal " << endl;
    inOrderTraversal(rootNode);
    cout << endl;

    cout << "Printing the tree via PreOrder Order Traversal " << endl;
    preOrderTraversal(rootNode);
    cout << endl;

    cout << "Printing the tree via PostOrder Order Traversal " << endl;
    postOrderTraversal(rootNode);
    cout << endl;

    return 0;
}

// OUTPUT ->

// Enter data :
// 1
// Enter data for left part : 1 node
// Enter data :
// 2
// Enter data for left part : 2 node
// Enter data :
// 4
// Enter data for left part : 4 node
// Enter data :
// -1
// Enter data for rigth part : 4 node
// Enter data :
// -1
// Enter data for rigth part : 2 node
// Enter data :
// 5
// Enter data for left part : 5 node
// Enter data :
// -1
// Enter data for rigth part : 5 node
// Enter data :
// -1
// Enter data for rigth part : 1 node
// Enter data :
// 3
// Enter data for left part : 3 node
// Enter data :
// -1
// Enter data for rigth part : 3 node
// Enter data :
// -1
// RootNode -> 0x5e96d0
// Insertion stop
// Printing the tree via Inorder Order Traversal
// 4 2 5 1 3
// Printing the tree via PreOrder Order Traversal
// 1 2 4 5 3
// Printing the tree via PostOrder Order Traversal
// 4 5 2 3 1
