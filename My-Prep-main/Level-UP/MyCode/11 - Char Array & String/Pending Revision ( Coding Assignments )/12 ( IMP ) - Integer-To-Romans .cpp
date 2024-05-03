/*
Leetcode Link - https://leetcode.com/problems/integer-to-roman/description/
*/


/* ROMAN NUMBER EXHAUSTED MAP
                         
        Symbol        Value
        M             1000
        CM            900
        D             500
        CD            400
        C             100
        XC            90
        L             50
        XL            40
        X             10
        IX            9
        V             5 
        IV            4
        I             1

*/

class Solution {
public:
    string intToRoman(int nums) 
    {
        string romanSymbols[] = {"M","CM", "D","CD", "C", "XC", "L", "XL",
        "X","IX","V","IV","I"};

        int valuesOfSymbols[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        // int size = valuesOfSymbols.size();
        string ans = "";

        for(int i=0;i<13;i++)
        {
            while(nums>=valuesOfSymbols[i])
            {
                // if jo no dia hai uski nums upr se search krte hue aaegi ,
                //  so value me jo usse chota mila just so 
                // us current index ka roman symbol add krdenge 
                // or uski vaulue substract kr denge nums me 
                ans = ans + romanSymbols[i];
                nums = nums - valuesOfSymbols[i];
            }
        }
        return ans;
        
    }
};