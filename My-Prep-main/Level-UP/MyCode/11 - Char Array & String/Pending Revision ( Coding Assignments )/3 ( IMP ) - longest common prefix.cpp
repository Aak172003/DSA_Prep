/*
LeetCode Link - https://leetcode.com/problems/longest-common-prefix/description/
*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        int i = 0; // iteratre over all characters of string
        string ans;

        while (true)
        {
            char curr_ch = 0; // is used to stor character of string
            
            /*
            // Loop me wo 3 br flower, flow , flight wale loop pr chalega 
            flower
            flow
            flight

            // ek brr teeno str pr chalne ke bdd wo check krega agr curr_ch != 0, then curr_ch ko push into string


            flower
            flow
            flight
            flower
            flow
            flight


            */
            for (auto str : strs)
            {
                // jb flower , flow ,  flower ---->> isme flow tk same hai , jaise hi wo e pr jaega to flow wale test case
                // me i >= size so curr_ch initialise with 0
                if (i >= str.size())
                {
                    curr_ch = 0;
                    break;
                }

                // if current character  == 0 ,
                // so hum array ki phli string ke first elemet ko curr_ch me daal denge
                if (curr_ch == 0)
                {
                    curr_ch = str[i]; // i indicates character of current String
                }

                // if curr_ch !=0 ,
                else if (str[i] != curr_ch)
                {
                    // if not equal , hrn break
                    curr_ch = 0;
                    break;
                }
            }

            // if curr_curr not equal to 0 , then push into string
            if (curr_ch == 0)
                break;
            ans.push_back(curr_ch);
            i++;
        }
        return ans;
    }
};