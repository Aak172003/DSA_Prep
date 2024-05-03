// Iterative Methdo

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;

        while (curr != NULL)
        {
            // node ko break krne se phle hum forwrd me store krna pdega jisse hamara link lost na hojaeb
            forward = curr->next;

            // step - 1
            curr->next = prev;
            // step - 2
            prev = curr;
            // step - 3
            curr = forward;
        }
        return prev;
    }
};

/*****************************************************************************/

// 1st - Reccursive solution , same using above 1st Iterative approach

void reverse(Node *&head, Node *curr, Node *prev)
{
    // if current hamara Null tk pauch gya hai
    if (cur == NULL)
    {
        // Last me jb curr null pr pauch jae to head me prev daal kr return krdenge
        head = prev;
        return prev;
    }
    // Fordward hamara curr->next element pr hoga
    Node *forward = curr->next;

    reverse(head, forward, curr)
        // curr aage forward kp point krne lg jata hai
        //  prev curr ko point krne lg jaata hai
        curr->next = prev;
}

Node *reverseLinkedList(Node *head)
{
    // Initialise Two poiner curr, head
    Node *curr = head;
    Node *prev = Null;

    // Jb reverse ko call krenge , tb curr->next = prev , daal denge
    // or jb phr se reverse call krenge , to calling me updated , pointer bhejenge

    // Like : curr = forward
    //        prev = curr
    reverse(head, curr, prev) return head;
}
