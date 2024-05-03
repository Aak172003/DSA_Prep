

// LeetCode - https : // leetcode.com/problems/delete-node-in-a-linked-list/

/*


Approach :- Just make the next element's value of node equal to node value,
and make node->next=node->next->next, which will skip the current node :)

eg. [4 -> 5 -> 1 -> 9] and node given = 5

// Steps to solve : : : : : : : : : :

Step 1 :  copy value in previous
=> [4->1->1->9]

Step 2 : By Pass the node which want to delete by (  node->next = node->next->next)
=> [4->1->9]

*/
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // jis node ko delete krna hai hum us node me just uske aage wale node ka value put krdenge
        node->val = node->next->val;

        node->next = node->next->next;
    }
};
