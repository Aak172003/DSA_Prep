/*
Leetcode Link - https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution
{
public:

    /*
        ------------------- ---Approach 1 ---------------------

    Time Complexity : O(N^2), Here Two nested loop creates the time complexity.
    Where N is the size of the
    string(s).

    Space Complexity : O(N^2*N), vector(substring) space.

    Solved using string(TwoNested Loop). Brute Force Approach.

    Note : this give TLE.

    */

    bool ischeckPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<string> substring;
        for (int i = 0; i < n; i++)
        {
            string temp = "" ;
            for (int j = i; j < n; j++)
            {
                // phle saara substring nikal lenge , or usko substring naam ke vector me daal denge
                temp = temp + s[j];
                substring.push_back(temp);
            }
        }

        int maxlength = 0;
        string finalans = substring[0]; // first element ko le lenge finalans me

        int m = substring.size();
        for (int i = 1; i < m; i++)
        {
            int s = substring[i].size();

            // if palindrome hoga tb jaega check hone ke lie
            if (ischeckPalindrome(substring[i], 0, s - 1))
            {
                if (s > maxlength)
                {
                    maxlength = s;
                    finalans = substring[i];
                }
            }
        }
        return finalans;

   /*
   ------------------- ---Approach 2 - Optimise Approch  ---------------------

   Time Complexity : O(N^3), Here three nested loop creates the time complexity.
   Where N is the size of the string(s).

   Space Complexity : O(1), Constant space.

   Solved using string(Three Nested Loop). Brute Force Approach.

  */

        bool ischeckPalindrome(string & s, int start, int end)
        {
            // this suppose , if (s,0,0) - (S,b,b) here start == end means true
            while (start < end)
            {
                if (s[start] != s[end])
                {
                    return false;
                }
                start++;
                end--;
            }
            return true;
        }

        string longestPalindrome(string s)
        {

            int starting_index = 0;
            int max_length = 0;

            int n = s.size();

            for (int i = 0; i < n; i++)
            {
                // j = i because a single character itself is a palindrome
                for (int j = i; j < n; j++)
                {
                    // jaha bhi i hoga or j index hoga , agr i and j index se if palindrome exist ,
                    // then go to maximum length and starting index
                    if (ischeckPalindrome(s, i, j))
                    {
                        // store maximum length if palindrome occur
                        if (j - i + 1 > max_length)
                        {
                            max_length = j - i + 1;
                            starting_index = i;
                        }
                    }
                }
            }
            // return some sequence of character from starting to max_length index
            return s.substr(starting_index, max_length);
        }
    }
};
