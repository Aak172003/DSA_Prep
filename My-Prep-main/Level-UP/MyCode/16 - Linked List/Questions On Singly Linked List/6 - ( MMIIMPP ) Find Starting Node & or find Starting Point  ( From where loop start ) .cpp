/*
LeetCode Link - https://leetcode.com/problems/linked-list-cycle-ii/description/

*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // if head empty hai , so return NULL
        if (head == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        // Fast point to values / data of node not the Address

        while (fast != NULL && fast->next != NULL)
        {
            // hum fast ko check krenge ki wo null hai ki nhi ,
            // agr nhi to hum ek brr fast bdha dete hai
            fast = fast->next;

            // then for next fast check , if prenet move fast by one and and slow by one
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            // We Found Duplicate Element , so point slow to head
            if (slow == fast)
            {
                slow = head;
                break;
            }
        }

        // If any one of 0
        if (!(fast && fast->next))
            return NULL;

        // Jb tk both not meet tb tk no return slow
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Means return starting node , from where loop start
        return slow;
    }
};