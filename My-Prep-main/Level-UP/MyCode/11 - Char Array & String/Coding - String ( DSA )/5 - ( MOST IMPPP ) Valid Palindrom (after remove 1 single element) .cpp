/*
Leetcode Link - https://leetcode.com/problems/valid-palindrome-ii/submissions/
*/

class Solution
{
public:
    // TC-O(n)    SC-O(1)
    bool checkPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            else
            {
                i++;
                j--;
            }
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            if (s[i] != s[j])
            {
                // palindrome after one removal
                /*
                EX - L E V E R A L
                     |           |
                     i           j

                Here both equal so move i++, j--

                EX - L E V E R A L
                       |       |
                       i       j

                Here both does not match , so here we have 2 options remove E or A
                so both cases ko hum lekr dekte hai or agr koi bhi treu aagya isme return true

                checkPalindrome(s, i+1, j) || checkPalindrome(s, i, j-1)

                */

                //  if reome E then check checkPalindrome(s, i+1, j)

                //  if remove A then check checkPalindrome(s, i, j-1)

                bool ans = checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
                return ans;
            }
            else
            {
                i++;
                j--;
            }
        }

        // palindrome with no removal
        return true;
    }
};