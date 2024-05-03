

// Gfg - https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {

        int i = 0, j = 0, n = s.size();
        ;
        unordered_map<char, int> mp;
        int maxLen = 0;

        while (j < n)
        {

            mp[s[j]]++;

            // if map ka size big usme loi 4 times repeated ko dlete ,
            //  Then final bde ko delete
            if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[s[i]]--;

                    // first delete it's occurance ,
                    //  Then remove it from map if it occurance becomes 0

                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);

                    //  Increase i++
                    i++;
                }
            }

            if (mp.size() == k)
            {
                //  for update , the original value
                maxLen = max(maxLen, j - i + 1);
            }

            j++;
        }
        if (maxLen == 0)
        {
            return -1;
        }

        return maxLen;
    }
};
