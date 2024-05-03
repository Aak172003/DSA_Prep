/*
Leetcode Link - https://leetcode.com/problems/permutation-in-string/description/
*/

// Solve Using Sliding Window 

class Solution {
private:
    bool checkCountEqual(int a[26],int b[26])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) 
    {
        // Frequency Count 
        int count1[26] = {0};

        for(int i=0;i<s1.length();i++)
        {
            int index= s1[i]-'a';
            count1[index]++;
        }

        // Traverse in s2 String of window size = s1.length()
        int i=0;
        int windowsize = s1.length();
        int count2[26]={0};
        while(i< windowsize && i<s2.length())
        {
            // hum sabhi element o -'a' isle kr rhe hai kyuki wo uska count store krega 
            int index=s2[i]-'a';   
            count2[index]++;
            i++;
        }
        
        // Check for 1st Two Value , is equal or not 
        if(checkCountEqual(count1,count2))
        return true;

        while(i<s2.length())
        // count 1 s1 string ka value hai , As we know updation of new elemet and deleteion of older elemnt in s2 string
        {
            // Add new character and count its frequency
            char newchar = s2[i];
            int index=newchar-'a';
            count2[index]++;  // Add new element 
            
            /* Older Character ko remove krne ke lie current index ko window size se minus krdenge to hum older 
            wale pr pauch jaenge jo ki bs window ke just peeche wal haia jisko hume remove krna hai */

            char olderchar = s2[i-windowsize];
            index=olderchar-'a';
            count2[index]--;  // Remove older element 
            i++;

        if(checkCountEqual(count1,count2))
        return true;
        }
        return false;

    }
};