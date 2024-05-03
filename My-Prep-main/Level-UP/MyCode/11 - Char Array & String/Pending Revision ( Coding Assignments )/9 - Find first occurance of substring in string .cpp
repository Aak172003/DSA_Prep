/*
LeetCode Link - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

// TC - O(N^2)
// SC - O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();    // haystack ka size
        int m = needle.size();      // needle ka size
        
        // loop n-m tk chelga kyuli comarison krne ke lie at least m size tk ki string chaiye haystack me 
        for(int i=0;i<=n-m;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if needle[j] != haystack[i+j] not equal so , j is not move only i is move 

                if(needle[j] != haystack[i+j])  
                // i+j islea kyuki mai i ko kuch mhi krna chahta ,
                //  mai j ki size ki help se i+j krke char compare krunga 
                {
                    break;
                }
                if(j == m-1)return i;
            }
        }
        return -1;
        
    }
};