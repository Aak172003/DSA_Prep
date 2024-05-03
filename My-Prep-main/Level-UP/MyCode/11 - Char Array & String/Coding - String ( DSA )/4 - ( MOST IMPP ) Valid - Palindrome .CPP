// LeetCode Link - https://leetcode.com/problems/valid-palindrome/submissions/888312680/

// There are four categories of non alphanumeric characters which are general punctuation,
// brackets, mathematical symbol and miscellaneous characters.

// Some of the examples of general punctuation are discussed
// above like , (comma), @ (at-sign), (grave accent), * (asterisk) _ (underscore) – (hyphen), ! (exclamation mark), : (colon), ? (question mark), ; (semicolon). (full-stop, period)‘ (apostrophe) and “ (double quote mark).

// Examples of brackets include ( (open parenthesis), ) (close parenthesis) { (open brace) } (close brace) [ (open bracket) ] (close bracket) < (less than) > (greater than). Examples of mathematical symbol include %(percent) +(plus sign) =(equals) .

// For Upper To Lower - ch-'A'+'a'
// For Lower to Upper - ch-'a'+'A'

// Babbar Bhaiya Method

class Solution
{
private:
    bool valid(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            return true;
        }
        else
            return false;
    }

    char toLowerCase(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return ch;
        else
        {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    bool checkPalindrome(string a)
    {
        int start = 0;
        int end = a.length() - 1;

        while (start <= end)
        {
            if (a[start] != a[end])
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s)
    {

        // faltu character hatado
        string temp = "";

        // faaltu characters pehle hi hatado
        //  (s[index]>='0' && s[index]<='9') || (s[index]>='a'&& s[index]<='z') || (s[index]>='A' && s[index]<='Z'))

        //  In me se kuch bhi aata hai to string avalid hai

        for (int j = 0; j < s.length(); j++)
        {
            if (valid(s[j]))
            {
                temp.push_back(s[j]);
            }
        }

        // sabhi alpabets ko lower case me kardo
        for (int j = 0; j < temp.length(); j++)
        {
            temp[j] = toLowerCase(temp[j]);
        }
        // check palindrome
        return checkPalindrome(temp);
    }
};
