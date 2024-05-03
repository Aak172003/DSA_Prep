
// GFG : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

class Solution
{
public:
    int getlength(struct Node *head)

    // function decleariation me * hume Node ke sth likhna pdta hai
    //  baaki nice koi pointer type ka variable declare krenge to , hume * us vaiable ke sth lgana pdega

    {
        int length = 0;
        struct Node *temp = head;
        while (temp->next != NULL) // while(temp!=NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }

    // Iska data Type Node*  because ye hume node return krega
    struct Node *reverse(Node *head)
    {
        //  Iteratively Reverse

        struct Node *prev = NULL;
        struct Node *forward = NULL;
        struct Node *current = head;
        while (current != NULL)
        {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }

        return prev;
    }
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // initially me first jis LL ko point kr rha hai
        // Hum chexk kr rhe hai jis LL ka size bda hoga hum usko le lenge

        // if maan lo second ll ka size bda hogya in case first se so hum swap krdenge

        // Always take big Number
        if (getlength(first) < getlength(second))
        {
            struct Node *temp = first;
            first = second;
            second = temp;
        }

        struct Node *node1 = reverse(first);
        // For iteration
        struct Node *f1 = node1;
        struct Node *node2 = reverse(second);
        // for iteration
        struct Node *s1 = node2;

        struct Node *prev = NULL;

        int carry = 0;

        // code here
        while (f1 != NULL or s1 != NULL)
        {

            int fdata = 0, sdata = 0;

            // initially hum fadat , sdata =  0 kr dete hai ,
            // then hum check krte hai agr f1 = null hai to 0 , agr null nhi hai to value daal denge fdata me
            if (f1 == NULL)
            {
                fdata = 0;
            }
            else
            {
                fdata = f1->data;
            }

            // initially hum fdata , sdata =  0 kr dete hai ,
            // then hum check krte hai agr s1 = null hai to 0 , agr null nhi hai to value daal denge sdata me
            if (s1 == NULL)
            {
                sdata = 0;
            }
            else
            {
                sdata = s1->data;
            }

            int sum = fdata + sdata + carry;

            carry = sum / 10;

            f1->data = sum % 10;
            // prev aage
            prev = f1;

            // f1 or aage
            f1 = f1->next;

            // IF corresponding LL is not empty wo bhi age shift
            if (s1 != NULL)
            {
                s1 = s1->next;
            }
        }
        // Add new if Carry is extra

        if (carry)
        {
            struct Node *newnode = new Node(carry);
            prev->next = newnode;
        }

        Node *Afterall = reverse(node1);

        return Afterall;
    }
};