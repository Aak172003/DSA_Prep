/*
LeetCode Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

YTube Link - https://youtu.be/s10gIVcz6bE
*/

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        // curr and curr ka next hai tbhi hum aage check krenge
        while (curr && curr->next)
        {
            // agr curr ka data or curr ke next ka data match ,
            // mai curr ke next me curr ke next ka next daal dunga
            if (curr->next->val == curr->val)
            {
                curr->next = curr->next->next;
            }
            // otherwise curr ko ek ek krke iterate krte rhenge
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};
