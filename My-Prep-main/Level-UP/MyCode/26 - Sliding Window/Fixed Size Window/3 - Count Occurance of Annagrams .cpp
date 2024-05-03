
// GFG - https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution
{
public:
    //                     Approach - 1 ( Naive Approach - O(N^2))

    // bool compare(string temp, string pat)
    // {
    //     unordered_map<char, int> mp;

    //     for (auto it : temp)
    //     {
    //         mp[it]++;
    //     }

    //     for (auto it : pat)
    //     {

    //         // if in any iteration ,
    //         // false the condition just i am returning

    //         if (mp.find(it) == mp.end())
    //             return false;
    //     }
    //     return true;
    // }

    // int search(string pat, string txt)
    // {

    //     int count = 0;

    //     int n = txt.size();
    //     int k = pat.size();

    //     for (int i = 0; i < n - k + 1; i++)
    //     {
    //         string temp = "";
    //         for (int j = i; j < k + i; j++)
    //         {
    //             temp += txt[j];
    //         }

    //         if (compare(temp, pat))
    //         {
    //             count++;
    //         }
    //     }

    //     return count;
    // }

        //                     Approach - 2 ( Naive Approach - O(N^2))

    bool allZero(vector<int> &counter)
    {
        for (auto it : counter)
        {
            if (it != 0)
                return false;
        }

        return true;
    }

    int search(string pat, string txt)
    {

        int count = 0;

        int n = txt.size();
        int k = pat.size();

        vector<int> counter(26, 0);

        // frequency
        for (int i = 0; i < k; i++)
        {
            char ch = pat[i];
            counter[ch - 'a']++;
        }

        int i = 0, j = 0;

        // j chalega end tk
        while (j < n)
        {

            // counter me uska occurance substracte krte chalenge
            char ch = txt[j];
            counter[ch - 'a']--;

            // jbtk j equal to k nhi ho jata
            // tb tk j++

            // When j == k hojaega ,
            if (j - i + 1 == k)
            {
                if (allZero(counter))
                {
                    count++;
                }

                // in this line we remove 1 element from piche se , then increment i
                // remove means noting ki remove ,
                // just increment the occurance of that ele
                // which i want to remove

                counter[txt[i] - 'a']++;
                i++;
            }
            j++;
        }

        return count;
    }
};