// LeetCode : https://leetcode.com/problems/rotate-list/description/

class Solution
{
public:
    int getLength(ListNode *head)
    {
        int length = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        int len = getLength(head);

        if (head == NULL)
            return head;

        // cout << "Get Len : " << len << endl;

        if (k == len || k % len == 0 || len == 1)
            return head;

        int j = 0, loop = k % len;
        loop = len - loop;

        ListNode *temp = head; // for traversing

        ListNode *firstNode = head; // for pointing first node who will

        while (temp != NULL)
        {
            j++;
            if (j == loop)
            {
                firstNode = temp->next;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }

        temp = firstNode;

        // After finding firstNode
        // then iterate over firstNode se last tk , and last me add Head

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = head;
        return firstNode;
    }
};