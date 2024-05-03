/*
LeetCode Link - https://leetcode.com/problems/power-of-four/description/
*/



// Recursive - Approach 1

// If a number is power of two, it can be recursively divided by 4 till it becomes 1
// If the start number is 0 or if any intermediate number is not divisible by 4, we return false


class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        if(n == 1) return true;
        
        //  if value n se % krne pr 0 ke sth sth , us value ko n / 4 ,
        //  krne pr wo sb values bhi remainder 0 degi to wo 4 ke power me aati hai
        return n % 4 == 0 && isPowerOfFour(n / 4);
        
    }
};

// Time Complexity : O(logn), where n is the given input number
// Space Complexity : O(logn), required for recursive stack


// Iterative  - Approach 2
// The same solution as above but done iteratively

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return 0;
        
        while(n % 4 == 0) 
            n /= 4;
        return n == 1;
    }
};

// Time Complexity : O(logn), where n is the given input number
// Space Complexity : O(1)




