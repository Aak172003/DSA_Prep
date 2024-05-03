
//                          1 - Iterative Approach -> From Left to Right me check

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    string str = "babub";
    int index = -1;
    int size = 5;
    char target = 'b';

    for (int i = 0; i < size; i++)
    {
        if (str[i] == target)
        {
            index = i;
        }
    }
    cout << " Final index " << index + 1 << endl;
    return 0;
}

//                          2 - Reccursively -> From Left to Right me check

#include <bits/stdc++.h>
using namespace std;

// Reccursive from Left to rigth
void LastOccuranceLeftToRight(string &str, char ch, int i, int &ans)
{
    if (i >= str.size())
        return;

    // Solve 1 case only

    if (str[i] == ch)
    {
        // phla index milne ke bdd bhi hum aage check krenge
        // + 1 becoz want 1 based indexing
        ans = i + 1;
    }

    // even milne ke bdd bhi or na milne ke bdd bhi hum aage check krenge hi krenge , tb tk hum right to lrft left again left jaate rhenge
    LastOccuranceLeftToRight(str, ch, i + 1, ans);
}

int main()
{
    string str = "abcddefg";
    char ch;
    cout << "Enter key value" << endl;
    cin >> ch;
    int ans = -1;

    LastOccuranceLeftToRight(str, ch, 0, ans);
    cout << "The last Occurance of " << ch << " : " << ans << endl;

    return 0;
}

//                          3 - Reccursively -> From Right to Left me check

void LastOccuranceRightToLeft(string &str, char ch, int i, int &ans)
{
    // Iteration start from piche see
    if (i < 0)
        return;

    // Solve 1 case only
    if (str[i] == ch)
    {
        /*
        yaha mujhe phla elemnt milta hai right to left me ,
        to ye compulsory hai ki wohi last element hai ,
        so aage hume check hi nhi krna
        */
        ans = i + 1;
        return;
    }

    // Jb tk hume nhi milta , tb tk hum right to lrft left again left jaate rhenge
    LastOccuranceRightToLeft(str, ch, i - 1, ans);
}

int main()
{
    string str = "abcddefd";
    int size = str.size() - 1;
    char ch;
    cout << "Enter key value" << endl;
    cin >> ch;
    int ans = 0;

    LastOccuranceRightToLeft(str, ch, size, ans);
    cout << "The last Occurance of " << ch << " : " << ans << endl;

    return 0;
}

//                             Mehod - 4 -> strrchr() function

// If ch is found, the strrchr() function returns a pointer to the last location of ch in str, otherwise returns a null pointer.
// Example: How strrchr() function works

#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char str[] = "Hello World!";
    char ch = 'o';

    char *p = strrchr(str, ch);

    if (p)
        cout << "Last position of " << ch << " in \"" << str << "\" is " << p - str;
    else
        cout << ch << " is not present \"" << str << "\"";

    return 0;
}
