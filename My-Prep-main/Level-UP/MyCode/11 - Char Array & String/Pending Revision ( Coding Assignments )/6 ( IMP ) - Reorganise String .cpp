/*
LeetCode Link - https://leetcode.com/problems/reorganize-string/description/

ye Question me hum queue ke terms ke kaam krenge , means (FIFO -> First In First Out)

 a | b  so for this
 top1 = a, top2 = b
 dono string me add hone ke bdd remove from queue , then elements hum phr se daalna start krenge
 ex = a | b |
*/

class Solution
{
public:
    //                                       Approach - 1 Using Greedy Method

    /*
    Step - 1 -> Find ? Most Occurant character & fit it non-adjacently in one go , ghum kr wapas nhi jaana chaiye
                Agr wo jaata hai to , wo problem hai hamare lie
    Step - 2 -> Fill the rest Character


    TC - o(N)
    SC - o(1)

    */

    string reorganizeString(string s)
    {
        int hash[26] = {0};

        // Create Hash_Map
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
        }

        // Find the most Frequent Character
        char max_freq_char;
        int max_freq = INT_MIN;

        for (int i = 0; i < 26; i++)
        {
            // here has store frequency count
            if (hash[i] > max_freq)
            {
                max_freq = hash[i];
                max_freq_char = i + 'a';
            }
        }

        // Try to score most freq character in alternative way
        int index = 0;

        // if max_freq > 0 or index ka size string ke ander hi ho
        while (max_freq > 0 && index < s.size())
        {
            // place kia index pr , then uski freq ko decrement krna hai
            // or ye dono kaam krne ke bdd uska index + 2 kr denge

            s[index] = max_freq_char;
            max_freq--;
            index += 2;
        }

        // Agr mai saale max_freq wala elemenet , saara count kr paya hu to uska freq_count decrement hote hote 0 ho jana chaiye
        // Agr nhi hota hai means kuch golmaal hai , then return empty string
        if (max_freq != 0)
        {
            return "";
        }

        // max_freq wale elemet ko pooti tarah se insert hone ke bdd uski jgah hum 0 daal denge
        hash[max_freq_char - 'a'] = 0;

        // Lets place the rest of the character

        for (int i = 0; i < 26; i++)                                         // Constant Time Complexity  (1)
        {
            // jo poora insert hogya tha , to uski jgah humne 0 daal dia
            // ab ham jiska count 0 se bda hai usko store krenge alternative position pr
            while (hash[i] > 0)
            {
                // most freq ko store krne ke bdd hume next element ko store krna hai
                // agr index out of bound hogya to usko 1st Index pr bhej do agr nhi hua to index pr hi rhne do
                index = index >= s.size() ? 1 : index;

                s[index] = i + 'a'; // to take lowercase Character
                hash[i]--;
                index += 2;
            }
        }

        return s;
    }

    

    //                                       Approach - 2 Using Hash Map & Priority Queue
    // TC - O(nlogn)
    // SC - O(N)

    string reorganizeString(string S)
    {
        string res = "";

        // Create Hash Map
        unordered_map<char, int> mp;
        // make count frequencies in Hash Table
        for (auto s : S)
            mp[s]++;

        // initialise priority Queue in terms of pair
        priority_queue<pair<int, char>> pq;
        // pair wise PriorityQueue me push kr denge
        for (auto m : mp)
            pq.push(make_pair(m.second, m.first));

        if
            while (pq.size() > 1)
            {
                // hamesha ( top1 , top2 ) pair form me rhega , kbhi bhi single me nhi jaega
                auto top1 = pq.top();
                pq.pop();
                auto top2 = pq.top();
                pq.pop();

                // res string me store krte chalenge
                res = res + top1.second;
                res = res + top2.second;

                top1.first--;
                top2.first--;

                // queue se pop krne ke bdd , dubara uka count check krenge , ki wo > 0 hai , so put into queue
                if (top1.first > 0)
                    pq.push(top1);
                // queue se pop krne ke bdd , dubara uka count check krenge , ki wo > 0 hai , so put into queue
                if (top2.first > 0)
                    pq.push(top2);
            }

        // if single elemet bcha ho queue me , so pair to bn nhi paega
        if (!pq.empty())
        {
            // agr pq.first means char ki frequencies ki bt ho rhi hai , wo 1 se jyada hai ,
            // to hum return " " krdenge
            if (pq.top().first > 1)
                return "";
            // otherwise usko res string me add kr denge
            else
                res += pq.top().second;
        }

        return res;
    }
};