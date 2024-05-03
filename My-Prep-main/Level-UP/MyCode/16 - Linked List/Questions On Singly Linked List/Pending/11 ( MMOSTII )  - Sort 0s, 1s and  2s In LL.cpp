/*
GFG Link -  https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it
*/

class Solution
{
public:

    // Approach - 1 -> Using The Counting Variable  ,

          
    Node *segregate(Node *head)
    {
        int zero = 0;
        int one = 0;
        int two = 0;

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == 0)
                zero++;
            else if (temp->data == 1)
                one++;
            else if (temp->data == 2)
                two++;
            temp = temp->next;
        }

        // step2: fill 0, 1 and 2s in the original ll
        temp = head;
        // fill zeroes
        while (zero--)
        {
            temp->data = 0;
            temp = temp->next;
        }

        // fill ones
        while (one--)
        {
            temp->data = 1;
            temp = temp->next;
        }

        // fill 2s
        while (two--)
        {
            temp->data = 2;
            temp = temp->next;
        }
        return head;
    }

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // Approach - 2 -> Withousing overwrite the value ,
    // or already exist value ko replace krna

    Node *sort2(Node *&head)
    {
        if (head == NULL)
        {
            cout << "LL is empty " << endl;
            return NULL;
        }
        if (head->next == NULL)
        {
            // sngle node in LL
            return head;
        }

        // create dummy nodes
        Node *zeroHead = new Node(-101);
        Node *zeroTail = zeroHead;

        Node *oneHead = new Node(-101);
        Node *oneTail = oneHead;

        Node *twoHead = new Node(-101);
        Node *twoTail = twoHead;

        // traverse the original LL
        Node *curr = head;
        while (curr != NULL)
        {

            if (curr->data == 0)
            {
                // take out the zero wali node
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;

                // append the zero node in zeroHead LL
                zeroTail->next = temp;
                zeroTail = temp;
            }
            else if (curr->data == 1)
            {
                // take out the one wali node
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;

                // append the zero node in zeroHead LL
                oneTail->next = temp;
                oneTail = temp;
            }
            else if (curr->data == 2)
            {
                // take out the zero wali node
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;

                // append the zero node in zeroHead LL
                twoTail->next = temp;
                twoTail = temp;
            }
        }

        // ab yha pr, zero , one, two, teeno LL readyv h

        // join them
        // remove dummmy nodes

        // modify one wali list
        //  ek new pointer name as temp
        /*
        Phle temp me dummy node aagya kyuki oneHead ek Dummy node tha
        then onehead ko ek aage bdha denge , coz i want remove Dummynode
        temp ke next ko NULL kr denge
        */
        Node *temp = oneHead;
        oneHead = oneHead->next;
        temp->next = NULL;
        delete temp;

        // modify two wali list
        //  Same for TwoHead
        /*
         Phle temp me dummy node aagya kyuki twoHead ek Dummy node tha
        then twohead ko ek aage bdha denge , coz i want remove Dummynode
        temp ke next ko NULL kr denge
        */
        temp = twoHead;
        twoHead = twoHead->next;
        temp->next = NULL;
        delete temp;

        // join list

        // If oneHead NUll hota to Twohead ko check krte zerohead se jodne ke lie otherwise
        // oneHead add hojaega , then Two head bhi check hoga is NULL or not
        // if not then add twohead at last of oneTail
        if (oneHead != NULL)
        {
            // one wali list is non empty
            // zero wali list ko one wali list se attach krdia

            // From upr se iterate krte krte wo sb last element ko point krte hai
            zeroTail->next = oneHead;

            if (twoHead != NULL)
                oneTail->next = twoHead;
        }
        else
        {
            // one wali list is empty
            if (twoHead != NULL)
                zeroTail->next = twoHead;
        }

        // remove zerohead dummy Node
        temp = zeroHead;
        zeroHead = zeroHead->next;
        temp->next = NULL;
        delete temp;

        // return head of the modified linked list
        return zeroHead;
    }
};