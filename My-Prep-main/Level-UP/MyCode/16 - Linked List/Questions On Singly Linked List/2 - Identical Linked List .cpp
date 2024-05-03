// Gfg - https://practice.geeksforgeeks.org/problems/identical-linked-lists/0

bool areIdentical(struct Node *head1, struct Node *head2)
{

    // Approach - 1 (Using Extra Space )

    // make a vector jisme ek brr ek linked list pr tarverse krke saara data vector me daal dete

    // Then next iteration on second linked list

    // Match krte jaate ki vector ke data se linked list ka data match kr rha hai ki nhi

    // or one more conditio  ki agr vector khatam hone ke bdd ,
    // bhi koi head2 address pda hota hai means same sixe ka ll nhi hai return false

    // ********************************************************************************************************************************************

    // Approch - 2
    if (head1 == NULL && head2 == NULL)
        return false;
    while (head1 != NULL && head1 != NULL)
    {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }

    // jbtk koi bhi null nhi tha , tb tk identical check hota gya ,
    // Last me ye or dhyan de dia ki agr head1 or head2 me kisi me bhi koi address pda hai ,
    // means abhi aage or node hai

    // Agr kisi me bhi ek node bhi mil jaata hai extra dono ke comparison me ,
    // so return false

    if (head1 || head2)
        return false;
    return true;
}