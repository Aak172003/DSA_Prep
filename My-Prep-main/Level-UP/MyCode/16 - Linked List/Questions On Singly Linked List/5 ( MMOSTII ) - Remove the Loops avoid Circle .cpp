
// Gfg : https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // if no element , or only single element
        if (head == NULL && head->next == NULL)
            // return krte time apne ko ye bhi dhyan dena pdega ki kya return kr rhe hai

            return;

        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                break;
            }
        }

        if (slow == fast)
        {
            // Slow point to head
            slow = head;

            if (slow == fast)
            {
                while (fast->next != slow)
                    fast = fast->next;
            }
            else
            {
                // jb tk aage bdhaenge , jb tk doono slow or fast meet nhi kr jaate
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            // Fast ke next me null daal dia
            fast->next = NULL;
        }
    }
};
