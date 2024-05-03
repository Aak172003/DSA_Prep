
// Gfg : https: // practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/*   Algo

1.reverse the list

2.add one to the reversed list

3.reverse the reversed list

4.if carry is 1 add this in front of list

*/
class Solution
{
public:
    Node *reverse(Node *head)
    {
        //  Iteratively Reverse

        Node *prev = NULL;
        Node *forward = NULL;
        Node *current = head;
        while (current != NULL)
        {
            forward = current->next;
            current->next = prev;
            prev = current;
            // Again point to after linking current to backside
            current = forward;
        }

        return prev;
    }

    Node *addOne(Node *head)
    {
        // Reverse Function ko call krne ke bdd hume new head milega jo ki last element ko point krega
        Node *newnode = reverse(head);

        //  For traversing declare variable
        Node *current = newnode;
        Node *prev = NULL;

        // reverse ke bdd jo head bna hai after reverse ulti side se ,
        // isko islea samhal kr rkha ki dubara reverse krna hai
        Node *current1 = newnode;
        int carry = 0;

        while (current != NULL)
        {
            int sum = 0;
            // if prev ==null means we have only value,
            // jbki prev hamara current ke piche piche move krta chaalega , here prev== Null
            //  islea lia hai ki maan lo hamare pss bs ek hi element hai
            if (prev == NULL)
            {
                // sum me store krlenge add krne ke bdd
                sum = current->data + 1;
            }
            else
            {
                sum = current->data + carry;
            }

            // phle case me agr element jyada hai to uska sum hum nikalenge ,
            // usse hum carry or jo sum krna hai wo nikal lenge
            carry = sum / 10;
            current->data = sum % 10;

            // update prev or current
            prev = current;
            current = current->next;

            // Again check until current addrwss is null
        }

        if (carry == 1)
        {
            Node *newnode = new Node(1);
            prev->next = newnode;
        }

        // kyuki yahi se data , reverse krna tha
        Node *newafterAll = reverse(current1);
        return newafterAll;
    }
};