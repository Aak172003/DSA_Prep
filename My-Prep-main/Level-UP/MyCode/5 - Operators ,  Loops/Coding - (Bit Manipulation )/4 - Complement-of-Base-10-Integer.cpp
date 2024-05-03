/*
LeetCode Link - https://leetcode.com/problems/complement-of-base-10-integer/
*/


//              1 More Approach from , PDF 

class Solution {
public:
    int bitwiseComplement(int n) {

        if(n==0)return 1;
        int x = 1;

        // Jb tk x jo ki XOR krne ke kaam aata hai wo last value bit tk nhi pauch jata ,
        //  tb tk ek brr Xor kene pr jo answer aaega ,
        //  ussi me Xor ko left shift krte jaenge 
        
        while(x<=n)
        {
            n = n^x;
            x = x<<1;
        }
        return n;
    }
};

           

//                   2nd Approach
class Solution {
public:
    int bitwiseComplement(int n) {

        int m=n;

        // initialise mask with 00000000000000000000
        int mask=0;

        // m use islea kia kyuki wo mask create hua ki nhi ye btaega ,
        // mask me jb tk saari bit nhi hojaati tb tk wo mask ko left shift krke ,
        // or krke 1 chipkayega or m ki bit me right shift krdega 
        
        if(m==0)return 1 ;

        // until we not get m == 0 we done lope again and again 
        while(m!=0)
        {
            // mask me 1 chipkana ke lie or 1 then left shift ki or 1 chipak ske 

            mask = (mask<<1) | 1;     // phle , or hoga then shift hoga

            // hum check kr rhe hai jb tk m == 0 nhi hota 
            // tb tk mask me left shift hoga or last value me (OR) hoga 
            // jitni brr 1 chipkaega utni brr hum m ko right shift krnege , 
            // jb 1 chipkaate chipkaate or m ko right move krke krte 0 hojaega , that time mask completer  

            m=m>>1;  // right shift , ki uski value 0000 na hojati
        }
        // phr mask me jitni value utne se and baaki sb mask me 0 , and 0 se & give result = 0
        
        int ans = (~n) & mask;  // mask creation above 
        return ans;
        
    }
};