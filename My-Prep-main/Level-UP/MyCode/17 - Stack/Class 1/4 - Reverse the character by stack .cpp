#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "Aakash";

    //   Phle hum saara string ka character usko hum stack me daal denge

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    // Then print the character from stack ,
    // Because stack reverse order me print krta hai

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}