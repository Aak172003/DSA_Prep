/*
LeetCode Link - https://leetcode.com/problems/power-of-two/
*/


class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        //  1 Approach 
        
        // here we take loop from 0 to 31 because integer range upto 31
        for(int i=0;i<31;i++)   
        {
            int ans= pow(2,i);
            if(ans==n)return true;
        }
        return false;


        // Better version of Approch 1 
        
        int ans=1;
        for(int i=0;i<31;i++)
        {
            // if n == 1 , so return true 
            if(ans==n)return true;
            // Her we reuse the code 
            
            if(ans<INT_MAX/2)  // Here checking The edge case 
            {
                // Here we Resue the code 
                ans=ans*2;
            }
        }
        return false ;

        //  3 Approach

        if(n<=0)
        return false;
        return (n&(n-1))==0;

        // OR 

        // 1 line of code of above Approach 3 
        return n < 1 ? false : (n & (n - 1)) == 0 ? true : false;

    }
};



// ✔️ Solution - I (Recursive)

// If a number is power of two, it can be recursively divided by 2 till it becomes 1
// If the start number is 0 or if any intermediate number is not divisible by 2, we return false

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if(n == 1) return true;
        
        //  if value n se % krne pr 0 ke sth sth , us value ko n / 2 ,
        //  krne pr wo sb values bhi remainder 0 degi to wo 2 ke power me aati hai
        return n % 2 == 0 && isPowerOfTwo(n / 2);
    }
};

// Time Complexity : O(logn), where n is the given input number
// Space Complexity : O(logn), required for recursive stack


// ✔️ Solution - II (Iterative)

// The same solution as above but done iteratively

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return 0;
        
        while(n % 2 == 0) 
            n /= 2;
        return n == 1;
    }
};

// Time Complexity : O(logn), where n is the given input number
// Space Complexity : O(1)





