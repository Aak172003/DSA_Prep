/* 
GFG Link - https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

For Merge two Linked list - https://www.youtube.com/watch?v=hKefY1ybgyw

*/

// Function to merge two sorted linked list.
Node *sortedMerge(Node *head1, Node *head2)
{
    // code here
    Node *fh = NULL, *ft = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        // tb jb merging ke time pr loi ll na ho
        if (fh == NULL && ft == NULL)
        {
            if (head1->data > head2->data)
            {
                fh = head2;
                ft = head2;
                head2 = head2->next;
            }
            else
            {
                fh = head1;
                ft = head1;
                head1 = head1->next;
            }
        }
        else
        {
            if (head1->data < head2->data)
            {
                ft->next = head1;
                ft = ft->next;
                head1 = head1->next;
            }
            else
            {
                ft->next = head2;
                ft = ft->next;
                head2 = head2->next;
            }
        }
    }
    if (head1 != NULL)
    {
        ft->next = head1;
    }
    if (head2 != NULL)
    {
        ft->next = head2;
    }

    return fh;
}