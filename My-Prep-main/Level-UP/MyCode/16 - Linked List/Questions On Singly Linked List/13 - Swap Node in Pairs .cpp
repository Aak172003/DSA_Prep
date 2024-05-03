
// LeetCode : https://leetcode.com/problems/swap-nodes-in-pairs/

// YTube Link - https://www.youtube.com/watch?v=b8_ZINq9yhA

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *curr = head;

        while (curr && curr->next)
        {
            swap(curr->val, curr->next->val);
            curr = curr->next->next;
        }

        return head;
    }
};