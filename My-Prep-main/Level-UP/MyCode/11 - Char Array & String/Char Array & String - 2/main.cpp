#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

// TC-O(n)    SC-O(n)
int findMinDifference(vector<string> timePoints)
{
    int n = timePoints.size();
    vector<int> minutes;

    // convert time (string) to minutes (int)
    for (int i = 0; i < n; i++)
    {
        string curr = timePoints[i];

        int hours = stoi(curr.substr(0, 2));
        int mins = stoi(curr.substr(3, 2));
        int totalMinutes = hours * 60 + mins;
        minutes.push_back(totalMinutes);
    }

    sort(minutes.begin(), minutes.end());

    int mini = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = minutes[i + 1] - minutes[i];
        mini = min(mini, diff);
    }

    // for ex - 00:00 and 23:59
    int lastDiff = minutes[0] + 1440 - minutes[n - 1]; // 1440 mins in 24 hours
    mini = min(mini, lastDiff);

    return mini;
}

// TC-O(n)    SC-O(1)
int expandAround(string s, int i, int j)
{
    int count = 0;
    int n = s.length();
    while (i >= 0 && j < n && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }

    return count;
}

// TC-O(n^2)    SC-O(1)
int countSubstrings(string s)
{
    int n = s.length();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // odd substrings
        int oddAns = expandAround(s, i, i);
        cnt += oddAns;

        // even substrings
        int evenAns = expandAround(s, i, i + 1);
        cnt += evenAns;
    }

    return cnt;
}

int main()
{

    // Minimum Time Difference

    int n;
    cin >> n;

    // Dynamic vector created
    vector<string> timePoints(n);

    for (int i = 0; i < n; i++)
    {
        cin >> timePoints[i];
    }

    int ans = findMinDifference(timePoints);
    cout << ans << '\n';

    // Palindromic Substrings
    string s;
    cin >> s;
    int ans = countSubstrings(s);
    cout << ans << '\n';

    return 0;
}
