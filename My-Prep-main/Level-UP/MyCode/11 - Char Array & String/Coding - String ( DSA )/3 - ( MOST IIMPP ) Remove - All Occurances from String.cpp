/*
Leetcode Link - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
*/

/*
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"

Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".

Now s has no occurrences of "abc".
*/

/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.
*/

//                                               Approach - 1  Iterative
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        // phle hum pos me wo index le lenge jaha se common / matching start ho rha hai
        int pos = s.find(part);

        // if pos == string::npos ke barabr means , means koi common wala mila hi nhi hai
        while (pos != string::npos)
        {
            // if pos != string::npos mean common milna start hogya , so hume erase krna pdega
            //  from s.find(part) to part.length tk ,
            // uske bdd phr se pos me index daal lenge ki aage or bhi kahi match kr rha hai kya

            s.erase(pos, part.length());
            pos = s.find(part);

            // ye hum tk rokenge jb tk pos !=string::npos
            // kyuki agr mil gya to string::npos ke barabr nhi rhega
        }
        return s;
    }

    //                                               Approach - 2  Reccursive

    void removeOcc(string &s, string &part)
    {
        int position = s.find(part);
        if (position != string::npos)
        {
            string leftPart = s.substr(0, position);
            string rightPart = s.substr(position + part.size(), s.size());

            s = leftPart + rightPart;

            removeOcc(s, part);
        }
        else
        {
            return;
        }
    }
    string removeOccurrences(string s, string part)
    {
        removeOcc(s, part);
        return s;
    }
};
