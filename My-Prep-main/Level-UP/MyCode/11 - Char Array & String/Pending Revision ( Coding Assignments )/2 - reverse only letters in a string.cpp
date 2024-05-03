/*
LeetCode Link - https://leetcode.com/problems/reverse-only-letters/


The isalpha() function in C++ checks if the given character is an alphabet or not. 
It is defined in the cctype header file.
Example - >>          // check if '7' is an alphabet
//                       int result = isalpha('7');


        int i=0;
        int j = s.length()-1;
        while(i<j)
        {
            if((isalpha(s[i]) ) && (isalpha(s[j])))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!isalpha(s[i]))
            i++;
            else
            j--;
        }
        return s;

*/

#include <iostream>
using namespace std;

// Craete My Own IsAlphabet function -> to check given element is alphabaet or not
bool isAlphabet(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    else
        return false;
}

string reverseOnlyLetters(string s)
{
    int n = s.length();
    int st = 0;
    int e = n - 1;

    while (st < e)
    {
        if (!isAlphabet(s[st]))
            st++;
        else if (!isAlphabet(s[e]))
            e--;
        else
            swap(s[st++], s[e--]);
    }

    return s;
}

int main()
{

    string s;
    getline(cin, s);
    string ans = reverseOnlyLetters(s);
    cout << ans << '\n';

    return 0;
}

/*INPUTS
a-bC-dEf-ghIj
*/