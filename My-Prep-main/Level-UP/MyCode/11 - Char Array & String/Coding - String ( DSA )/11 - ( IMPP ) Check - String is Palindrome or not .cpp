// Codestudio link - https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5&leftPanelTab=0

/*
For Upper To Lower - ch-'A'+'a'
For Lower to Upper - ch-'a'+'A'
*/

#include <bits/stdc++.h>

// Function to convert Upper to Lower Case
char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        // Means agr wo a to z se 0 to 9 ke beech me hai , means LowerCase me hai
        return ch;
    }
    else
    {
        // Otherwise Convert krke bhejna pdega
        return ch - 'A' + 'a';
    }
}
bool isValidAlpha(string s, int index)
{
    if ((s[index] >= '0' && s[index] <= '9') || (s[index] >= 'a' && s[index] <= 'z') || (s[index] >= 'A' && s[index] <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkPalindrome(string s)
{

    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        // (s[index]>='0' && s[index]<='9') || (s[index]>='a'&& s[index]<='z') || (s[index]>='A' && s[index]<='Z')){
        // In me se kuch bhi aata hai to string avalid hai
        if (isValidAlpha(s, i))
        {
            // Jb wo valid hota hai to wo hum string me daal dete hai
            str.push_back(s[i]);
        }
    }

    // For Comparison using Two Pointer Approach

    int start = 0;
    int end = str.length() - 1;

    while (start < end)
    {
        if (toLowerCase(str[start]) != toLowerCase(str[end]))
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}