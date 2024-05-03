
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
// Approach 1
void printLevelOrderTraversal(TreeNode *root)
{

    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    cout << "root node Inside Level Order Traversal -> " << root << endl;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        //   Step A -> store q.front() into temp
        TreeNode *temp = q.front();
        //   Step B -> q.pop() pop that element which i have store in temp
        q.pop();

        // Step C -> print data
        cout << temp->data << " ";

        //   Insert Left and right child if exist
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
        //   }
    }
}

// Enter data :
// 20
// Enter data for left part : 20 node
// Enter data :
// 30
// Enter data for left part : 30 node
// Enter data :
// 50
// Enter data for left part : 50 node
// Enter data :
// -1
// 6Enter data for rigth part : 50 node
// Enter data :
// 60
// Enter data for left part : 0 node
// Enter data :
// -1
// Enter data for rigth part : 0 node
// Enter data :
// -1
// Enter data for rigth part : 30 node
// Enter data :
// 40
// Enter data for left part : 40 node
// Enter data :
// -1
// Enter data for rigth part : 40 node
// Enter data :
// -1
// Enter data for rigth part : 20 node
// Enter data :
// 100
// Enter data for left part : 100 node
// Enter data :
// -1
// Enter data for rigth part : 100 node
// Enter data :
// -1
// RootNode -> 0x1f716d0
// Insertion stop
// Printing the tree via Level Order Traversal
// root node Inside Level Order Traversal -> 0x1f716d0
// 20 30 100 50 40 60

// *****************************************************************************************************************************

// If i want ki every Level node , should print in its own Level Only
void printLevelOrderTraversal(TreeNode *root)
{

    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    cout << "root node Inside Level Order Traversal " << root << endl;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        //   Step A -> store q.front() into temp
        TreeNode *temp = q.front();
        //   Step B -> q.pop() pop that element which i have store in temp
        q.pop();

        // Step C -> print data
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";

            //   Insert Left and right child if exist
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

// Enter data :
// 20
// Enter data for left part : 20 node
// Enter data :
// 30
// Enter data for left part : 30 node
// Enter data :
// 50
// Enter data for left part : 50 node
// Enter data :
// -1
// Enter data for rigth part : 50 node
// Enter data :
// 60
// Enter data for left part : 60 node
// Enter data :
// -1
// Enter data for rigth part : 60 node
// Enter data :
// -1
// Enter data for rigth part : 30 node
// Enter data :
// 40
// Enter data for left part : 40 node
// Enter data :
// -1
// Enter data for rigth part : 40 node
// Enter data :
// -1
// Enter data for rigth part : 20 node
// Enter data :
// 100
// Enter data for left part : 100 node
// Enter data :
// -1
// Enter data for rigth part : 100 node
// Enter data :
// -1
// RootNode -> 0x15a36d0
// Insertion stop
// Printing the tree via Level Order Traversal
// root node Inside Level Order Traversal 0x15a36d0
// 20

// 30 100

// 50 40

// 60

int main()
{

    // Initial me root ko null initialise kia
    TreeNode *rootNode = NULL;

    rootNode = buildTree();

    cout << "RootNode -> " << rootNode << endl;

    cout << "Insertion stop " << endl;

    cout << "Printing the tree via Level Order Traversal " << endl;
    printLevelOrderTraversal(rootNode);

    return 0;
}
