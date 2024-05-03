/*
LeetCode Link - https://leetcode.com/problems/group-anagrams/description/
*/

class Solution
{
public:
    /*
    //                                       Approach 1 - Using Sorting , And HashMap

    Step - 1 string ki ek ek value ko s me lene ka or map bnana hai key hamara str ki
            string ek ek krke after sort it take as key
    Step - 2 then s me jo str ki string ke rhe hai usko hum value ki tarah treat kreneg

    TC- O(nklogk) - n for traversal , klogk for sorting
    SC - O(Nk) k is a vector space , n is map space
    */

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<vector<string>> ans;

        // Here Says we consider unorder_mao of
        // key is string type
        // value is array collection of string
        unordered_map<string, vector<string>> mp;

        /*
               Consider example 1 : strs = ["eat","tea","tan","ate","nat","bat"]

               After the below opeartion of for loop map will contain

               aet -- eat, tea, ate
               ant -- tan, nat
               abt -- bat
       */

        for (int i = 0; i < strs.size(); i++)
        {
            //  given array ke ek ek string element ko pkdega
            string s = strs[i];
            // usko sort krega
            sort(strs[i].begin(), strs[i].end());

            // uske bdd jo jo usse milta hoga usko same vector me dalta jaega
            /*
            Working of Hash Map
            Like This ->

            phle sort wali chiz , then jo jo sork ke bdd same aa skte hai wo add ho jaenge

            aet -- eat, tea, ate
            ant -- tan, nat
            abt -- bat

            */
            // str ko sort krne ke bdd str ko as a key and s ko treat as value
            mp[strs[i]].push_back(s);
        }

        // now simply put the elements  of second column of map in ans

        for (auto i : mp)
        {
            ans.push_back(i.second);
        }

        return ans;




        //                            Approach 2 - Without Using Sorting only using  HashMap
        /*
        TC- O(nk) - n and k for traversal  
        SC - O(Nk) k is also map size , n is map space
        */
        class Solution
        {
        public:

            // Create Function to calculate hash map
            std::array<int, 256> hash(string s)
            {
                std::array<int, 256> hash = {0};
                /*
                eat 
                e - > 1
                a - > 1
                t - > 1
                */
                for (int i = 0; i < s.size(); i++)
                {
                    hash[s[i]]++;
                }
                /*
                eat 
                e - > 1
                a - > 1
                t - > 1
                */
                return hash;
            }
            vector<vector<string>> groupAnagrams(vector<string> &strs)
            {

                //  here says key is array of 256 ssize and its value is array of string type
                map<std::array<int, 256>, vector<string>> mp;
                // <std::array<int, 256> is used to create create array of 256 via inbuilt function

                for (auto str : strs)
                {
                // here hash map is take as key , 
                /*
                eat 
                e - > 1
                a - > 1
                t - > 1
                */
                    // or strings ki ek ek string called value

                    // hash(str) -> Calling Function
                    mp[hash(str)].push_back(str);
                    
                }

                vector<vector<string>> ans;
                for (auto it = mp.begin(); it != mp.end(); it++)
                {
                    ans.push_back(it->second);
                }
                return ans;
            }
        };
    }
};