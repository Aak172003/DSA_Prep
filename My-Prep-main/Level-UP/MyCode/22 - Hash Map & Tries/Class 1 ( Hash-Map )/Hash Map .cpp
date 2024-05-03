
#include <iostream>

using namespace std;
#include <unordered_map>

int main()
{
    // cout<<"Hello World";
    unordered_map<string, int> mpp;

    // Method 1 for Insertion
    pair<string, int> p1 = make_pair("Aakash", 1);
    mpp.insert(p1);

    // Method 2 for Insertion
    pair<string, int> p2("Amana", 2);
    mpp.insert(p2);

    // Method 3 for Insertion
    mpp["Mummy"] = 3;

    // Method 1 for print value
    cout << mpp.at("Aakash") << endl;
    cout << mpp.at("Amana") << endl;
    cout << mpp.at("Mummy") << endl;

    // Method 2 for print value

    cout << mpp["Aakash"] << endl;

    // Search

    // If exist return 1 , otherwise 0
    cout << "Count value " << mpp.count("Aakash") << endl;

    // 2nd Method to find any value

    if (mpp.find("Aakash") != mpp.end())
    {
        cout << "Element Found" << endl;
    }
    else
    {
        cout << "Element Not found" << endl;
    }

    // Print size of map
    cout << "size is : " << mpp.size() << endl;

    cout << mpp["Papa"] << endl;

    cout << "size is : " << mpp.size() << endl;

    // Method 3 Printing value in loop

    for (auto it : mpp)
    {
        cout << "key -> " << it.first << " value -> " << it.second << endl;
    }

    return 0;
}
