/*
Leetcode Link - https://leetcode.com/problems/string-compression/

It is also known as Run Length Encoding Technique 
*/

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        /*
        ---------- Approach 1 - Uing an extra string variable , means it is not inplace working---------------
        TC - O(N)
        SC - O(N)
        */

        int count = 1;
        // Initialse an ans empty string , to store string
        string ans;

        for (int i = 0; i < chars.size(); i++)
        {
            // here hum aage wala char piche wale se check krr rhe hai , same hone pr count++ , and i++
            while (i < chars.size() - 1 && chars[i + 1] == chars[i])
            {
                count++;
                i++;
            }
            // when at point both are different , so ith position ka char hum ans me store kr denge
            ans += chars[i];

            // if count==1 then hume kuch krne ki jarroat nhi hai
            if (count == 1)
                continue;
            /*
            to_string is a function template in the Standard Library that converts a numerical value
            (such as an int, float, double, etc.) into its equivalent string representation.
            */

            // when count>1 so usko hume ans me store krna pdega
            ans += to_string(count);
            // then for further processing , we make count = 1
            count = 1;
        }

        // chars array se sb ans me jaane ke bdd chars ko clear krdenge
        chars.clear();
        // char me wapas daal rhe hai ans ka saara data
        for (int i = 0; i < ans.size(); i++)
            chars.push_back(ans[i]);

        return chars.size();
    }









    /*
    ---------- Approach 2 - Uing Without extra string variable , means it is inplace working---------------
    TC - O(N)
    SC - O(1)
    */

    int compress(vector<char> &chars)
    {
        int size = chars.size();
        if (size == 0)
            return 0;

        int i = 0, count = 1;
        int index = 0; // index variable iterate ove original char array

        char prevChar = chars[0];

        for (i = 1; i < size; i++)
        {
            if (chars[i] == prevChar)
            {
                count++;
            }
            else
            {
                chars[index] = prevChar;
                index++;
                if (count > 1)
                {
                    // count if in 2 digit , so store in string
                    string countStr = to_string(count);
                    // then iterate over that string and put into original char array
                    for (char ch : countStr)
                    {
                        chars[index] = ch;
                        index++;
                    }
                }
                // update prev to i , and count == 1
                prevChar = chars[i];
                count = 1;
            }
        }

        // for last iteration
        chars[index] = prevChar;
        index++;
        if (count > 1)
        {
            // count if in 2 digit , so store in string
            string countStr = to_string(count);
            // then iterate over that string and put into original char array
            for (char ch : countStr)
            {
                chars[index] = ch;
                index++;
            }
        }

        return index;
    }
};