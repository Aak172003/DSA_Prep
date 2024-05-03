
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int findPosition(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// build tree from inorder and preorder traversal

// &preIndex This is main Thing
Node *buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{

    // base case
    if (preIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Step A:  extract value from preOrder Array
    int element = preorder[preIndex];
    preIndex++;

    // Step B: Create root node
    Node *root = new Node(element);
    // Step c: Find Find Position of that element in Inorder array
    // Get Index
    int pos = findPosition(inorder, size, element);

    // step D: root->left solve ( Same goes for Left and Left )
    root->left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos - 1);
    // Step E: root->right solve ( Same goes for Right and Right )
    root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);

    return root;
}

// Wanted to Print in level eise
void levelOrderTraversal(Node *root)
{

    cout << "Come into Level Order levelOrderTraversal " << endl;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        Node *temp = q.front();
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

int main()
{

    int inorder[] = {40, 20, 50, 10, 60, 30, 70};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70};

    int size = 7;

    // preIndex index and inorderStart and inorderEnd Index
    int preIndex = 0;

    // This inorderStart and inorderEnd will always for every array
    int inorderStart = 0;
    int inorderEnd = size - 1;

    cout << "Building Tree: " << endl;
    // This return root node
    Node *root = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);

    cout << endl;
    cout << "Printing level order traversal " << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}