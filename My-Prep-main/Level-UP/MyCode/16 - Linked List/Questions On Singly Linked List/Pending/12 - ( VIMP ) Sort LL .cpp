/*

Sort the LinkedList
Here uses two concept ,
1 - break the ll in two parts
2 - then add both two sorted linkedlist


LeetCode Link - https://leetcode.com/problems/sort-list/description/

For Sort  - https://www.youtube.com/watch?v=PHxHAjQ7974

For Merge two Linked list - https://www.youtube.com/watch?v=hKefY1ybgyw

*/

// Approach - 1 we can use insertion sort as well which take (N^2) Time Complexity
// But we apply Merge sort for sorting the linked list , which takes (NLOGN) Time Complexity

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        // if only one element
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *middle = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        // middle of linked list
        while (fast != NULL && fast->next != NULL)
        {
            middle = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // this beak the line
        middle->next = NULL;

        ListNode *list1 = sortList(head);
        ListNode *list2 = sortList(slow);

        return mergeList(list1, list2);
    }

    //  **************************** MergeList code ************************

    ListNode *mergeList(ListNode *head1, ListNode *head2)
    {
        // where fh is FinalHeda or ft is FinalTail

        ListNode *fh = NULL, *ft = NULL;
        // jb upr se dono linkedlist ka head na mila ho maeans ,
        // hume upr se do head aana hi chaiye

        while (head1 != NULL && head2 != NULL)
        {
            // tb jb merging ke time pr loi ll na ho
            if (fh == NULL && ft == NULL)
            {

                // if head1 ki value is choti than head2 , then fh me head1 daalne ka
                if (head1->val > head2->val)
                {
                    // FinalHead is Fixed , But finalTail is not fixed
                    fh = head2;
                    ft = head2;
                    // then move head2 pointer
                    head2 = head2->next;
                }
                else
                {
                    fh = head1;
                    ft = head1;
                    // then move head1 pointer
                    head1 = head1->next;
                }
            }
            // if ab fh me kuch hai , not empty
            else
            {
                if (head1->val < head2->val)
                {
                    ft->next = head1;
                    ft = ft->next;
                    // then move head1 pointer
                    head1 = head1->next;
                }
                else
                {
                    ft->next = head2;
                    ft = ft->next;
                    // then move head2 pointer
                    head2 = head2->next;
                }
            }
        }
        // if head1 or head2 koi bhi null pr pauch gya ho to jo nhi pauch ausko simply daalte jaenge
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
};