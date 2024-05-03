#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// ******************************************** string ******************************************************

bool charCmp(char first, char second)
{
    return first < second;
    // first will come first if first < second
    // first parameter in comparater function will act as first
}

bool charCmp2(char first, char second)
{
    return first > second;
    // first will come first if first > second      first parameter in comparater function will act as first
    // true means return first
}

// ******************************************** Vector ******************************************************

bool intCmp(int first, int second)
{
    return first < second;
}

void printVector(vector<int> arr)
{
    for (auto i : arr)
        cout << i << ' ';
    cout << '\n';
}

bool intCmp2(int first, int second)
{
    return first > second;
}

// ******************************************** Vector of String ******************************************************

void printStringVector(vector<string> arr)
{
    for (auto i : arr)
        cout << i << ' ';
    cout << '\n';
}

int stringValue(string s)
{
    int ans = 0;
    for (auto i : s)
        ans += i;
    return ans;
}

// sort with respect to sum of ascii values of chars of string
bool stringCmp(string first, string second)
{
    return stringValue(first) < stringValue(second);
}

void printStringVectorValue(vector<string> arr)
{
    for (auto i : arr)
    {
        // cout << stringValue(i) << ' ';
        cout << i << ' ';
    }
    cout << '\n';
}

bool stringCmp2(string first, string second)
{
    return first > second;
}

int main()
{

    // custom comparater in sort function in string

    // simple sort method in Ascending Order
    string one = "babbar";
    sort(one.begin(), one.end());
    cout << one << '\n';

    // greater<char>() method to sort in dexreasing Order
    string two = "babbar";
    sort(two.begin(), two.end(), greater<char>());
    cout << two << '\n';

    // Custom Camparator for Increasing Order
    string three = "edcba";
    sort(three.begin(), three.end(), charCmp);
    cout << three << '\n';

    // Custom Camparator for descending order
    string four = "abcde";
    sort(four.begin(), four.end(), charCmp2);
    cout << four << '\n';
    cout << '\n';

    // *****************************************************************************************************

    // custom comparater in sort function in vector

    // Simple Sort Function for increasing Order
    vector<int> arr{5, 3, 1, 2, 4};
    sort(arr.begin(), arr.end());
    printVector(arr);

    // Use greater<int>() for Decreasing Order
    arr = {5, 3, 1, 2, 4};
    sort(arr.begin(), arr.end(), greater<int>());
    printVector(arr);
    cout << endl;

    arr = {5, 3, 1, 2, 4};
    sort(arr.begin(), arr.end(), intCmp);
    printVector(arr);

    arr = {5, 3, 1, 2, 4};
    sort(arr.begin(), arr.end(), intCmp2);
    printVector(arr);

    // *****************************************************************************************************

    // custom comparater in sort function in vector of strings

    vector<string> arr{"abk", "acb", "bac", "bca"};

    sort(arr.begin(), arr.end());
    printStringVector(arr);

    arr = {"love", "babbar", "rahul", "sandeep"};
    sort(arr.begin(), arr.end(), greater<string>());
    printStringVector(arr);

    arr = {"love", "babbar", "rahul", "sandeep"};
    sort(arr.begin(), arr.end(), stringCmp);
    printStringVector(arr);

    printStringVectorValue(arr);

    arr = {"love", "babbar", "rahul", "sandeep"};
    sort(arr.begin(), arr.end(), stringCmp2);
    printStringVector(arr);

    return 0;
}