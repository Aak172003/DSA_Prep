#include <iostream>
using namespace std;

bool checkPalindrome(string &str, int size, int startInd, int lastInd)
{
    if (startInd > lastInd)
    {
        return true;
    }

    // check single conditon
    // If character of startInd and lastInd are not same return false
    if (str[startInd] != str[lastInd])
    {
        return false;
    }
    checkPalindrome(str, size, startInd + 1, lastInd - 1);
}

int main()
{
    string str = "booba";
    int size = 5;
    int startInd = 0;
    int lastInd = size - 1;

    bool decision = checkPalindrome(str, size, startInd, lastInd);
    if (decision)
    {
        cout << "palindrome " << endl;
    }
    else
    {
        cout << "Not Palindrome " << endl;
    }
    return 0;
}