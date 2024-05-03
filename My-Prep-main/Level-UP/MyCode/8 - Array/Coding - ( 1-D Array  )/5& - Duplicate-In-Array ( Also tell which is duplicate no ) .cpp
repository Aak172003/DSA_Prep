/*
Coding Ninja Link - https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTab=1


*/

// This can also be solve by Tortoise Algorithm
// (This Tortoise Working From my Notes)

int findDuplicate(vector<int> &arr)
{
    // Write your code here
    int ans = 0;

    // Jo array me dia hai un sbka xor kia
    for (int i = 0; i < arr.size(); i++)
    {
        // array index from 0 to n-1
        ans = ans ^ arr[i];
        /*
        arr = [1 2 3 4 4]
        jb hum ans  =  ans ^ arr[i] krte hai to wo hume duplicate elements ko remove krke dega
        Like 0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 4
        so ans  = 1 ^ 2 ^ 3
        */
    }
    // Jo array me dia hai ,  unsb ko 1 to size tk ke saare eleements se XOR
    for (int i = 1; i < arr.size(); i++)
    {
        // so i value start from 1 to n-1

        ans = ans ^ i;
        /*
        ans = 1 2 3 - But when we xor with it array size
                    1 ^ 2 ^ 3
              XOR - 1 ^ 2 ^ 3 ^ 4

            yaha pr jo duplicate hoga wo mil jaega , jaise ki 4 is dupliacte here
        */
    }

    return ans;
}
