/*
Leetcode Link - https://leetcode.com/problems/palindrome-linked-list/description/

*/

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        // Approach - 2 Copy the Linked List data into array or string

        // this will take TC - O(N) -> for traverse to copy in string
        //                SC - O(N) -> string to stor ll value

        string datastring;

        while (head != NULL)
        {
            datastring = datastring + head->val;
            head = head->next;
        }
        // Store S string to new string
        string newstring = datastring;

        reverse(newstring.begin(), newstring.end());
        if (datastring == newstring)
            return true;
        else
            false;
    }
};

// Approach - 3
// this will take TC - O(N) -> for traverse to copy in string
//                SC - O(1) -> NO use any extra space

// StepA: find the middle node;
// slow pointer is pointing to the middle node

// Step B: reverse LL after middle/slow node
// Step C: start comparison with both half node

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool checkPalindrome(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return true;
    }
    if (head->next == NULL)
    {
        // only 1 node
        return true;
    }

    // >1 node in LL

    // StepA: find the middle node;
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    // slow pointer is pointing to the middle node

    // Step B: reverse LL after middle/slow node
    Node *reverseLLKaHead = reverse(slow->next);
    // join the reversed LL into the left part
    slow->next = reverseLLKaHead;

    // Step C: start comparison
    Node *temp1 = head;
    Node *temp2 = reverseLLKaHead;

    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            // not a palindome
            return false;
        }
        else
        {
            // if data is equal, then aage badh jao
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}