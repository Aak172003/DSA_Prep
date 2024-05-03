#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr)
{
    for (auto i : arr)
        cout << i << ' ';
    cout << '\n';
}

void findAllOcc(string &s, int &n, int i, char &target, vector<int> &ans)
{
    if (i == n)
        return;

    // mans jis jis indx pr , wo same hota hai , mai us index ko store kr deta huuu vector me
    // jisko ki humne by reference use kia hua hai
    if (s[i] == target)
        ans.push_back(i);

    findAllOcc(s, n, i + 1, target, ans);
}
int main()
{
    // find all occurence of key
    string str = "aakash";
    int n = str.length();
    char target = 'a';

    int i = 0;
    vector<int> ans;
    findAllOcc(str, n, i, target, ans);
    printVector(ans);

    return 0;
}
