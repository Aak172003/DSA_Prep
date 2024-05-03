

//                                      My Notes 

/*
GFG Link - https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
*/


#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string str = "zarcaazrd";
    int freq[26] = {0};
    queue<char> q;

    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // Increment frequenc
        freq[ch - 'a']++;
        // q.push
        q.push(ch);

        // Agr q empty nhi hota to hum ander jaate
        while (!q.empty())
        {
            // jb kisi char ka count > 1 ,
            //  hoga tabhi hum # wala sochenge

            if (freq[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            // otherwise front ke element ka count = 1,
            //  means simply push krte chalenge
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        // Agr maan lo aaa dia hai tring me , so sb pop hojaenge ,
        // so last me mai # daal deunga
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    cout << "The final ans is :" << ans << endl;

    return 0;
}
