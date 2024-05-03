#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int searchInString(string s, int n, int i, char key)
{
    // int searchInString(string &s, int &n, int i, char &key){     // will also work but have less TC and SC
    if (i == n)
        // if(s[i]=='\0')       // will also work
        return -1;

    if (s[i] == key)
        return i;
    else
        // i+1 br br next index pr pauchaega
        return searchInString(s, n, i + 1, key);
}

int main()
{
    /// search in string
    string str = "lovebabbar";
    int n = str.length();
    char key = 'a';
    int i = 0;
    int ans = searchInString(str, n, i, key);
    cout << ans << '\n';

    return 0;
}