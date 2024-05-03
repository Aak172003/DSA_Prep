
// Gfg -> https://www.geeksforgeeks.org/problems/sum-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    int giveSum(Node *root)
    {
        // if node ke left me koi nhi hai so return
        if (root == NULL)
        {
            return 0;
        }

        // agr hai left me , to left sum naam ka variable bna kr , usme keft -> left jaate
        // phr last left pr pauchne ke bdd
        // node ke left me jaate rhna , end pr left me  aajaega , jb node null hojaega ,
        // then ab goes to right -> right phr last me wo bhi  de dega
        int leftSum = giveSum(root->left);
        int rightSum = giveSum(root->right);
        return (leftSum + rightSum + root->data);
    }
    bool isSumTree(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        // Leaf node ke lie , not Check
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        // humne left side ka pointer , de kr left ->left last me pauch gye
        // phr last left pr pauchne ke bdd uska right or left nikalte hai

        // Leaf node se ek above check krlenge
        bool left = isSumTree(root->left);
        bool right = isSumTree(root->right);

        int sum = giveSum(root->left) + giveSum(root->right);

        bool sumcheck = (sum == root->data); // if true means equal

        if (left && right && sumcheck)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};