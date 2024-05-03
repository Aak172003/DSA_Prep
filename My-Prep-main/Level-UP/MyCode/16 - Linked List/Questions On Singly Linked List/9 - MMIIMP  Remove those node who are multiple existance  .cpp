/*
LeetCode Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

Explaination Video - https://youtu.be/R6-PnHODewY
*/

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // create a dummy node that pointing to the original head
        ListNode *dummy = new ListNode(0);
        // connect dummy node to the original head
        dummy->next = head;

        ListNode *pre = dummy; // pointing to last node which has no duplicate
        ListNode *curr = head; // To traverse the linked list

        // traverse over node
        while (curr != NULL)
        {
            // Create a loop until the current and previous values are same, keep updating curr...
            while (curr->next != NULL && pre->next->val == curr->next->val)
            {
                curr = curr->next;
            }

            // if curr has non-duplicate value, move the pre pointer to next node
            if (pre->next == curr)
            {
                pre = pre->next;
            }

            // If curr is updated to the last duplicate value, discard it & connect pre and curr->next
            else
            {
                pre->next = curr->next;
            }
            // Move curr forward
            // In next iteration, we still need to check whether curr points to duplicate value
            curr = curr->next;
        }
        return dummy->next;
    }
};