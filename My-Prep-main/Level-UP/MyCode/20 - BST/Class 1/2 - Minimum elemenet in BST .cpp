
// Gfg - https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

void getMinElement(Node *root, Node *&fvalue)
{
    if (root == NULL)
        return;

    // if fvalue-> data > root->data ke so fvalue me i put rrot ka data
    if (fvalue->data > root->data)
    {
        fvalue->data = root->data;
    }

    getMinElement(root->left, fvalue);
}

int minValue(Node *root)
{

    if (root == NULL)
    {
        // Handle the case when the tree is empty
        return -1;
    }

    if (root->left == NULL)
        return root->data;

    Node *fvalue = root;

    getMinElement(root, fvalue);

    return fvalue->data;
}