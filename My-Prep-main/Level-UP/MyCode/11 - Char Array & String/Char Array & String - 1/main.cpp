#include <iostream>
#include <string.h>
using namespace std;

// TC-O(n)    SC-O(1)
int getLength(char ch[])
{

    int length = 0;
    int i = 0;
    while (ch[i] != '\0')
    {
        length++;
        i++;
    }

    return length;
}

// ***************************************************************************************

// TC-O(n)    SC-O(1)
void reverse(char ch[])
{

    int i = 0;
    int n = getLength(ch);
    int j = n - 1;

    while (i < j)
    {
        swap(ch[i++], ch[j--]);
    }
}

// ***************************************************************************************

// TC-O(n)    SC-O(1)
void replaceSpaces(char ch[])
{

    int n = strlen(ch);
    for (int i = 0; i < n; i++)
    {
        if (ch[i] == ' ')
            ch[i] = '@';
    }
}

// ***************************************************************************************

// Palindrome check krne ka apne pss 2 way hai

// 1 - Way -> use Wxtra space

// TC-O(n)    SC-O(n)
bool isPalindrome(char ch[])
{

    int n = getLength(ch);

    char ch2[100];
    for (int i = 0; i < n; i++)
    {
        ch2[i] = ch[i];
    }
    ch2[n] = '\0';

    // Reverse kr dena hai , us new wale character array me
    reverse(ch2);

    for (int i = 0; i < n; i++)
    {
        if (ch[i] != ch2[i])
            return false;
    }

    return true;
}

// 2 Way ->  Two pinter Approach
// TC-O(n)    SC-O(1)
bool isPalindrome2(char ch[])
{

    int n = getLength(ch);
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (ch[i++] != ch[j--])
            return false;
    }

    return true;
}

// ***************************************************************************************

// TC-O(n)    SC-O(1)

// Lower to Upper

void toUpperCase(char ch[])
{

    int n = getLength(ch);

    for (int i = 0; i < n; i++)
    {
        if (ch[i] >= 'a' && ch[i] <= 'z')
            ch[i] = ch[i] - 'a' + 'A';
    }
}

// ***************************************************************************************

// TC-O(n)    SC-O(1)

// Upper to Lower
void toLowerCase(char ch[])
{

    int n = getLength(ch);

    for (int i = 0; i < n; i++)
    {
        if (ch[i] >= 'A' && ch[i] <= 'Z')
            ch[i] = ch[i] - 'A' + 'a';
    }
}

// ***************************************************************************************

// TC-O(n)    SC-O(1)
bool compare(string str1, string str2)
{
    // if dono string ka size hi same nhi hua to , hai false return krdenge
    if (str1.length() != str2.length())
        return false;

    int n = str1.length();
    for (int i = 0; i < n; i++)
    {
        if (str1[i] != str2[i])
            return false;
    }

    return true;
}

// ***************************************************************************************

int main()
{

    // pallindrome

    // convert to uppercase

    // implement compare 2 strings

    return 0;
}
