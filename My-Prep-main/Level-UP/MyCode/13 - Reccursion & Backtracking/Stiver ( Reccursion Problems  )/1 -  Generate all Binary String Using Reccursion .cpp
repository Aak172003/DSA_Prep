/*
Link - https://practice.geeksforgeeks.org/problems/generate-all-binary-strings/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=generate-all-binary-strings
*/

// Expected Time Complexity: O(2^N) -> Here reccursion tree structure like left + right Calls
// Expected Auxiliary Space: O(N)
/*
EX - num = 2                          __ , __
                                       /    \
                                      /      \
                            [ 0 , _ ]         [1 , _ ]
                             /  \                /  \
                            /    \              /    \
                           /      \            /      \
                    [ 0 , 0 ]   [0 , 1 ]  [ 1 , 0 ]  [1 , 1 ]

*/

class Solution
{
public:
    void solve(int num, string output, int ind)
    {
        // means hr br call krne pr hum index bdha rhe hai ,
        // or tb tk bdenge , jb tk apna ind num ke size ke barabar nhi ho jata
        // kyuki num size hai ki kitni no of bits bnegi
        if (num == ind)
        {
            cout << output << " ";
            return;
        }

        // let suppose index 0 na ho , or output me agr phle kuch gya hai to check krenge
        // ki string ke last me kya hai , agr 1 hota hai to hum
        // output + 0 ka call krte hai
        
        if (ind != 0 && output[ind - 1] == '1')
        {
            solve(num, output + '0', ind + 1);
        }

        // at initiallly me string empty hoga , to ek br hum output me
        // output + 0
        // output + 1
        // ka function call kr dete hai
        else
        {
            solve(num, output + '0', ind + 1);
            solve(num, output + '1', ind + 1);
        }
    }

    void generateBinaryStrings(int num)
    {
        // Write your code
        solve(num, "", 0);
        return;
    }
};
