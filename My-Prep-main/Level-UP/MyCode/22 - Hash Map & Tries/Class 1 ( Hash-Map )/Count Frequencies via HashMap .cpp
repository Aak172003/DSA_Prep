
#include <iostream>

using namespace std;
#include <unordered_map>

#include <map> // ordered Map

// char tolower_custom(char ch)
// {
//     if (ch >= 'A' && ch <= 'Z')
//     {
//         return ch + 32; // Add 32 to convert to lowercase
//     }
//     return ch; // Return unchanged if it's not an uppercase letter
// }

// char tolower_custom(char ch)
// {
//     if (ch >= 'A' && ch <= 'Z')
//     {
//         return ch + ('a' - 'A');
//     }
//     return ch;
// }

int main()
{

    unordered_map<char, int> mpp; // unordered_map

    // map<char , int>mpp;        // map
    string name = "Aakash Prajapati";

    cout << "The size is : " << name.size() << endl;

    // Convert all capital letters to lowercase
    for (int i = 0; i < name.size(); i++)
    {
        name[i] = tolower(name[i]);
    }

    // for (int i = 0; i < name.size(); i++)
    // {
    //     name[i] = tolower_custom(name[i]);
    // }

    for (auto it : name)
    {
        cout << "keys " << it << endl;
    }

    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == ' ')
            continue;
        mpp[name[i]]++;
    }

    for (auto it : mpp)
    {
        cout << "key -> " << it.first << " value -> " << it.second << endl;
    }

    // Print Frequency
    for (auto it : mpp)
    {
        cout << "Frequecy " << it.first << " of " << it.second << endl;
    }

    return 0;
}
