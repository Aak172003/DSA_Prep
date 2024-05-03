/*
Leetcode Link - https://leetcode.com/problems/valid-anagram/description/
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t)
{
    //                                             Approach - 1 >>> Sorting Method

    if (s.length() != t.length())
        return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t)
        return true;
    else
        return false;

    // Check in iterative way

    // int i=0,j=0;
    // while(i<s.length() && j<t.length())
    // {

    //     if(s[i]==t[j])
    //     {
    //         i++,j++;
    //     }
    //     else
    //     return false;
    // }
    // return true;

    //                                               Approach - 2 >>> Counting Method
    //                                               here using 2 Frequenciezs Array

    int n = s.length();
    int m = t.length();

    if (n != m)
        return false;

    // use 2 frequencies table
    int s_array[256] = {0};
    int t_array[256] = {0};

    for (int i = 0; i < m; i++)
    {
        s_array[s[i]]++;
        t_array[t[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (s_array[i] != t_array[i])
            return false;
    }
    return true;

    //                                                Approach - 2 >>> Counting Method
    //                                                here using 1 Frequenciezs Array

    int n = s.length();
    int m = t.length();

    int freq[256] = {0};
    // ek frequency table me uski occurance kitni brr hai update krna hai ,
    // phr bdd me 2nd array ke sth traverse krke uski occurance no ko delete krna hai
    // if frequency array is 0 in all index , return true
    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
    }

    // Frequency array create hone ke bdd hum, t wale string me iterate krenge'
    // same value pdte hi freq array me se uska count km krte chalenge
    for (int i = 0; i < n; i++)
    {
        freq[t[i]]--;
    }

    // ek br freq me iterate krenge saare operation hone ke bdd
    // agr poore frequency array me 0 nhi milta to return false ,
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

int main()
{

    string s;
    getline(cin, s);
    // string input lene ka , input me space , tab , or ko kbhi ignore nhi krega

    string t;
    getline(cin, t);
    // string input lene ka , input me space , tab , or ko kbhi ignore nhi krega

    isAnagram(s, t);
    return 0;
}
