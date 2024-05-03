/*

LeetCode : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

*/

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {

        if (head->next == NULL)
            return NULL;

        ListNode *prev = head;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            if (slow != head)
                prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;

            // prev = prev->next;
        }

        // cout << "the data is : " << prev->val << endl;

        // if fat goes to null or fast->next == NULL , so prev->next = slow->next for delete
        prev->next = slow->next;
        // Memory release
        delete slow;

        return head;
    }
};