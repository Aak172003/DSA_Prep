/*
LeetCode Link - https://leetcode.com/problems/reverse-vowels-of-a-string/description/
*/


class Solution
{
public:
    // Method 1 -> to define condition
    bool isVowel(char ch)
    {
        // yaha hum char jo aarha hai usko , lower case me convert krne ke bdd check krenge
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        // return 1;
    }

    // Method 2 -> to define condition

    // bool isVowel(char ch)
    // {
    //     // yaha hum ek ek krke saare case check krenge , upper as well as Lower case
    //     if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    //         return true;
    //     else
    //         return false;
    // }

    string reverseVowels(string s)
    {
        int low = 0;
        int high = s.length() - 1;

        while (low < high)
        {
            if (isVowel(s[low]) && isVowel(s[high]))
            {
                swap(s[low], s[high]);
                low++, high--;
            }
            if (!isVowel(s[low]))
                low++;
            else if (!isVowel(s[high]))
                high--;
        }
        return s;
    }
};

/*INPUTS
LEEtcode
*/