/*
GFG Link - https://practice.geeksforgeeks.org/problems/reverse-a-string/1

LeetCode Link - https://leetcode.com/problems/reverse-string/

*/

// Approach - 1 ( Using Reccursively )

void reversestring(string &str, int start, int end, int l)
{
    if (start >= end)
        return;

    swap(str[start], str[end]);
    reversestring(str, start + 1, end - 1, l);
}

string reverseWord(string str)
{
    // Your code here
    int start = 0, l = str.size();
    int end = l - 1;
    reversestring(str, start, end, l);

    return str;
}

// Approach - 2 ( Using Iteratively )

class Solution
{
public:
    void reverseString(vector<char> &s)
    {

        int start = 0, l = s.size();
        int end = l - 1;

        while (start <= end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
