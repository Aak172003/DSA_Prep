/*
LeetCode Link - https://leetcode.com/problems/power-of-three/description/
*/


// Recursive - Approach 1

// If a number is power of two, it can be recursively divided by 3 till it becomes 1
// If the start number is 0 or if any intermediate number is not divisible by 3, we return false


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n == 1) return true;
        
        //  if value n se % krne pr 0 ke sth sth , us value ko n / 3 ,
        //  krne pr wo sb values bhi remainder 0 degi to wo 3 ke power me aati hai
        return n % 3 == 0 && isPowerOfThree(n / 3);
        
    }
};

// Time Complexity : O(logn), where n is the given input number
// Space Complexity : O(logn), required for recursive stack


// Iterative  - Approach 2
// The same solution as above but done iteratively

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return 0;
        
        while(n % 3 == 0) 
            n /= 3;
        return n == 1;
    }
};

// Time Complexity : O(logn), where n is the given input number
// Space Complexity : O(1)




