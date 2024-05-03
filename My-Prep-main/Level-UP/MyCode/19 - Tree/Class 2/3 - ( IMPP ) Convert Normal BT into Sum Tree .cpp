/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree

    int fSum(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftRightData = fSum(root->left) + fSum(root->right);
        // root->data = ;

        // here return root->data + rdata
        // ( becausein leaf node pr rdata is 0 , so here i need to send root->data alsso )

        int sumData = root->data + leftRightData;
        return sumData;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        if (node == NULL)
            return;

        int leftChild = fSum(node->left);
        int rightChild = fSum(node->right);

        // If leaf node , pr hota hai , so niche se 0 + 0 aaega , so us 0 ko node->data me store krwa denge
        node->data = leftChild + rightChild;

        // First root node ke lie ,
        // ke lie code kia , then reccursion samhal lega
        if (node->left)
        {
            toSumTree(node->left);
        }
        if (node->right)
        {
            toSumTree(node->right);
        }
    }
};