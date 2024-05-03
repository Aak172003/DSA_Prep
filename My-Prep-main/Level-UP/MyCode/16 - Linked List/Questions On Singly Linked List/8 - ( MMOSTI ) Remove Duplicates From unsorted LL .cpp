/*

GFG Link - https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
Ytube Link - https://www.youtube.com/watch?v=dAZJgVFHpqA&list=PLPyD8bF-abzuor0yYzO1g7v8y7u6vO-Fe&index=10

*/

/*
Approach - 1 -> Using Two For loop where 1st loop for store the value in a variable and ,
                other loop for iterate all eemets to compare

Approach - 2 -> Using HashMap / or using Unordered_Set
                Here both ds me mai data store krunga

Approach - 3 -> First Sort , Then Apply Remove duplicated from Sorted Linked List

*/

class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {

        unordered_set<int> st;
        //  Pick elements one by one , ek curr variable aage aage jaega or
        //  uske piche piche prev jo ko bdd me duplicate wale elemnts ko list se remove
        // krne ke kaam aaega

        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            // if st set me curr->data check krenge aakhri tk ,
            // agr wo nhi , milta to hum usko set me daal dete hai

            if (st.find(curr->data) != st.end())
            // agr aakhri pointer tk jaane se phle hi usko mil jata hai to,means wo duplicate hai
            {
                prev->next = prev->next->next;
                // Dynamically delete krenge , kyuki linked list dynamically create hoata hai
                delete (curr);
            }
            else
            {
                st.insert(curr->data);
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};