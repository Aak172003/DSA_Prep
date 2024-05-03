/*
Leetcode Link - https://leetcode.com/problems/middle-of-the-linked-list/description/
*/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {

        // Approach - 1 ( Using Slow & Fast Pointer )
        /*

        Time Complexity: O(N)
        Space Complexity: O(1)
        */

        // Edge Cases
        if (head == NULL)
        {
            cout << "LL is empty" << endl;
            return head;
        }
        if (head->next == NULL)
        {
            // only 1 node in LL
            return head;
        }

        ListNode *slow = head, *fast = head;

        // jbtk slow & fast pointer null tk nhi pauchte
        while (slow != NULL && fast != NULL)
        {
            // ek brr hum fast bdhaenge
            fast = fast->next;

            // agr fast ka next null nhi hai to to hum fast ko ek brr or slow ko ek brr
            // kyuki 2 br fast pr ek slow move krta hai , otherwise slow return

            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        //                                               OR

        // agr fast null na ho or fast ka next bhi null na ho tbhi
        // Hum slow ko ek br or fast ko do brr

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;

        /************************************************************************************/

        // Approach - 2 to solve in 2 Pass
        /*

        Time Complexity: O(N)+O(N/2) = O(N)
        Space Complexity: O(1)

        First for counting length ,
        Second for going at middle position
        */

        ListNode *temp = head;

        int length = 0;
        // Traversing temp till the end of linked list to find length #O(n)

        while (temp)
        {
            length++;
            temp = temp->next;
        }
        int middle = length / 2;

        temp = head; // for Traversing

        // traversing temp node back to middle node #O(n/2)
        while (temp && middle--)
        {
            temp = temp->next;
        }
        return temp;
    }
};
