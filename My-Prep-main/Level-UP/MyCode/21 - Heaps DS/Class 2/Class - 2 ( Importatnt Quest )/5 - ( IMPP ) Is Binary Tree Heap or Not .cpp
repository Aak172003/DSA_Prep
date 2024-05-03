// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution
{
public:
    //   Count No of nodes
    int CountNodes(Node *root)
    {

        // if root not given , give 0 length tree
        if (root == NULL)
            return 0;

        //
        int noOfNodes = 1 + CountNodes(root->left) + CountNodes(root->right);
        return noOfNodes;
    }

    bool isCBT(Node *root, int index, int cntNodes)
    {
        if (root == NULL)
            return true;

        if (index >= cntNodes)
            return false;
        else
        {

            // 0 based Indexing
            bool left = isCBT(root->left, 2 * index + 1, cntNodes);
            bool right = isCBT(root->right, 2 * index + 2, cntNodes);

            return (left && right);
        }
    }

    bool isMaxHeap(Node *root)
    {

        // if node is leaf node
        if (root->left == NULL && root->right == NULL)
            return true;

        // only one child exist ,
        // This is Complete Binary tree , that why any missing data only from right side
        if (root->right == NULL)
        {

            // Root ka data > root ke left ka data
            return (root->data > root->left->data);
        }
        else
        {

            // both child exists
            bool left = isMaxHeap(root->left);
            bool right = isMaxHeap(root->right);

            return ((root->data > root->left->data && root->data > root->right->data) && (left && right));
        }
    }

    bool isHeap(struct Node *root)
    {

        // If root is not given , then return true
        if (root == NULL)
            return true;

        // 0 Based indexing
        int index = 0;

        // Count total no of node
        int countNodes = CountNodes(root);

        // cout<<"Size of "<<countNodes<<endl ;

        // First check this tree , is complete binary tree or not
        // Then check this tree is also a heap or not
        if ((isCBT(root, index, countNodes)) && (isMaxHeap(root)))
            return true;
        else
            return false;
    }
};