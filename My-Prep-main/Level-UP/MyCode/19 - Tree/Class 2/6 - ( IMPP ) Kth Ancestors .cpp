

// GFG - https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// Return Node  Approach - 1

bool find(Node *root, int &k, int node, int &ans)
{
    if (root == NULL)
        return false;

    if (root->data == node)
    {
        return true;
    }

    bool l = find(root->left, k, node, ans);
    bool r = find(root->right, k, node, ans);

    // 1 ke lie , 2 se true aaega , but 2 ke lie 4 & 5 ki help se check krlenge

    // If kahi bhi mil jaata hai , k-- krdena hai

    if (l || r)
    {
        k--;
    }

    if (k == 0 && ans == -1)
    {
        ans = root->data;
    }

    return l || r;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;

    find(root, k, node, ans);

    return ans;
}

// Return Node  Approach - 2

Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
        return root;

    Node *leftans = solve(root->left, k, node);
    Node *rightans = solve(root->right, k, node);

    //  Lets say left me value mili ho
    if (leftans != NULL && rightans == NULL)
    {

        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }

        return leftans;
    }
    if (leftans == NULL && rightans != NULL)
    {

        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }

        return rightans;
    }

    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    // Lets say and me NUll pda hai , so us null node ka data kaisa hoskta hai
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}
