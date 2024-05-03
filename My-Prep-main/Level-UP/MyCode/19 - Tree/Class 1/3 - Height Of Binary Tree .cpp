
// LeetCode - https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    cout << "Enter data " << endl;
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

int calculateHeight(TreeNode *root)
{

    if (root == NULL)
        return 0;

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    int maxHeight = 1 + max(leftHeight, rightHeight);

    return maxHeight;
}

int main()
{
    // Initial me root ko null initialise kia
    TreeNode *rootNode = NULL;
    rootNode = buildTree();

    cout << "RootNode -> " << rootNode << endl;

    cout << "Insertion stop " << endl;

    int Height = calculateHeight(rootNode);
    cout << "The Height / MaxDepth is " << Height << endl;
}

// Enter data
// 12
// Enter data for left part : 12 node
// Enter data
// 2
// Enter data for left part : 2 node
// Enter data
// -1
// Enter data for rigth part : 2 node
// Enter data
// 10
// Enter data for left part : 10 node
// Enter data
// -1
// Enter data for rigth part : 10 node
// Enter data
// -1
// Enter data for rigth part : 12 node
// Enter data
// 5
// Enter data for left part : 5 node
// Enter data
// 8
// Enter data for left part : 8 node
// Enter data
// 3
// Enter data for left part : 3 node
// Enter data
// -1
// Enter data for rigth part : 3 node
// Enter data
// -1
// Enter data for rigth part : 8 node
// Enter data
// 11
// Enter data for left part : 11 node
// Enter data
// -1
// Enter data for rigth part : 11 node
// Enter data
// -1
// Enter data for rigth part : 5 node
// Enter data
// 4
// Enter data for left part : 4 node
// Enter data
// -1
// Enter data for rigth part : 4 node
// Enter data
// -1
// RootNode -> 0x10e16d0
// Insertion stop
// The Height / MaxDepth is 4