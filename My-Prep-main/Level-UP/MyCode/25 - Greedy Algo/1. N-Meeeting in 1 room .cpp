
// Gfg - https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// All are same Problem

// N meeting in a Room
// Activity selection Problem
// n trains and 1 platform

class Solution
{
public:
    static bool cmp(pair<int, int> pair1, pair<int, int> pair2)
    {
        // Jiska ending time chota hai usko phle rkhna hai ,
        // /Kyuki sort kene ke lie 2 element to chaiye hi , so ans me pair hai , so do pair chala gya

        return pair1.second < pair2.second;
    }

    int maxMeetings(int start[], int end[], int n)
    {

        vector<pair<int, int>> ans;
        pair<int, int> p;

        // For loop chala kr sb insert kia
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = make_pair(start[i], end[i]);

            //                            OR
            // p.first = start[i];
            // p.second = end[i];
            ans.push_back(p);
        }
        // Creating Custom Comparator
        sort(ans.begin(), ans.end(), cmp);

        // pair me [(1,2),(3,4),(0,6),(5,7),(8,9),(5,9)]

        int count = 1;
        // pair me [(1,2),(3,4),(0,6),(5,7),(8,9),(5,9)]

        int prevtime = ans[0].second;
        for (int i = 1; i < n; i++)
        {
            // pair me [(1,2),(3,4),(0,6),(5,7),(8,9),(5,9)]
            if (ans[i].first > prevtime)
            {
                count++;
                prevtime = ans[i].second;
            }
        }
        return count;
    }
};