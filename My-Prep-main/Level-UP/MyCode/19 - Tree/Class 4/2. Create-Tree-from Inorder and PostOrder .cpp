
#include <bits/stdc++.h>

// #include <iostream>
// #include <queue>
// #include <unordered_map>
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

//                              Approach -1 Using for Loop

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

Node *buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int &postIndex, int size, int inorderStart, int inorderEnd)
{
    // base case
    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // A
    int element = postorder[postIndex];
    postIndex--;
    Node *root = new Node(element);

    int pos = findPosition(inorder, size, element);
    // int pos = mapping[element];
    // root->right solve
    root->right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, pos + 1, inorderEnd);

    // root->left solve
    root->left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, pos - 1);

    return root;
}

// //                              Approach -2 Using Hash Maping

// void createMapping(unordered_map<int, int> &mapping, int inorder[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         mapping[inorder[i]] = i;
//     }
// }

// // When i am changing any thing in mapping , so why do i send as a path by Reference
// Node *buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int &postIndex, int size, int inorderStart, int inorderEnd, unordered_map<int, int> mapping)
// {
//     // base case
//     if (postIndex < 0 || inorderStart > inorderEnd)
//         return NULL;

//     // Step A:  extract value from preOrder Array
//     int element = postorder[postIndex];
//     postIndex--;

//     // Step B: Create root node
//     Node *root = new Node(element);

//     // Step c: Find Find Position of that element in Inorder array
//     // Get Index
//     int pos = mapping[element];

//     // step D: root->right solve ( Same goes for Right and Right )
//     root->right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, pos + 1, inorderEnd, mapping);

//     // step D: root->left solve ( Same goes for Left and Left )
//     root->left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, pos - 1, mapping);

//     return root;
// }

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // initially
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // A
        Node *temp = q.front();
        // B
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
            // C
            cout << temp->data << " ";
            // D
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

    int inorder[] = {40, 20, 10, 50, 30, 60};
    int postorder[] = {40, 20, 50, 60, 30, 10};
    int size = 6;
    int postIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    // Approach 1 -> With Linear Search

    cout << "Building the tree: " << endl;
    Node *root = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, inorderEnd);

    // Approach 2 -> With Mapping

    // unordered_map<int, int> mapping;
    // createMapping(mapping, inorder, size);

    // cout << "Building the tree: " << endl;
    // Node *root = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, inorderEnd, mapping);

    cout << "Printing the postorder tree " << endl;
    levelOrderTraversal(root);
}
